//-------------------------------------------------------------------
//	mywebsvr.cpp
//
//	This is a minimal webserver application which will allow web
//	browsers (e.g., Mozilla Firefox or Internet Explorer) to get
//	a listing of all the files in your present working directory
//	or get a textfile that has HyperText Markup Language format.
//
//		to compile:  $ g++ mywebsvr.cpp -o mywebsvr
//		to execute:  $ ./mywebsvr
//
//	programmer: ALLAN CRUSE
//	written on: 03 APR 2009
//-------------------------------------------------------------------

#include <arpa/inet.h> // for inet_ntoa()
#include <netdb.h>     // for gethostbyname()
#include <stdio.h>     // for printf(), perror()
#include <stdlib.h>    // for exit()
#include <string.h>    // for strcpy(), strrchr()
#include <sys/stat.h>  // for stat()
#include <sys/wait.h>  // for wait()
#include <unistd.h>    // for fork(), dup2(), close()

#define DEMO_PORT 54321

int main(int argc, char **argv)
{
  // get this server's hostname and network address
  char hostname[64] = {0};
  gethostname(hostname, 63);
  char hostaddr[16] = {0};
  struct hostent *hp = gethostbyname(hostname);
  if (!hp)
  {
    herror("gethostbyname");
    exit(1);
  }
  strcpy(hostaddr, inet_ntoa(*(in_addr *)hp->h_addr));
  printf("\nmywebsvr: \'%s\' (%s) \n", hostname, hostaddr);

  // prepare this server's socket-address structure
  struct sockaddr_in saddr = {0};
  socklen_t salen = sizeof(saddr);
  saddr.sin_family = AF_INET;
  saddr.sin_port = htons(DEMO_PORT);
  saddr.sin_addr.s_addr = inet_addr(hostaddr);

  // create a reusable connection-oriented socket for listening
  int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock < 0)
  {
    perror("socket");
    exit(1);
  }
  int oval = 1;
  int olen = sizeof(oval);
  if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &oval, olen) < 0)
  {
    perror("setsockopt SO_REUSEADDR");
    exit(1);
  }

  // bind this server's address and port-number to our socket
  if (bind(sock, (sockaddr *)&saddr, salen) < 0)
  {
    perror("bind");
    exit(1);
  }

  // convert our socket into a listening socket
  int backlog = 5;
  if (listen(sock, backlog) < 0)
  {
    perror("listen");
    exit(1);
  }

  // begin an infinite loop to accept and process client requests
  int count = 0;
  for (;;)
  {
    // accept the next connection-request from a client
    struct sockaddr_in caddr = {0};
    socklen_t calen = sizeof(caddr);
    int conn = accept(sock, (sockaddr *)&caddr, &calen);
    if (conn < 0)
    {
      perror("accept");
      break;
    }
    printf("\naccepting request #%d ", ++count);
    printf("from %s\n", inet_ntoa(*(in_addr *)&caddr.sin_addr));

    // convert the connection-socket into separate I/O streams
    FILE *rx = fdopen(conn, "r");
    FILE *tx = fdopen(dup(conn), "w");
    if (!rx || !tx)
    {
      perror("fdopen");
      close(conn);
      break;
    }

    // get the HTTP request-line
    char request[BUFSIZ] = {0};
    fgets(request, BUFSIZ, rx);
    printf("\n %s", request);

    // exhaust the HTTP request-headers
    char header[BUFSIZ] = {0};
    while (fgets(header, BUFSIZ, rx))
    {
      printf(" %s", header);
      if (strcmp(header, "\r\n") == 0)
        break;
    }

    // figure out what the client wants
    char cmd[BUFSIZ] = {0}, arg[BUFSIZ] = {0};
    strcpy(arg, "./");
    if (sscanf(request, "%s%s", cmd, arg + 2) != 2)
    {
      perror("sscanf");
      close(conn);
      break;
    }

    // we can't do any command except "GET"
    if (strcmp(cmd, "GET") != 0)
    {
      fprintf(stderr, "server cannot do that\n");
      //
      fprintf(tx, "HTTP/1.0 501 Not Implemented\r\n");
      fprintf(tx, "Content-type: text/plain\r\n");
      fprintf(tx, "\r\n");
      //
      fprintf(tx, "That one is not yet implemented\r\n");
      fclose(rx);
      fclose(tx);
      continue;
    }

    // check for presence of the requested file-object
    struct stat info = {0};
    if (stat(arg, &info) < 0)
    {
      fprintf(stderr, "target does not exist\n");
      //
      fprintf(tx, "HTTP/1.0 404 Not Found\r\n");
      fprintf(tx, "Content-type: text/plain\r\n");
      fprintf(tx, "\r\n");
      //
      fprintf(tx, "Requested item not found\r\n");
      fclose(rx);
      fclose(tx);
      continue;
    }

    // process a request for directory listing
    if (S_ISDIR(info.st_mode))
    {
      fprintf(stderr, "target is a directory\n");
      //
      fprintf(tx, "HTTP/1.0 200 OK\r\n");
      fprintf(tx, "Content-type: text/plain\r\n");
      fprintf(tx, "\r\n");
      //
      fflush(tx);
      if (fork() == 0)
      {
        dup2(conn, 1);
        dup2(conn, 2);
        close(conn);
        execlp("ls", "ls", "-l", arg, NULL);
        perror(arg);
        exit(1);
      }
      wait(NULL);
      fclose(rx);
      fclose(tx);
      continue;
    }

    // process a request for an HTML textfile
    if (strcmp(strrchr(arg, '.') + 1, "html") == 0)
    {
      fprintf(stderr, "target is an html file\n");
      //
      fprintf(tx, "HTTP/1.0 200 OK\r\n");
      fprintf(tx, "Content-type: text/html\r\n");
      fprintf(tx, "\r\n");
      //
      fflush(tx);
      if (fork() == 0)
      {
        dup2(conn, 1);
        dup2(conn, 2);
        close(conn);
        execlp("cat", "cat", arg, NULL);
        perror(arg);
        exit(1);
      }
      wait(NULL);
      fclose(rx);
      fclose(tx);
      continue;
    }

    // otherwise report that the object will not be served
    fprintf(stderr, "target is not an html file\n");
    //
    fprintf(tx, "HTTP/1.0 406 Not acceptable\r\n");
    fprintf(tx, "Content-type: text/plain\r\n");
    fprintf(tx, "Connection: close\r\n");
    fprintf(tx, "\r\n");
    //
    fprintf(tx, "The format requested is not acceptable\r\n");
    fflush(tx);
    fclose(rx);
    fclose(tx);
    continue;
  }

  close(sock);
  printf("\nthis server has been terminated \n");
}
