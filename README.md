# RGB to Grayscale Medical Image Conversion

A foundational C script that converts a 269x187 raw RGB dermatological image into a standard 8-bit grayscale format.

## Key Technologies
* C (Standard Library)
* Custom `dip.h` and `dipcopy.h` dynamic memory libraries

## Methodology
The algorithm parses the interleaved RGB raw data and applies an average-based color space transformation. For every pixel, the Red, Green, and Blue intensities are extracted and averaged using the formula: $Output = \frac{R + G + B}{3}$. The result is cast back to an unsigned character, producing a single-channel intensity matrix representing the structural details of the image without color data.
