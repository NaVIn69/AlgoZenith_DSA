// here we have given the expression and , we have make the expression tree from that 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"
struct node{
  char val;
  node*left;
  node*right;
  node(int data){
    this->val=data;
    this->left=NULL;
    this->right=NULL;
  }

};

// here we have given the expreesion to evaluate , and first convert into the expression tree
node*expressiontree(string expression){
    // stack<char>st;
    stack<node*>st;
    for(auto ch:expression){
        if(ch==')'){
            if(!st.empty()){
                node*rt=st.top(); st.pop();
                node*op=st.top(); st.pop();
                node*lf=st.top();st.pop();
                op->right=rt;
                op->left=lf;
                st.push(op);
            }
        }else if(ch!='('){
            node*temp=new node(ch);
            st.push(temp);
        }
    }
    return st.empty() ? nullptr : st.top();
}
// if we have the expression tree then we can convert that into postFixNotation by postorder tarversal
// here we are converting the expression tree into the postfixnotation , prefixnotation, inordernotation
void postorderNotation(node*root,string &ans){
    if(root==NULL) return ;
    postorderNotation(root->left,ans);
    postorderNotation(root->right,ans);
    cout<<root->val<<" ";
    ans+=root->val;
}
void inorderNotation(node*root,string&ans){
    if(root==NULL) return ;
    inorderNotation(root->left,ans);
    cout<<root->val<<" ";
    inorderNotation(root->right,ans);

}
void preorderNotation(node *root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    preorderNotation(root->left);
    preorderNotation(root->right);
}

// here we have given the postfix notation now ,we have to convert into the expression tree and also we have to evaluate it
node*postfixToexpressiontree(string str){
     stack<node*>st;
     for(auto val:str){
        if(val=='*'||val=='-'||val=='+'||val=='/'){
            node*left=st.top() ; st.pop();
            node*right=st.top() ;st.pop();
            node*temp=new node(val);
            temp->left=right;
            temp->right=left;
            st.push(temp);
        }else{
            node*temp=new node(val);
            st.push(temp);
        }
     }
     return st.empty() ? nullptr : st.top();
}
int calculate(char op,int lval,int rval){
     if(op=='+'){
        return lval+rval;
     }else if(op=='-') return lval-rval;
     else if(op=='*') return lval*rval;
     else if(op=='/') return lval/rval;
}
int eval(node*curr){
    if(curr->val=='*'||curr->val=='/'|| curr->val=='+'||curr->val=='-'){
        int lval=eval(curr->left);
        int rval=eval(curr->right);
        return calculate(curr->val,lval,rval);
    }else{
        return curr->val-48;
    }
}
void print(node*root){
    if(root==NULL) return ;
   cout<<root->val<<" : ";
   if(root->left!=NULL){
    cout<<" L "<<root->left->val<<", ";
   }
   if(root->right!=NULL){
    cout<<" R "<<root->right->val;
   }
   cout<<endl;
   print(root->left);
   print(root->right);
}

void solve(){
   string str;
   cin>>str;
   node*root=expressiontree(str);
//    cout<<root->val<<endl;
   print(root);
   cout<<"value of expression is "<<eval(root)<<endl;
   cout<<"postfix notation of that expression is"<<" "<<endl;
   string str2="";
   // this give me the postordernotation of the tree
   postorderNotation(root,str2);
   node*pre=postfixToexpressiontree(str2);
   print(pre);

}

// "((1+(5*3))/4)"

signed main(){
  solve();
}
