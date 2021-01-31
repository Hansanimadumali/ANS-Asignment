#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main()
{	
    // server socket creation
    int s_socket;
    s_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(s_socket == -1)
    {
        printf("Error in socket creation\n");
        exit(1);
    }

    char s_msg[256];
    char ping[10];

    struct sockaddr_in c_address;
    socklen_t client_len;
    
    client_len = sizeof(c_address);

    

    struct sockaddr_in s_address;
    s_address.sin_family = AF_INET;
    s_address.sin_port = htons(8090); 
    s_address.sin_addr.s_addr = INADDR_ANY;
  
    //bind the socket 
    bind(s_socket, (struct sockaddr *) &s_address, sizeof(s_address));
    

    // get message from client 1
    recvfrom(s_socket,s_msg,sizeof(s_msg),0, (struct sockaddr *) &c_address, &client_len);
  
    printf("Client sent the character: %s\n", s_msg);
    
    //decrement the character
    if(s_msg[0] == 'a')
    {
        s_msg[0] = 'z';
    }
    else if (s_msg[0] == 'A')
    {
        s_msg[0] == 'Z';
    }
    else
    {
        s_msg[0] = s_msg[0] - 1;
    }

    // client 2 pings 
    recvfrom(s_socket,ping,sizeof(ping),0, (struct sockaddr *) &c_address, &client_len);
   

   sendto(s_socket, s_msg, sizeof(s_msg), 0, (struct sockaddr *) &c_address, client_len);
   
    printf("Server Process completed.\n");

    close(s_socket);
    return 0;
}
