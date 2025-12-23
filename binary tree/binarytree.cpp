#include<iostream>
#include<queue>
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
void printtree(binarytreenode<int>*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<":";
    if(root->left!=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}
binarytreenode<int>*takeinput(){
    int rootdata;
    // cin>>rootdata;
    cout<<"enter data"<<endl;
     cin>>rootdata;
     if(rootdata==-1){
        return NULL;
     }
     binarytreenode<int>*root=new binarytreenode<int>(rootdata);
     binarytreenode<int>*leftchild=takeinput();
     binarytreenode<int>*rightchild=takeinput();
     root->left=leftchild;
     root->right=rightchild;
     return root;
}
binarytreenode<int>*takeinputlevelwise(){
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1){
        return NULL;
    }
    binarytreenode<int>*root=new binarytreenode<int>(rootdata);
    queue<binarytreenode<int>*>pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        binarytreenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter leftchild of "<<front->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1){
            binarytreenode<int>*child=new binarytreenode<int>(leftchild);
            front->left=child;
            pendingnodes.push(child);
        }
        cout<<"enter rightchild of "<<front->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1){
            binarytreenode<int>*child=new binarytreenode<int>(rightchild);
            front->right=child;
            pendingnodes.push(child);
        }

    }
    return root;
}
void printlevelwise(binarytreenode<int>*root){
queue<binarytreenode<int>*>pendingnodes;
pendingnodes.push(root);
pendingnodes.push(NULL);
while(!pendingnodes.empty()){
    binarytreenode<int>*front=pendingnodes.front();
    pendingnodes.pop();
    if(front==NULL){
        if(pendingnodes.empty()){
            break;
        }
        pendingnodes.push(NULL);
        cout<<endl;
        continue;

    }
    cout<<front->data<<" ";
    if(front->left!=NULL){
        pendingnodes.push(front->left);
    }
    if(front->right!=NULL){
        pendingnodes.push(front->right);
    }
}
}
int countnodes(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+countnodes(root->left)+countnodes(root->right);
}
bool isnodepresent(binarytreenode<int>*root,int x){
    if(root==NULL){
        return false;
    }
    if(root->data==x){
        return true;
    }
    return isnodepresent(root->left,x)||isnodepresent(root->right,x);
}
int sum(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    return root->data+sum(root->left)+sum(root->right);
}
int height(binarytreenode<int>*root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
int isbalance(binarytreenode<int>*root){
    if(root==NULL) return 0;
    int lh=isbalance(root->left);
    int rh=isbalance(root->right);
    

} 
bool istreebalanced(binarytreenode<int>*root){

}
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(){
    binarytreenode<int>*root=takeinputlevelwise();
    printlevelwise(root);
    cout<<endl;
    cout<<countnodes(root)<<endl;
    cout<<isnodepresent(root,0)<<endl;

   
}