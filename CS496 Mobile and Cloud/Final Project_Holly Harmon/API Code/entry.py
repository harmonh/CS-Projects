# Name: Holly Harmon
# OSUID: 932456676
# Assignment: 3 - API
# Class: CS496
# Overall code and structure adapted from OSU CS496 lecture "API Demo" by Justin Woldford
# Upon POST, Bike allows for BikeEntry entitity creation. Must include a user key/id and a date.
# and upon GET, it displays the information about a given entity or the keys for all BikeEntry entities.
# Upon POST, Run allows for RunEntry entitity creation. Must include a user key/id and a date.
# Upon GET, it displays the information about a given entity or the keys for all RunEntry entities.

import webapp2
from datetime import datetime
from google.appengine.ext import ndb
import db_models
import json


class Bike(webapp2.RequestHandler):
    def post(self):
        '''Create new entry
        user
        bike_type
        distance
        kilos
        time
        level
        date
        '''
        new_entry = db_models.BikeEntry()
        uid = self.request.get('user', default_value=None)
        date = self.request.get('date', default_value=None)
        bike_type = self.request.get('bike_type', default_value=None)
        distance = self.request.get('distance', default_value=None)
        kilos = self.request.get('kilos', default_value=None)
        time = self.request.get('time', default_value=None)
        level = self.request.get('level', default_value=None)

        if uid:
            uid = ndb.Key(db_models.User, int(uid)).get()
            if not uid:
                self.response.status = 404
                self.response.status_message = "User not found"
                self.response.write("User not found\n")
                return
        else:
            self.response.status = 400
            self.response.status_message = "Invalid request, User ID required"
            self.response.write("Invalid request, User id required\n")
            return
        
        if date:
            new_entry.date = date
            #Got date to save as a correct DateProperty, but didn't quite figure out
            #converting it to be displayed in json. Set it to StringProperty for simplification
            #try:
            #    d = datetime.strptime(date, '%Y-%m-%d').date()
            #    new_entry.date = d
            #    self.response.write(d)
            #except ValueError:
            #    self.response.write("Invalid Format: Enter date as m/d/y ex: 01/02/2003\n")
        else:
            self.response.status = 400
            self.response.status_message = "Invalid request, Date is requried"
            return

        if bike_type:
            new_entry.bike_type = bike_type
        if distance:
            try:
                new_entry.distance = int(distance)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, distance must be integer"
                #self.response.write("Distance not integer\n")
                return
        if kilos == "True" or kilos == "true":
            new_entry.kilos = True
        if time:
            try:
                new_entry.time = int(time)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, time must be integer"
                return
        if level:
            try:
                new_entry.level = int(level)
            except ValueError:
                self.response.status = 400
                self.response.status_message = "Invalid request, level must be integer"
                return
        k = new_entry.put()
        uid.bikes.append(k)
        uid.put()
        out = new_entry.to_dict()
        self.response.write(json.dumps(out))
        return

    def get(self, **kwargs):
        #Displays information about bike entries

        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'id' in kwargs:
            entry = ndb.Key(db_models.BikeEntry, int(kwargs['id'])).get()
            if not entry:
                self.response.status = 404
                self.response.status_message = "Entry Not Found"
                self.response.write("Entry Not Found")
                return
            out = entry.to_dict()
            self.response.write(json.dumps(out))
        #if no entry is specified, displays all bike entry keys
        else:
            q = db_models.BikeEntry.query()
            keys = q.fetch(keys_only=True)
            results = { 'bike entry keys' : [x.id() for x in keys]}
            self.response.write(json.dumps(results))


class Run(webapp2.RequestHandler):
    def post(self):
        '''Create new entry
        user
        path
        distance
        kilos
        time
        date
        '''
        new_entry = db_models.RunEntry()
        uid = self.request.get('user', default_value=None)
        date = self.request.get('date', default_value=None)
        path = self.request.get('path', default_value=None)
        distance = self.request.get('distance', default_value=None)
        kilos = self.request.get('kilos', default_value=False)
        time = self.request.get('time', default_value=None)

        if uid:
            uid = ndb.Key(db_models.User, int(uid)).get()            
            if not uid:
                self.response.status = 404
                self.response.status_message = "User not found"
                self.response.write("User not found\n")
                return
        else:
            self.response.status = 400
            self.response.status_message = "Invalid request, User id required"
            self.response.write("Invalid request, User id required\n")
            return
        
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
        k = new_entry.put()
        uid.runs.append(k)
        uid.put()
        out = new_entry.to_dict()
        self.response.write(json.dumps(out))
        return

    def get(self, **kwargs):
        #displays info about a run entry
        if 'application/json' not in self.request.accept:
            self.response.status = 406
            self.response.status_message = "Not Acceptable"
            return
        if 'id' in kwargs:
            entry = ndb.Key(db_models.RunEntry, int(kwargs['id'])).get()
            if not entry:
                self.response.status = 404
                self.response.status_message = "Entry Not Found"
                self.response.write("Entry Not Found")
                return
            out = entry.to_dict()
            self.response.write(json.dumps(out))
        #if no entry is specified, displays all run entry keys
        else:
            q = db_models.RunEntry.query()
            keys = q.fetch(keys_only=True)
            results = { 'run entry keys:' : [x.id() for x in keys]}
            self.response.write(json.dumps(results))