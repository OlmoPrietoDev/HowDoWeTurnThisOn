#include "stack.h"

/*template <class T> 
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
T* stack<T>::getTop() {
  return top_->data_;
}

template <class T> 
void stack<T>::push(T *data) {
  Node *tmp = new Node();
  
  if (size_ == 0) {
    tmp->previous_ = NULL;
    tmp->data_ = data;
  } else {
    tmp->data_ = data;
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
}

template <class T> 
stack<T>::Node::~Node() {

}

template <class T> typename 
stack<T>::Node* stack<T>::Node::operator = (Node *other) {
  data_ = other->data_;
  previous_ = other->previous_;

  return this;
}*/
