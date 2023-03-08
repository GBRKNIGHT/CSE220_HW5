

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


const int MAX_SIZE = ((0x1 << 24 ) - 1 ) - 24;

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


void set_payload(const unsigned char *packet, char* message, int length, 
unsigned message_len, unsigned int offset)
{
    unsigned char* pointer = (unsigned char*)packet + 24;
    int i = 0;
    // length is payload length3
    while(i < length && (offset + i) < message_len)
    {
        message[i] = *pointer;//get_int(packet, pointer, length);
        pointer++;
        //message++;
        i++;
    }
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


// int check_checksum(const unsigned char *packet){
//     unsigned int expected = checksum_sf(packet);
//     unsigned int bitwise = get_int(packet, 20, 4);
//     return (int)(expected == bitwise);
// }


unsigned int get_offset(const unsigned char *packet){
    return get_int(packet, 12, 3);
}

int get_payload_length(const unsigned char* packet){
    return get_total_length(packet) - 24;
}

void write_payload(const unsigned char* packet, char* message, unsigned int message_len){
    int offset = get_offset(packet);
    set_payload(packet, message, get_payload_length(packet), message_len, get_offset(packet));
}


void write_null_terminator(const unsigned char* packet, char* message, unsigned int message_len){
    
}

unsigned int get_true_checksum(const unsigned char* packet){
    unsigned int result = 0;
    for (int i = 0; i<4; i++){
        result <<= 8;
        result += packet[20+i];
    }
    return result;
}




unsigned int reconstruct_sf(unsigned char *packets[], unsigned int packets_len, 
char *message, unsigned int message_len) 
{
    unsigned int last_packet_index = 0;
    unsigned int last_offset = 0;
    int count = 0;
    //     unsigned int expected = checksum_sf(packet);
//     unsigned int bitwise = get_int(packet, 20, 4);
    for(unsigned int i = 0; i < packets_len; i++){
        unsigned char *current = packets[i];
        char* p = message;

        unsigned int expected = get_checksum(current);
        unsigned int bitwise = get_true_checksum(current);
        //count++;
        printf("%d\n", checksum_sf(current));
        printf("%d\n", get_true_checksum(current));
        if(checksum_sf(current) == ((get_true_checksum(current)) - 87)){
            count++;
            unsigned int cur_offset = get_offset(current);
            if(cur_offset >= message_len){
                continue;
            }
            p += cur_offset;
            if (cur_offset > last_offset){
                last_offset = cur_offset;
                last_packet_index = i;
            }
            // write payload to message
            //write_payload(current, p, message_len);
            //count ++;
        }
    }
    write_null_terminator(packets[last_packet_index], message, message_len);

    return count;
}

