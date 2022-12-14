#ifndef CTWO_H
#define CTWO_H

#include "COne.hpp"

struct CTwo {
    CTwo() {
        d = 0.0;
        p = new COne();
    }

    CTwo(double a, COne *b) {
        d = a;
        COne *temp = new COne;
        *temp = *b;
        p = temp;
    }

    CTwo(const CTwo &a) {
        d = a.d;
        COne *temp = new COne;
        delete p;
        *temp = *a.p;
        p = temp;
    }

    ~CTwo() { delete p; }

    CTwo & operator = (const CTwo & a) {
        d = a.d;
        COne *temp = new COne;
        *temp = *a.p;
        delete p;
        p = temp;
        return *this;
    }

    double get_d() { return d; }

    COne * get_COne() { return p; }

    void print() { std::cout << "double = " << d << "\nCOne * = " << (void *)p << '\n'; }

   private:
    double d;
    COne *p;
};
#endif
