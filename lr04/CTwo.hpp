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
        *temp = *a.p;
        p = temp;
    }

    virtual ~CTwo() { delete p; }

    CTwo &operator=(const CTwo &a) {
        d = a.d;
        COne *temp = new COne;
        *temp = *a.p;
        delete p;
        p = temp;
        return *this;
    }

    double get_d() { return d; }

    COne *get_COne() { return p; }

    virtual void print() {
        std::cout << "  CTwo\ndouble = " << d << "\n";
        p->print();
        std::cout << '\n';
    }

   private:
    double d;
    COne *p;
};

#endif
