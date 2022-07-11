# Minimal-Browser2
Next version of Minimal Browser C++

<b> Current version is 2.5 Beta. Notice that this version might contain bugs.</b>

Copyright (c) 2020 JJ Posti <techtimejourney.net>

This is free software, and you are welcome to redistribute it under GPL Version 3 or Apache v2 license.


<b>Licensing Dual licensing model:</b> 

GPL v2 is upgraded to GPL v3.
Also adding Apache v2 license as an alternative possibility if GPL v3 is not desired.


![browser](https://user-images.githubusercontent.com/29865797/178351588-e53b7b0d-bd46-4806-95d0-a1f9527658a5.jpg)

Features added by v2.5 beta

- DuckDuckGo as search engine.
- Tabbed browsing.
- UI is redesigned.
- Icons removed.
- Navigation improvements:
	<b>Navigation example, URLs should be written like this:</b>
		
		techtimejourney.net

		OR
		
		www.yle.fi
		
Do not add http or https in front - things will fail.	


#### Link handling 

If a link does not open automatically, right-click the link and choose the Open Link option.

If you wish to copy a specific link, right-click on it and choose Copy Link option.


Save Link and Open in New Window options from the right-click menu are not integrated yet.


		
####  Downloading files


Minimal browser does not yet support downloading files by directly clicking on them.

To download a file, use <b>Copy Link option</b> from the right-click menu. Next, copy link to the addressbar and press the Download button.


####  Known issues

<b> Coming from QT bugs: sites like Youtube & Google have issues loading.</b>


Features added by v2.

Old version is available at: https://github.com/postman721/Minimal_Browser

###### OLD GUI looked like this

![minimal2](https://user-images.githubusercontent.com/29865797/72383214-aa5fa780-3723-11ea-8124-98cd12362701.jpg)

 - Google as a search engine.
 - Zoom in and out buttons added.
 - Web-inspector added.
 - Browsing now accepts: www.some_address.something OR https://some_address.something 
 - Save file or object: Saves whatever is listed on addressbar location. Using Wget via QProcess.
 - Tooltips for buttons.
 - Gui is redesigned and has darker colors now.
 
 - Javascript set to enabled.
 - Installed system plugins set to enabled.
 - PrivateBrowsingEnabled,true.
 - SpatialNavigationEnabled,true.
 - Accelerated2dCanvasEnabled,true.
 - AcceleratedCompositingEnabled.
 - AutoLoadImages,true.
 - ScrollAnimatorEnabled,true.
 - DeveloperExtrasEnabled,true.
 - FullScreenSupportEnabled,true.
 - WebGLEnabled,true.
 - JavascriptCanOpenWindows,true.
 - LocalContentCanAccessRemoteUrls, true.


Features - since v1.

- Go back. 
- Go forward.
- Stop loading.
- Print page.
- Reload page.
- Go Home (This points to current AWS hosted Postx Gnu/Linux landing page).
- Does not support http. Https only.
- Statusbar giving generic messages about page loading states.
<b>Opening links and copying links:</b>



<b>Dependencies:</b> 


QT5, QWebview and its friends. Names vary upon distributions. See header file of this project for possible hints on what to install.

I installed something like this: sudo apt-get install libqt5webkit5-dev libqt5webview5 qtcreator
 

