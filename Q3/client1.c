#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct message
{
    float floatnum;
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

    c_address.sin_family = AF_INET;//address family
    c_address.sin_port = htons(8090);//port number
    c_address.sin_addr.s_addr = INADDR_ANY;//IP address

    //getting user inputs
    printf("Enter a floating point number:\n");
    scanf("%f", &c_data.floatnum);
    //send client data
    sendto(c_socket, &c_data, sizeof(c_data), 0, (struct sockaddr *)&c_address, sizeof(c_address));
    //close the socket
    close(c_socket);
    return 0;
}
