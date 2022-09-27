#include "COne.hpp"
#include "CTwo.hpp"

int main() {
    char lol[] = "Hello";
    char kek[] = "kek";
    COne a(1.2, lol);
    COne b(3.32, kek);
    a.print();
    b.print();
    
    CTwo c(22.2, &a);
    CTwo d(0.009, &b);
    c.print();
    d.print();
    c = d;
    c.print();
    return 0;
}
