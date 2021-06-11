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

./fuzzer_store_png_rgba ../reports/05/leak-d64c7edeb83c942e970fe783495b837b89068ef8

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the free statement to free 'compressed_data_buf' in store_idat_rgb_alpha()

if (compressed_data_buf)
{
    free(compressed_data_buf);
}