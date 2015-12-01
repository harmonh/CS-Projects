import os
from time import strftime

import jinja2
import webapp2

# Creating a new Jinja2 template environment. Code from Google App Engine python
# tutorial: https://cloud.google.com/appengine/docs/python/gettingstartedpython27/templates
JINJA_ENVIRONMENT = jinja2.Environment(
    loader=jinja2.FileSystemLoader(os.path.dirname(__file__)),
    extensions=['jinja2.ext.autoescape'],
    autoescape=True)

class MainPage(webapp2.RequestHandler):

    def get(self):
        # Getting current date/time and setting as strings
        date = strftime("%A, %B %d")
        time = strftime("%I:%M:%S %p %Z")
        #self.response.write(time)
        # Setting variables to be passed to the html template
        temp_vals = {
            'date': date,
            'time': time
        }

        # rendering jinja template. Help for correct code taken from google python tutorial: 
        # https://cloud.google.com/appengine/docs/python/gettingstartedpython27/templates
        template = JINJA_ENVIRONMENT.get_template('index.html')
        self.response.write(template.render(temp_vals))


application = webapp2.WSGIApplication([
    ('/', MainPage),
], debug=True)
