# Bug Report

## Name

Double free

## Description

In read_png_chunk(), chunk->chunk_data is freed.
But it is also freed in error section of load_png()

## Affected Lines

In pngparser.c: 1141

## Expected vs Observed

We expect chunk->chunk_data to freed in load_png()
But it is freed twice due to read_png_chunk()

## Steps to Reproduce

1. Run the program with below command

## Command

./fuzzer_load_png ../reports/02/crash-d45c06e57b466820665e0d2557bc76d2a26d9c49

## Proof-of-Concept Input (if needed)

It is difficult to define the specific PNG that causes this bug.

## Suggested Fix Description

Delete free statement in read_png_chunk()