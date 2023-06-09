#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char *packets[] = {
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x13\x02\x14\x00\x00\x2b\x8e\x9f\x02\x2b\x77\x69\x6e\x65\x2e\x20\x53\x6f\x6d\x65\x74\x69\x6d\x65\x73\x20\x49\x20\x65",
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x39\x02\x14\x00\x00\x2b\x8e\x9f\x02\x51\x6f\x6f\x64\x2e\x20\x20\x2d\x57\x2e\x43\x2e\x20\x46\x69\x65\x6c\x64\x73\x2d",
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x00\x02\x14\x00\x00\x2b\x8e\x9f\x02\x18\x49\x20\x61\x6c\x77\x61\x79\x73\x20\x63\x6f\x6f\x6b\x20\x77\x69\x74\x68\x20",
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x26\x02\x14\x00\x00\x2b\x8e\x9f\x02\x3e\x76\x65\x6e\x20\x61\x64\x64\x20\x69\x74\x20\x74\x6f\x20\x74\x68\x65\x20\x66",
    };
    unsigned int packets_len = 4;
    unsigned int message_len = 77;  // original message has 76 characters
    char *message_act = malloc(message_len+3);

    // fill memory with "random" garbage
    srand(444);
    for (unsigned int i = 0; i < message_len+3; i++)
        message_act[i] = (char)(rand() % 90 + 35);
        
    reconstruct_sf((unsigned char **)packets, packets_len, message_act, message_len);
    free(message_act);
    return 0;
}