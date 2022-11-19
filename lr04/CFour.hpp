#ifndef CFOUR_HPP
#define CFOUR_HPP

#include "CThree.hpp"

struct CFour : public CThree{
    explicit CFour() : h(0) {}

    explicit CFour(int a) : h(a) {}

    explicit CFour(const CFour &a) : CThree(a), h(a.h) {}

    explicit CFour(const CThree &a, int b) : CThree(a) , h(b) {}

    CFour &operator=(const CFour &a) {
        h = a.h;
        return *this;
    }

    CFour &operator=(int a) {
        h = a;
        return *this;
    }

    virtual ~CFour() {}

    virtual int get_int() { return h; }

    virtual void print() {
        std::cout << "  CFour\nint = " << h << '\n'; 
        CThree::print();
        std::cout << '\n';
    }

   private:
    int h;
};

#endif
