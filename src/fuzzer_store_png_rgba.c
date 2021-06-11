#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    store_png("store_rgba_NULL.png", NULL, NULL, 0);

    if (Data && Size > sizeof(struct pixel))
    {
        struct image *img = malloc(sizeof(struct image));
        img->size_x = 1;
        img->size_y = Size / sizeof(struct pixel);
        img->px = malloc(sizeof(struct pixel) * img->size_x * img->size_y);
        for (size_t i = 0; i < img->size_x * img->size_y; i++)
        {
            img->px[i].red = (uint8_t)Data[4 * i];
            img->px[i].green = (uint8_t)Data[4 * i + 1];
            img->px[i].blue = (uint8_t)Data[4 * i + 2];
            img->px[i].alpha = (uint8_t)Data[4 * i + 3];
        }

        store_png("store_rgba.png", img, NULL, 0);
        free(img->px);
        free(img);
    }
    return 0;
}