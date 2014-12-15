/*
**	Name: Holly Harmon
**	email: harmonh@onid.oregonstate.edu
**	Class: CS372
**	Assignment: Project 2
**	Program: ftserver.java
**	This program performs the server side of a file transfer program. It excepts the port
**	number of the port the user would like the server to listen on. When the program receives
**	a connection request from the client side chat program it will open a connection (P) and
**	wait for a message from the user on the client side. The client side will send over a file
**	name and a second port number for a data connection. If the file name is empty, the program
**	knows the client has chosen the "l" command and sends back a list of the files in the current
**	directory. If there is a file name, it knows the client has chosen the "g" command and will send
** 	the appropriate file to the user, unless the file does not exist, in which case it will send an
** 	error message.
**
**	The general program layout was adapted from http://introcs.cs.princeton.edu/java/84network/EchoServer.java
**	and http://docs.oracle.com/javase/tutorial/networking/sockets/readingWriting.html
**
**	The code for retrieving the list of files in a directory is adapted from: http://www.javaprogrammingforums.com/
**	java-programming-tutorials/3-java-program-can-list-all-files-given-directory.html
**
**	The file transfer code (starting at line 134) was written with help from: http://www.rgagnon.com/javadetails/java-0542.html
*/

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class ftserver {
	public static void main(String[] args) throws IOException {
        
		if(args.length != 1) {
			System.err.println("Enter port number on command line");
			System.exit(1);
		}
        
		int serverPort = Integer.parseInt(args[0]);
		String fileName = " ";
		int dataPort = 0;
		int fileExists = 0;
		String path = ".";
		String files;
		String sendFiles = "";
		File folder = new File(path);
		FileInputStream fis = null;
	    BufferedInputStream bis = null;
	    OutputStream os = null;
     
		ServerSocket serverSocket_P = new ServerSocket(serverPort);
		System.out.println("Listening on port " + serverPort);
		
		// repeatedly wait for connections, and process
		while (true) {
			// a "blocking" call which waits until a connection is requested
			Socket clientSocket_P = serverSocket_P.accept();
			System.out.println("Accepted connection from client");

			// open up IO streams
			BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket_P.getInputStream()));
			PrintWriter out = new PrintWriter(clientSocket_P.getOutputStream(), true);

			String sentence = " "; 
			String clientResp;
			String quit = "\\quit";
			//Scanner hosta = new Scanner(System.in); //input from host A user

			clientResp = in.readLine();
			String[] commands = clientResp.split(",");
			fileName = commands[0];
			dataPort = Integer.parseInt(commands[1]);
			//System.out.println(fileName);
			//System.out.println(dataPort);


			if(fileName.equals("NULL")) {
				System.out.println("-l command");
				out.println("Q");
				//System.out.println("Q sent");
				ServerSocket serverSocket_Q = new ServerSocket(dataPort);
				System.out.println("Listening on port " + dataPort);
				//while(true) {
					Socket clientSocket_Q = serverSocket_Q.accept();
					System.out.println("Connection opened on Port " + dataPort);
					PrintWriter outQ = new PrintWriter(clientSocket_Q.getOutputStream(), true);

					File[] listOfFiles = folder.listFiles();

					for(int i = 0; i < listOfFiles.length; i++) {
						if(listOfFiles[i].isFile()) {
							files = listOfFiles[i].getName();
							if(files.endsWith(".txt") || files.endsWith(".TXT")) {
								sendFiles = sendFiles + files + ",";
							}
						}
					}
					//System.out.println(sendFiles);
					outQ.println(sendFiles);

					System.out.println("Closing connection Q");
					outQ.close();
					clientSocket_Q.close();
				//}
			}

			else {
				System.out.println("-g command for file: " + fileName);
				String fileToSend = "";
				File[] listOfFiles = folder.listFiles();
				//PrintWriter outQ = new PrintWriter(clientSocket_Q.getOutputStream(), true);
				for(int i = 0; i < listOfFiles.length; i++) {
					if(listOfFiles[i].isFile()) {
						files = listOfFiles[i].getName();
						if(files.equals(fileName)) {
							//System.out.println("file exists");
							fileToSend = listOfFiles[i].getPath();
							//System.out.println(fileToSend);
							fileExists = 1;
						}
					}
				}

				if(fileExists == 0) {
					out.println("E");
				}

				else {
					out.println("Q");
					ServerSocket serverSocket_Q = new ServerSocket(dataPort);
					System.out.println("Listening on port " + dataPort);
					Socket clientSocket_Q = serverSocket_Q.accept();
					System.out.println("Connection opened on Port " + dataPort);
					
					File myFile = new File (fileToSend);
					byte [] mybytearray = new byte [(int)myFile.length()];
					//System.out.println("byte: " + mybytearray.length);
					fis = new FileInputStream(myFile);
					bis = new BufferedInputStream(fis);
					bis.read(mybytearray, 0, mybytearray.length);
					os = clientSocket_Q.getOutputStream();
					os.write(mybytearray, 0, mybytearray.length);
					os.flush();

				/*	//small txt files:
					if(mybytearray.length < 4096) {
						bis.read(mybytearray, 0, mybytearray.length);
						os = clientSocket_Q.getOutputStream();
						os.write(mybytearray, 0, mybytearray.length);
						os.flush();
					}
					//large txt files:
					else {
						int parts = mybytearray.length/2048;
						int offset = 0;
						for(int i = 0; i < parts;  i++) {
							bis.read(mybytearray, offset, 2048);
							os = clientSocket_Q.getOutputStream();
							os.write(mybytearray, offset, 2048);
							offset = offset + 2048;
						}
						int remainder = mybytearray.length % 2048;
						bis.read(mybytearray, offset, remainder);
						os = clientSocket_Q.getOutputStream();
						os.write(mybytearray, offset, remainder);
							
						os.flush();
					} */

					clientSocket_Q.close();
					bis.close();
					os.close();
				}
			}

			// close IO streams, then socket
			System.out.println("Closing connection with client");
			
			out.close();
			in.close();
			clientSocket_P.close();
		}
	}
}