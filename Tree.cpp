#include <iostream>
#include "Tree.hpp"
using namespace std;
using namespace ariel;

Node::Node(int v){
      val = v;
      left =nullptr;
      right=nullptr;
      parent=nullptr;
    }
int Node::getData(){
    return val;
}
/**
Tree::Tree(){
    root = nullptr;
    _size = 0;
}
*/
void Tree::print(){
  print(_root);
  std::cout << "\n";
}
void Tree::print(Node* t){
  Node *tmp = t;
  if (tmp != NULL) {
    print(tmp->left);
    std::cout << tmp->val << '\t';
    print(tmp->right);
}
}
int Tree::size(){
  return _size;
}
int Tree::root(){
  if(_root != nullptr){return _root->val;}
  else {throw "dosent exist!";}
}
bool contains(int data){
  return true;
}
Tree& Tree::insert(int v){
if(_root == nullptr){_root= new Node(v);_size++;}
else if(contains(v)){throw "exist !";}
else{insert(_root , v );}
return *this;
}
void Tree::insert(Node *n,int v){
Node *ptr = nullptr;
if(v >n->val){
        if(n->right==nullptr){ptr=n; n=n->right;n=new Node(v);n->parent=ptr;ptr->right=n;_size++;}
      else{n=n->right;insert(n,v);}}
else{
        if(n->left==nullptr){ptr=n; n=n->left;n=new Node(v);n->parent=ptr;ptr->left=n;_size++;}
      else{n=n->left;insert(n,v);}}
}
int Tree::right(int v){
if(!contains(v)){throw "dosent exist!";}
else{Node *ptr = find(_root,v);
return ptr->right->val;}
}
int Tree::left(int v){
if(!contains(v)){throw "dosent exist!";}
else{Node *ptr = find(_root,v);return ptr->left->val;}
}
int Tree::parent(int v){
if(!contains(v)){throw "dosent exist!";}
else{Node *ptr = find(_root,v);
    if(ptr->parent==nullptr){throw "dosent exist!";}
    return ptr->parent->val;
}
}
bool Tree::remove(int v){
if(!contains(v)){throw "dosent exist !";}
Node *ptr = find(_root,v);
if(ptr->val==_root->val){
        if(_size==1){
            root=nullptr;
             delete(ptr);
              _size--;return false;
              }
        else if(_size==2){
                if(ptr->right !=nullptr){
                    Node *R = nullptr;
                    R = (ptr->right);
                    R->parent = nullptr;
                    delete(ptr);
                    root = R;
                   _size--;

                   }
                else {
                    Node *R = nullptr;
                    R = (ptr->left);
                    R->parent = nullptr;
                    delete(ptr);
                    _root = R;
                   _size--;
                   }
               }
        else {
            Node *newroot = nullptr;
            newroot = ptr->right;
            if(ptr->right->left != nullptr){
                Node *l = nullptr;
                l = ptr->right->left;
                Node *leftroot = nullptr;
                leftroot = ptr->left;
                newroot->parent = nullptr;
                while(leftroot->right !=nullptr){leftroot=leftroot->right;}
                leftroot->right = l;
                l->parent = leftroot;
            }
                newroot->left = ptr->left;
                newroot->left->parent = newroot;
                    delete(ptr);
                    root = newroot;
                   _size--;

            }
        }
else{
        Node *par = nullptr;
    if(ptr->right == nullptr && ptr->left == nullptr){
        par = ptr->parent;
        if(par->right->val == ptr->val){par->right = nullptr;}
        else {par->left = nullptr; }
        delete(ptr);
        _size--;
    }
    else if(ptr->left == nullptr && ptr->right !=nullptr){
        par = ptr->parent;
        ptr->parent = nullptr;
        par->right = ptr->right;
        par->right->parent = par;
        delete(ptr);
        _size--;
    }
    else if(ptr->right == nullptr && ptr->left !=nullptr){
        par = ptr->parent;
        ptr->parent = nullptr;
        par->left = ptr->left;
        par->left->parent = par;
        delete(ptr);
        _size--;
    }
    else {
            Node *newsubroot = nullptr;
            newsubroot = ptr->right;
            Node *par = ptr->parent;
            if(newsubroot->left != nullptr){
                Node *l = nullptr;
                l = newsubroot->left;
                Node *leftsubroot = nullptr;
                leftsubroot = ptr->left;
                while(leftsubroot->right !=nullptr){leftsubroot=leftsubroot->right;}
                leftsubroot->right = l;
                l->parent = leftsubroot;
            }
                newsubroot->parent = par;
                if(par->right->val==ptr->val){par->right=newsubroot;}
                else{par->left=newsubroot;}
                newsubroot->left = ptr->left;
                newsubroot->left->parent = newsubroot;
                    delete(ptr);
                   _size--;
            }

}
}
bool Tree::contains(int v){
  bool b = false;
  if(_root != nullptr){
    Node *ptr = find(_root,v);
    if(ptr!=nullptr){b=true;}
}
return b;
}
Node* Tree::find(Node *n , int v){
if(n==nullptr){return n;}
else if(n->val==v){return n;}
else if(n->val<v){n = n->right; find(n,v);}
else{n=n->left; find(n,v);}
//return *this;
}
