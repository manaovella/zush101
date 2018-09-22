#include "oscserver.h"

void myprintf(const char* string);

bool gShouldStop = false;

//
OSCServer::OSCServer()
{
}

//
void OSCServer::checkMessages(void *ptr)
{
    OSCServer *instance = (OSCServer *)ptr;
    while (!gShouldStop)
    {
        instance->messageCheck();
        usleep(1000);
    }
}

//
void OSCServer::setup(int _port)
{
    port = _port;
    if (!socket.init(port))
        myprintf("socket not initialised\n");

}

//
void OSCServer::messageCheck()
{
    if (socket.waitUntilReady(true, UDP_RECEIVE_TIMEOUT_MS))
    {
        int msgLength = socket.read(&inBuffer, UDP_RECEIVE_MAX_LENGTH, false);
        pr.init(inBuffer, msgLength);
        oscpkt::Message *inmsg;
        while (pr.isOk() && (inmsg = pr.popMessage()) != 0)
        {
        }
    }
}

//
bool OSCServer::messageWaiting()
{
    return !inQueue.empty();
}

//
oscpkt::Message OSCServer::popMessage()
{
    if (!inQueue.empty())
    {
        poppedMessage = inQueue.front();
        inQueue.pop();
    }
    else
    {
        poppedMessage.init("/error");
    }
    return poppedMessage;
}

//
void OSCServer::receiveMessageNow(int timeout)
{
    if (socket.waitUntilReady(true, timeout))
    {
        int msgLength = socket.read(&inBuffer, UDP_RECEIVE_MAX_LENGTH, false);
        pr.init(inBuffer, msgLength);
        oscpkt::Message *inmsg;
        while (pr.isOk() && (inmsg = pr.popMessage()) != 0)
			inQueue.push(*inmsg);
    }
}
