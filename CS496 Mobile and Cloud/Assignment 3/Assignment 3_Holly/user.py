# Name: Holly Harmon
# OSUID: 932456676
# Assignment: 3 - API
# Class: CS496
# Overall code and structure adapted from OSU CS496 lecture "API Demo" by Justin Woldford
# mainly the post, get, and put functions.
# User: POST will allow for creation of a User entity and must include a name not already
# in the database. GET will display the information of the provided User or a list of all
# User entity keys if no User key/id is provided. DELETE will remove the User entity specified
# including all BikeEntry and RunEntry entities referenced in the User's bikes[] and runs[].
# UserBike: PUT allows the user to update a BikeEntry entity and DELETE removes the entity from
# the User's bikes[] list and deletes the entity from the database. UserRun does the same for
# RunEntry entities.

import webapp2
from google.appengine.ext import ndb
import db_models
import json


class User(webapp2.RequestHandler):
    def post(self):
        """Create User Entity
		name - Required
		age 
		bikes[]
		runs[]		
		"""
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        new_user = db_models.User()
        name = self.request.get('name', default_value=None)
        password = self.request.get('pass', default_value=None)
        new_user.password = password
        age = self.request.get('age', default_value=None)
        if name:
            q = db_models.User.query(db_models.User.name == name).fetch()
            #self.response.write(q)
            if q:
                self.response.status = 400
                self.response.status_message = "Invalid Request, User name already exists"
                return
            else:
                new_user.name = name
        else:
            self.response.status = 400
            self.response.status_message = "Invalid request, User Name is Required"
            return
        if age:
            new_user.age = int(age)
        k = new_user.put()
        # rout = db_models.User.query()
        # sout = rout.fetch()
        # self.response.write(sout)
        out = new_user.to_dict()
        self.response.write(json.dumps(out))
        return

    def get(self, **kwargs):
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'id' in kwargs:
            user = ndb.Key(db_models.User, int(kwargs['id'])).get()
            if not user:
                self.response.status = 404
                self.response.status_message = "User Not Found"
                self.response.write("User Not Found")
                return
            out = user.to_dict()
            self.response.write(json.dumps(out))
        else:
            q = db_models.User.query()
            keys = q.fetch(keys_only=True)
            results = { 'user keys' : [x.id() for x in keys]}
            self.response.write(json.dumps(results))

    def delete(self, **kwargs):
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'id' in kwargs:
            user = ndb.Key(db_models.User, int(kwargs['id'])).get()
            if not user:
                self.response.status = 404
                self.response.status_message = "User Not Found"
                self.response.write("User Not Found")
                return
        else:
            self.response.status = 406
            self.response.status_message = "Not Acceptable: Must include User ID for Delete."
            self.response.write("Not Acceptable: Must include User ID for Delete.")
            return
        #First delete all user entries
        #Bikes:
        entries = user.bikes
        for entry in entries:
            bike = entry.get()
            bike.key.delete()
        #Runs:
        entries = user.runs
        for entry in entries:
            run = entry.get()
            run.key.delete()
        #Finally delete user
        user.key.delete()


class UserBike(webapp2.RequestHandler):
    def put(self, **kwargs):
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'uid' in kwargs:
            user = ndb.Key(db_models.User, int(kwargs['uid'])).get()
            if not user:
                self.response.status = 404
                self.response.status_message = "User Not Found"
                self.response.write("User Not Found")
                return
        if 'bid' in kwargs:
            entry = ndb.Key(db_models.BikeEntry, int(kwargs['bid'])).get()
            if not entry:
                self.response.status = 404
                self.response.status_message = "Entry Not Found"
                self.response.write("Entry Not Found")
                return
        if entry.key not in user.bikes:
            #not sure if this is a 404 error
            self.response.status = 404
            self.response.status_message = "User has no such entry"
            self.response.write("User has no such entry")
            return

        date = self.request.get('date', default_value=None)
        bike_type = self.request.get('bike_type', default_value=None)
        distance = self.request.get('distance', default_value=None)
        kilos = self.request.get('kilos', default_value=None)
        time = self.request.get('time', default_value=None)
        level = self.request.get('level', default_value=None)
        if date:
            entry.date = date
        if bike_type:
            entry.bike_type = bike_type
        if distance:
            try:
                entry.distance = int(distance)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, distance must be integer"
                #self.response.write("Distance not integer\n")
                return
        if kilos == "True" or kilos == "true":
            entry.kilos = True
        if time:
            try:
                entry.time = int(time)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, time must be integer"
                return
        if level:
            try:
                entry.level = int(level)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, level must be integer"
                return

        entry.put()
        out = entry.to_dict()
        self.response.write(json.dumps(out))
        #self.response.write(entry.key)
        #self.response.write(user.bikes)

    def delete(self, **kwargs):
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'uid' in kwargs:
            user = ndb.Key(db_models.User, int(kwargs['uid'])).get()
            if not user:
                self.response.status = 404
                self.response.status_message = "User Not Found"
                self.response.write("User Not Found")
                return
        else:
            self.response.status = 406
            self.response.status_message = "Not Acceptable: Must include User ID for Delete."
            self.response.write("Not Acceptable: Must include User ID for Delete.")
            return
        if 'bid' in kwargs:
            entry = ndb.Key(db_models.BikeEntry, int(kwargs['bid'])).get()
            if not entry:
                self.response.status = 404
                self.response.status_message = "Entry Not Found"
                self.response.write("Entry Not Found")
                return
        if entry.key not in user.bikes:
            #not sure if this is a 404 error
            self.response.status = 404
            self.response.status_message = "User has no such entry"
            self.response.write("User has no such entry")
            return
        #delete reference in user:
        bikes = user.bikes
        for bike in bikes:
            if bike == entry.key:
                self.response.write(bike)
                user.bikes.remove(bike)
                user.put()
        #delete entry:
        entry.key.delete()

class UserRun(webapp2.RequestHandler):
    def put(self, **kwargs):
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'uid' in kwargs:
            user = ndb.Key(db_models.User, int(kwargs['uid'])).get()
            if not user:
                self.response.status = 404
                self.response.status_message = "User Not Found"
                self.response.write("User Not Found")
                return
        if 'rid' in kwargs:
            entry = ndb.Key(db_models.RunEntry, int(kwargs['bid'])).get()
            if not entry:
                self.response.status = 404
                self.response.status_message = "Entry Not Found"
                self.response.write("Entry Not Found")
                return
        if entry.key not in user.runs:
            #not sure if this is a 404 error
            self.response.status = 404
            self.response.status_message = "User has no such entry"
            self.response.write("User has no such entry")
            return

        date = self.request.get('date', default_value=None)
        path = self.request.get('path', default_value=None)
        distance = self.request.get('distance', default_value=None)
        kilos = self.request.get('kilos', default_value=False)
        time = self.request.get('time', default_value=None)

        if date:
            new_entry.date = date
        else:
            self.response.status = 400
            self.response.status_message = "Invalid request, Date is requried"
        if path:
            new_entry.path = path
        if distance:
            try:
                new_entry.distance = int(distance)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, distance must be integer"
                return
        if kilos == "True" or kilos == "true":
            new_entry.kilos = True
        else:
            new_entry.kilos = False
        if time:
            try:
                new_entry.time = int(time)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, time must be integer"
                return

        entry.put()
        out = entry.to_dict()
        self.response.write(json.dumps(out))

    def delete(self, **kwargs):
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'uid' in kwargs:
            user = ndb.Key(db_models.User, int(kwargs['uid'])).get()
            if not user:
                self.response.status = 404
                self.response.status_message = "User Not Found"
                self.response.write("User Not Found")
                return
        else:
            self.response.status = 406
            self.response.status_message = "Not Acceptable: Must include User ID for Delete."
            self.response.write("Not Acceptable: Must include User ID for Delete.")
            return
        if 'rid' in kwargs:
            entry = ndb.Key(db_models.BikeEntry, int(kwargs['rid'])).get()
            if not entry:
                self.response.status = 404
                self.response.status_message = "Entry Not Found"
                self.response.write("Entry Not Found")
                return
        if entry.key not in user.runs:
            #not sure if this is a 404 error
            self.response.status = 404
            self.response.status_message = "User has no such entry"
            self.response.write("User has no such entry")
            return
        #delete reference in user:
        runs = user.runs
        for run in runs:
            if run == entry.key:
                #self.response.write(run)
                user.runs.remove(run)
                user.put()
        #delete entry:
        entry.key.delete()