#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

int main()
{
    int c_socket;
    struct sockaddr_in c_address;
    socklen_t server_len;
    char c_msg[2];

    server_len = sizeof(c_address);

    // client1 socket creation

    c_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(c_socket == -1)
    {
        printf("Error in socket creation\n");
        exit(1);
    }

    c_address.sin_family = AF_INET;
    c_address.sin_port = htons(8090);
    c_address.sin_addr.s_addr = INADDR_ANY;
    
    //getting character input
    printf("Input the character to send\n");
    fgets(c_msg, sizeof(c_msg), stdin);
    //sending data
   sendto(c_socket, c_msg, sizeof(c_msg),0, (struct sockaddr *) &c_address, server_len);
    

    printf("client send the message to the server\n");
    //close the socket
    close(c_socket);

    return 0;
}
