# Youtube Subscriber
Downloads feed from youtube channels and locally generates a simple html/css page to embed/display thumbnail/video link. As is should only work on linux due to the use of `strptime` on ![youtube_parser.cpp](./youtube_parser.cpp).

# Setup
1. Clone / download this repo
2. Install libCURL development libraries, in Ubuntu: `sudo apt install libcurl4-gnutls-dev`
3. Go into downloaded directory in a terminal and run: `make`
4. If everything compiled and produced no error, run: `make foruse`
5. If no error, setup is complete. Now, can run the program as such: `./run`

# Use
* See output after running `./run` without any option to see how to run
* Note: full URL (ie. one that you see on your browser) of any youtube video or channel is to be used for the subscription option

# How I use it
I have aliases in my `~/.bashrc`
```
# shortcut to subscription
alias ysub='cd your-download-location/; ./run -sub "$@"'

# if using firefox browser
alias yview='cd your-download-location/; ./run -gen -view'
```


# About
As is. Made for learning and personal use.
