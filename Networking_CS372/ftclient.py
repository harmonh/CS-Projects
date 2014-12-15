##	Name: Holly Harmon
##	email: harmonh@onid.oregonstate.edu
##	Class: CS372
##	Assignment: Project 2
#	Program: ftclient.py
#	This program performs the client side of a file transfer program. It excepts the hostname and port
#	number of the server it would like to connect with on the command line along with a command (-l for
#	"list" and -g <FILENAME> for "get") and a port number for the data connection. The list command
#	will retrieve the list of files in the server's directory and print them to the screen. The get
#	command will retrieve the file requested on the command line. My program transfers small text
#	files just fine, but I was not able to successfully implement a program that could transfer very
#	large text files.
#
#	Client socket code was mostly adapted from the TCPClient.py program code on pg 164 in the
#	book "Computer Networking" (Kurose, James F., and Keith W. Ross. Computer Networking: 
#		A Top-down Approach. 6th ed. Boston: Pearson, 2013.)



import sys
import os
from socket import *

if len(sys.argv) < 5:
	print "Use: python ftclient.py <SERVER_HOST> <SERVER_PORT> <COMMAND> <FILENAME> <DATA_PORT>"
	sys.exit()

if sys.argv[3] == "-g":
	if(len(sys.argv) < 6):
		print "Missing a command element: if using -g command include a <FILENAME>"
		sys.exit()

if sys.argv[3] != "-l" and sys.argv[3] != "-g":
	print "Invalid command: Use -l for list or -g <FILENAME> for get"
	sys.exit()

fileName = "NULL"
serverHost = sys.argv[1]
serverPort = int(sys.argv[2])
command = sys.argv[3]

if command == "-g":
	fileName = sys.argv[4]
	dataPort = sys.argv[5]
	dataPort_i = int(sys.argv[5])
else:
	dataPort = sys.argv[4]
	dataPort_i = int(sys.argv[4])



serverSend = fileName + "," + dataPort + "\n"

#print "Host: " + serverHost
#print "SPort: ",serverPort,
#print "Comm: " + command
#print "File: " + fileName
#print "DPort: ",dataPort,
#sentence = " "
#quit = "\quit"

clientSocket_P = socket(AF_INET, SOCK_STREAM)
clientSocket_P.connect((serverHost,serverPort))
clientSocket_P.send(serverSend)

if command == "-l":
	#while(1):
		serverResp = clientSocket_P.recv(1024)
		#server calls \quit
	
		if "Q" in serverResp:
			#print "Q is ready"
			clientSocket_Q = socket(AF_INET, SOCK_STREAM)
			clientSocket_Q.connect((serverHost,dataPort_i))
			files = clientSocket_Q.recv(1024)
			printFiles = files.split(',')
			printFiles.remove("\n")
			print '\n'.join(printFiles)

elif command == "-g":
	#while(1):
		serverResp = clientSocket_P.recv(1024)
		if "E" in serverResp:
			print "Error: File not in directory"
			sys.exit()

		dirs = os.listdir(".")
		if fileName in dirs:
			print "Duplicate File: File already exists in directory"
			sys.exit()
		newFile = open(fileName, "ab")
		
		#serverResp = clientSocket_P.recv(1024)
		#server calls \quit
	
		if "Q" in serverResp:
			#print "Q is ready"
			clientSocket_Q = socket(AF_INET, SOCK_STREAM)
			clientSocket_Q.connect((serverHost,dataPort_i))
			
			#while True:
			sentence = clientSocket_Q.recv(4096)
			newFile.write(sentence)
		
		print "Transfer Complete"
		newFile.close()
	
#print "Closing sockets"
clientSocket_Q.close()
clientSocket_P.close()