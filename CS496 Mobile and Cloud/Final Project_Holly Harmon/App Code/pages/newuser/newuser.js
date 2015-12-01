// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
// For an introduction to the Page Control template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkId=232511
(function () {
    "use strict";

    WinJS.UI.Pages.define("/pages/newuser/newuser.html", {
        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            // TODO: Initialize the page here.
            var newUserButton = document.getElementById("newUserButton");
            newUserButton.addEventListener("click", this.newButtonClickHandler, false);
            
        },

        newButtonClickHandler: function (eventInfo) {
            var inputError = 0;
            var name = document.getElementById("name").value;
            var payload = 'age=default&name=';
            if (name) {
                payload = payload + name;
                var password = document.getElementById("password").value;
                if (password) {
                    payload = payload + '&pass=' + password;
                }
                else {
                    document.getElementById("nameDiv").innerText = "Must enter password";
                    inputError = 1;
                }
            }
            else {
                document.getElementById("nameDiv").innerText = "Must enter username";
                inputError = 1;
            }

            if (inputError === 0) {
                var userC = new Windows.Web.Http.HttpClient();
                var userUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/user");
                userC.postAsync(userUri, Windows.Web.Http.HttpStringContent(payload, Windows.Storage.Streams.UnicodeEncoding.utf8, "application/x-www-form-urlencoded")).done(function (result) {
                    //var jsonResult = JSON.parse(result.content.toString());
                    //console.log(result.statusCode);
                    //console.log(result.content);
                    WinJS.Navigation.navigate('/pages/newuser/newlog.html');
                }, onError);

                function onError(reason) {
                    // get call failed
                    console.log("HTTP Client Error");
                }
            }
        },

        unload: function () {
            // TODO: Respond to navigations away from this page.
        },

        updateLayout: function (element) {
            /// <param name="element" domElement="true" />

            // TODO: Respond to changes in layout.
        }
    });

    WinJS.UI.Pages.define("/pages/newuser/newlog.html", {
        ready: function (element, options) {
            // TODO: Initialize the page here.
            var loginButton = document.getElementById("login");
            loginButton.addEventListener("click", this.loginClickHandler, false);

        },

        loginClickHandler: function (eventInfo) {
            WinJS.Navigation.navigate('/pages/home/home.html');
        }

    });
})();
