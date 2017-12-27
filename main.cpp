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


void printArray(bytePtr array, size_t arraySize) {
    std::string str;
    printf("%p: \n", (void*)array);
    for(size_t i = 0; i < arraySize; i++) {
        str += ' ' + std::to_string(array[i]);
    }
    printf("%s\n", str.c_str());
}

/**
 * rotate image - faster solution
 * @param data - original image to rotate
 * @param length - original image length, in pisels (bytes)
 * @param width - image width
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

int main() {
    //2d array = 3 x 4
    size_t arraySize = 12;
    size_t width = 3;

    bytePtr test = new byte[arraySize];
    for(size_t i = 0; i < arraySize; i++) {
        test[i] = i * 2;
    }

    bytePtr result = rotate90cw(test, arraySize, width);
    printArray(test, arraySize);
    printArray(result, arraySize);

    return 0;
}
