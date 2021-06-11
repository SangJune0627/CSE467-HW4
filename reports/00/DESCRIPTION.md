# Bug Report

## Name

Null File Close

## Description

if program fail to open the file, 'input' become null and go to error section.

## Affected Lines

In pngparser.c: 785

## Expected vs Observed

if program fail to open the file, we expect the program to terminate.
But error occur in fclose because 'input' is null.

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_load_png_name ../reports/00/crash-2d5ff885f157e7321b0f50c06272f3da682963af

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Like below, add the if statement to check whether 'input' is null or not
  if (input)
    fclose(input);