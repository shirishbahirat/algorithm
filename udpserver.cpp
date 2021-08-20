//----------------------------------------------------------------
//	udpserver.cpp
//
//	This program creates a network socket which it can use to
//	receive a datagram sent from a remote client to its port.
//	It displays the received message, then transmits it back.
//
//	     usage:  $ ./udpserver
//
//	NOTE: This code is adapted from an example in the Masters
//	Thesis submitted by Mr. Okki Tranggana on 15 May 1991.
//
//	programmer: ALLAN CRUSE
//	written on: 19 JAN 2008
//----------------------------------------------------------------

#include <netinet/in.h> // for socket(), bind()
#include <stdio.h>      // for printf(), perror()
#include <stdlib.h>     // for exit()
#include <string.h>     // for bzero()
#include <unistd.h>     // for close()

#define BUFSZ 1500 // Maximum size for an ethernet datagram

int main(void)
{
  //------------------------------------------------------------
  // create a socket on which to receive and transmit datagrams
  //------------------------------------------------------------
  int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sock < 0)
  {
    perror("opening datagram socket");
    exit(1);
  }

  //------------------------------------------------------
  // initialize a socket-address strcture using wildcards
  //------------------------------------------------------
  struct sockaddr_in name;
  socklen_t nlen;

  nlen = sizeof(name);
  bzero(&name, nlen);
  name.sin_family = AF_INET;
  name.sin_port = htons(0);

  //------------------------------------------------
  // Bind our socket to this generic socket-address
  //------------------------------------------------
  if (bind(sock, (sockaddr *)&name, nlen))
  {
    perror("binding datagram socket");
    exit(1);
  }

  //----------------------------------------------------
  // find the system-assigned portnumber and display it
  //----------------------------------------------------
  if (getsockname(sock, (sockaddr *)&name, &nlen))
  {
    perror("getting socket name");
    exit(1);
  }

  printf("Socket has port #%d \n", ntohs(name.sin_port));

  //----------------------------------------------------
  // initialize a socket-address structure for the peer
  //----------------------------------------------------
  struct sockaddr_in peer;
  socklen_t plen = sizeof peer;
  bzero(&peer, plen);

  //---------------------------------------------------
  // read any datagram sent to our socket's portnumber
  //---------------------------------------------------
  char buf[BUFSZ];
  if (recvfrom(sock, buf, BUFSZ, 0, (sockaddr *)&peer, &plen) < 0)
    perror("receiving datagram packet");

  //-----------------------------------------
  // display the received datagram's message
  //-----------------------------------------
  printf("-->%s\n", buf);

  //-------------------------------------------------------
  // transmit a message-acknowledgement back to the client
  //-------------------------------------------------------
  int msbytes = strlen(buf);
  int txbytes = sendto(sock, buf, msbytes, 0, (sockaddr *)&peer, plen);

  //----------------------------------------------------------
  // close the socket, and report on this message-transaction
  //----------------------------------------------------------
  close(sock);

  if (txbytes < 0)
    perror("error transmitting reply to client");
  else
    printf("reply was sent to client (%d bytes)\n", txbytes);
}
