# Bug Report

## Name

Null File Close

## Description

Program fail to open the file if there is a character which is not printable. 
Even though, we give 'w' option to fopen(), it return null.
So, 'input' become null and make some trouble in code as well as in fclose()

## Affected Lines

In pngparser.c: 1141

## Expected vs Observed

if program fail to open the file, we expect the program to terminate.
But error occur in many part of code because 'output' is null.

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_store_png_name ../reports/01/crash-638d54695c85e28e0d236a42c3bea63814835014

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the if statement to check whether 'output' is null or not

  if (!output)
    return 1;