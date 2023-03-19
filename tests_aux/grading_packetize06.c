#include <stdlib.h>
#include "wolfpack.h"

int main() {
    char msg[] = "If Java had true garbage collection, most programs would delete themselves upon execution. *Robert Sewell*";
    unsigned char *packets_act[50];
    unsigned int packets_len = 50;
    unsigned int max_payload = 25;
    unsigned long src_addr =  0x6316322456L;
    unsigned long dest_addr = 0x80032cdabfL;
    unsigned short encryption = 11794;
    unsigned int num_packets_exp = 5;
    packetize_sf(msg, packets_act, packets_len, max_payload, src_addr, dest_addr, encryption);
    for (unsigned int i = 0; i < num_packets_exp; i++)
        free(packets_act[i]);
}