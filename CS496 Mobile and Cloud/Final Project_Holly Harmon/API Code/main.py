'''
Name: Holly Harmon
OSUID: 932456676
Assignment: 3 - API
Class: CS496
'''

import webapp2
from google.appengine.api import oauth

application = webapp2.WSGIApplication([
    ('/user', 'user.User'),
], debug=True)

application.router.add(webapp2.Route(r'/user/<id:[0-9]+><:/?>', 'user.User'))
application.router.add(webapp2.Route(r'/bike', 'entry.Bike'))
application.router.add(webapp2.Route(r'/bike/<id:[0-9]+><:/?>', 'entry.Bike'))
application.router.add(webapp2.Route(r'/run', 'entry.Run'))
application.router.add(webapp2.Route(r'/run/<id:[0-9]+><:/?>', 'entry.Run'))
application.router.add(webapp2.Route(r'/user/<uid:[0-9]+><:/?>/bike/<bid:[0-9]+><:/?>', 'user.UserBike'))
application.router.add(webapp2.Route(r'/user/<uid:[0-9]+><:/?>/run/<rid:[0-9]+><:/?>', 'user.UserRun'))
application.router.add(webapp2.Route(r'/auth', 'auth.Authenticate'))