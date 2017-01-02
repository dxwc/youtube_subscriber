
# Youtube Subscriber
Downloads feed from youtube channels and locally generates a simple html/css page to embed/display thumbnail/video link. As is should only work on linux due to the use of `strptime` on ![youtube_parser.cpp](./functions/youtube_parser.cpp).

<a href="#youtube-subscriber"><img src="./images/img_1.png" align="middle" width="40%" alt="GUI demo" /></a>

# Setup
* Make sure you have:
	* Qt installed, ex: `sudo apt install libqt4-dev`
	* libCurl installed, ex: `sudo apt install libcurl4-gnutls-dev`

* Clone and `cd` into this folder and execute these commands in terminal:
	* `qmake ytube_gui.pro`
	* `make`

Note: ignore the compiler warnings, they will not cause any failures.

# Run
* Either
	* go into the directory in terminal and `./ytube` or,
	* go into the directory and double click the executable

# Use
Hopefully is obvious.

# About
As is. Made for learning and personal use.
