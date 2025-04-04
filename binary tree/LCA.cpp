
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void LCA_n1(Node*root,stack<Node*>&st1,int n1){
    // here first we search n1 and n2 in the tree
    if(root==NULL) return ;
   
    st1.push(root);
     if(root->val==n1) return ;
    if(n1<root->val){
        
        LCA_n1(root->left,st1,n1);
    }else {
       
        LCA_n1(root->right,st1,n1);
    }

}
void LCA_n2(Node*root,stack<Node*>&st2,int n2){
    if(root==NULL) return ;
    
    st2.push(root);
    if(root->val==n2) return ;
    if(n2<root->val){
        LCA_n2(root->left,st2,n2);
    }else{
        LCA_n2(root->right,st2,n2);
    }
}
Node *getLCANode(Node* root, int n1, int n2)
{
    // Complete the function.
    // here we we use the two stack and store the both node 
    stack<Node*>st1,st2;
    LCA_n1(root,st1,n1);
    LCA_n2(root,st2,n2);
    int n=st1.size(); 
    int m=st2.size();
  
    if(n>m){
        while(n!=m){
            st1.pop();
            n--;
        }
    }else if(n<m) {
         while(n!=m){
            st2.pop();
            m--;
         }
    }

        while((!st1.empty()&&!st2.empty())&&st1.top()!=st2.top()){
            st1.pop();
            st2.pop();
        }
       return st1.top();
    

}

Node* getBinaryTree(vector<int> &num, int*ind) {
    if(num[*ind] == -1)
        return NULL;
    Node* node = new Node(num[*ind]);
    (*ind)++;
    node->left = getBinaryTree(num,ind);
    (*ind)++;
    node->right = getBinaryTree(num,ind);
    return node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin>>n>>q;
        assert(n<=1000000);
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int ind = 0;
        Node* tree = getBinaryTree(arr,&ind);
        for(int i=0;i<q;i++){
            int k1,k2;
            cin>>k1>>k2;
            cout<<getLCANode(tree,k1,k2)->val<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
