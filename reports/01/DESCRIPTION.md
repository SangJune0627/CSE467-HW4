# Bug Report

## Name

Null Pointer Dereference

## Description

load_png function in pngparser.c returns 1 when error and 0 when success.
In the case of success, the program is terminated and the loaded png file is not free, causing a memory leak.
When an error occurs, a memory bug such as a Null Pointer Dereference is caused by referring to a png that is not loaded completely.

## Affected Lines

In size.c:22

## Expected vs Observed

Given the code structure of size.c, the load_png function must return 1 when loaded successfully.
But on the contrary, when png load is successful, it returns 0.

## Steps to Reproduce

1. Run the program with below command

## Command

./size ../reports/00/id000003,sig06,src000000,opflip1,pos11

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

  if (!output)
    return 1;