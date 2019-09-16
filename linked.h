#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            if(this->head == nullptr)
                throw out_of_range("This list is empty.");
            return this->head->data;
        }

        T back() {
            if(this->tail == nullptr)
                throw out_of_range("This list is empty.");
            return this->tail->data;
        }

        void push_front(T value) {
            auto *temp = new Node<T>;
            temp->data = value;
            temp->next = this->head;

            if(this->head == nullptr){
                this->head = temp;
                this->tail = temp;
            } else {
                this->head->prev = temp;
                this->head = temp;
                temp->prev = nullptr;
            }

            this->size++;
        }

        void push_back(T value) {
            auto *temp = new Node<T>;
            temp->data = value;
            temp->next = nullptr;
            temp->prev = this->tail;

            if (this->head == nullptr) {
                this->head = temp;
                this->tail = temp;
            } else {
                this->tail->next = temp;
                this->tail = temp;
            }

            this->size++;
        }

        void pop_front() {
            auto temp = this->head;
            this->head = this->head->next;
            temp->next = nullptr;
            delete temp;

            if(this->get_size()<=1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->size--;
        }

        void pop_back() {
            auto temp = this->tail;
            this->tail = this->tail->prev;
            temp->prev = nullptr;
            delete temp;

            if(this->get_size()<=1){
                this->head = nullptr;
                this->tail = nullptr;
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


        void clear() {
            while(this->head != nullptr) pop_back();
        }

        void sort() {
            T tempArray[this->get_size()];
            auto temp = this->head;
            for (int i = 0 ; temp != nullptr ; temp = temp->next, i++)
                tempArray[i] = temp->data;
            int n = sizeof(tempArray)/sizeof(tempArray[0]);
            std::sort(tempArray, tempArray+n);
            this->clear();
            for(auto elementoOrdenado:tempArray)
                this->push_back(elementoOrdenado);
        }
    
        void reverse() {
            for (auto temp = this->head; temp != nullptr ; temp = temp->prev)
                std::swap(temp->next, temp->prev);
            std::swap(this->head, this->tail);
        }

        void print() override{
            for (auto temp = this->head ; temp != nullptr ; temp = temp->next)
                cout << temp->data << endl;
            cout << "Size: " << this->get_size() << endl;
        }


        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T> (this->head);
        }

	    BidirectionalIterator<T> end() {
            // this->tail->next
            return BidirectionalIterator<T> (this->head->next);
        }

        void merge(LinkedList<T> list) {
            for (auto temp = list->head; temp != nullptr ; temp = temp->next)
                push_back(temp->data);
        }
};

#endif