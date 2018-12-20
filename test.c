#include "bmp_utils.h"

int main(int argc, char* argv[]) {
    if (argc < 2) return 0;
    analyse_bmp_file(argv[1]);
    return 0;
}
