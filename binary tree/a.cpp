#include<bits/stdc++.h>
using namespace std;
// #define int long long 
#define endl "\n"
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
// here we are taking the input of the tree for any datatype , means
// depth taking input 
template<typename T>
Treenode<T>*takeInput(){
  T rootdata;
  cin>>rootdata;
  // here we make the rootdata 
  Treenode<T>*root= new Treenode<T>(rootdata);
  int n;
  cout<<"Enter the number Of child"<<rootdata<<endl;
  cin>>n;
  for(int i=0;i<n;i++){
    Treenode<T>*child=takeInput<T>();
    root->children.push_back(child);
  }
  return root;
}

template<typename T>
Treenode<T>*takeInputlevelwise(){
    cout<<"root data"<<endl;
    T rootdata;
    cin>>rootdata;
    Treenode<T>*root= new Treenode<T>(rootdata);
    queue<Treenode<T>*>pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        Treenode<T>*front=pendingNode.front();
        pendingNode.pop();
        cout<<"number of children of"<<front->data <<endl;
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            T childData;
            cout<<"Enter"<<" "<<i<<" th child of"<<front->data<<endl;
            cin>>childData;
            Treenode<T>*Node=new Treenode<T>(childData);
            front->children.push_back(Node);
            pendingNode.push(Node);
        }
    }
    return root;

}
void solve(){
    // Treenode<int>*root= new Treenode<int>(1);
    // Treenode<int>*node1= new Treenode<int>(2);
    // Treenode<int>*node2= new Treenode<int>(3);
    // Treenode<int>*node3= new Treenode<int>(4);
    // Treenode<int>*node4= new Treenode<int>(5);
    //  Treenode<int>*node5= new Treenode<int>(6);
    //   Treenode<int>*node6= new Treenode<int>(7);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // root->children.push_back(node3);
    // root->children.push_back(node4);
    // node2->children.push_back(node5);
    // node3->children.push_back(node6);
    // we have to call the function like take 
   Treenode<int>*root=takeInputlevelwise<int>();
    Printtree(root);

}
int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}