#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char *packets[] = {
        "\x00\x9c\xea\xdf\xce\x00\x55\xa0\x06\xbf\x20\x40\x00\x00\x1d\x00\xde\x00\x00\x35\xf2\x8a\xe8\x1d\x6e\x20\x66\x72\x61\x6d\x65\x77\x6f\x72\x6b\x20\x66\x6f\x72\x20\x62\x75\x69\x6c\x64\x69\x6e\x67\x20\x64\x79\x6e\x61",
        "\x00\x9c\xea\xdf\xce\x00\x55\xa0\x06\xbf\x20\x40\x00\x00\x00\x00\xde\x00\x00\x35\xf2\x8a\xe8\x00\x56\x61\x6c\x67\x72\x69\x6e\x64\x20\x69\x73\x20\x61\x6e\x20\x69\x6e\x73\x74\x72\x75\x6d\x65\x6e\x74\x61\x74\x69\x6f",
        "\x00\x9c\xea\xdf\xce\x00\x55\xa0\x06\xbf\x20\x40\x00\x00\x3a\x00\xde\x00\x00\x2b\xf2\x8a\xe8\x30\x6d\x69\x63\x20\x61\x6e\x61\x6c\x79\x73\x69\x73\x20\x74\x6f\x6f\x6c\x73\x2e",
    };
    unsigned int packets_len = 3;
    unsigned int message_len = 2;  
    char *message_act = malloc(message_len+3);

    // fill memory with "random" garbage
    srand(412);
    for (unsigned int i = 0; i < message_len+3; i++)
        message_act[i] = (char)(rand() % 90 + 35);
        
    reconstruct_sf((unsigned char **)packets, packets_len, message_act, message_len);
    free(message_act);
    return 0;
}