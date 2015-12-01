// Name: Holly Harmon
// OSUID: 932456676
// Class: CS496
// pickSinglePhoto() function written with help from: https://msdn.microsoft.com/en-us/library/windows/apps/xaml/windows.storage.pickers.fileopenpicker.aspx

(function () {
    "use strict";

    WinJS.UI.Pages.define("/pages/auth/auth.html", {
        // This function is called whenever a user navigates to this page. It
        // populates the page elements with the app's data.
        ready: function (element, options) {
            // TODO: Initialize the page here.

            //set icon
            var picturesLibrary = Windows.Storage.KnownFolders.cameraRoll;

            //  Get folder contents
            picturesLibrary.getItemsAsync().then(function (items) {
                var i = 0;
                var match;
                // For example, display info for each item
                items.forEach(function (item) {
                    if (!item.isOfType(Windows.Storage.StorageItemTypes.folder)) {
                        if (item.name === _globIcon) {
                            // user's icon is in pituresLibrary
                            match = i;
                        }
                    }
                    i++;
                });
                console.log(match);
                if (match >= 0) {
                    var imageBlob = URL.createObjectURL(items[match]);
                    document.getElementById("imageControl").src = imageBlob;
                }
                else {
                    // user does not have icon, set default image
                    document.getElementById("imageControl").src = "/images/Icon-user.png";
                }
            });

            // event handlers
            var viewButton = document.getElementById("viewButton");
            viewButton.addEventListener("click", this.viewButtonClickHandler, false);

            var addButton = document.getElementById("addButton");
            addButton.addEventListener("click", this.addButtonClickHandler, false);

            var photoPick = document.getElementById("photoButton");
            photoPick.addEventListener("click", this.pickSinglePhoto, false);

            var logOutButton = document.getElementById("logOutButton");
            logOutButton.addEventListener("click", this.logButtonClickHandler, false);

        },

        viewButtonClickHandler: function (eventInfo) {
            //Navigates to page associated with button
            WinJS.Navigation.navigate('/pages/view/view.html');
        },

        addButtonClickHandler: function (eventInfo) {
            //Navigates to page associated with button
            WinJS.Navigation.navigate('/pages/addnew/addnew.html');
        },

        pickSinglePhoto: function (eventInfo) {
            // allows user to pick photo from library or take new photo with camera
            var openPicker = new Windows.Storage.Pickers.FileOpenPicker();
            openPicker.viewMode = Windows.Storage.Pickers.PickerViewMode.thumbnail;
            openPicker.suggestedStartLocation = Windows.Storage.KnownFolders.picturesLibrary;
            openPicker.fileTypeFilter.replaceAll([".png", ".jpg", ".jpeg"]);
            openPicker.pickSingleFileAndContinue();
        },

        logButtonClickHandler: function (eventInfo) {
            filesTemporaryIncrement(0);
            _globUserId = 0;
            WinJS.Navigation.navigate('/pages/home/home.html');
        },

    });

    // user id storage
    var temporaryFolder = Windows.Storage.ApplicationData.current.temporaryFolder;
    var filename = "sampleFile.txt";
    var temporaryCounter = 0;
    // user icon sotrage
    var localFolder = Windows.Storage.ApplicationData.current.localFolder;
    var picLibrary = Windows.Storage.KnownFolders.picturesLibrary;
    
    // stores user id
    function filesTemporaryIncrement(userId) {
        var temporaryCounter = userId;

        temporaryFolder.createFileAsync(filename, Windows.Storage.CreationCollisionOption.replaceExisting)
            .then(function (file) {
                return Windows.Storage.FileIO.writeTextAsync(file, temporaryCounter);
            }).done(function () {
                //filesReadTemporaryCounter();
            });
    }


})();
