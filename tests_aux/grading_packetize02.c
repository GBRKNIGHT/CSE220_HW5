#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char msg[] = "C is quirky, flawed, and an enormous success. (Dennis Ritchie)";
    unsigned char *packets_act[1];
    unsigned int packets_len = 1;
    unsigned int max_payload = 60;
    unsigned long src_addr =  0x0091efc760L;
    unsigned long dest_addr = 0x821ecab029L;
    unsigned short encryption = 220;
    unsigned int num_packets_exp = 1;
    packetize_sf(msg, packets_act, packets_len, max_payload, src_addr, dest_addr, encryption);
    for (unsigned int i = 0; i < num_packets_exp; i++)
        free(packets_act[i]);
}