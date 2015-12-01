// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
// Citations:
//      filesTemporaryIncrement() and fileReadTemporaryCounter() are copied or adapted from:
//      Title: Application data sample
//      Date: 4/2/2014
//      Availability: https://code.msdn.microsoft.com/windowsapps/ApplicationData-sample-fb043eb2#content

// For an introduction to the Page Control template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkId=232511
(function () {
    "use strict";

    WinJS.UI.Pages.define("/pages/home/home.html", {
        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            // checks to see if a user is already/still logged in
            filesReadTemporaryCounter();

            var logButton = document.getElementById("logButton");
            logButton.addEventListener("click", this.logInbuttonClickHandler, false);

            var newButton = document.getElementById("newButton");
            newButton.addEventListener("click", this.newUserButtonClickHandler, false);
            
        },

        logInbuttonClickHandler: function (eventInfo) {
            // authenticating user
            var user_name = document.getElementById("user").value;
            var pass = document.getElementById("password").value;
            var payload = 'name=' + user_name + '&pass=' + pass;
            var logC = new Windows.Web.Http.HttpClient();
            var loguri = new Windows.Foundation.Uri("http://api-holly.appspot.com/auth");
            logC.postAsync(loguri, Windows.Web.Http.HttpStringContent(payload, Windows.Storage.Streams.UnicodeEncoding.utf8, "application/x-www-form-urlencoded")).done(function (result) {
                if (result.statusCode == 200) {
                    var jsonResult = JSON.parse(result.content);
                    var key = jsonResult.key;
                    filesTemporaryIncrement(key);
                    _globUserId = key;
                    getIconName();
                }
                else {
                    document.getElementById("no_auth").innerText = 'Username or Password is incorrect';
                }
         
            }, onError);
            
            function onError(reason) {
                //get call failed
                console.log("HTTP Client Error");
            }

        },

        newUserButtonClickHandler: function (eventinfo) {
            WinJS.Navigation.navigate('/pages/newuser/newuser.html');
        },

        unload: function () {
            // TODO: Respond to navigations away from this page.
        },

        updateLayout: function (element) {
            // TODO: Respond to changes in layout.
        }
    });

    var temporaryFolder = Windows.Storage.ApplicationData.current.temporaryFolder;
    var filename = "sampleFile.txt";
    var temporaryCounter = 0;
    
    // Storing user ID to temp storage to keep user logged in
    function filesTemporaryIncrement(userId) {
        var temporaryCounter = userId;

        temporaryFolder.createFileAsync(filename, Windows.Storage.CreationCollisionOption.replaceExisting)
            .then(function (file) {
                return Windows.Storage.FileIO.writeTextAsync(file, temporaryCounter);
            }).done(function () {
                //filesReadTemporaryCounter();
            });
    }

    function filesReadTemporaryCounter() {
        temporaryFolder.getFileAsync(filename)
            .then(function (file) {
                return Windows.Storage.FileIO.readTextAsync(file);
            }).done(function (text) {
                temporaryCounter = text;
                if (temporaryCounter != 0) {
                    _globUserId = temporaryCounter;
                    console.log("id set");
                    getIconName();                   
                }
            }, function () {
                // getFileAsync or readTextAsync failed.
                //document.getElementById("filesTemporaryOutput").innerText = "Temporary Counter: <not found>";
            });
    }

    // getting name of icon photo from user data
    function getIconName() {
        console.log("get call");
        var userC = new Windows.Web.Http.HttpClient();
        var userUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/user/" + _globUserId);
        userC.getAsync(userUri, Windows.Web.Http.HttpStringContent(Windows.Storage.Streams.UnicodeEncoding.utf8, "application/x-www-form-urlencoded")).done(function (result) {
            var jsonResult = JSON.parse(result.content);
            var icon = jsonResult.age;
            _globIcon = icon;
            console.log("navigating to auth:" + _globIcon);
            WinJS.Navigation.navigate('/pages/auth/auth.html');
        }, onError);

        function onError(reason) {
            //get call failed
            console.log("HTTP Client Error");
        }
    }

})();
