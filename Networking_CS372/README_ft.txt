Holly Harmon
harmonh@onid.oregonstate.edu
CS372
Project 2 - Readme

ftserver.java:
Compile/run this program before ftclient.

To compile on the access.engr.orst.edu server enter the following:
	javac ftserver.java

To execute you need to enter the port number you would like to listen on:
	java ftserver <port number>

The program will wait until is receives a connection request from ftclient.py. Once
a connection is established, no more input should be required on the server side.


ftclient.py:
Make sure ftserver.java is up and running and ready to accept client connections.

To connect to the server you will need to know it's hostname and the port number it is
listening on.

To compile/execute on the access.engr.orst.edu server enter the following:
	python ftclient.py <SERVER_HOST> <SERVER_PORT> <COMMAND> [<FILENAME>] <DATA_PORT>
The <SERVER_PORT> will be the port the server is listening on and will be set up as a 
control connection. THe <DATA_PORT> is the port you would like the data transfer connection
to be set up on.
The program excepts two command options on the command line:
	-l 	"list" will print a list of the .txt file contents of the server's current directory
	-g 	"get" must be followed by a <FILENAME> to retrieve a file from the server