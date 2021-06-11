#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    struct image *test_img;

    FILE *input = fopen("load_name.png", "w");

    int temp[5] = {1, 2, 3, 4, 5};
    fwrite(temp, 5, 1, input);
    fclose(input);

    if (Data && Size < 255 && Size > 0)
    {
        if (load_png((const char *)Data, &test_img) == 0)
            free(test_img);
    }

    return 0;
}