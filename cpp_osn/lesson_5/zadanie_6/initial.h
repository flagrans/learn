#ifndef INITIAL_H
#define INITIAL_H
namespace  mySpace{
    void initial(int* arr, int size) {
        int init_num = 1;
        for(int i = 0; i < size; ++i) {
            arr[i] = init_num;
            init_num += 3;
        }
    }
}
#endif // INITIAL_H
