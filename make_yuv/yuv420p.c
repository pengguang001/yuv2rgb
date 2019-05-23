#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "fill_yuvdata.h"
#include "file_utils.h"

int main(int argc, char* argv[])
{
    if (argc < 4) {
        printf("usage: %s <w> <h> <yuv_file>\n", argv[0]);
        return 0;
    }

    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    const char* filename = argv[3];

    int size = w*h*3/2;
    unsigned char* buffer = (unsigned char*)malloc(size);
    fill_yuv_yuv420_2(buffer, w, h);

    write_file(filename, (char*)buffer, size);
    free(buffer);

    printf("%s\n", filename);

    return 0;
}
