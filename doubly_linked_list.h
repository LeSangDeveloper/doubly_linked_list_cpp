#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template<typename E>
struct Node {
    E elem;
    Node<E>* prev;
    Node<E>* next;
};

template<typename E>
class NodeList;

template<typename E>
class Iterator {
    private:
        Node<E>* v;
        Iterator(Node<E>* u);
    public:
        E& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator<E>& operator++();
        Iterator<E>& operator--();
        friend class NodeList<E>;
};

template<typename E>
class NodeList {
    private:
        int n;
        Node<E>* header;
        Node<E>* trailer;
    public:
        NodeList();
        int size() const;
        bool empty() const;
        Iterator<E> begin() const;
        Iterator<E> end() const;
        void insertFront(const E& e);
        void insertBack(const E& e);
        void insert(const Iterator<E>& p, const E& e);
        void eraseFront();
        void eraseBack();
        void erase(const Iterator<E>& p);
};

#endif