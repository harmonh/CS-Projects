// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
// For an introduction to the Navigation template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkID=329110

var _globBikeId;
var _globUserId;
var _globIcon;

(function () {
    "use strict";
    

    var activation = Windows.ApplicationModel.Activation;
    var app = WinJS.Application;
    var nav = WinJS.Navigation;
    var sched = WinJS.Utilities.Scheduler;
    var ui = WinJS.UI;

    app.addEventListener("activated", function (args) {
        if (args.detail.kind === activation.ActivationKind.launch) {
            if (args.detail.previousExecutionState !== activation.ApplicationExecutionState.terminated) {
                // TODO: This application has been newly launched. Initialize
                // your application here.
            } else {
                // TODO: This application has been reactivated from suspension.
                // Restore application state here.
                
            }

            
            // Save previous execution state
            WinJS.Application.sessionState.previousExecutionState = args.detail.previousExecutionState;

            nav.history = app.sessionState.history || {};
            nav.history.current.initialPlaceholder = true;

            // Optimize the load of the application and while the splash screen is shown, execute high priority scheduled work.
            ui.disableAnimations();
            var p = ui.processAll().then(function () {
                return nav.navigate(nav.location || Application.navigator.home, nav.state);
            }).then(function () {
                return sched.requestDrain(sched.Priority.aboveNormal + 1);
            }).then(function () {
                ui.enableAnimations();
            });

            args.setPromise(p);
        }


        else if (args.detail.kind == activation.ActivationKind.pickFileContinuation) {
            // Inputs user chosen photo to auth.html as user icon
            var listToken;
            var file = args.detail.detail[0].files[0];            
            filesSetIcon(file.name);
            _globIcon = file.name;
            var imageBlob = URL.createObjectURL(file);
            document.getElementById("imageControl").src = imageBlob;
            //loadImage(file);
        }
    });


    function filesSetIcon(iconName) {
        // adds icon name to user data for future reference
        var iconUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/user/" + _globUserId);
        var iconC = new Windows.Web.Http.HttpClient();

        // "age" was not being used by me, so I adjusted it to store the photo name, but didn't go through the API and change the property name
        var payload = "age=" + iconName;
        iconC.putAsync(iconUri, Windows.Web.Http.HttpStringContent(payload, Windows.Storage.Streams.UnicodeEncoding.utf8, "application/x-www-form-urlencoded")).done(function (result) {
            // info for each bike entry
            //var jsonResult = JSON.parse(result.content);
            //console.log(result);
        }, onError);

        function onError(reason) {
            // get call failed
            console.log("HTTP Client Error");
        }

    }

    app.oncheckpoint = function (args) {
        // TODO: This application is about to be suspended. Save any state
        // that needs to persist across suspensions here. If you need to 
        // complete an asynchronous operation before your application is 
        // suspended, call args.setPromise().
        app.sessionState.history = nav.history;
    };

    app.start();
})();
