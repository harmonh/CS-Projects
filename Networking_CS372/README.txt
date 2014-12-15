Holly Harmon
harmonh@onid.oregonstate.edu
CS372
Project 1 - Readme

chatserve.java:
Compile/run this program before chatclient.

To compile on the access.engr.orst.edu server enter the following:
	javac chatserve.java

To execute you need to enter the port number you would like to listen on:
	java chatserve <port number>

The program will wait until is receives a connection request from chatclient.py. Once
a connection is established, the user on the client side will have the chance to message first. The user on the server side must wait until prompted by the handle "HostA>" before sending a message. To close the connection to the client type "\quit" as your message. The server will not exit, but instead continue to wait for a new connection request.


chatclient.py:
Make sure chatserve.java is up and running and ready to accept client connections.

To connect to the server you will need to know it's hostname and the port number it is
listening on.
To compile/execute on the access.engr.orst.edu server enter the following:
	python chatclient.py <hostname> <port number>

After a connection is formed the program will prompt you to enter a user handle. It
must be 10 characters or less and contain no spaces. The client side user gets to send
the first message to the server and then waits for a response. To close the connection 
and exit the program type "\quit" as your message.