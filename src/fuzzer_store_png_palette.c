#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{

    if (Data && Size > sizeof(struct pixel) * 2)
    {
        struct image *img = malloc(sizeof(struct image));
        img->size_x = (uint16_t)Data[0];
        img->size_y = (uint16_t)Data[2];

        struct pixel palette[2];

        palette[0].red = (uint8_t)Data[0];
        palette[0].green = (uint8_t)Data[1];
        palette[0].blue = (uint8_t)Data[2];
        palette[0].alpha = (uint8_t)Data[3];

        palette[1].red = (uint8_t)Data[4];
        palette[1].green = (uint8_t)Data[5];
        palette[1].blue = (uint8_t)Data[6];
        palette[1].alpha = (uint8_t)Data[7];

        img->px = malloc(sizeof(struct pixel) * img->size_x * img->size_y);
        for (size_t i = 0; i < img->size_x * img->size_y; i++)
        {
            int color = i % 2;
            img->px[i].red = palette[color].red;
            img->px[i].green = palette[color].green;
            img->px[i].blue = palette[color].blue;
            img->px[i].alpha = palette[color].alpha;
        }
        store_png("store_palette.png", NULL, palette, 2);
        store_png("store_palette.png", img, palette, 2);
        free(img->px);
        free(img);
    }
    return 0;
}