#include <iostream>
#include "CThree.hpp"

int main() {
    CThree * bruh = new CThree(88);
    bruh->print();
    *bruh = 99;
    std::cout << bruh->get_int() << '\n';

    std::cout << bruh->get_COne()->get_f() << '\n';

    ((CTwo *)bruh)->print();
    
    delete bruh;
    return 0;
}
