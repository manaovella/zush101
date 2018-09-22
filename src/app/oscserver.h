#ifndef __OSCServer_H_INCLUDED__
#define __OSCServer_H_INCLUDED__ 

#include "oscpkt.h"
#include "UdpServer.h"
#include <queue>

#define UDP_RECEIVE_TIMEOUT_MS 20
#define UDP_RECEIVE_MAX_LENGTH 16384

class OSCServer{
    public:
        OSCServer();

        void setup(int port);
        bool messageWaiting();
        oscpkt::Message popMessage();

        void receiveMessageNow(int timeout);
        
    private:
        int port;
		UdpServer socket;
		
        void messageCheck();
        
        static void checkMessages(void*);
        std::queue<oscpkt::Message> inQueue;
        int inBuffer[UDP_RECEIVE_MAX_LENGTH];
        oscpkt::Message poppedMessage;
        oscpkt::PacketReader pr;
};

#endif
