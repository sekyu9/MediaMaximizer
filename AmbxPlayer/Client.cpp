#include "StdAfx.h"
#include "Client.h"
#include <string>
#include <vector>
#include <sstream>

Client::Client()
{
	IPaddr ="127.0.0.1";
	portNum = 1234;
	sSocket = (socketStruct*)malloc(sizeof(socketStruct));
	SprayIsCreate = false;
}

Client::~Client()
{

}

void Client::MessageSender(long intensity)
{
	string message;
	int sendTest;
	ostringstream temp;
	temp << intensity;
	message = temp.str();

	if(WSAStartup(MAKEWORD(2, 2), &wsaData) !=0)
		ErrorHandling("WSAStartup() errer!");

	hSocket=socket(PF_INET, SOCK_STREAM, 0);
	if(hSocket==INVALID_SOCKET)
		ErrorHandling("hSocketet() error!");
	
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family=AF_INET;
	servAddr.sin_addr.s_addr=inet_addr(IPaddr);
	servAddr.sin_port=htons(portNum);

	if(connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr))==SOCKET_ERROR)
		ErrorHandling("connect() error!");	 
	
	sendTest = send( hSocket, message.c_str(), message.length(),NULL);

	closesocket(hSocket);
	WSACleanup();
}


void Client::ErrorHandling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
