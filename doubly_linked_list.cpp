#include"doubly_linked_list.h"
using namespace std;

template<typename E>
Iterator::Iterator(Node* u) {
    u = v;
}

template<typename E>
E& Iterator::operator*() {
    return v->elem;
}

template<typename E>
bool Iterator::operator==(const Iterator& p) const {
    return v == p.v;
}

template<typename E>
bool Iterator::operator!=(const Iterator& p) const {
    return v != p.v;
}

template<typename E>
Iterator& Iterator::operator++() {
    v = v->next;
    return *this;
}

template<typename E>
Iterator& NodeList::operator--(){
    v = v->prev;
    return *this;
}

template<typename E>
NodeList::Node() {
    n = 0;
    header = new Node;
    trailer = new Node;
    header->next = trailer;
    trailer->prev = header; 
}

template<typename E>
int NodeList::size() const {
    return n;
}

template<typename E>
bool NodeList::empty() const {
    return n==0;
}

template<typename E>
NodeList::Iterator NodeList::begin() const {
    return Iterator(header->next);
}

template<typename E>
Iterator NodeList::end() const {
    return Iterator(trailer);
}

template<typename E>
void NodeList::insert(const Iterator& p, const E& e) {
    Node* w = p.v;
    Node* u = w->prev;
    Node* v = new Node;
    v->elem = e;
    v->next = w; w->prev = v;
    v->prev = u; u->next = v;
    n++;
}

template<typename E>
void NodeList::insertFront(const E& e) {
    insert(begin(), e);
}

template<typename E>
void NodeList::insertBack(const E& e) {
    insert(end(), e);
}

template<typename E>
void NodeList::erase(const Iterator& p) {
    Node* v = p.v;
    Node* w = v->next;
    Node* u = v->prev;
    u->next = w; w->prev = u;
    delete v;
    n--;
}

template<typename E>
void NodeList::eraseFront() {
    erase(begin());
}

template<typename E>
void NodeList::eraseBack() {
    erase(--end());
}


template class Iterator<int>;
template class Iterator<double>;
template class Iterator<float>;
template class Iterator<string>;

template class NodeList<int>;
template class NodeList<double>;
template class NodeList<float>;
template class NodeList<string>;