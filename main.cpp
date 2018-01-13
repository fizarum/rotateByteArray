/*
 * File:   main.cpp
 * Author: mykhailo.zhyliakov
 *
 * Created on December 26, 2017, 12:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string>

typedef unsigned char byte;
typedef byte * bytePtr;


void printArray(bytePtr array, size_t arraySize, bool printAdress = false) {
    std::string str;
    if(printAdress) {
        printf(" %p: ", (void*)array);
    }
    printf("\n");
    for(size_t i = 0; i < arraySize; i++) {
        str += ' ' + std::to_string(array[i]);
    }
    printf("%s\n", str.c_str());
}

void printArray2D(bytePtr array, size_t arraySize, size_t width, bool printAdress = false) {
    std::string str;
    if(printAdress) {
        printf(" %p: \n", (void*)array);
    }
    printf("\n");
    size_t rows = arraySize / width;

    for(size_t i = 0; i < rows; ++i) {
        for(size_t index = 0; index < width; ++index) {
           str += ' ' + std::to_string(array[i * width + index]);
        }
        printf("%s\n", str.c_str());
        str = "";
    }
}

/**
 * rotate image - on 90 deg (cw direction)
 * @param data - original image to rotate
 * @param length - original image length, in pixels (bytes)
 * @param width - image width
 * @return rotated image
 */
bytePtr rotate90cw(bytePtr data, size_t length, size_t width) {
    bytePtr result = new byte[length];
    size_t incr = 0;
    for(long long int shift = width; shift >= 0; --shift) {
        for(long long int index = length - shift; index >= 0 && incr < length; index -= width) {
            result[incr] = data[index];
            incr++;
        }
    }
    return result;
}

/**
 * rotate image on 90 deg (ccw direction) or 270 deg
 * @param data - original image to rotate
 * @param length - original image length, in pixels (bytes)
 * @param width - image width
 * @return rotated image
 * */
bytePtr rotate270cw(bytePtr data, size_t length, size_t width) {
    bytePtr result = new byte[length];
    size_t incr = 0;
    for(long long int shift = width - 1; shift >= 0; --shift) {
        for(long long int index = shift; index <= length && incr < length; index += width) {
            result[incr] = data[index];
            incr++;
        }
    }
    return result;
}

/**
 * rotate image on 180 deg
 * @param data - original image to rotate
 * @param length - original image length, in pixels (bytes)
 * @return rotated image
 * */
bytePtr rotate180(bytePtr data, size_t length) {
    bytePtr result = new byte[length];
    size_t i = 0;
    for(long long int index = length - 1; index >= 0; --index, ++i) {
        result[i] = data[index];
    }
    return result;
}

int main() {
    //2d array = 3 x 4
    size_t arraySize = 12;
    size_t width = 3;
    size_t height = arraySize / width;

    bytePtr test = new byte[arraySize];
    for(size_t i = 0; i < arraySize; i++) {
        test[i] = i * 2;
    }

    printf("\noriginal 2d (width :%d) array: ", width);
    printArray2D(test, arraySize, width);

    printf("\nflat view: ", width);
    printArray(test, arraySize);

    printf("\n90 deg test: ");
    bytePtr result = rotate90cw(test, arraySize, width);
    printArray(result, arraySize);

    printf("\n180 deg test: ");
    result = rotate180(test, arraySize);
    printArray(result, arraySize);

    printf("\n270 deg test: ");
    result = rotate270cw(test, arraySize, width);
    printArray(result, arraySize);
    printArray2D(result, arraySize, height);
    return 0;
}
