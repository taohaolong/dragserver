#pragma once

#include <string>
#include <sstream>
//#include "base/macro.h"
#include "common/type.h"
#include "base/base_sock.h"
#include "common/common.h"
using namespace std;

BEGIN_NAME_SPACE(NetDrag)


//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////�����ַά������///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class InetAddress
{
public:
	InetAddress();
	explicit InetAddress(uint16_t);		//�����˿�
	InetAddress(std::string);
	InetAddress(std::string, uint16_t);	//�����˿�
	InetAddress(uint32_t, uint16_t);	//����IP��ַ������˿�
	InetAddress(uint64_t);				//��32ΪIP��ַ����32ΪPort�˿�
	InetAddress(const struct sockaddr_in&);
public:
	const struct sockaddr_in&	get_sock_addr()const						{	return addr;	}
	struct sockaddr_in&			get_sock_addr()								{	return addr;	}
	void						set_sock_addr(const struct sockaddr_in& sa)	{	addr = sa;		}
	void						set_sock_addr(string);
	void						set_sock_addr(string, uint16_t);			//�����˿�
	void						set_sock_addr(uint32_t, uint16_t);			//����IP��ַ������˿�
	void						set_sock_addr(uint64_t);
public:
	uint64_t	get_addr_endian()const;
	uint32_t	get_ip_net_endian()const		{ return addr.sin_addr.s_addr;	}
	uint16_t	get_port_net_endian()const		{ return addr.sin_port;			}
public:
	string		get_ip()const;
	uint16_t	get_port()const;
	string		get_addr()const;
	bool		empty()const;				//��ʽ��"0.0.0.0:0"
public:
	bool operator == (const InetAddress & _addr)
	{
		return get_addr_endian() == _addr.get_addr_endian();
	}
	friend std::ostream& operator << (std::ostream& out, const InetAddress& addr)
	{
		out << "addr = " << addr.get_addr();
		return out;
	}
public:
	sockaddr_in addr;
};

END_NAME_SPACE
