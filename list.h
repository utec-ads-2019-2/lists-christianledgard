#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename T>
class List {
    protected:
        Node<T>* head;
        Node<T>* tail;
        int nodes;
        unsigned int size;

    public:
        List() : head(nullptr), tail(nullptr), nodes(0), size(0) {};

        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual void print() = 0;
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        unsigned int get_size() {
            return this->size;
        }

        ~List() {
            auto current = this->head;
            for (unsigned int i = 0; i < this->nodes; i++) {
                auto temp = current;
                if (temp != nullptr) {
                    delete temp;
                    current = current->next;
                }
            }
        }
};

#endif