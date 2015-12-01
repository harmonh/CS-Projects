# Name: Holly Harmon
# OSUID: 932456676
# Assignment: 3 - API
# Class: CS496
# "to_dict" function code copied from OSU CS496 lecture "API Demo" by Justin Woldford

from google.appengine.ext import ndb


class Model(ndb.Model):
    def to_dict(self):
        d = super(Model, self).to_dict()
        d['key'] = self.key.id()
        return d


class User(Model):
    name = ndb.StringProperty(required=True)
    password = ndb.StringProperty(required=True)
    age = ndb.IntegerProperty()
    bikes = ndb.KeyProperty(repeated=True)
    runs = ndb.KeyProperty(repeated=True)

    def to_dict(self):
        d = super(User, self).to_dict()
        d['bikes'] = [m.id() for m in d['bikes']]
        d['runs'] = [n.id() for n in d['runs']]
        return d


class BikeEntry(Model):
    date = ndb.StringProperty(required=True)
    bike_type = ndb.StringProperty()
    distance = ndb.IntegerProperty()
    kilos = ndb.BooleanProperty(default=False)
    time = ndb.IntegerProperty()
    level = ndb.IntegerProperty()
    
    
class RunEntry(Model):
    date = ndb.StringProperty(required=True)
    distance = ndb.IntegerProperty()
    kilos = ndb.BooleanProperty(default=False)
    time = ndb.IntegerProperty()
    path = ndb.StringProperty()
    
