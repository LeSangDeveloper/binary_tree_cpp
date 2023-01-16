#include"binary_tree.h"
#include<string>
#include<list>

using namespace std;

template<typename E>
E& Position<E>::operator*() {
    return v->elt;
}

template<typename E>
Position<E> Position<E>::left() const {
    return Position<E>(v->left);
}

template<typename E>
Position<E> Position<E>::right() const {
    return Position<E>(v->right);
}

template<typename E>
Position<E> Position<E>::parent() const {
    return Position<E>(v->parent);
}

template<typename E>
bool Position<E>::isRoot() const {
    return v->parent != NULL;
}

template<typename E>
bool Position<E>::isExternal() const {
    return v-> left == NULL && v->right == NULL;
}

template<typename E>
int LinkedBinaryTree<E>::size() const {
    return n;
}

template<typename E>
bool LinkedBinaryTree<E>::empty() const {
    return size() == 0;
}

template<typename E>
Position<E> LinkedBinaryTree<E>::root() const {
    return Position<E>(_root);
}

template<typename E>
LinkedBinaryTree<E> LinkedBinaryTree<E>::addRoot() {
    _root = new Node;
    n = 1;
}

template<typename E>
void LinkedBinaryTree<E>::expandExternal(const Position&p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->parent = v;
    v->right = new Node;
    v->right->parent = v;
    n += 2;
}

template<typename E>
Position<E> LinkedBinaryTree<E>::removeAboveExternal(const Position& p) {
    Node* w = p.v;
    Node* v = w->parent;
    Node* sib = (w == v->left ? v->right : v->left);
    if (v == _root) {
        _root = sib;
        sib->parent = NULL;
    } else {
        Node* gpar = v->parent;
        // w's grandparent
        if (v == gpar->left) gpar->left = sib;
        // replace parent by sib
        else gpar->right = sib;
        sib->parent = gpar;
    }
    delete w; delete v;
    n -= 2;
    return Position(sib);
}

template<typename E>
list<Position<E> > LinkedBinaryTree<E>::positions() const {
    list<Position<E> > pl;
    preorder(_root, pl);
    return pl;
}

template<typneame E>
void LinkedBinaryTree<E>::preorder(Node* v, list<Position<E> >& pl) const {
    pl.push_back(Position(v));
    if (v->left != NULL)
        preorder(v->left, pl);
    if (v->right != NULL)
        preorder(v->right, pl);
}

template class Position<int>;
template class Position<double>;
template class Position<float>;
template class Position<string>;
template class Position<bool>;

template class LinkedBinaryTree<int>;
template class LinkedBinaryTree<double>;
template class LinkedBinaryTree<float>;
template class LinkedBinaryTree<string>;
template class LinkedBinaryTree<bool>;