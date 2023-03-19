#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char msg[] = "There are two ways to write error-free programs; only the third one works. - Alan J. Perlis";
    unsigned char *packets_act[8];
    unsigned int packets_len = 8;
    unsigned int max_payload = 12;
    unsigned long src_addr =  0x38918a2731L;
    unsigned long dest_addr = 0x1e82cab029L;
    unsigned short encryption = 799;
    unsigned int num_packets_exp = 8;
    packetize_sf(msg, packets_act, packets_len, max_payload, src_addr, dest_addr, encryption);
    for (unsigned int i = 0; i < num_packets_exp; i++)
        free(packets_act[i]);
}