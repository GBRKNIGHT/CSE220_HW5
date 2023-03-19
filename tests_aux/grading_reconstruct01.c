#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char *packets[] = {
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x32\x02\x14\x00\x00\x2b\x8e\x9f\x02\x4a\x79\x20\x67\x69\x76\x65\x20\x79\x6f\x75\x20\x61\x6e\x73\x77\x65\x72\x73\x2e",
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x00\x02\x14\x00\x00\x31\x8e\x9f\x02\x1e\x50\x61\x62\x6c\x6f\x20\x50\x69\x63\x61\x73\x73\x6f\x3a\x20\x43\x6f\x6d\x70\x75\x74\x65\x72\x73\x20",
        "\x63\xff\xf2\x24\x56\x00\x8e\xac\xda\xbf\x20\x40\x00\x00\x19\x02\x14\x00\x00\x31\x8e\x9f\x02\x37\x61\x72\x65\x20\x75\x73\x65\x6c\x65\x73\x73\x2e\x20\x54\x68\x65\x79\x20\x63\x61\x6e\x20\x6f\x6e\x6c",
    };
    unsigned int packets_len = 3;
    unsigned int message_len = 75;  
    char *message_act = malloc(message_len*sizeof(char));

    // fill memory with "random" garbage
    srand(4321);
    for (unsigned int i = 0; i < message_len; i++)
        message_act[i] = (char)(rand() % 90 + 35);
        
    reconstruct_sf((unsigned char **)packets, packets_len, message_act, message_len);
    free(message_act);
    return 0;
}