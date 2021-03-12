#ifndef SHIFTARRAY_H
#define SHIFTARRAY_H
#include <iostream>
namespace  mySpace{
    void shiftArray(int* arr, int size, int shift) {
        int temp[size];
        for(int i = 0; i < size; ++i) {
            temp[i] = arr[i];
        }
        int t;

        if(shift > 0) {
            if (shift
                    > size) shift -= size;
            t = size - shift;
        } else if(shift < 0) {
            if (std::abs(shift) > size) shift += size;
            t = std::abs(shift);
        } else {
            return;
        }

        for(int i = 0; i < size; ++i) {
            if(t == size) t = 0;
            arr[i] = temp[t];
            t++;
        }
    }
}
#endif // SHIFTARRAY_H
