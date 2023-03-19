#include <stdlib.h>
#include "wolfpack.h"

int main() {
 char *packets[] = {
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\x57\x06\x1f\x00\x00\x35\xce\x44\x07\x4b\x74\x68\x61\x74\x20\x74\x68\x65\x72\x65\x20\x61\x72\x65\x20\x6f\x62\x76\x69\x6f\x75\x73\x6c\x79\x20\x6e\x6f\x20\x64",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\x74\x06\x1f\x00\x00\x35\xce\x44\x07\x68\x65\x66\x69\x63\x69\x65\x6e\x63\x69\x65\x73\x2e\x20\x41\x6e\x64\x20\x74\x68\x65\x20\x6f\x74\x68\x65\x72\x20\x77\x61",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\x00\x06\x1f\x00\x00\x35\xce\x44\x06\xf4\x54\x68\x65\x72\x65\x20\x61\x72\x65\x20\x74\x77\x6f\x20\x77\x61\x79\x73\x20\x6f\x66\x20\x63\x6f\x6e\x73\x74\x72\x75",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\x91\x06\x1f\x00\x00\x35\xce\x44\x07\x85\x79\x20\x69\x73\x20\x74\x6f\x20\x6d\x61\x6b\x65\x20\x69\x74\x20\x73\x6f\x20\x63\x6f\x6d\x70\x6c\x69\x63\x61\x74\x65",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\xae\x06\x1f\x00\x00\x35\xce\x44\x07\xa2\x64\x20\x74\x68\x61\x74\x20\x74\x68\x65\x72\x65\x20\x61\x72\x65\x20\x6e\x6f\x20\x6f\x62\x76\x69\x6f\x75\x73\x20\x64",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\xcb\x06\x1f\x00\x00\x33\xce\x44\x07\xbd\x65\x66\x69\x63\x69\x65\x6e\x63\x69\x65\x73\x2e\x20\x28\x43\x2e\x41\x2e\x52\x2e\x20\x48\x6f\x61\x72\x65\x29",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\x1d\x06\x1f\x00\x00\x35\xce\x44\x07\x11\x63\x74\x69\x6e\x67\x20\x61\x20\x73\x6f\x66\x74\x77\x61\x72\x65\x20\x64\x65\x73\x69\x67\x6e\x2e\x20\x20\x4f\x6e\x65",
        "\xab\xcd\x32\x24\x56\x80\x01\x11\xda\xbf\x20\x40\x00\x00\x3a\x06\x1f\x00\x00\x35\xce\x44\x07\x2e\x20\x77\x61\x79\x20\x69\x73\x20\x74\x6f\x20\x6d\x61\x6b\x65\x20\x69\x74\x20\x73\x6f\x20\x73\x69\x6d\x70\x6c\x65\x20",
    };
    unsigned int packets_len = 8;
    unsigned int message_len = 300;  // original message has 230 characters
    char *message_act = malloc(message_len*sizeof(char));

    // fill memory with "random" garbage
    srand(4321);
    for (unsigned int i = 0; i < message_len; i++)
        message_act[i] = (char)(rand() % 90 + 35);

    reconstruct_sf((unsigned char **)packets, packets_len, message_act, message_len);
    free(message_act);
    return 0;
}