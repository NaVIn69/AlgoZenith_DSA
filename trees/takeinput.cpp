#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class treeNode{
    public:
    T data;
    vector<treeNode*>children;
    treeNode(T data){
        this->data=data;
    }
};

 /// @brief 
 /// @param root 
 void printTree(treeNode<int>*root){
    if(root==NULL){
        return ;//it is not a base case it is a edge case
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
treeNode<int>*takeinput(){
    int rootdata;
    cout<<"enter the data"<<endl;
    cin>>rootdata;
    treeNode<int>*root=new treeNode<int>(rootdata);
    int n;
    cout<<"enter the number of children"<<" "<<rootdata<<endl;;
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode<int>*child=takeinput();
        root->children.push_back(child);
    }
    return root; 
}
treeNode<int>*takeinputlevelwise(){
    int rootdata;
    cout<<"enter the rootdata"<<endl;
    cin>>rootdata;
    treeNode<int>*root=new treeNode<int>(rootdata);
    queue<treeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        treeNode<int>*front=pendingNode.front();
        pendingNode.pop();
        cout<<"enter the number of children of "<<front->data<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int childdata;
            cout<<"enter "<<i<<"th child of "<<front->data<<endl;
            cin>>childdata;
            treeNode<int>*child=new treeNode<int>(childdata);
            root->children.push_back(child);
            pendingNode.push(child);
        }
    }
return root;

}
void printlevelwise(treeNode<int>*root){
      if(root==NULL){
        return ;
    }
    queue<treeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
    treeNode<int>*f=pendingNode.front();
    pendingNode.pop();
    // cout<<front-><<":";
    cout<<f->data<<":";
    for(int i=0;i<f->children.size();i++){
        cout<<f->children[i]->data<<",";
    }
    cout<<endl;
   for(int i=0;i<f->children.size();i++){
     pendingNode.push(f->children[i]);
   }
    }
}
void printatlevelK(treeNode<int>*root,int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
        cout<<root->data<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printatlevelK(root->children[i],k-1);
    }
}
//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main(){
    treeNode<int>*root=takeinputlevelwise();
    printlevelwise(root);
    cout<<"level 2";
    printatlevelK(root,2);

}