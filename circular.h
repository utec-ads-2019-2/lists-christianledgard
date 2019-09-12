#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            if(this->get_size()==0)
                throw out_of_range("This list is empty f.");
            return this->head->data;
        }

        void sort(){}

        T back() {
            if(this->get_size()==0)
                throw out_of_range("This list is empty. b");
            return this->head->prev->data;
        }

        void push_front(T value) {
            push_back(value);
            //this->head = this->head->prev->data;
            this->size++;
        }

        void push_back(T value) {
            auto *temp = new Node<T>;
            temp->data = value;
            temp->next = this->head;
            if (this->head == nullptr) {
                this->head = temp;
                this->head->next = temp;
                this->head->prev = temp;
            } else {
                this->head->prev->next = temp;
                temp->prev = this->head->prev;
                this->head->prev = temp;
            }

            this->size++;
        }

        void pop_front() {
            if (this->head != nullptr) {
                auto temp = this->head;
                this->nodes--;
                if (this->nodes == 0)
                    this->head = nullptr;
                else {
                    this->head->prev->next = this->head->next;
                    this->head->next->prev = this->head->prev;
                    this->head = this->head->next;
                }
                delete temp;
            }
            this->size--;
        }

        void pop_back() {
            if (this->head != nullptr) {
                auto temp = this->head->prev;
                this->nodes--;
                if (this->nodes == 0)
                    this->head = nullptr;
                else {
                    this->head->prev->prev->next = this->head;
                    this->head->prev = this->head->prev->prev;
                }
                delete temp;
            }
            this->size--;
        }

        T operator[](int index) {
            if (index < this->get_size() and this->head != nullptr) {
                auto temp = this->head;
                for (unsigned int i = 0; i < index; i++) temp = temp->next;
                return temp->data;
            }
            throw out_of_range("Index out of range");
        }

        bool empty() {
            return this->tail == nullptr;
        }


        void print() override{
            auto temp = this->head;
            for (int i = 0; i < this->get_size(); ++i, temp = temp->next)
                cout << temp->data << endl;
            cout << "Size: " << this->get_size() << endl;
        }

        void clear() {
            while(this->head != nullptr) pop_back();
        }
    
        void reverse() {
            auto temp = this->head;
            for (int i = 0; i < this->get_size(); ++i, temp = temp->prev)
                std::swap(temp->next, temp->prev);
            std::swap(this->head, this->tail);
        }


        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->head);
        }

        void merge(CircularLinkedList<T> list) {
            for (auto temp = list->head; temp != nullptr ; temp = temp->next)
                push_back(temp->data);
        }
};

#endif