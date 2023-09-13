#include <iostream>
#include <cstdlib> // Include for malloc and free

#ifndef CUR_TYPE
#define CUR_TYPE int 
#endif

using namespace std;

class collection {
    CUR_TYPE* arr;
    int max;
    int size;

public:
    collection(int max);
    ~collection();

    CUR_TYPE insert(CUR_TYPE data);
    void show();
    CUR_TYPE append(CUR_TYPE data, int index);

    int isempty();

    collection operator+(const collection& other) const;
};

collection::collection(int arrsize) {
    if (arrsize > 0) {
        arr = (CUR_TYPE*)malloc(arrsize * sizeof(CUR_TYPE));
        if (arr) {
            max = arrsize;
            size = 0;
        }
    }
    else {
        arr = nullptr;
        max = 0;
        size = 0;
    }
}

collection::~collection() {
    cout << "inside destructor\n";
    free(arr);
}

CUR_TYPE collection::insert(CUR_TYPE data) {
    if (size < max) {
        *(arr + size) = data;
        size += 1;
        return 0;
    }
    return 1;
}

void collection::show() {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

CUR_TYPE collection::append(CUR_TYPE data, int index) {
    if (index >= 0 && index < size && size < max) {
        *(arr + index) = data;
        return 0;
    }
    return 1;
}

int main() {
    collection myc(10);
    myc.insert(1);
    myc.insert(2);
    myc.insert(3);
    myc.insert(4);
    myc.show();

    return 0;
}
