#ifndef CHECKBALANCE_H
#define CHECKBALANCE_H
namespace  mySpace{
    bool checkBalance(int* arr, int size) {
        if (size == 1) return false;
        for (int i = 0; i < (size-1); ++i) {
            int lv = 0, rv = 0;
            for (int k = 0; k <= i; ++k) {
                lv += arr[k];
            }
            for (int k = i + 1; k < size; ++k) {
                rv += arr[k];
            }
            if ( lv == rv) return true;
        }
        return false;
    }
}
#endif // CHECKBALANCE_H
