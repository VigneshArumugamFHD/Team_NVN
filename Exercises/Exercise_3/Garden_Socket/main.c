/*
	Create a TCP socket
*/

#include<stdio.h>

#define _WIN32_WINNT 0x6000
#include<winsock2.h>
#include<ws2tcpip.h>


//#define NI_MAXHOST 1025
//#define NI_MAXSERV  32
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
	if((listening = socket(AF_INET , SOCK_STREAM , 0 )) == -1)
	{
		printf("Could not create socket : %d" , WSAGetLastError());
	}
	else
    {
        printf("Socket created, listening = %d .\n",listening);
	}

	//server.sin_addr.s_addr = inet_addr("192.168.56.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8000 );
	server.sin_addr.S_un.S_addr = INADDR_ANY;

	bind(listening, (struct sockaddr *)&server ,sizeof(server));

	printf("Address %u and size %d\n",(struct sockaddr *)&server,sizeof(server));

	printf("Status of listening %d\n",listen(listening, SOMAXCONN));


	struct sockaddr_in client;

	client.sin_family = AF_INET;
    client.sin_port = htons(8000);

    int client_size = sizeof(client);

	SOCKET clientSocket = socket(AF_INET , SOCK_STREAM , 0 );

    SOCKET new_server_soc_connect = accept(listening,(struct sockaddr*)&client, (socklen_t*)&client_size);

	//Connect to remote server
	if (connect(clientSocket , (struct sockaddr *)&client , sizeof(client)) < 0)
	{
		printf("connect error\n");
	}
	else
    {
        printf("Connected\n");
    }






	printf("Client socket %d\n",clientSocket);

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    ZeroMemory(host, NI_MAXHOST);
	ZeroMemory(service, NI_MAXSERV);






	getnameinfo((struct sockaddr*)&client, sizeof(client),host, NI_MAXHOST, service, NI_MAXSERV, 0);

	if(getnameinfo((struct sockaddr*)&client, sizeof(client),host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        printf("%s connected on port %s",host,service);

    }
    else
    {
      //  inet_ntoa()
       // inet_ntop()
      //  inet_ntoa(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        printf("%s connected on port %s");
    }



    closesocket(listening);



	//Send some data
	//message = "GET / HTTP/1.1\r\n\r\n";
	//if( send(listening , message , strlen(message) , 0) < 0)
///	{
//		puts("Send failed");
//		return 1;
//	}
//	puts("Data Send\n");

	//return 0;
}
