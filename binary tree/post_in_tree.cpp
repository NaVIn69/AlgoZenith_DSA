
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
map<int,int>mpp;
Node*create_in_post_to_binarytree(int lin,int rin,int lpos,int rpos,vector<int>&in,vector<int>&post){
    if(rin<lin) return NULL;
    // if(rpos<lpos) return NULL;
    int rootval=post[rpos];
    int brpoints=mpp[rootval];
    Node*root=new Node(rootval);
    root->left=create_in_post_to_binarytree(lin,brpoints-1,lpos,lpos+(brpoints-lin)-1,in,post);
    root->right=create_in_post_to_binarytree(brpoints+1,rin,rpos-(rin-brpoints),rpos-1,in,post);

    return root;

}

Node* getBinaryTree(vector<int>&in,vector<int>&post)
{
  // Complete the function.
  for(int i=0;i<in.size();i++){
    mpp[in[i]]=i;
  }
  int n=in.size();
  return create_in_post_to_binarytree(0,n-1,0,n-1,in,post);
}

void generateArray(Node* root, vector<int>&ans){
    if(root==NULL){
        ans.push_back(-1);
        return;
      }
    ans.push_back(root->val);
    generateArray(root->left,ans);
    generateArray(root->right,ans);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        assert(n<=1000000);
        vector<int>arr1(n);
        for(int i=0;i<n;i++)
            cin>>arr1[i];
        vector<int>arr2(n);
        for(int i=0;i<n;i++)
            cin>>arr2[i];
        Node* tree = getBinaryTree(arr1,arr2);
        vector<int>ans;
        generateArray(tree,ans);
        cout<<"<p>";
        for(auto v:ans)cout<<v<<" ";
        cout<<" "<<"&nbsp;</p>";
        // cout<<"\n";
    }
    return 0;
}
