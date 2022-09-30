#include "15.hpp"

int main() {
    Complex<double> f(1, 2);
    Complex<double> d(3, 4);
    Complex<double> hehe(0, 0);
    Complex<double> temp;
    std::cout << "f = ";
    f.print();
    std::cout << "d = ";
    d.print();
    std::cout << "zero = ";
    hehe.print();
    std::puts("");
    std::cout << "f + d = ";
    temp = f + d;
    temp.print();
    std::cout << "f - d = ";
    temp = f - d;
    temp.print();
    std::cout << "f / zero = ";
    temp = f / hehe;
    temp.print();
    std::cout << "f / d = "; 
    temp = f / d;
    temp.print();
    std::cout << "f * d = ";
    temp = f * d;
    temp.print();
    return 0;
}
