#include "5.hpp"
#include "15.hpp"

int main() {
    char text[] = "Hello!";
    String a;
    a.read();
    std::cout << "Length = " << a.Length() << '\n';
    std::cout << "Substr(3, 6) = ";
    String b = a.Substr(3, 6);
    b.print();
    std::cout << "Remove(2, 2) = ";
    a.Remove(2, 2);
    a.print();
    std::cout << "Insert(\"Hello!\", 4) = ";
    a.Insert(text, 4);
    a.print();
    std::cout << "Trim = ";
    a.trim();
    a.print();
    std::cout << "Copy(\"Hello!\") = ";
    a.Copy(text);
    a.print();

    String c(a);
    c.print();

    std::puts("");
    std::cout << "---------------------------------------------------------------------------------------\n";
    std::puts("");

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
