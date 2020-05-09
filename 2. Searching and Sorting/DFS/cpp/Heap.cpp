#include "Heap.h"


Heap::Heap(){
    this->head = NULL;
}

Heap::~Heap(){
    if(this->head != NULL){
        Node<Vertex>* temp;
        while(this->head->getNext() != NULL){
            temp = this->head->getNext();
            delete this->head;
            this->head = temp;
        }
        delete this->head;
    }
}

template <class T>
Heap::Node<T>::Node(const T& data){
    this->data = data;
    this->next = NULL;
}

template <class T>
Heap::Node<T>::~Node(){}

Vertex Heap::pop(){
    Node<Vertex>* tempNode = this->head;
    Vertex tempVertex = tempNode->getData();
    this->head = tempNode->getNext();
    delete tempNode;
    
    return tempVertex;
}

void Heap::push(const Vertex& node){
    Node<Vertex>* newHead = new Node<Vertex>(node);
    newHead->setNext(this->head);
    this->head = newHead;
}

bool Heap::empty(){
    if (this->head == NULL){
        return true;
    }
    return false;
}