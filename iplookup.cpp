#include <arpa/inet.h> // for ‘inet_atop();
#include <netdb.h>     // for ‘gethostbyname();
#include <stdio.h>     // for ‘printf()’
#include <string.h>    // for ‘strcpy()’, ‘strncpy()’

#define BUFLEN INET_ADDRSTRLEN

int main(int argc, char *argv[])
{
  char hostname[64] = {0};
  if (argc == 1)
    strcpy(hostname, "localhost");
  else
    strncpy(hostname, argv[1], 63);

  char hostip[BUFLEN] = {0};
  struct hostent *hp = gethostbyname(hostname);
  if (!hp)
    strcpy(hostip, "unknown");
  else
    inet_ntop(AF_INET, hp->h_addr, hostip, BUFLEN);

  printf("The IP-address for \'%s\' is %s \n", hostname, hostip);
}
