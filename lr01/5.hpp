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

    String(const String &other) : size{other.size}, str{new char[size + 1]} {
        strcpy(str, other.str);
        str[size] = '\0';
    }

    ~String() { delete[] str; }

    size_t Length() { return size; }

    void Copy(const String &stri) {
        if (str != stri.str) {
            delete[] str;
            str = new char[stri.size + 1];
            strcpy(str, stri.str);
            size = stri.size;
        }
    }

    void Copy(const char *stri) {
        if (str != stri) {
            delete[] str;
            size = strlen(stri);
            str = new char[size + 1];
            strcpy(str, stri);
        }
    }

    void prsize_t() { std::cout << str << '\n'; }

    void read() {
        std::string stri;
        std::getline(std::cin, stri);
        delete[] str;
        size = stri.size();
        str = new char[size + 1];
        strcpy(str, stri.c_str());
    }

    void Remove(size_t index, size_t count) {
        if (index < size) {
            char *new_buff = new char[size - count + 1];
            for (size_t i{0}; i < index; ++i) {
                new_buff[i] = str[i];
            }
            for (size_t i{index}, j{index + count}; j < size; ++i, ++j) {
                new_buff[i] = str[j];
            }
            delete[] str;
            new_buff[size - count] = '\0';
            str = new_buff;
            size -= count;
        }
    }

    void trim() {
        size_t count1 = 0, count2 = 0;
        while (*(str + count1) == ' ') count1++;
        while (*(str + size - count2) == ' ') count2++;
        char *new_buff = new char[size - count1 - count2 + 1];
        for (size_t i{count1}, j{0}; i < size - count2; ++i, ++j)
            new_buff[j] = str[i];
        delete[] str;
        str = new_buff;
        str[size - count1 - count2] = '\0';
        size = size - count1 - count2;
    }

    String Substr(size_t index, size_t count) {
        size_t new_size = 0;
        if (index < size)
            new_size = (index + count) < size ? count : (size - index);
        char *stri = new char[new_size + 1];
        for (size_t i{}; i < new_size; ++i) stri[i] = str[index + i];
        stri[new_size] = '\0';
        String temp(stri);
        delete[] stri;
        return temp;
    }

    void Insert(const char *other, size_t index) {
        if (index >= size) {
            index = size;
        }
        char *new_data = new char[size + strlen(other) + 1];
        memcpy(new_data, str, sizeof(char) * index);
        memcpy(new_data + index, other, strlen(other));
        memcpy(new_data + index + strlen(other), str + index,
               strlen(str + index));
        size = size + strlen(other);
        new_data[size] = '\0';
        delete[] str;
        str = new_data;
    }

    void print() { std::cout << str << '\n'; }

   private:
    size_t size;
    char *str;
};

#endif
