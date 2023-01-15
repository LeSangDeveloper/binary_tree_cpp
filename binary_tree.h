#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<list>

template<typename E>
struct Node {
    E elt;
    Node* parent;
    Node* left;
    Node* right;
    Node(): elt(), parent(NULL), left(NULL), right(NULL) { }
}

template<typename E>
class LinkedBinaryTree;

template<typename E>
class Position {
    private:
        Node* v;
    public:
        Position(Node* _v = NULL) : v(_v) {}
        E& operator*();
        Position<E> left() const;
        Position<E> right() const;
        Position<E> parent() const;
        bool isRoot() const;
        bool isExternal() const;
        friend class LinkedBinaryTree;
}

template<typename E>
class LinkedBinaryTree {
    private:
        Node* _root;
        int n;
    protected:
        void preorder(Node* v, std::list<Position<E> >& pl) const;
    public:
        LinkedBinaryTree();
        int size() const;
        bool empty() const;
        Position<E> root() const;
        std::list<Position<E> > positions() const;
        void addRoot();
        void expandExternal(const Position& p);
        Position<E> removeAboveExternal(const Position& p);
}

#endif