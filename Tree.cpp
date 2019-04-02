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

// Tree::~Tree(){
//   destroytree(_root);
// }
// void Tree::destroytree(Node *ptr){
//     if (ptr == NULL) {
// 	return;
// 	}
// 	destroytree(ptr->left);
// 	destroytree(ptr->right);
// delete ptr;
// }
void Tree::print(){
  print(_root);
  std::cout << "\n";
}
void Tree::print(Node* t){
  Node *tmp = t;
  if (tmp != NULL) {
    print(tmp->left);
    std::cout << tmp->value << '\t';
    print(tmp->right);
}

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
      t->left->parent = t;
    }
  }
  else if(i >= t->value){
		if(t->right != NULL){
			insert(i, t->right);
		}else{
			t->right = new Node(i);

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
  if(_root==nullptr){throw("empty tree!");}
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
bool ans  = contains(i);
if(!ans){throw ("this value do not exist");}
else{
  Node *current = nullptr;
  current = _root;
  Node *pre = nullptr;
  while (current != nullptr){
    if((current->value)== i){
      break;
    }
    else if(current->value > i)
    {
      pre = current;
      current = current->left;
    }
    else
    {
      pre = current;
      current = current->right;
    }
}
  if(current->left ==nullptr && current->right==nullptr){
    if(_size == 1){delete _root ; _root = nullptr;delete current ; current = nullptr;}
    else{
      if(pre->left ==current){pre->left=nullptr;}
      else{pre->right=nullptr;}
      delete current;
      current = nullptr;
    }
    _size--;
  }
  //only left subtree
    else if(current->left !=nullptr && current->right==nullptr){
      if(current->value == _root->value){
      pre = current->left;
      _root = pre;
    }
      else{
        if(pre->left == current){
        pre->left = current->left;
        (current->left)->parent = pre;
      }
      else{pre->right = current->left; (current->left)->parent = pre;}
      }
      delete current;
      current = nullptr;
      _size--;
    }
    //only right subtree
    else if(current->right !=nullptr && current->left==nullptr){
      if(current->value == _root->value){
      pre = current->right;
      _root = pre;
    }
    else{
      if(pre->right == current){
      pre->right = current->right;
      (current->right)->parent = pre;
    }
    else{pre->left = current->right; (current->right)->parent = pre;}

    }
      delete current;
      current = nullptr;
      _size--;
    }
    //remove root with 2 child
    else{
      bool b =false;
      if(current->value==_root->value){b=true;}
      if(b){pre = current->right;
         if(pre->left != nullptr){Node *p = nullptr; p = pre->left;
         pre->left = current->left;
         if(pre->left->right != nullptr){
         Node *tmp = pre->left->right;
         while(tmp->right != nullptr){
           tmp = tmp->right;
         }
         tmp->right = p;
         delete current;
         current = nullptr;
        _root = pre;
         _size--;
       }
       else {
         pre->left->right = p;
         delete current;
         current = nullptr;
         _root = pre;
         _size--;
       }
      }
      else{
        pre->left = current->left;
        delete current;
        current = nullptr;
        if(b){ _root = pre;}
        _size--;
      }
    }
  else{
      pre->right=current->right;
          Node *tmp = current->right;
            while(tmp->left != nullptr){
                  tmp=tmp->left;}
            tmp->left = current->left;

          delete current;
          current = nullptr;
          _size--;
}
}
}
}
