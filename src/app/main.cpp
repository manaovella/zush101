#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include "oscserver.h"
#include "UdpClient.h"

#define _OSC_PUSH   0
#define _OSC_FADER  1
#define _OSC_BUTTON 2
#define _OSC_ROTARY 3
#define _OSC_MAXVALUE 65535.0

#define RPMSG_GET_KFIFO_SIZE 1
#define RPMSG_GET_AVAIL_DATA_SIZE 2
#define RPMSG_GET_FREE_SPACE 3

//
struct _oscpayload {
	unsigned int osccmd;
	unsigned int value;
};

OSCServer oscServer;
UdpClient socket0;
UdpClient socket1;

struct _oscpayload payload;

bool active = true;

char dbg_server[] = "10.171.2.12";
char dbg_port0 = 12000;
char dbg_port1 = 12001;
char driver[] = "rpmsg_user_dev_driver";
char user_fw_path[] = "/home/root/myfw";
char fw_dst_path[] = "/lib/firmware/myfw";
char sysfw_path[]  = "/sys/class/remoteproc/remoteproc0/firmware";
char sysstate_path[] = "/sys/class/remoteproc/remoteproc0/state";
char devrpmsg_path[] = "/dev/rpmsg_proxy0";

//
void setdbgsocket()
{
	socket0.setServer(dbg_server);
	socket0.setPort(dbg_port0);
	socket1.setServer(dbg_server);
	socket1.setPort(dbg_port0);
}

//
void myprintf0(const char* string)
{
	socket0.send((void*)string, sizeof(char) * strlen(string));
	socket0.send((void*)"\r\n", sizeof(char) * 2);
}

//
void myprintf0(const char* string, float val)
{
	socket0.send((void*)string, sizeof(char) * strlen(string));
	char buf[64];
	int ret = snprintf(buf, 64, "%f", val);
	myprintf0(buf);
}

//
void myprintf0(char* string, int val) 
{
	socket0.send((void*)string, sizeof(char) * strlen(string));
	char buf[64];
	int ret = snprintf(buf, 64, "%d", val);
	myprintf0(buf);
}


//
int file_write(char *path, char *str)
{
	int fd;
	ssize_t bytes_written;
	size_t str_sz;

	fd = open(path, O_WRONLY);
	if (fd == -1) {
		perror("Error");
		return -1;
	}
	str_sz = strlen(str);
	bytes_written = write(fd, str, str_sz);
	if (bytes_written != str_sz) {
		if (bytes_written == -1) {
			perror("Error");
		}
		close(fd);
		return -1;
	}

	if (-1 == close(fd)) {
		perror("Error");
		return -1;
	}
	return 0;
}

// 
void stopremote()
{
	system("modprobe -r rpmsg_user_dev_driver");
	(void)file_write(sysstate_path, "stop");
}

//
void exit_action_handler(int signum)
{
}

//
void kill_action_handler(int signum)
{
}

//
void setsigaction()
{
	struct sigaction exit_action;
	struct sigaction kill_action;
	char *user_fw_path = 0;

	/* Initialize signalling infrastructure */
	memset(&exit_action, 0, sizeof(struct sigaction));
	memset(&kill_action, 0, sizeof(struct sigaction));
	exit_action.sa_handler = exit_action_handler;
	kill_action.sa_handler = kill_action_handler;
	sigaction(SIGTERM, &exit_action, NULL);
	sigaction(SIGINT, &exit_action, NULL);
	sigaction(SIGKILL, &kill_action, NULL);
	sigaction(SIGHUP, &kill_action, NULL);
}

//
int initrpmsg()
{
	char sbuf[512];

	//
	system("modprobe rpmsg_user_dev_driver");
	(void)file_write(sysstate_path, "stop");

	// 
	myprintf("\r\n Master>Loading remote firmware \r\n");
	if (user_fw_path) {
		sprintf(sbuf, "cp %s %s", user_fw_path, fw_dst_path);
		system(sbuf);
	}

	// 
	if (0 != file_write(sysfw_path, "image_rpc_demo"))
		return -1;

	// 
	if (0 != file_write(sysstate_path, "start")) 
		return -1;

	return 0;
}

//
int openrpmsg()
{
	// Open proxy rpmsg device */
	myprintf("\r\nMaster>Opening rpmsg proxy device\r\n");
	int i = 0;
	do {
		fd = open(devrpmsg_path, O_RDWR);
		sleep(10);
	} while (fd < 0 && (i++ < 2));

	if (fd < 0) {
		myprintf("\r\nMaster>Failed to open rpmsg proxy driver device file.\r\n");
		return -1;
	}

	return 0;
}

//
void recvrpmsg()
{
	do {
		bytes_rcvd = read(proxy->rpmsg_proxy_fd, proxy->rpc, RPC_BUFF_SIZE);
		if (!active)
			break;
	} while (bytes_rcvd <= 0);

	if (!active)
		break;
}

//
void startosc()
{
	myprintf("starting oscserver...");
	oscServer.setup(55555);
	myprintf("...started");
}

//
void stoposc()
{

}

//
void closerpmsg()
{

}

//
void closedbgsocket()
{

}

//
void stoposc()
{

}

//
void uninitrpmsg()
{

}

//
void createwaveform()
{

}

//
int main(int argc, char *argv[])
{
	setsigaction();
	cratewaveform();
	initrpmsg();
	openrpmsg();
	setdbgsocket();
	startosc();

	while (active)
	{
		//
		recvrpmsg();
		
		//
		oscServer.receiveMessageNow(10);
		while (oscServer.messageWaiting())
		{
			//
			float f;
			oscpkt::Message msg = oscServer.popMessage();
			msg.arg().popFloat(f);
			if (msg.addressPattern().length() > 3)
				myprintf(msg.addressPattern().c_str(), f);

			//
			payload.osccmd = _OSC_BUTTON;
			payload.value = (unsigned int)(_OSC_MAXVALUE * f);

			//
			myprintf("\r\n sending payload with value:", payload.value);
			bytes_sent = write(fd, &payload, (2 * sizeof(unsigned int)));
			myprintf("echo test: sent: ", bytes_sent);
		}		
	}

	stoposc();
	closedbgsocket();
	closerpmsg();
	uninitrpmsg();
	return 0;
}
