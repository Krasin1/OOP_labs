#include "CFour.hpp"

void printAll(CTwo** a, int n) {
    for (int i{}; i < n; ++i) {
        a[i]->print();
    }
}

int main() {
    char str[] = "Hello";
    COne temp {(float)3.14, str};
    CTwo a{6.28, &temp};
    CThree b{a, 8};
    CFour c{b, 10};
    CTwo* array[3]{&a, &b, &c};
    printAll(array, 3);
    return 0;
}
