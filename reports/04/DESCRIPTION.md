# Bug Report

## Name

Memory Leak

## Description

'non_compressed_buf' is not freed after malloc()

## Affected Lines

In pngparser.c:1010

## Expected vs Observed

memory is allocated to 'non_compressed_buf' in pngparser.c:981
But there are no free.

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_store_png_rgba ../reports/04/leak-d64c7edeb83c942e970fe783495b837b89068ef8

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the free statement to free 'non_compressed_buf'

free(non_compressed_buf);