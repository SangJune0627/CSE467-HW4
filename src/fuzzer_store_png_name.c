#include "pngparser.h"
#include <stdio.h>
#include <assert.h>

struct image generate_rand_img()
{
    struct image img;
    do
    {
        img.size_x = rand() % 256;
    } while (img.size_x == 0);
    do
    {
        img.size_y = rand() % 256;
    } while (img.size_y == 0);
    img.px = malloc(img.size_x * img.size_y * sizeof(struct pixel));
    if (img.px == NULL)
        assert(0 && "Rerun test, malloc failed");
    for (long i = 0; i < img.size_y * img.size_x; i++)
    {
        img.px[i].red = rand();
        img.px[i].green = rand();
        img.px[i].blue = rand();
        img.px[i].alpha = rand();
    }

    return img;
}

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    struct image img = generate_rand_img();

    if (Data && Size < 255 && Size > 0)
        store_png((const char *)Data, &img, NULL, 0);
    free(img.px);

    return 0;
}
