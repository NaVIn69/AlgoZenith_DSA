#include<iostream>
using namespace std;
template<typename T>
class binarytreenode{
    public:
    T data;
    binarytreenode*left;
    binarytreenode*right;
    binarytreenode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~binarytreenode(){
        delete left;
        delete right;
    }
};
class BST{
binarytreenode<int>*root;
public:
BST(){
    root=NULL;
}
~BST(){
    delete root;
}
void deletedata(int data){

}
void insert(int data){

}
private:
bool hasdata(int val ,binarytreenode<int>*node){
if(node==NULL){
    return false;
}
if(node->data==val){
    return true;
}else if(val>node->data){
    return hasdata(val,node->right);
}else{
    return hasdata(val,root->left);
}
}
public:
bool hasdat(int data){
    return hasdata(data,root); 
}
};