// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
// For an introduction to the Page Control template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkId=232511
(function () {
    "use strict";

    WinJS.UI.Pages.define("/pages/edit/edit.html", {
        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            // TODO: Initialize the page here
            
            var deleteButton = document.getElementById("deleteButton");
            deleteButton.addEventListener("click", this.deleteButtonClickHandler, false);

            // Getting bike entry data to prepopualate the HTML form fields
            var bikeUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/bike/" + _globBikeId);
            var bikeC = new Windows.Web.Http.HttpClient();
            bikeC.getAsync(bikeUri).done(function (result) {
                // info for each bike entry
                var jsonResult = JSON.parse(result.content);
                if (jsonResult.bike_type === "Stationary") {
                    document.getElementById("sbike").checked = "checked";
                }
                document.getElementById("time").value = jsonResult.time;
                document.getElementById("distance").value = jsonResult.distance;
                if (jsonResult.kilos === true) {
                    document.getElementById("kilos").checked = "checked";
                }
                var date = jsonResult.date.split("/");
                var month = parseInt(date[0]) - 1;
                var day = parseInt(date[1]) - 1;
                var year = date[2];
                document.getElementById('monthValue').getElementsByTagName('option')[month].selected = 'selected';
                document.getElementById('dayValue').getElementsByTagName('option')[day].selected = 'selected';
                var yearSel = document.getElementById("yearValue");
                var yearOpts = yearSel.options;
                for (var opt, j = 0; opt = yearOpts[j]; j++) {
                    if (opt.value == year) {
                        yearSel.selectedIndex = j;
                        break;
                    }
                }
                var level = parseInt(jsonResult.level);
                document.getElementById('level').getElementsByTagName('option')[level].selected = 'selected';
            }, onError);

            function onError(reason) {
                // get call failed
                console.log("HTTP Client Error");
            }

            var updateButton = document.getElementById("updateButton");
            updateButton.addEventListener("click", this.updateButtonClickHandler, false);
        },

        updateButtonClickHandler: function (eventInfo) {
            var inputError = 0;
            var bikeType = "Road";
            var statBike = document.getElementById("sbike").checked;
            var roadBike = document.getElementById("rbike").checked;
            if (statBike === true) {
                bikeType = "Stationary";
            }
            var newMonth = document.getElementById("monthValue").value;
            var newDay = document.getElementById("dayValue").value;
            var newYear = document.getElementById("yearValue").value;
            var newDate = newMonth + "/" + newDay + "/" + newYear;
            var newTime = document.getElementById("time").value;
            if (isNaN(newTime)) {
                document.getElementById("timeDiv").innerText = "Time must be a number";
                inputError = 1;
            }
            var newDistance = document.getElementById("distance").value;
            if (isNaN(newDistance)) {
                document.getElementById("distDiv").innerText = "Distance must be a number";
                inputError = 1;
            }
            var newKilos = document.getElementById("kilos").checked;
            var newLevel = document.getElementById("level").value;
            var payload = 'date=' + newDate + '&bike_type=' + bikeType + '&distance='
                + newDistance + '&kilos=' + newKilos + '&time=' + newTime + '&level=' + newLevel;
            if (inputError == 0) {
                var upUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/user/" + _globUserId + "/bike/" + _globBikeId);
                var upC = new Windows.Web.Http.HttpClient();
                upC.putAsync(upUri, Windows.Web.Http.HttpStringContent(payload, Windows.Storage.Streams.UnicodeEncoding.utf8, "application/x-www-form-urlencoded")).done(function (result) {
                    // info for each bike entry
                    //var jsonResult = JSON.parse(result.content);
                    //console.log(result)
                }, onError);

                function onError(reason) {
                    // get call failed
                    console.log("HTTP Client Error");
                }

                WinJS.Navigation.navigate('/pages/auth/auth.html');
            }
        },

        deleteButtonClickHandler: function (eventInfo) {
            var delUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/user/" + _globUserId + "/bike/" + _globBikeId);
            console.log(delUri);
            var delC = new Windows.Web.Http.HttpClient();
            delC.deleteAsync(delUri).done(function (result) {
                //var jsonResult = JSON.parse(result.content);
                //console.log(result);
            }, onError);

            function onError(reason) {
                // get call failed
                console.log("HTTP Client Error");
            }
            WinJS.Navigation.navigate('/pages/auth/auth.html');
        },

        unload: function () {
            // TODO: Respond to navigations away from this page.
        },

        updateLayout: function (element) {
            // TODO: Respond to changes in layout.
        }
    });
})();
