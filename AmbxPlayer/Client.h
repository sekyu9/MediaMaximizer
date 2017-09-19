#pragma once
#include "StdAfx.h"

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <windows.h>
#include <sys/types.h> 

using namespace std;

struct socketStruct {
	int nrData;
	int data_size;
	double data[3];
	char string_data[256];
};

class Client{

public:
	Client(void);
	~Client(void);

private:
	char* IPaddr;
	int portNum;
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;
	socketStruct* sSocket;	
	bool SprayIsCreate;

public:
	void MessageSender(long intensity);
	void ErrorHandling(char* message);
};