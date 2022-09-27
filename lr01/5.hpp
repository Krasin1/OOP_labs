#ifndef STR_HPP
#define STR_HPP

#include <cstring>
#include <iostream>

struct String {
    String() {
        size = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char *stri) {
        size = strlen(stri);
        str = new char[size + 1];
        strcpy(str, stri);
    }

    ~String() { delete[] str; }

    int Length() { return size; }

    void Copy(const String &stri) {
        delete[] str;
        str = new char[stri.size + 1];
        strcpy(str, stri.str);
        size = stri.size;
    }

    void Copy(const char *stri) {
        delete[] str;
        size = strlen(stri);
        str = new char[size + 1];
        strcpy(str, stri);
    }

    void print() { std::cout << str << '\n'; }

    void read() {
        std::string stri;
        std::getline(std::cin, stri);
        delete[] str;
        size = stri.size();
        str = new char[size + 1];
        strcpy(str, stri.c_str());
    }

    void Remove(int index, int count) {
        if (index < size) {
            char *new_buff = new char[size - count + 1];
            for (int i{0}; i < index; ++i) {
                new_buff[i] = str[i];
            }
            for (int i{index}, j{index + count}; j < size; ++i, ++j) {
                new_buff[i] = str[j];
            }
            delete[] str;
            new_buff[size - count] = '\0';
            str = new_buff;
            size -= count;
        }
    }

    void trim() {
        int count1 = 0, count2 = 0;
        while (*(str + count1) == ' ') count1++;
        while (*(str + size - count2) == ' ') count2++;
        char *new_buff = new char[size - count1 - count2 + 1];
        for (int i{count1}, j{0}; i < size - count2; ++i, ++j)
            new_buff[j] = str[i];
        delete[] str;
        str = new_buff;
        str[size - count1 - count2] = '\0';
        size = size - count1 - count2;
    }

    String Substr(int index, int count) {
        int new_size = 0;
        if (index < size)
            new_size = (index + count) < size ? count : (size - index);
        char *stri = new char[new_size + 1];
        for (int i{}; i < new_size; ++i) stri[i] = str[index + i];
        stri[new_size] = '\0';
        String temp(stri);
        delete[] stri;
        return temp;
    }

    void Insert(char *s, int index) {
        char * temp;
        if (index <= size) { 
            temp = new char[size - index + 1]; 
            strcpy(temp, str + index);
        } else { 
            index = size;
            temp = new char[1];
            temp[0] = '\0';
        }
        int count = 0;
        while (*(s + count) != '\0') ++count;
        int new_size = size + count;
        char *buff = new char[new_size + 1];
        for (int i {}; i < index; ++i) buff[i] = str[i];
        for (int i {index}, j {}; i < index + count; ++i, ++j) buff[i] = s[j];
        for (int i {index + count}, j {}; i < new_size; ++i, ++j) buff[i] = temp[j];
        buff[new_size] = '\0';
        delete[] temp;
        delete[] str;
        str = buff;
        size = new_size;
    }

   private:
    int size;
    char *str;
};

#endif
