#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char *packets[] = {
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x24\x01\x41\x00\x00\x21\xa0\x0c\xe8\x85\x73\x6b\x79\x64\x69\x76\x69\x6e\x67",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x2d\x01\x41\x00\x00\x21\xa0\x0c\xe8\x8e\x20\x69\x73\x6e\x27\x74\x20\x66\x6f",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x00\x01\x41\x00\x00\x21\xa1\x0c\xe8\x61\x49\x66\x20\x61\x74\x20\x66\x69\x72",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x48\x01\x41\x00\x00\x1b\xa0\x0c\xe8\xa3\x67\x68\x74",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x09\x01\x41\x00\x00\x21\xa0\x0c\xe8\x6a\x73\x74\x20\x79\x6f\x75\x20\x64\x6f",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x1b\x01\x41\x00\x00\x21\xa0\x0c\xe8\x7c\x65\x64\x2c\x20\x74\x68\x65\x6e\x20",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x12\x01\x41\x00\x00\x21\xa0\x0c\xe8\x73\x6e\x27\x74\x20\x73\x75\x63\x63\x65",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x36\x01\x41\x00\x00\x21\xa0\x0c\xe8\x97\x72\x20\x79\x6f\x75\x2e\x20\x2d\x53",
        "\x09\xff\xea\xdf\xce\x08\xa0\x22\x06\xbf\x20\x40\x00\x00\x3f\x01\x41\x00\x00\x21\xa0\x0c\xe8\xa0\x74\x65\x76\x65\x6e\x20\x57\x72\x69",
    };
    unsigned int packets_len = 9;
    unsigned int message_len = 51;  
    char *message_act = malloc(message_len+3);

    // fill memory with "random" garbage
    for (unsigned int i = 0; i < message_len; i++)
        message_act[i] = '&';
        
    reconstruct_sf((unsigned char **)packets, packets_len, message_act, message_len);
    free(message_act);
    return 0;
}