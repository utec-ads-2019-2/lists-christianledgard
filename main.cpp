#include <iostream>
#include "test/tester.h"

#include "forward.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "\tLists Practice" << endl;
    cout << "===========================================================" << endl << endl;

    //Tester::execute();

    List<int>* temp = new LinkedList<int>();

    temp->push_back(1);
    temp->push_back(6);
    temp->push_back(5);
    temp->push_back(3);
    temp->push_back(9);
    temp->push_back(4);
    temp->sort();
    temp->reverse();


    //temp->pop_back();
    //temp->sort();
    //temp->clear();
    //temp->reverse();


    cout <<"Head (FRONT): "<< temp->front() << endl;
    cout <<"Tail (BACK): "<< temp->back() << endl;
    temp->print();


    return EXIT_SUCCESS;
}
