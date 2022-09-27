#include "CTwo.hpp"

struct CThree : public CTwo {
    explicit CThree() = default;

    explicit CThree(int a) : var(a) {}

    explicit CThree(const CThree &a) { var = a.var; }

    CThree &operator=(const CThree &a) {
        var = a.var;
        return *this;
    }

    CThree &operator=(int a) {
        var = a;
        return *this;
    }

    ~CThree() {}

    int get_int() { return var; }

    virtual void print() { std::cout << "int = " << var << '\n'; }

   private:
    int var;
};
