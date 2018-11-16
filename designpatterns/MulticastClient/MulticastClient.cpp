#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <winsock.h>

#pragma comment(lib, "Wsock32.lib")
#define close closesocket

#define LOCAL_IP "0.0.0.0"

typedef int socklen_t;



#define  GROUP_IP	"239.255.0.1"  //224.0.0.0-239.255.255.255

#define  PORT		8058



int InitSocket()
{
	int Error;
	WORD VersionRequested;
	WSADATA WsaData;
	VersionRequested = MAKEWORD(2, 2);
	Error = WSAStartup(VersionRequested, &WsaData); //启动WinSock2
	if (Error != 0)
	{
		return 0;
	}
	else
	{
		if (LOBYTE(WsaData.wVersion) != 2 || HIBYTE(WsaData.wHighVersion) != 2)
		{
			WSACleanup();
			return 0;
		}
	}

	return 0;
}


int main(int argc, char *argv[])
{
	InitSocket();

	struct in_addr localInterface;
	struct sockaddr_in groupSock;

	char bufSend[BUFSIZ];

	int sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0)
	{
		perror("Opening datagram socket error");
		exit(1);
	}
	memset((char *)&groupSock, 0, sizeof(groupSock));
	groupSock.sin_family = AF_INET;
	groupSock.sin_addr.s_addr = inet_addr(GROUP_IP);//GROUP_IP 第一个字节不超过239 后面3个字节用来区别分组 不是掩码
	groupSock.sin_port = htons(PORT);
	localInterface.s_addr = inet_addr(LOCAL_IP);//自己的ip,可以和目标不在一个网，但设置不同的网段。

	//设置组播
	if (setsockopt(sd, IPPROTO_IP, IP_MULTICAST_IF, (char *)&localInterface, sizeof(localInterface)) < 0)
	{
		printf("Setting local interface error");
		exit(1);
	}
	else
	{
		printf("Setting the local interface...OK\n");
	}


	for (int i = 0;; i++)
	{
		sprintf(bufSend, "%d", i);
		sendto(sd, bufSend, sizeof(bufSend), 0, (struct sockaddr*)&groupSock, sizeof(groupSock));
		printf("group=%s,locolip=%s,send=%s\n", GROUP_IP, LOCAL_IP, bufSend);
		Sleep(1000);
	}
	return 0;
}


