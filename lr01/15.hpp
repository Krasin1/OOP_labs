#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <concepts>

template <std::floating_point T>
struct Complex {
    Complex() : re(0), im(0) {}
    Complex(T a, T b) : re(a), im(b) {}
    ~Complex() {}

    Complex operator*(const Complex &a) {
        Complex temp(re * a.re - im * a.im, re * a.im + im * a.re);
        return temp;
    }
    Complex operator/(const Complex &a) {
        if (a.re == 0 && a.im == 0) {
            std::cout << "На ноль делишь?\n";
            return *this;
        }
        Complex temp((re * a.re + im * a.im) / (a.re * a.re + a.im * a.im),
                     (im * a.re - re * a.im) / (a.re * a.re + a.im * a.im));

        return temp;
    }
    Complex operator-(const Complex &a) {
        Complex temp(re - a.re, im - a.im);
        return temp;
    }
    Complex operator+(const Complex &a) {
        Complex temp(re + a.re, im + a.im);
        return temp;
    }

    void operator=(const Complex &a) {
        im = a.im;
        re = a.re;
    }

    void print() { std::cout << re << " + " << im << " * i" << '\n'; }

   private:
    T re;
    T im;
};

#endif
