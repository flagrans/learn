#ifndef INVERT2_H
#define INVERT2_H
#include <iostream>
#include <cstdarg>
namespace  mySpace{
    void invert(int size, ...) {
        va_list vl;
        va_start(vl, size);
        for (int i = 0; i < size; ++i) {
            std::cout << !va_arg(vl, int) << " ";
        }
        std::cout << std::endl;
        va_end(vl);
    }
}
#endif // INVERT2_H
