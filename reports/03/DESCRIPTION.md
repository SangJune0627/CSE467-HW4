# Bug Report

## Name

Null Pointer Dereference

## Description

There are no checks for img or img->px to be null in store_png()
So, error occurs in many part of this.

## Affected Lines

In pngparser.c:1133

## Expected vs Observed

When img or img->px is null, errors occur in many part of store_png()
Because there are no checks whether they are null or not

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_store_png_rgba ../reports/03/crash-da39a3ee5e6b4b0d3255bfef95601890afd80709

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the if statement to check whether 'img' or 'img->px' is null or not

if (!img || !img->px)
    return 1;