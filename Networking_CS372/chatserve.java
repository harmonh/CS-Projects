/*
**	Name: Holly Harmon
**	email: harmonh@onid.oregonstate.edu
**	Class: CS372
**	Assignment: Project 1
**	Program: chatserve.java
**	This program performs the server side of a chat program. It excepts the port
**	number of the port the user would like the server to listen on. When the program receives
**	a connection request from the client side chat program it will open a connection and
**	wait for a message from the user on the client side. Once a message is received the user
**	can send a message back to the client user. This process continues until the client user or 
**	server user enters the command "\quit" at which point the client will be disconnected and
**	the server will continue to wait for a new connection.
**
**	The general program layout was addapted from http://introcs.cs.princeton.edu/java/84network/EchoServer.java
**	and http://docs.oracle.com/javase/tutorial/networking/sockets/readingWriting.html
*/

import java.net.*;
import java.io.*;
import java.util.Scanner;

public class chatserve {
	public static void main(String[] args) throws IOException {
        
		if(args.length != 1) {
			System.err.println("Enter port number on command line");
			System.exit(1);
		}
        
		int serverPort = Integer.parseInt(args[0]);
		String handle = "HostA> ";
     
		ServerSocket serverSocket = new ServerSocket(serverPort);
		System.out.println("Listening on port " + serverPort);
		
		// repeatedly wait for connections, and process
		while (true) {
			// a "blocking" call which waits until a connection is requested
			Socket clientSocket = serverSocket.accept();
			System.out.println("Accepted connection from client");

			// open up IO streams
			BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
			PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);

			String sentence = " "; 
			String clientResp;
			String quit = "\\quit";
			Scanner hosta = new Scanner(System.in); //input from host A user

			while ((clientResp = in.readLine()) != null) {
				//client calls \quit
				if(clientResp.equals(quit)) {
					break;
				}
				System.out.println(clientResp);
				System.out.print(handle);
				sentence = hosta.nextLine();
				//server calls \quit
				if(sentence.equals(quit)) {
					out.println(sentence);	
					break;
				}
				out.println(handle + sentence);
			}

			// close IO streams, then socket
			System.out.println("Closing connection with client");
			out.close();
			in.close();
			clientSocket.close();
		}
	}
}