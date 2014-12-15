-- Name: Holly Harmon
-- email: harmonh@onid.oregonstate.edu
-- Class: CS275
-- Table creation for a Game of Thrones Database

CREATE TABLE location (
	id int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	region varchar(255),
	language varchar(255),
	PRIMARY KEY (id)
	) ENGINE=InnoDB;

CREATE TABLE house (
	id int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	symbol varchar(255),
	house_words text,
	lid int(11),
	PRIMARY KEY (id),
	FOREIGN KEY (lid) REFERENCES location(id)
	) ENGINE=InnoDB;

CREATE TABLE religion (
	id int(11) NOT NULL AUTO_INCREMENT,
	name varchar(255) NOT NULL,
	deities text,
	PRIMARY KEY (id)
	) ENGINE=InnoDB;

CREATE TABLE people (
	id int(11) NOT NULL AUTO_INCREMENT,
	fname varchar(255) NOT NULL,
	lname varchar(255),
	pl_of_birth int(11),
	hid int(11),
	rid int(11),
	PRIMARY KEY (id),
	UNIQUE (fname, lname),
	FOREIGN KEY (pl_of_birth) REFERENCES location(id),
	FOREIGN KEY (hid) REFERENCES house(id),
	FOREIGN KEY (rid) REFERENCES religion(id)
	) ENGINE=InnoDB;

CREATE TABLE relation_type (
	id int(11) NOT NULL AUTO_INCREMENT,
	type varchar(255),
	PRIMARY KEY (id)
	) ENGINE=InnoDB;

CREATE TABLE relation_people (
	person_id int(11),
	relation_id int(11),
	type_id int(11),
	PRIMARY KEY (person_id, relation_id),
	FOREIGN KEY (person_id) REFERENCES people(id),
	FOREIGN KEY (relation_id) REFERENCES people(id),
	FOREIGN KEY (type_id) REFERENCES relation_type(id)
	) ENGINE=InnoDB;

--add location:
INSERT INTO location (name, population, language) values ([name], [pop], [lang]);

--add house:
INSERT INTO house (lid, name, symbol, house_words) 
SELECT id, [name], [symbol], [house_words]
FROM location WHERE name = [house location];

--add religion:
INSERT INTO religion (name, deities) values ([name], [deities]);

--add person:
INSERT INTO people (fname, lname, pl_of_birth, hid, rid)
SELECT [first name], [last name], (SELECT id FROM location WHERE name = [birth place]),
(SELECT id FROM house WHERE name = [house name]), id 
FROM religion WHERE name = [religion];

--add relation_type (ex: mother, brother, bannerman, etc):
INSERT INTO relation_type (type) values ([type]);

--add relation_people:
INSERT INTO relation_people (person_id, relation_id, type_id)
SELECT id, (SELECT id FROM people WHERE fname = [first name] AND lname = [last name]),
(SELECT id FROM relation_type WHERE type = [type])
FROM people WHERE fname = [first name] AND lname = [last name];

--Select all people in a house:
SELECT P.fname, P.lname FROM people P INNER JOIN
house H ON P.hid = H.id WHERE H.name = [house]
ORDER BY P.lname;

--update person's house:
UPDATE people
SET hid = (SELECT id FROM house WHERE name = [house])
WHERE fname = [first name] AND lname = [last name];

--select all people related to a person in a certain way (ex: all of the children of one person)
SELECT P.fname, P.lname FROM people P INNER JOIN
(SELECT RP.relation_id FROM relation_people RP INNER JOIN
relation_type RT ON RP.type_id = RT.id
WHERE RT.type = [relationship type] AND RP.person_id = 
(SELECT id FROM people WHERE fname = [fname] AND lname = [lname])) 
AS RTable ON RTable.relation_id = P.id;