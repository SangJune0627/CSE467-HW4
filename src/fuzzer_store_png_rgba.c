#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{

    if (Data && Size > 4 + sizeof(struct pixel))
    {
        struct image *img = malloc(sizeof(struct image));
        img->size_x = (uint16_t)Data[0];
        img->size_y = (uint16_t)Data[2];
        img->px = malloc(img->size_x * img->size_y);
        img->px = (struct pixel *)Data;

        store_png("store_rgba.png", img, NULL, 0);
        free(img->px);
        free(img);
    }
    return 0;
}