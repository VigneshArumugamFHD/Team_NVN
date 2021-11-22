/*
	Create a TCP socket
*/

#include<stdio.h>
#include<winsock2.h>


#define NI_MAXHOST 1025
#define NI_MAXSERV  32
//#pragma comment(lib,"ws2_32.lib") //Winsock Library

int main(int argc , char *argv[])
{
	WSADATA wsa;
	SOCKET listening;
	struct sockaddr_in server;
	char *message;

	printf("\nInitialising Winsock...");

	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("Failed. Error Code : %d",WSAGetLastError());
		return 1;
	}
	else
    {
        printf("Initialised.\n");
    }


	//Create a socket
	if((listening = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}
	else
    {
        printf("Socket created.\n");
	}

	//server.sin_addr.s_addr = inet_addr("192.168.56.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8000 );
	server.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (struct sockaddr *)&server ,sizeof(server));

	listen(listening, SOMAXCONN);


	struct sockaddr_in client;

	SOCKET clientSocket = accept(listening,(struct sockaddr*)&client, sizeof(client));

	char host[NI_MAXHOST];
	char service[NI_MAXSERV];

	ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);

	if(getnameinfo((struct sockaddr*)&client, sizeof(client),host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        printf("%s connected on port %s",host,service);

    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        printf("%s connected on port %s",host, ntohs(client.sin_port));
    }

    closesocket(listening);

	//Connect to remote server
	if (connect(listening , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");

	//Send some data
	message = "GET / HTTP/1.1\r\n\r\n";
	if( send(listening , message , strlen(message) , 0) < 0)
	{
		puts("Send failed");
		return 1;
	}
	puts("Data Send\n");

	return 0;
}
