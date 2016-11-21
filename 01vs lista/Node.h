#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node {
public:
    Node() ;
    Node(T);
    ~Node();
    Node *next;
    T data;
    void delete_all();
};

 // Constructor por parámetro
template<typename T>
Node<T>::Node(T data_)
{

    data = data_;
    next = NULL;
}

// Eliminar todos los Nodos
template<typename T>
void Node<T>::delete_all()
{
    if (next)
        next->delete_all();
    delete this;
}


template<typename T>
Node<T>::~Node() {}


#endif // NODE_H_INCLUDED
