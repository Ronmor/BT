#include "Tree.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;
//
Node::Node(int data){
value = data;
left = NULL;
right = NULL;
parent = NULL;
}

int Node::getData(){
  return value;
}

Tree::Tree(){
  _root = NULL;
  _size = 0;
}

Tree::~Tree(){
  _root = NULL;
}
void Tree::print(){
  print(_root);
  std::cout << "\n";
}
void Tree::print(Node* t){
  //std::cout << "" << '\n';
  Node *tmp = t;
  if (tmp != NULL) {
    print(tmp->left);
    std::cout << tmp->value << '\t';
    print(tmp->right);
}
  //std::cout << "" << '\n';
}
int Tree::size(){
  return _size;
}

Tree& Tree::insert(int i){
  if (contains(i)) {
    throw invalid_argument("Already Contains Element!");
  }
  if (_root != NULL) {
    insert(i , _root);
    _size++;
  }
  else {
    _root = new Node(i);
    _root->left = NULL;
    _root->right = NULL;
    _root->parent = NULL;
    _size++;
  }
  return *this;
}

void Tree::insert(int i,Node *t){
  if (i < t->value) {
    if (t->left != NULL) {
    insert(i , t->left);
    }
    else {
      t->left = new Node(i);
      t->left->left = NULL;
      t->left->right = NULL;
      t->left->parent = t;
    }
  }
  else if(i >= t->value){
		if(t->right != NULL){
			insert(i, t->right);
		}else{
			t->right = new Node(i);
			t->right->value = i;
			t->right->right = NULL;
			t->right->left = NULL;
      t->right->parent = t;
		}
	}
}
bool Tree::contains(int i){
  return (contains(i , _root) != NULL);
}
Node* Tree::contains(int i, Node *t){
	if(t != NULL){
		if(i == t->value){
			return t;
		}
		if(i < t->value){
			return contains(i, t->left);
		}else{
			return contains(i, t->right);
		}
	}else{
		return NULL;
	}
}
int Tree::root(){
  return _root->value;
}
int Tree::left(int i){
  if (!contains(i)) {
    std::cout << "value does not exist" << '\n';
    return -1;
  }
  Node* tmp = contains(i , _root)->left;
  return tmp->value;

}
int Tree::right(int i){
  if (!contains(i)) {
    std::cout << "value does not exist" << '\n';
    return -1;
  }
  Node* tmp = contains(i ,_root )->right;
  return tmp->value;
}
int Tree::parent(int i){
  Node* tmp = contains(i , _root);
  if ((tmp->value == _root->value) || (!contains(i)))
   {
    std::cout << "_root has no upper level" << '\n';
    return -1;
    }
  else {
    return tmp->parent->value;
  }
}
void Tree::remove(int i){
  Node* tmp = contains(i , _root);
  if (tmp == NULL) {
    std::cout << "invalid input exeption" << '\n';
    return;
  }
    if (tmp->value == _root->value && _size == 1) {
      delete _root;
      _size--;
      return;
    }
     if (tmp->right == NULL && tmp->left != NULL) {
    _root = tmp->left;
    }
    else if(tmp->right != NULL && tmp->left == NULL){
      _root = tmp->right;
    }
    if (tmp->left == NULL && tmp->right == NULL) {
      if (tmp->parent->right->value == tmp->value) {
        tmp->parent->right = NULL;
      }
      else {
        tmp->parent->left = NULL;
      }
      delete tmp;
      _size--;
      return;
    }
    else {
      Node* leaving_current_branch = tmp->right->left;
      if (leaving_current_branch != NULL) {
        Node* brn_dst = tmp->left;
        while (brn_dst->right != NULL) {
          brn_dst = brn_dst->right;
        }
        brn_dst->right = leaving_current_branch;
      }
      else {
        tmp->left->parent = tmp->right;
        tmp->right->left = tmp->left;
      }
    }
  }
