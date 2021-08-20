//----------------------------------------------------------------
//	udpclient.cpp
//
//	This program sends a datagram to a specified port on the
//	remote host whose name is supplied on the commwand-line.
//	Its message is from a celebrated poem by Matthew Arnold.
//
//	      usage:   $ ./udpclient <hostname> <portnumber>
//
//	NOTE: This code is adapted from an example in the Masters
//	Thesis submitted by Mr. Okki Tranggana on 15 May 1991.
//
//	programmer: ALLAN CRUSE
//	written on: 19 MAY 2008
//----------------------------------------------------------------

#include <netdb.h>  // for socket(), gethostbyname(), sendto()
#include <stdio.h>  // for printf(), fprintf(), perror()
#include <stdlib.h> // for atoi(), exit()
#include <string.h> // for bzero(), bcopy(), strlen()
#include <unistd.h> // for close()

#define MTU 1500 // Maximum Transmission Unit (bytes)
#define DATA "The sea is calm tonight, the tide is full..."

int main(int argc, char *argv[])
{
  //-------------------------------------------------------
  // check for the required pair of command-line arguments
  //-------------------------------------------------------
  if (argc < 3)
  {
    fprintf(stderr, "usage: $ %s ", argv[0]);
    fprintf(stderr, "<hostname> <portnumber> \n");
    exit(1);
  }

  //--------------------------------------------------
  // obtain the network address for the station whose
  // hostname was provided as a command-line argument
  // and initialize our socket-address data-structure
  //--------------------------------------------------
  struct hostent *hp = gethostbyname(argv[1]);
  if (!hp)
  {
    fprintf(stderr, "%s: unknown host\n", argv[1]);
    exit(2);
  }

  struct sockaddr_in name;
  socklen_t nlen = sizeof name;
  bzero(&name, nlen);
  bcopy(hp->h_addr, &name.sin_addr, hp->h_length);
  name.sin_family = AF_INET;
  name.sin_port = htons(atoi(argv[2]));

  //------------------------------------------------------
  // create a network socket on which to send and receive
  //------------------------------------------------------
  int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock < 0)
  {
    perror("opening datagram socket");
    exit(3);
  }

  //---------------------------------------------------
  // send our message to the port on the remote server
  //---------------------------------------------------
  if (sendto(sock, DATA, sizeof(DATA), 0, (sockaddr *)&name, nlen) < 0)
    perror("sending datagram message");
  else
    printf("message sent -- awaiting reply...\n");

  //-----------------------------------------------------
  // wait for an acknowledgement from that remote server
  //-----------------------------------------------------
  char buf[MTU];
  bzero(&buf, MTU);

  int rxbytes = recv(sock, buf, MTU, 0);
  if (rxbytes < 0)
    perror("awaiting reply");
  else
    printf("-->%s\n", buf);

  close(sock);
}
