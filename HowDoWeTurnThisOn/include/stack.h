#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template <class T> 
class stack {
  public:

    stack();
    ~stack();

    class Node {
      public:
        Node();
        Node(T *data);
        ~Node();
        Node* operator = (Node *other);

      private:
        T *data_;
        Node *previous_;

      friend class stack;
    };

    // template <class T> T*    
    T getTop();
    void push(T data);
    void pop();
    bool isEmpty();
    unsigned int size();

  private:
    Node *top_;
    unsigned int size_;
};

// DECLARATION BELOW AS TEMPLATE FUNCTIONS
// NEED TO BE ACCESIBLE FROM THE FILE USING THEM

template <class T> 
stack<T>::stack() {
  top_ = NULL;
  size_ = 0;
}

template <class T> 
stack<T>::~stack() {
  while (top_ != NULL) {
    Node *tmp = top_->previous_;
    delete top_;
    top_ = tmp;
  }
}

template <class T> 
T stack<T>::getTop() {
  return *(top_->data_);
}

template <class T> 
void stack<T>::push(T data) {
  Node *tmp = new Node();
  
  if (size_ == 0) {
    tmp->previous_ = NULL;
    *(tmp->data_) = data;
  } else {
    *(tmp->data_) = data;
    tmp->previous_ = top_;
  }

  top_ = tmp;

  ++size_;
}

template <class T> 
void stack<T>::pop() {
  Node *tmp = top_->previous_;
  delete top_;
  top_ = tmp;

  --size_;
}

template <class T> 
bool stack<T>::isEmpty() {
  return size_ == 0;
}

template <class T> 
unsigned int stack<T>::size() {
  return size_;
}

//

template <class T> 
stack<T>::Node::Node() {
  data_ = NULL;
  previous_ = NULL;
}

template <class T> 
stack<T>::Node::Node(T *data) {
  data_ = data;
  previous_ = NULL;
}

template <class T> 
stack<T>::Node::~Node() {

}

template <class T> typename 
stack<T>::Node* stack<T>::Node::operator = (Node *other) {
  data_ = other->data_;
  previous_ = other->previous_;

  return this;
}

#endif // __STACK_H__
