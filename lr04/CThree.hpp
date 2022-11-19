#ifndef CTHREE_HPP
#define CTHREE_HPP

#include "CTwo.hpp"

struct CThree : public CTwo {
    explicit CThree() : var() {};

    explicit CThree(int a) : var(a) {}

    explicit CThree(const CThree &a) :CTwo(a), var(a.var) {}

    explicit CThree(const CTwo &a, int b) : CTwo (a) , var(b) {}

    CThree &operator=(const CThree &a) {
        var = a.var;
        return *this;
    }

    CThree &operator=(int a) {
        var = a;
        return *this;
    }

    virtual ~CThree() {}      //деструктор

    int get_int() { return var; }

    virtual void print() { 
        std::cout << "  CThree:\nint = " << var << '\n'; 
        CTwo::print();   
        std::cout << '\n';
    }

   private:
    int var;
};

#endif
