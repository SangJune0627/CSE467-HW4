# Bug Report

## Name

Memory Leak

## Description

'non_compressed_buf' is not freed after malloc()

## Affected Lines

In pngparser.c:1066

## Expected vs Observed

memory is allocated to 'non_compressed_buf' in pngparser.c:1036
But there are no free.

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_store_png_palette ../reports/06/leak-ccf8eaea91c36f7c92fc996c3f76a14417dfa6c0

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the free statement to free 'non_compressed_buf' in store_idat_plte

free(non_compressed_buf);