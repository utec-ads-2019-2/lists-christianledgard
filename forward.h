#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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
                this->head = temp;
            }
            this->size++;
        }

        void push_back(T value) {
            auto *temp = new Node<T>;
            temp->data = value;
            temp->next = nullptr;

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
            delete temp;

            if(this->get_size()<=1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->size--;
        }

        void pop_back() {
            auto temp = this->head;
            while(temp->next != this->tail){
                temp = temp->next;
            }
            this->tail = temp;
            delete temp->next;
            temp->next = nullptr;

            if(this->get_size()<=1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            this->size--;
        }

        void print() override{
            for (auto temp = this->head ; temp != nullptr ; temp = temp->next)
                cout << temp->data << endl;
            cout << "Size: " << this->get_size() << endl;
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
            // Puede ser return !this->tail;
            return this->tail == nullptr;
        }


        void clear() {
            // Pudiste haber llamado a killSelf()
            while(this->head != nullptr) pop_front();
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
            auto previo = this->head, siguiente = this->head;
            previo = siguiente = nullptr;
            this->tail = this->head;

            while (this->head != nullptr) {
                siguiente = this->head->next;
                this->head->next = previo;
                previo = this->head;
                this->head = siguiente;
            }

            this->head = previo;
        }
        

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T>(this->head);
        }

	    ForwardIterator<T> end() {
            return ForwardIterator<T>(this->tail->next);
        }

        void merge(ForwardList<T> list) {
            auto temp = list->head;
            for (int i = 0 ; temp != nullptr ; temp = temp->next, i++)
                push_back(temp->data);
        }
};

#endif