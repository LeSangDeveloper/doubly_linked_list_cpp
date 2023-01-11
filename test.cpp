#include"doubly_linked_list.h"
#include<iostream>

using namespace std;

int main() {
    cout << "Begin..." << endl;
    NodeList<int> a;
    cout << "Constructor.." << endl;
    a.insertFront(2);
    cout << "Insert " << endl;
    Iterator<int> i = a.begin();
    cout << *i << endl;
    cout << "End..." << endl;
    return 0;
}