//
// Created by tao Jacky on 11/16/16.
//

#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "sockutil.h"
#include "base/base_sock.h"

#include <stdio.h>

BEGIN_NAME_SPACE(NetDrag)


void signal_handle(int sig)
{
    printf("program exit for signal = %d\n", sig);
    exit(0);
}

#ifndef WIN32
void check_linux_release()
{
    int stat = 0;
    char result[1024];
    char cmd[1024];
    memset(result,'\0',1024);
    memset(cmd,'\0',1024);
    FILE *ptr;
    strcpy(cmd, "uname -r");
    if((ptr=popen(cmd, "r"))!=NULL)
    {
        while(fgets(result, 1024, ptr)!=NULL)
        {
            if(strlen(result)>1024)
            {
                break;
            }
            else if(strlen(result)>0)
            {
                stat = 1;
                *(strchr(result, '\n')) = '\0';
            }
            else
            {
                break;
            }

        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", cmd);
    }
    if(stat)
    {
        string res(result);
        if(res > "2.6.26")
        {
            return;
        }
        else
        {
            printf("program exit for linux release [%s] is too low, must>(2.6.26)!\n",result);
            exit(0);
        }

    }
    else
    {
        printf("program exit for get linux release error\n");
        exit(0);
    }
}
#endif


void Socket::Init()
{
#ifdef	WIN32
    WSADATA wsa_data;
	int	 r = WSAStartup(MAKEWORD(2,2), &wsa_data);
#else
    signal(SIGPIPE,SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    signal(SIGINT, signal_handle);
    signal(SIGTERM, signal_handle);
#ifndef __MACH__
    check_linux_release();
#endif //__MACH__
#endif //WIN32
}




/*
 * @brief create TCP Socket
 * @param[in,out] none
 * @return TCP socket id to event_socket
 */
evutil_socket_t Socket::create_tcp() {


#ifndef NOTNETPRINT
    // test log info on console.
    printf("[DEBUG]evutil_socket_t Socket::create_tcp() \n");
#endif
    return ::socket(AF_INET, SOCK_STREAM, 0);
}


/*
 * @brief create TCP Socket
 * @param[in,out] none
 * @return UDP socket id to event_socket
 */
evutil_socket_t Socket::create_udp() {

#ifndef NOTNETPRINT
    // test log info on console.
    printf("[DEBUG]evutil_socket_t Socket::create_udp() \n");
#endif

    return ::socket(AF_INET, SOCK_DGRAM, 0);
}

END_NAME_SPACE