#ifndef CONE_H
#define CONE_H

#include <iostream>

struct COne {
    COne() {
        f = 0;
        ps = nullptr;
    }
    COne(float a, char *b) : f(a) {
        int size = 0;
        while (*(b + size) != '\0') ++size;
        char *buff = new char[size + 1];
        for (int i{}; *(b + i) != '\0'; ++i) buff[i] = b[i];
        buff[size] = '\0';
        ps = buff;
    }
    COne(const COne &copy) {
        int size = 0;
        while (*(copy.ps + size) != '\0') ++size;
        char *buff = new char[size + 1];
        for (int i{}; *(copy.ps + i) != '\0'; ++i) buff[i] = copy.ps[i];
        buff[size] = '\0';
        delete[] ps;
        ps = buff;
        f = copy.f;
    }

    ~COne() { delete[] ps; }

    COne &operator=(const COne &a) {
        int size = 0;
        while (*(a.ps + size) != '\0') ++size;
        char *buff = new char[size + 1];
        for (int i{}; *(a.ps + i) != '\0'; ++i) buff[i] = a.ps[i];
        buff[size] = '\0';
        delete[] ps;
        ps = buff;
        f = a.f;
        return *this;
    }

    void print() {
        std::cout << "  Cone:\n";
        if (ps) 
            std::cout << "float = " << f << "\nchar * = " << ps << "\n\n";
        else 
            std::cout << "float = " << f << "\nchar * = " << (void *)ps << "\n\n";
    }

    float get_f() { return f; }
    char *get_ch() { return ps; }

   private:
    float f;
    char *ps;
};
#endif
