#include<bits/stdc++.h>
using namespace std;
template<typename T>
// here T can be anything measn it can be int , string, char etc
class Treenode{
    public:
    T data;
    vector<Treenode<T>*>children;
    Treenode(T data){
        this->data=data;
        
    }

};
template<typename T>
void Printtree(Treenode<T>*root){
  
     cout<<root->data<<":";
     // here we are printing the root ke children
   for(int i=0;i<root->children.size();i++){
      cout<<root->children[i]->data<<" ";
   }
   cout<<endl;
   // here we are recursevily printing the root ke children
   for(int i=0;i<root->children.size();i++){
      Printtree(root->children[i]);
   }
}
template<typename T>
Treenode<T>*takeInputlevelwise(){
    cout<<"root data"<<endl;
    T rootdata;
    cin>>rootdata;
    cout<<rootdata<<endl;
    Treenode<T>*root= new Treenode<T>(rootdata);
    queue<Treenode<T>*>pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        Treenode<T>*front=pendingNode.front();
        pendingNode.pop();
        cout<<"number of children of"<<front->data <<endl;
        int numChild;
        cin>>numChild;
        cout<<numChild<<endl;
        for(int i=0;i<numChild;i++){
            T childData;
            cout<<"Enter"<<" "<<i<<" th child of"<<front->data<<endl;
            cin>>childData;
            cout<<childData<<endl;
            Treenode<T>*Node=new Treenode<T>(childData);
            front->children.push_back(Node);
            pendingNode.push(Node);
        }
    }
    return root;

}
template<typename T>
int countNode(Treenode<T>*root){
    if(root==nullptr) return 0;
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=countNode(root->children[i]);
    }
    return ans;
}
template<typename T>
int heightTree(Treenode<T>*root){
    if(root==nullptr) return 0;
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        // ans=1+max(heightTree(root->children[i]),ans);
        int h=heightTree(root->children[i]);
        
        cout<<root->children[i]->data<<" "<<h<<endl;
        ans=max(h,ans);

    }
    // here we find  the height of all the children of root then now, we add 1 for root node 
    
    return ans+1;
}

template<typename T>
int leafnode(Treenode<T>*root){
    if(root==nullptr) return 0;
    if(root->children.size()==0) return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++){
      ans+=leafnode(root->children[i]);    
    }
    return ans;


}
template<typename T>
bool isPresent(Treenode<T>*root,T x){
   if(root->data==x) return true;
   bool ans=false;
   for(int i=0;i<root->children.size();i++){
      ans= ans|isPresent(root->children[i],x);
   }
   return ans;
}

template<typename T>
void printlevelWise(Treenode<T>*root){
    if(root ==NULL) return;
    queue<Treenode<T>*>pendingnodes;
    pendingnodes.push(root);
    
    while(!pendingnodes.empty()){
        int levelsize=pendingnodes.size();
        for(int i=0;i<levelsize;i++){
            Treenode<T>*node=pendingnodes.front();
            pendingnodes.pop();
            cout<<node->data<<" ";
            for(int i=0;i<node->children.size();i++){
                pendingnodes.push(node->children[i]);
            }
        }
        cout<<endl;
    }
}
template<typename T>
void printlevelZigZag(Treenode<T>*root){
    if(root ==NULL) return;
    queue<Treenode<T>*>pendingnodes;
    pendingnodes.push(root);
    bool check=true; 
    while(!pendingnodes.empty()){
        int levelsize=pendingnodes.size();
        vector<int>levelnode;
        for(int i=0;i<levelsize;i++){
            Treenode<T>*node=pendingnodes.front();
            pendingnodes.pop();
            // cout<<node->data<<" ";
            levelnode.push_back(node->data);
          
            for(int i=0;i<node->children.size();i++){
                pendingnodes.push(node->children[i]);
            }
            
            
        }
        if(check){
            for(int i=0;i<levelnode.size();i++){
                cout<<levelnode[i]<<" ";
            }
         
        }else{
            for(int i=levelnode.size()-1;i>=0;i--){
                cout<<levelnode[i]<<" ";
            }
        }
        cout<<endl;
        check=!check;
    }
}

template<typename T>
int nextlargernode(Treenode<T>*root,int x){
     if(root==nullptr) return INT_MAX;
     int ans=INT_MAX;
     if(root->data>x){
        ans=root->data;
        return ans;
     }
    
     for(int i=0;i<root->children.size();i++){
          int val=nextlargernode(root->children[i],x);
          // this val tells me about that children[i] root ke liye nextlareg is x
          ans=min(ans,val);
     }
     return ans;
}

void solve(){
    Treenode<int>*root=takeInputlevelwise<int>();
    cout<<endl;
    // cout<<"number of node of tree"<<countNode(root)<<endl;;
    // cout<<"height of tree"<<heightTree(root)<<endl;
    // cout<<"s5 is present or "<<isPresent(root,5)<<endl;
    // cout<<" 8 is present or "<<isPresent(root,8)<<endl;
    // printlevelZigZag(root);
    // cout<<leafnode(root)<<endl;
    // cout<<nextlargernode(root,9);
    int x;
    cin>>x;
    if(nextlargernode(root,x)==INT_MAX){
        cout<<x<<" is the largest element in tree"<<endl;
    }else{
        cout<<nextlargernode(root,x)<<endl;
    }

  
}
signed main(){
  solve();
}