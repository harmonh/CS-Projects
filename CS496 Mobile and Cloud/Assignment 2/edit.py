import os
from google.appengine.ext import ndb
import jinja2
import webapp2


JINJA_ENVIRONMENT = jinja2.Environment(
    loader=jinja2.FileSystemLoader(os.path.dirname(__file__)),
    extensions=['jinja2.ext.autoescape'],
    autoescape=True)

class Entries(ndb.Model):
    bike_type = ndb.StringProperty(required=True)
    distance = ndb.StringProperty(required=True)
    kilos = ndb.StringProperty(required=True)
    time = ndb.StringProperty(required=True)
    level = ndb.StringProperty(required=True)
    date = ndb.StringProperty(required=True)


class EditEntry(webapp2.RequestHandler):
    def get(self):
        entry_key = ndb.Key(urlsafe=self.request.get('key'))
        entry = entry_key.get()
        template_values = {
        	'entry':entry
        }

        template = JINJA_ENVIRONMENT.get_template('edit.html')
        self.response.write(template.render(template_values))

    def post(self):
    	entry_key = ndb.Key(urlsafe=self.request.get('key'))
        entry = entry_key.get()
        entry.bike_type = self.request.get('bike')
        entry.distance = self.request.get('distance')
        entry.kilos = self.request.get('kilos')
        entry.time = self.request.get('time')
        entry.level = self.request.get('level')
        entry.date = self.request.get('date')
        template_values = {'entry':entry}

        entry.put()

        template = JINJA_ENVIRONMENT.get_template('edit_display.html')
        self.response.write(template.render(template_values))