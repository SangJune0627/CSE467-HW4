# Bug Report

## Name

Memory Leak

## Description

'compressed_data_buf' is not freed after realloc()

## Affected Lines

In pngparser.c:1010

## Expected vs Observed

memory is allocated to 'compressed_data_buf' in pngparser.c:939
But there are no free.

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_store_png_palette ../reports/07/leak-0ba96c1156b6cc9f823cff2ff9b7e031a526ad3a

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the free statement to free 'compressed_data_buf' in store_idat_plte()

if (compressed_data_buf)
{
    free(compressed_data_buf);
}