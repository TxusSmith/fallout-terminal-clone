# fallout-terminal-clone
What is fallout-terminal-clone?

	fallout-terminal-clone is a recreation of the "terminal hacking" system
	in Fallout 3 and Fallout: New Vegas developed with curses. It runs directly
	in your terminal or command prompt. I made this as a fun and interesting
	way to explore C.

Instructions

	Use the arrow keys (by default) to move, and ENTER to choose your selected letter. Ctrl-C to quit.

Building

	WINDOWS

		Requirements:
		MinGW installed with the following packages:
			- mingw32-gcc
			- mingw32-pdcurses (dev and dll)

		Once the above dependencies are satisfied, simply open
		a command prompt in the source directory and run:
			make

		If you get an error about gcc not being found, you most
		likely didn't add MinGW tools to your path. Either do
		that, or change the line:
	CC = gcc
		to read:
	CC = C:\MinGW\bin\gcc
		(assuming you installed MinGW in that location)

	LINUX

		Requirements:
			- gcc
			- ncurses

		Once the above dependencies are satisfied, simply open
		a terminal in the source directory and run:
			make

	OSX

		Requirements:
			Xcode Tools (just run xcode-select --install)

		Once this is finished, simply open
		a terminal in the source directory and run:
			make


TODO list:

	Decent looking screen centering
	Add a typing animation for the guesses
	Possible mouse support?


Bugs:

	Fallout 3 and New Vegas don't seem to play well with the launching.

	The OSX binary may segfault with error 11. This hasn't happened with the
	couple macs I've tested it on, but my friend's mac does it constantly. It
	may have something to do with having development xcode tools installed.

Thanks to:

	/u/aftli_work for suggesting macros before I knew what they were


I do not own the idea for this game, nor do I claim any ownership of any game
of the Fallout series. Those copyrights are the property of Bethesda Softworks.
