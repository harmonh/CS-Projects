// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
// For an introduction to the Page Control template, see the following documentation:
// http://go.microsoft.com/fwlink/?LinkId=232511
(function () {
    "use strict";
    WinJS.Utilities.query("a").listen("click", linkClickEventHandler, false);

    WinJS.UI.Pages.define("/pages/view/view.html", {
        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            // TODO: Initialize the page here.
            // Retrieves bike entries linked to user:
            //filesReadTemporaryCounter();
            var homeButton = document.getElementById("homeButton");
            homeButton.addEventListener("click", this.homeButtonClickHandler, false);

            var temporaryFolder = Windows.Storage.ApplicationData.current.temporaryFolder;
            var filename = "sampleFile.txt";
            var tempID = 0;
            temporaryFolder.getFileAsync(filename)
                .then(function (file) {
                    return Windows.Storage.FileIO.readTextAsync(file);
                }).done(function (text) {
                    tempID = text;
                    _globUserId = tempID;
                    var bikes = new Array();
                    var uri = new Windows.Foundation.Uri("http://api-holly.appspot.com/user/" + tempID);
                    var c = new Windows.Web.Http.HttpClient();
                    c.getAsync(uri).done(function (result) {
                        var jsonResult = JSON.parse(result.content);
                        var bikes = jsonResult.bikes;
                        var table = document.getElementById("viewTable");
                        // Fills table with bikes
                        var n = 1;
                        for (var i = 0; i < bikes.length; i++) {
                            var bikeUri = new Windows.Foundation.Uri("http://api-holly.appspot.com/bike/" + bikes[i]);
                            var bikeC = new Windows.Web.Http.HttpClient();
                            bikeC.getAsync(bikeUri).done(function (result) {
                                // info for each bike entry
                                var jsonResult = JSON.parse(result.content);
                                var distance;
                                if (jsonResult.kilos === false) {
                                    distance = jsonResult.distance + ' mi';
                                }
                                else {
                                    distance = jsonResult.distance + ' ki';
                                }
                                var row = table.insertRow(n);
                                row.innerHTML = '<td style="width:60px; text-align:center">' + jsonResult.date + '</td><td style="text-align:center; width:60px">'
                                    + jsonResult.time + '</td><td style="width:60px; text-align:center">'
                                    + distance + '</td><td style="width:60px; text-align:center">'
                                    + jsonResult.level + '</td><td style="width:60px; text-align:center">'
                                    + jsonResult.bike_type + '</td><td><a href="/pages/edit/edit.html" id="' + jsonResult.key + '">edit</a></td>';
                                WinJS.Utilities.query("a").listen("click", linkClickEventHandler, false);
                                n++;
                            }, onError);

                            function onError(reason) {
                                // get call failed
                                console.log("HTTP Client Error");
                            }
                        }

                    }, onError);

                    function onError(reason) {
                        // get call failed
                        console.log("HTTP Client Error");
                    }
                }, function () {
                    // getFileAsync or readTextAsync failed.
                    //document.getElementById("output").innerText = "Temporary Counter: <not found>";
                });

            
        },

        homeButtonClickHandler: function (eventInfo) {
            WinJS.Navigation.navigate("/pages/auth/auth.html");
        },

        unload: function () {
            // TODO: Respond to navigations away from this page.
            //console.log("away");
        },
        
        
        updateLayout: function (element) {
            /// <param name="element" domElement="true" />
            //console.log("update");
            
            // TODO: Respond to changes in layout.
        }
    });

    

    function linkClickEventHandler(eventInfo) {
        eventInfo.preventDefault();
        var link = eventInfo.target;
        //console.log(link.id);
        _globBikeId = link.id;
        WinJS.Navigation.navigate(link.href);
    }

    
})();
