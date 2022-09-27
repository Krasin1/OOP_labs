#include "CThree.hpp"

struct CFour : public CThree{
    explicit CFour() : h(0) {}

    explicit CFour(int a) : h(a) {}

    explicit CFour(const CFour &a) { h = a.h; }

    CFour &operator=(const CFour &a) {
        h = a.h;
        return *this;
    }

    CFour &operator=(int a) {
        h = a;
        return *this;
    }

    ~CFour() {}

    int get_int() { return h; }

    void print() { std::cout << "int = " << h << '\n'; }

   private:
    int h;
};
