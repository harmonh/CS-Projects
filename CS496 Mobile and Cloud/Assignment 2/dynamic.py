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


class MainPage(webapp2.RequestHandler):

    def get(self):
#        entries = Entries.query().order(-Entries.date).fetch(10)
#        template_values = {
#            'entries':entries
#        }

#        for entry in entries:
#            self.response.write(entry.bike_type)
        
        entries = Entries.query(ancestor=ndb.Key(Entries, 'default_key')).order(-Entries.date).fetch()
        template_values = {
                'entries':entries
        }
        template = JINJA_ENVIRONMENT.get_template('index.html')
        self.response.write(template.render(template_values))

    def post(self):
        k = ndb.Key(Entries, 'default_key')
        if self.request.get('action') == 'new_entry':
            entry = Entries(parent=k,
                bike_type=self.request.get('bike'),
                distance = self.request.get('distance'),
                kilos = self.request.get('kilos'),
                time = self.request.get('time'),
                level = self.request.get('level'),
                date = self.request.get('date')
            )

            entry.put()

        template_values = {}
        
        entries = Entries.query(ancestor=k).order(-Entries.date).fetch()
        template_values = {
            'entries':entries
        }

        template = JINJA_ENVIRONMENT.get_template('index.html')
        self.response.write(template.render(template_values))
