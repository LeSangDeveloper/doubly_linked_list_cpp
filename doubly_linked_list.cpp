#include"doubly_linked_list.h"
#include<string>

using namespace std;

template<typename E>
Iterator<E>::Iterator(Node<E>* u) {
    v = u;
}

template<typename E>
E& Iterator<E>::operator*() {
    return v->elem;
}

template<typename E>
bool Iterator<E>::operator==(const Iterator<E>& p) const {
    return v == p.v;
}

template<typename E>
bool Iterator<E>::operator!=(const Iterator<E>& p) const {
    return v != p.v;
}

template<typename E>
Iterator<E>& Iterator<E>::operator++() {
    v = v->next;
    return *this;
}

template<typename E>
Iterator<E>& Iterator<E>::operator--(){
    v = v->prev;
    return *this;
}

template<typename E>
NodeList<E>::NodeList() {
    n = 0;
    header = new Node<E>;
    trailer = new Node<E>;
    header->next = trailer;
    trailer->prev = header;
    header->prev = NULL;
    trailer->next = NULL; 
}

template<typename E>
int NodeList<E>::size() const {
    return n;
}

template<typename E>
bool NodeList<E>::empty() const {
    return n==0;
}

template<typename E>
Iterator<E> NodeList<E>::begin() const {
    return Iterator<E>(header->next);
}

template<typename E>
Iterator<E> NodeList<E>::end() const {
    return Iterator<E>(trailer);
}

template<typename E>
void NodeList<E>::insert(const Iterator<E>& p, const E& e) {
    Node<E>* w = p.v;
    Node<E>* u = p.v->prev;
    Node<E>* v = new Node<E>;
    v->elem = e;
    v->prev = u;
    u->next = v;
    v->next = w; 
    w->prev = v; 
    n++;
}

template<typename E>
void NodeList<E>::insertFront(const E& e) {
    insert(begin(), e);
}

template<typename E>
void NodeList<E>::insertBack(const E& e) {
    insert(end(), e);
}

template<typename E>
void NodeList<E>::erase(const Iterator<E>& p) {
    Node<E>* v = p.v;
    Node<E>* w = v->next;
    Node<E>* u = v->prev;
    u->next = w; w->prev = u;
    delete v;
    n--;
}

template<typename E>
void NodeList<E>::eraseFront() {
    erase(begin());
}

template<typename E>
void NodeList<E>::eraseBack() {
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