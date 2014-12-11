//
//  PomeloSocket.h
//  TalesRomance
//
//  Created by qll on 14/12/11.
//
//

#ifndef __TalesRomance__PomeloSocket__
#define __TalesRomance__PomeloSocket__

#include <stdio.h>
#include "cocos2d.h"
#include "pomelo.h"
using namespace cocos2d;

#define NET_MESSAGE "net_message"

enum SOCKET_STATE
{
    STOPED,     //连接已经断开
    CONNECTING,  //正在连接中
    CONNECTED_OK,   //连接已经确立
    
    /*正在断开连接。在此状态下，CCPomeloWrapper的所有client api都会被忽略。
     出现此状态的一个典型场景是：主动或被动的stop()调用，使得所有未完成的request/notify
     的回调得以触发，在这些回调中发起的所有的client api的调用从逻辑上都是无效的。
     This status means CCPomeloWrapper is shutting down.
     Pending request/notify callbacks will be fired if stop() called by
     user or CCPomeloWrapper itself, and then the status will change to
     EPomeloStopped.
     You must NOT call any client api until the status becomes EPomeloStopped.
     */
    STOPING
};


class PomeloSocket : public Ref{
    pc_client_t *client;
    SOCKET_STATE state;
public:
    PomeloSocket();
    int connect(const char* addr,int port);
    int sendMsg(const char* route,std::string msg);
    int notify(const char* route,std::string msg);
    void stop();
    
    static void onPushDataCallback(pc_client_t *client, const char *event, void *data);
    static void onDisconnectCallback(pc_client_t *client, const char *event, void *data);
    static void requstCallback(pc_request_t *req, int status, json_t *resp);
    static void notifyCallback(pc_notify_t *ntf, int status);

    
    static void clearRequest();
    static void clearNotify();
    void heartBeat();
    void update(float dt);
    

};

#endif /* defined(__TalesRomance__PomeloSocket__) */
