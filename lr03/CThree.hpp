#include "/home/xxx/uni/2/oop/lr02/CTwo.hpp"

struct CThree : public CTwo {
    explicit CThree() : var(0) {}

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

    void print() { std::cout << "int = " << var << '\n'; }

   private:
    int var;
};
