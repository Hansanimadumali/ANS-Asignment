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
    struct message client_data;

  
    c_address.sin_family = AF_INET;//address family
    c_address.sin_port = htons(8090);//port number
    c_address.sin_addr.s_addr = INADDR_ANY;//IP address

    printf("Enter an integer value:\n");
    scanf("%d", &client_data.integer);
    
    sendto(c_socket, &client_data, sizeof(client_data), 0, (struct sockaddr *)&c_address, sizeof(c_address));
    
    //close the socket
    close(c_socket);
    return 0;
}
