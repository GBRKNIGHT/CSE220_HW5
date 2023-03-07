

/**
 * Name: Yichen Li
 * SBU_ID: 112946979
 * CSE_220_R01
 * 
*/


#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#include "wolfpack.h"


// General print function to print data fields, e.g. source address, destination address...
void print_bytes(const unsigned char *packet, int start, int length){
    unsigned char* p = (unsigned char*)packet + start;
    for(int i = 0; i < length; i++){
        printf("%02x", *p);
        p++;
    }
    printf("\n");
    
}


int get_total_length(const unsigned char *packet){
    int result = 0;
    unsigned char* p = (unsigned char*)packet + 17;
    for(int i = 0; i < 3; i++){
        result = result << 8;
        result = result + *p;
        p++;
    }
    return result;
}

unsigned int get_int(const unsigned char* packet, int start, int end){
    unsigned int result = 0;
    unsigned char* p = (unsigned char*)packet + start;
    for(int i = 0; i < end; i++){
        result = result << 8;
        result = result + *p;
        p++;
    }
    return result;
}

unsigned int get_checksum(const unsigned char *packet){
    unsigned int result = 0;

    result += get_int(packet, 0, 5);
    result += get_int(packet, 5, 5);
    result += get_int(packet, 10, 1);
    result += get_int(packet, 11, 1);
    result += get_int(packet, 12, 3);
    result += get_int(packet, 15, 2);
    result += get_int(packet, 17, 3);
    
    return result;
}

// Print function to print the payloads. 
void print_to_end(const unsigned char *packet, int start){
    unsigned char* p = (unsigned char*)packet + start;
   
    // printf("%d\n", get_total_length(packet));

    int end = get_total_length(packet) - 24;
    for(int i = 0; i < end; i++){
        printf("%c", *p);
        p++;
    }


    printf("\n");
}

// Print function. 
void print_packet_sf(const unsigned char *packet) {
    const unsigned char* p = (unsigned char*)packet;
    print_bytes(p, 0, 5);
    print_bytes(p, 5, 5);
    print_bytes(p, 10, 1);
    print_bytes(p, 11, 1);
    print_bytes(p, 12, 3);
    print_bytes(p, 15, 2);
    print_bytes(p, 17, 3);
    print_bytes(p, 20, 4);
    print_to_end(p, 24);
    // printf("\n");
}

unsigned int packetize_sf(const char *message, unsigned char *packets[], unsigned int packets_len, unsigned int max_payload,
    unsigned long src_addr, unsigned long dest_addr, unsigned short flags) {
    return 0;
}

unsigned int checksum_sf(const unsigned char *packet) {
    //unsigned char* p = (unsigned char*) packet;
    unsigned int checksum = get_checksum(packet);
    return checksum;
}

unsigned int reconstruct_sf(unsigned char *packets[], unsigned int packets_len, char *message, unsigned int message_len) {
    return 0;
}

