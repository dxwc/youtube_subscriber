CXXFLAGS = $(shell curl-config --cflags)
LDLIBS   = $(shell curl-config --libs)
CXX      = g++ -std=c++11 -O2
OBJS     = main.o yt_functions.o youtube_parser.o downloader.o

run : $(OBJS)
	g++ -o run $(OBJS) $(LDLIBS)

main.o : yt_functions.h
yt_functions.o : yt_functions.h youtube_parser.h downloader.h
youtube_parser.o : youtube_parser.h
downloader.o : downloader.h

.PHONY : foruse

foruse:
	rm $(OBJS)
	mkdir -p code
	mv -i *.cpp *.h Makefile README.md code/
	mv -i .git/ code/
	@echo "Done!"

.PHONY : clean

clean:
	rm run $(OBJS)

# Additional requirement other than C++ and Linux: 
# LibCURL
#     - installation instruction on Ubuntu and simialr OS:
#     - sudo apt install libcurl4-gnutls-dev
#
# Tested on Ubuntu 16.04, libcurl version: 7.47.0
