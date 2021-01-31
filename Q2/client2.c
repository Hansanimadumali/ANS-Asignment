#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct message
{
    int integer;
};

int main()
{
    //client socket creation
    int c_socket;
    c_socket = socket(AF_INET, SOCK_DGRAM, 0);

    if (c_socket == -1)
    {
        printf("Error in socket creation.");
        exit(1);
    }

    struct sockaddr_in c_address;
    struct message c_data;
    socklen_t client_len;
    int ping = 1;
    int error_check;

    client_len = sizeof(c_address);
   

    c_address.sin_family = AF_INET;//address family
    c_address.sin_port = htons(8090);//port number
    c_address.sin_addr.s_addr = INADDR_ANY;//IP address

    sendto(c_socket, &ping, sizeof(ping), 0, (struct sockaddr *)&c_address, sizeof(c_address));
   

    recvfrom(c_socket, &c_data, sizeof(c_data), 0, (struct sockaddr *)&c_address, &client_len);
  

    printf("Server sent this Integer:\n");
     printf("Integer:%d\n",c_data.integer);
    
    //close the socket
    close(c_socket);
    return 0;
}
