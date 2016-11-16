#include <sstream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include "base/base_sock.h"
//#include "base/util.h"
#include "inet_address.h"

//using namespace BASE;

BEGIN_NAME_SPACE(NetDrag)

InetAddress::InetAddress()
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= htonl(INADDR_ANY);
	addr.sin_port			= htons(0);
}

InetAddress::InetAddress(uint16_t port)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= htonl(INADDR_ANY);
	addr.sin_port			= htons(port);
}

InetAddress::InetAddress(std::string ip_and_port)
{
	set_sock_addr(ip_and_port);
}

InetAddress::InetAddress(std::string ip, uint16_t port)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= ::inet_addr(ip.c_str());
	addr.sin_port			= htons(port);
}

InetAddress::InetAddress(uint32_t ip, uint16_t port)	//IP��ַ���˿�
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= ip;
	addr.sin_port			= port;
}

InetAddress::InetAddress(uint64_t ip_and_port)				//��32ΪIP��ַ����32ΪPort�˿�
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= ip_and_port >> 32;
	addr.sin_port			= ip_and_port & 0X000000000000FFFF; 
}

InetAddress::InetAddress(const struct sockaddr_in& sa): addr(sa)
{
	
}

void InetAddress::set_sock_addr(string ip_and_port)
{
#ifdef NoWrrog
	vector<string> array;
	split_string(ip_and_port.c_str(), ":", array);

	if(array.size() == 2)
	{
		memset(&addr, 0, sizeof(addr));
		addr.sin_family			= AF_INET;
		addr.sin_addr.s_addr	= ::inet_addr(array[0].c_str());
		addr.sin_port			= htons(atoi(array[1].c_str()));
	}
#endif
}

void InetAddress::set_sock_addr(string ip, uint16_t port)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= ::inet_addr(ip.c_str());
	addr.sin_port			= htons(port);
}

void InetAddress::set_sock_addr(uint32_t ip, uint16_t port)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= ip;
	addr.sin_port			= port;
}

void InetAddress::set_sock_addr(uint64_t ip_and_port)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_family			= AF_INET;
	addr.sin_addr.s_addr	= ip_and_port >> 32;
	addr.sin_port			= ip_and_port & 0X000000000000FFFF; 
}
uint64_t InetAddress::get_addr_endian()const
{
	return (uint64_t(addr.sin_addr.s_addr) << 32) | addr.sin_port;
}

std::string	InetAddress::get_ip()const
{
#ifdef	WIN32
	return ::inet_ntoa(addr.sin_addr);
#else
	char dst[1024];
	memset(dst, '\0', 1024);
	if((inet_ntop(AF_INET,&addr.sin_addr.s_addr, dst, sizeof(dst))) == NULL)
	{
		return string(dst);
	}
	return ::inet_ntoa(addr.sin_addr);
#endif

}

uint16_t InetAddress::get_port()const
{
	return ntohs(addr.sin_port);
}

std::string	InetAddress::get_addr()const
{
	std::stringstream ss;
	ss << get_ip() << ":" << get_port();
	return ss.str();
}

bool InetAddress::empty()const
{
	if(addr.sin_addr.s_addr	== htonl(INADDR_ANY) && addr.sin_port == htons(0) )
	{
		return true;
	}
	return false;
}

END_NAME_SPACE
