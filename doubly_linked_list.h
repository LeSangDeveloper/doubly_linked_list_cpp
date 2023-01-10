#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct Node {
    E& e;
    Node* prev;
    Node* next;
};

template<typename E>
class NodeList;

template<typename E>
class Iterator {
    private:
        Node* v;
        Iterator(Node* u);
    public:
        E& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();
        friend class NodeList<E>;
}

template<typename E>
class NodeList {
    private:
        int n;
        Node* header;
        Node* trailer;
    public:
        NodeList();
        int size() const;
        bool empty() const;
        Iterator begin() const;
        Iterator end() const;
        void insertFront(const E& e);
        void insertBack(const E& e);
        void insert(const Iterator& p, const E& e);
        void eraseFront();
        void eraseBack();
        void erase(const Iterator& p);
}

#endif