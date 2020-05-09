#ifndef HEAP_H
#define HEAP_H

#include <vector>

#include "Vertex.h"

class Heap{
private:
    template <class T>
    class Node{
        private:
            T data;
            Node<T>* next;
        
        public:
            Node<T>(const T&);
            ~Node<T>();

            inline T getData() {return this->data; }
            inline Node<T>* getNext(){ return this->next; }
            inline void setData(const T& data){ this->data = data; }
            inline void setNext(Node<Vertex>* node){ this->next = node; }
    };
    Node<Vertex>* head;

public:
    Heap();
    ~Heap();

    Vertex pop();
    void push(const Vertex&);
};

#endif