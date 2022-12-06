#include "complex.hpp"
#include "stek.hpp"

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
    try {
        temp = f / hehe;
        temp.print();
    } catch (const std::exception &err) {
        std::cout << "exception catched!!!\n";
    }
    std::cout << "f / d = "; 
    temp = f / d;
    temp.print();
    std::cout << "f * d = ";
    temp = f * d;
    temp.print();

    std::cout << "-------------------------------------------------\n";
    stek<int> one{99238};
    one.push_back(2);
    one.push_back(3);
    one.push_back(4);
    one.push_up(222);
    one.print();
    std::cout << one.pop_up() << '\n';
    one.print();
    std::cout << "-----------------------------------------\n";
    stek<double> two;
    try {
        std::cout << two.pop_back() << '\n';
    } catch (const std::exception &err) {
        std::cout << "exception catched!!!\n";
    }
    std::cout << "-----------------------------------------\n";
    stek<int> three ;
    three.push_up(92);
    three = one;
    three.print();
    std::cout << "-----------------------------------------\n";
    stek<int> four{three};
    four.print();
    std::cout << "-----------------------------------------\n";
    try {
        
        four.push_up(true);
        four.print();
    } catch(const std::exception &err) {
        std::cout << "exception catched!!!\n";
    }
    std::cout << "-----------------------------------------\n";
    try {
        stek<int> five{'3'};
    } catch (const std::exception &err) {
        std::cout << "exception catched!!!\n";
    }
    return 0;
}
