# Name: Holly Harmon
# OSUID: 932456676
# Assignment: 3 - API
# Class: CS496
# Overall code and structure adapted from OSU CS496 lecture "API Demo" by Justin Woldford

import webapp2
from google.appengine.ext import ndb
import db_models
import json


class Authenticate(webapp2.RequestHandler):
    def post(self, **kwargs):
        # Authenticate user
        # "name" and "pass"

        name = self.request.get('name', default_value=None)
        password = self.request.get('pass', default_value=None)
        if name:
            # check name
            q = db_models.User.query(db_models.User.name == name).fetch()
            if q:
                # check pass
                if password:
                    # check pass
                    if password == q[0].password:
                        q = db_models.User.query(db_models.User.name == name)
                        key = q.fetch(keys_only=True)
                        results = { 'key' : [x.id() for x in key]}
                        self.response.write(json.dumps(results))
                        return
                    else:
                        self.response.status = 400
                        self.response.status_message = "Invalid Request, Incorrect Password"
                else:
                    self.response.status = 400
                    self.response.status_message = "Invalid request, Password is Required"
                    return
            else:
                self.response.status = 400
                self.response.status_message = "Invalid Request, User does not exist"
                return
        else:
            self.response.status = 400
            self.response.status_message = "Invalid request, User Name is Required"
            return