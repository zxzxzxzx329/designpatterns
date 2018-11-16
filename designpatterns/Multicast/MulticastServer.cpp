#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
#include <winsock.h>
 
#pragma comment(lib, "Wsock32.lib")
#define close closesocket
 
#define LOCAL_IP "0.0.0.0"
 
typedef int socklen_t;
 
 
 
#define  GROUP_IP	"239.255.0.1"//224.0.0.0-239.255.255.255
 
#define  PORT		8058
 
 
 
struct sockaddr_in localSock;
struct ip_mreq group;
 
 
int GetSOCK_DGRAM(unsigned short port)
{
	int sd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sd < 0)
	{
		perror("Opening datagram socket error");
		exit(1);
	}
	else
		printf("Opening datagram socket....OK.\n");
 
	{
		int reuse = 1;
		if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&reuse, sizeof(reuse)) < 0){
			perror("Setting SO_REUSEADDR error");
			close(sd);
			exit(1);
		}
		else
			printf("Setting SO_REUSEADDR...OK.\n");
	}
 
 
	int ret = 0;
 
	memset((char *)&localSock, 0, sizeof(localSock));
	localSock.sin_family = AF_INET;
	localSock.sin_port = port;
	localSock.sin_addr.s_addr = INADDR_ANY;
	if (bind(sd, (struct sockaddr*)&localSock, sizeof(localSock)))
	{
		perror("Binding datagram socket error");
		close(sd);
		exit(1);
	}
	else
	{
		printf("Binding datagram socket...OK.\n");
	}
	group.imr_multiaddr.s_addr = inet_addr(GROUP_IP);//相当于组名
	group.imr_interface.s_addr = inet_addr(LOCAL_IP);//自己的ip
	if (setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&group, sizeof(group)) < 0)
	{
		perror("Adding multicast group error");
		close(sd);
		exit(1);
	}
	else
		printf("Adding multicast group...OK.\n");
 
	return sd;
}
 
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
	int sd = GetSOCK_DGRAM(htons(PORT));
	struct sockaddr_in from;
	int fromlen = sizeof(from);
	int nRecvLen = 1;
	const int recvSize = 1024 * 1000;
	unsigned char* databuf = new unsigned char[recvSize];
	while (1)
	{
		nRecvLen = recvfrom(sd, (char*)databuf, recvSize, 0, (struct sockaddr*)&from, (socklen_t*)&fromlen);//read
		if (nRecvLen > 0)
		{
			//	continue;
		}
 
		printf("recv=%s\n", databuf);
 
	}
 
	return 0;
}
