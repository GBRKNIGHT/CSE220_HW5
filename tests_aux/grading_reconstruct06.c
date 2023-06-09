#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char *packets[] = {
        "\x00\x77\xea\xdf\xce\x07\x70\x22\x06\xbf\x20\x40\x00\x00\x2c\x03\x78\x00\x00\x2e\xe8\x0c\xea\xc6\x63\x69\x65\x6e\x74\x69\x73\x74\x2c\x20\x6d\x61\x74\x68\x65\x6d\x61\x74\x69\x63\x69\x61",
        "\x00\x77\xea\xdf\xce\x07\x70\x22\x06\xbf\x20\x40\x00\x00\x00\x03\x78\x00\x00\x2e\xe8\x0c\xea\x9a\x44\x6f\x6e\x61\x6c\x64\x20\x45\x72\x76\x69\x6e\x20\x4b\x6e\x75\x74\x68\x20\x69\x73\x20",
        "\x00\x77\xea\xdf\xce\x07\x70\x22\x06\xbf\x20\x40\x00\x00\x33\x03\x78\x00\x00\x1d\xe8\x0c\xea\xf7\x73\x69\x74\x79\x2e",
        "\x00\x77\xea\xdf\xce\x07\x70\x22\x06\xbf\x20\x40\x00\x00\x16\x03\x78\x00\x00\x2e\xe8\x0c\xea\xb0\x61\x6e\x20\x41\x6d\x65\x72\x69\x63\x61\x6e\x20\x63\x6f\x6d\x70\x75\x74\x65\x72\x20\x73",
        "\x00\x77\xea\xdf\xce\x07\x70\x22\x06\xbf\x20\x40\x00\x00\x42\x03\x78\x00\x00\x2e\xe8\x0c\xea\xdc\x6e\x2c\x20\x61\x6e\x64\x20\x70\x72\x6f\x66\x65\x73\x73\x6f\x72\x20\x65\x6d\x65\x72\x69",
        "\x00\x77\xea\xdf\xce\x07\x70\x22\x06\xbf\x20\x40\x00\x00\x58\x03\x78\x00\x00\xff\xe8\x0c\xea\xf2\x74\x75\x73\x20\x61\x74\x20\x53\x74\x61\x6e\x66\x6f\x72\x64\x20\x55\x6e\x69\x76\x65\x72",
    };
    unsigned int packets_len = 6;
    unsigned int message_len = 125;  // original message has 115 characters
    char *message_act = malloc(message_len+1);

    // fill memory with "random" garbage
    for (unsigned int i = 0; i < message_len; i++)
        message_act[i] = '#';
    message_act[message_len] = '\0';
        
    reconstruct_sf((unsigned char **)packets, packets_len, message_act, message_len);
    free(message_act);
    return 0;
}