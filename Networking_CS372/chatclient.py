##	Name: Holly Harmon
##	email: harmonh@onid.oregonstate.edu
##	Class: CS372
##	Assignment: Project 1
#	Program: chatclient.py
#	This program performs the client side of a chat program. It excepts the hostname and port
#	number of the server it would like to connect with on the command line when running
#	the program. Once a connection is established with the chat server, the user can send
#	a message to the server, then waits for a response. It will continue to send and wait
#	until the client user or server user enters the command "\quit".
#
#	Client socket code was mostly adapted from the TCPClient.py program code on pg 164 in the
#	book "Computer Networking" (Kurose, James F., and Keith W. Ross. Computer Networking: 
#		A Top-down Approach. 6th ed. Boston: Pearson, 2013.)

import sys
from socket import *

if(len(sys.argv) < 3):
	print "Use Command: python chatclient.py <hostname> <port_number>"
	sys.exit()

serverName = sys.argv[1]
serverPort = int(sys.argv[2])
sentence = " "
quit = "\quit"
#print serverName
#print serverPort
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

#assign user handle (10 chars or less, no spaces)
handle = raw_input("Enter your user handle (one word, no spaces): ")
while(len(handle) > 10):
	handle = raw_input("Must be 10 characters or less: ")
if " " in handle:
	handle = raw_input("No spaces in name: ")	
handle = handle + "> "

while(1):
	sentence = raw_input(handle)
	#client calls \quit
	if(sentence == quit):
		clientSocket.send("\quit\n")	
		sys.exit()		
	sentence = handle + sentence + "\n"
	clientSocket.send(sentence)
	serverResp = clientSocket.recv(1024)
	#server calls \quit
	if quit in serverResp:
		sys.exit()
	print serverResp

clientSocket.close()