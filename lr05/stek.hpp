#ifndef STEK_HPP
#define STEK_HPP

#include <iostream>

template <typename T>
struct stek {
    explicit stek() : end(nullptr), size(0) {}
    explicit stek(T some_value)
        : end(new(node){some_value, nullptr}), size(1) {}

    template <typename some_type>
    stek(some_type) {
        throw std::exception();
    };

    explicit stek(const stek& other) : end(nullptr), size{0} {
        node* temp = other.end;
        if (temp) {
            for (temp; temp->previous; temp = temp->previous) {
                push_up(temp->value);
            }
            push_up(temp->value);
        }
    }

    void operator=(const stek& other) {
        if (end != other.end) {
            node* temp = other.end;
            delete_stek();
            size = 0;
            if (temp) {
                for (temp; temp->previous; temp = temp->previous) {
                    push_up(temp->value);
                }
                push_up(temp->value);
            }
        }
    }

    template <typename some_type>
    void push_back(some_type) {
        throw std::exception();
    };
    void push_back(T some_value) {
        end = new (node){some_value, end};
        size++;
    }
    template <typename some_type>
    void push_up(some_type) {
        throw std::exception();
    };

    void push_up(T some_value) {
        size++;
        node* temp = end;
        if (temp) {
            for (temp; temp->previous; temp = temp->previous)
                ;
            temp->previous = new (node){some_value, nullptr};
        } else {
            end = new (node){some_value, end};
        }
    }
    T pop_back() {
        if (size <= 0) {
            std::cout << "Стек пуст\n";
            throw std::exception();
        }
        size--;
        T temp_value = end->value;
        node* temp_node = end;
        end = end->previous;
        delete temp_node;
        return temp_value;
    }
    T pop_up() {
        if (size <= 0) {
            std::cout << "Стек пуст\n";
            throw std::exception();
        }
        size--;
        node* this_node = nullptr;
        node* prev_node = end;
        for (this_node, prev_node; prev_node->previous;
             this_node = prev_node, prev_node = prev_node->previous)
            ;
        T temp_value = prev_node->value;
        delete prev_node;
        this_node->previous = nullptr;
        return temp_value;
    }

    bool is_empty() { return size == 0; }

    size_t get_size() { return size; }

    void print() {
        node* temp = end;
        std::cout << "Кол-во элементов = " << size << '\n';
        if (temp) {
            for (temp; temp->previous; temp = temp->previous) {
                std::cout << temp->value << " > ";
            }
            std::cout << temp->value << '\n';
        }
    }

    void delete_stek() {
        if (end) {
            node* temp = end;
            while (end->previous) {
                temp = end->previous;
                delete end;
                end = temp;
            }
            delete end;
            end = nullptr;
        }
    }

    ~stek() { delete_stek(); }

   private:
    struct node {
        T value;
        node* previous;
    };

    node* end;
    size_t size;
};

#endif
