// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
(function () {
    "use strict";

    WinJS.UI.Pages.define("/pages/addnew/addnew.html", {
        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            // TODO: Initialize the page here.
            
            // getting user ID
            filesReadTemporaryCounter();

            // Retrieve the button and register your event handler. 
            var addButton2 = document.getElementById("addButton2");
            addButton2.addEventListener("click", this.buttonClickHandler, false);

        },

        buttonClickHandler: function (eventInfo) {
            var inputError = 0;
            var bikeType = "Road";
            var statBike = document.getElementById("sbike").checked;
            var roadBike = document.getElementById("rbike").checked;
            if (statBike === true) {
                bikeType = "Stationary";
            }
            var month = document.getElementById("monthValue").value;
            var day = document.getElementById("dayValue").value;
            var year = document.getElementById("yearValue").value;
            var date = month + "/" + day + "/" + year;
            var time = document.getElementById("time").value;
            if (isNaN(time)) {
                document.getElementById("timeDiv").innerText = "Time must be a number";
                inputError = 1;
            }
            var distance = document.getElementById("distance").value;
            if (isNaN(distance)) {
                document.getElementById("distDiv").innerText = "Distance must be a number";
                inputError = 1;
            }
            var kilos = document.getElementById("kilos").checked;
            var level = document.getElementById("level").value;

            var payload = 'user=' + tempID + '&date=' + date + '&bike_type=' + bikeType + '&distance='
                + distance + '&kilos=' + kilos + '&time=' + time + '&level=' + level;
            if (inputError === 0) {
                var addC = new Windows.Web.Http.HttpClient();
                var adduri = new Windows.Foundation.Uri("http://api-holly.appspot.com/bike");
                addC.postAsync(adduri, Windows.Web.Http.HttpStringContent(payload, Windows.Storage.Streams.UnicodeEncoding.utf8, "application/x-www-form-urlencoded")).done(function (result) {
                    //var jsonResult = JSON.parse(result.content.toString());
                    //console.log(result.statusCode);
                    //console.log(result.content);
                    WinJS.Navigation.navigate('/pages/auth/auth.html');
                }, onError);

                function onError(reason) {
                    // get call failed
                    console.log("HTTP Client Error");
                }
            }
        },

    });

    var temporaryFolder = Windows.Storage.ApplicationData.current.temporaryFolder;
    var filename = "sampleFile.txt";
    var tempID = 0;

    function filesReadTemporaryCounter() {
        temporaryFolder.getFileAsync(filename)
            .then(function (file) {
                return Windows.Storage.FileIO.readTextAsync(file);
            }).done(function (text) {
                tempID = text;
                //console.log("temp:" + tempID);
            }, function () {
                // getFileAsync or readTextAsync failed.
                //document.getElementById("output").innerText = "Temporary Counter: <not found>";
            });
    }
})();
