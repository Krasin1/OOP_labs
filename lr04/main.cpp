#include "CFour.hpp"

void printAll(CTwo** a, int n) {
    for (int i{}; i < n; ++i) {
        a[i]->print();
    }
}

int main() {
    CTwo a{};
    CThree b{};
    CFour c{};
    CTwo* array[3]{&a, &b, &c};
    printAll(array, 3);
    return 0;
}
