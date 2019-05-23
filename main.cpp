#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "yuv2rgb.h"
#include "rgb2yuv.h"
#include "bmp_utils.h"

// yuv422p
int save_bmp422(const char* yuvfile, const char* bmpfile, int width, int height)
{
    FILE* fp1;
    int frameSize = 0; 
    int picSize = 0;
    int ret = 0;
    int i = 0;
    unsigned char* framePtr = NULL;
    unsigned char* rgbPtr = NULL;
    long rgbSize = 0;

    rgbSize = width * height * 3;
    frameSize = width * height;

    // yuv422p: w * h * 2
    // yuv420p: w * h * 3 / 2
    picSize   = frameSize * 2;;

    framePtr = (unsigned char *) malloc(sizeof(unsigned char) * picSize);
    if (framePtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(framePtr, '\0', picSize);

    rgbPtr = (unsigned char *) malloc(sizeof(unsigned char) * rgbSize);
    if (rgbPtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(rgbPtr, '\0', rgbSize);

    if ((fp1 = fopen(yuvfile, "rb")) == NULL )
    {
        printf("open yuv file failed.\n");
        return -1;
    }

    ret = (int)fread(framePtr, 1, picSize, fp1);

    //yuv422p_to_rgb24(framePtr, rgbPtr, width, height);
	yuv_to_rgb24(YUV422P, framePtr, rgbPtr, width, height);

    // rgb --> bgr
    swap_rgb(rgbPtr, rgbSize);

    // save file
    write_bmp_file(bmpfile, rgbPtr, width, height);

    fclose(fp1);


    free(framePtr);
    free(rgbPtr);

    printf("done.\n");
    return 0;
}

// yuv422sp
int save_bmp422sp(const char* yuvfile, const char* bmpfile, int width, int height)
{
    FILE* fp1;
    int frameSize = 0; 
    int picSize = 0;
    int ret = 0;
    int i = 0;
    unsigned char* framePtr = NULL;
    unsigned char* rgbPtr = NULL;
    long rgbSize = 0;

    rgbSize = width * height * 3;
    frameSize = width * height;

    // yuv422sp: w * h * 2
    // yuv420p: w * h * 3 / 2
    picSize   = frameSize * 2;;

    framePtr = (unsigned char *) malloc(sizeof(unsigned char) * picSize);
    if (framePtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(framePtr, '\0', picSize);

    rgbPtr = (unsigned char *) malloc(sizeof(unsigned char) * rgbSize);
    if (rgbPtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(rgbPtr, '\0', rgbSize);

    if ((fp1 = fopen(yuvfile, "rb")) == NULL )
    {
        printf("open yuv file failed.\n");
        return -1;
    }

    ret = (int)fread(framePtr, 1, picSize, fp1);

    //yuv422sp_to_rgb24(framePtr, rgbPtr, width, height);
	yuv_to_rgb24(YUV422SP, framePtr, rgbPtr, width, height);

    // rgb --> bgr
    swap_rgb(rgbPtr, rgbSize);

    // save file
    write_bmp_file(bmpfile, rgbPtr, width, height);

    fclose(fp1);


    free(framePtr);
    free(rgbPtr);

    printf("done.\n");
    return 0;
}

// yuv420
int save_bmp420(const char* yuvfile, const char* bmpfile, int width, int height)
{
    FILE* fp1;
    int frameSize = 0; 
    int picSize = 0;
    int ret = 0;
    unsigned char* framePtr = NULL;
    unsigned char* rgbPtr = NULL;
    long rgbSize = 0;

    rgbSize = width * height * 3;
    frameSize = width * height;

    // yuv422p: w * h * 2
    // yuv420p: w * h * 3 / 2
    picSize   = frameSize * 3 / 2;

    framePtr = (unsigned char *) malloc(sizeof(char) * picSize);
    if (framePtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(framePtr, '\0', picSize);

    rgbPtr = (unsigned char *) malloc(sizeof(unsigned char) * rgbSize);
    if (rgbPtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(rgbPtr, '\0', rgbSize);

    if ((fp1 = fopen(yuvfile, "rb")) == NULL )
    {
        printf("open yuv file failed.\n");
        return -1;
    }

    ret = (int)fread(framePtr, 1, picSize, fp1);

    //yuv420p_to_rgb24(framePtr, rgbPtr, width, height);
	//yuv_to_rgb24(YUV420P, framePtr, rgbPtr, width, height);
	yuv420_to_rgb24_2(framePtr, rgbPtr, width, height);

    // rgb --> bgr
    swap_rgb(rgbPtr, rgbSize);

    // save file
    write_bmp_file(bmpfile, rgbPtr, width, height);

    fclose(fp1);

    free(framePtr);
    free(rgbPtr);

    printf("done.\n");
    return 0;
}

int save_bmp420sp_nv21(const char* yuvfile, const char* bmpfile, int width, int height)
{
    FILE* fp1;
    int frameSize = 0; 
    int picSize = 0;
    int ret = 0;
    unsigned char* framePtr = NULL;
    unsigned char* rgbPtr = NULL;
    long rgbSize = 0;

    rgbSize = width * height * 3;
    frameSize = width * height;

    // yuv422p: w * h * 2
    // yuv420p: w * h * 3 / 2
    picSize   = frameSize * 3 / 2;

    framePtr = (unsigned char *) malloc(sizeof(char) * picSize);
    if (framePtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(framePtr, '\0', picSize);

    rgbPtr = (unsigned char *) malloc(sizeof(unsigned char) * rgbSize);
    if (rgbPtr == NULL)
    {
        printf("malloc failed.\n");
        return -1;
    }
    memset(rgbPtr, '\0', rgbSize);

    if ((fp1 = fopen(yuvfile, "rb")) == NULL )
    {
        printf("open yuv file failed.\n");
        return -1;
    }

    ret = (int)fread(framePtr, 1, picSize, fp1);

    //yuv420p_to_rgb24(framePtr, rgbPtr, width, height);
	//yuv_to_rgb24(YUV420P, framePtr, rgbPtr, width, height);
	yuv420sp_nv21_to_rgb24(framePtr, rgbPtr, width, height);

    // rgb --> bgr
    swap_rgb(rgbPtr, rgbSize);

    // save file
    write_bmp_file(bmpfile, rgbPtr, width, height);

    fclose(fp1);

    free(framePtr);
    free(rgbPtr);

    printf("done.\n");
    return 0;
}
// �Ӷ�֡YUV�ļ���ȡ��һ֡
void split_file(const char* src, const char* dst, int width, int height, int type)
{
    FILE* fp1;
    FILE* fp2;
    int file_size;

    fp1 = fopen(src, "rb");
    if (fp1 == NULL)
    {
        printf("open %s failed!\n", src);
        return;
    }
    fp2 = fopen(dst, "wb");
    if (fp2 == NULL)
    {
        printf("open %s failed!\n", dst);
        return;
    }

    if (type == 0)
    {
        file_size = width * height * 3 / 2;
    }
    else if (type == 1)
    {
        file_size = width * height * 2;
    }
    else
    {
        return;
    }

    unsigned char* buffer1 = (unsigned char*)malloc(file_size);

    if ( NULL == buffer1)
    {
        printf("malloc failed!\n");
        return;
    }

    int ret = 0;
    ret = (int)fread(buffer1, 1, file_size, fp1);
    if (ret != file_size)
    {
        printf("fread failed! real: %d ret: %d\n", file_size, ret);
        return;
    }

    ret = (int)fwrite(buffer1, 1, file_size, fp2);
    if (ret != file_size)
    {
        printf("fwrite failed! real: %d ret: %d\n", file_size, ret);
        return;
    }

    fclose(fp1);
    fclose(fp2);
}

void ConvertImage(const char* src, const char* dst, int width, int height)
{
    FILE* fp1;
    FILE* fp2;

    fp1 = fopen(src, "rb");
    if (fp1 == NULL)
    {
        printf("open %s failed!\n", src);
        return;
    }
    fp2 = fopen(dst, "wb");
    if (fp2 == NULL)
    {
        printf("open %s failed!\n", dst);
        return;
    }

    int file_size = width * height * 2;

    unsigned char* buffer1 = (unsigned char*)malloc(file_size);
    unsigned char* buffer2 = (unsigned char*)malloc(file_size);

    if ( NULL == buffer1 || NULL == buffer2)
    {
        printf("malloc failed!\n");
        return;
    }

    int ret = 0;
    ret = (int)fread(buffer1, 1, file_size, fp1);
    if (ret != file_size)
    {
        printf("fread failed! real: %d ret: %d\n", file_size, ret);
        return;
    }

    yuv422sp_to_yuv422p(buffer1, buffer2, width, height);

    //yuv420sp_to_yuv420p(buffer1, buffer2, width, height);

    ret = (int)fwrite(buffer2, 1, file_size, fp2);
    if (ret != file_size)
    {
        printf("fwrite failed! real: %d ret: %d\n", file_size, ret);
        return;
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char* argv[])
{
    if (argc < 5) {
        printf("usage: %s <w> <h> <yuv_file> <bmp_file>\n", argv[0]);
        return 0;
    }

    int w = atoi(argv[1]);
    int h = atoi(argv[2]);
    const char* yuv = argv[3];
    const char* bmp = argv[4];
    save_bmp420sp_nv21(yuv, bmp, w, h);

	return 0;
}
