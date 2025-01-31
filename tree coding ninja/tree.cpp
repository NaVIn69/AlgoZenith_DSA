#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Treenode{
    public:
    T data;
    vector<Treenode<T>*>children;
    Treenode(T data){
      this->data=data;
    }
};
void Print(Treenode<int>*root){
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
       cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        Print(root->children[i]);
    }
}
int main(){
    Treenode<int>*root=new Treenode<int>(1);
    Treenode<int>*node1=new Treenode<int>(2);
    Treenode<int>*node2=new Treenode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
    // for(int i=0;i<root->children.size();i++){
    //     cout<<root->children[i]->data<<" ";
    // }
    Print(root);
    return 0;
}