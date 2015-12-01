import webapp2

application = webapp2.WSGIApplication([
    ('/', 'dynamic.MainPage'),
    ('/edit', 'edit.EditEntry'),
    ('/edit_display', 'edit_display.DisEntry')
], debug=True)
