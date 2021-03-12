#ifndef INVERT_H
#define INVERT_H
namespace  mySpace{
    void invert(bool* arr, int size) {
        for (int i = 0; i < size; ++i) {
            arr[i] = !arr[i];
        }
    }
}
#endif // INVERT_H
