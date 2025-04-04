class Solution {
public:
 struct node{
    node*child[26];
    int prefix;
    node(){
        prefix=0;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
 };
 struct trie{
     node*root;
     trie(){
        root=new node;
     }
     void insert(string s){
         node*curr=root;
         for(int i=0;i<s.size();i++){
             int x=s[i]-'a';
            
             if(curr->child[x]==NULL){
                curr->child[x]=new node;
             }
             curr=curr->child[x];
             curr->prefix++;
         }

     }
     string getLCP(int totalwords){
          string ans="";
          node*curr=root;

          while(true){
          int cnt=0;
          int next_char=-1;
          for(int i=0;i<26;i++){
              if(curr->child[i]!=NULL){
                cnt++;
                next_char=i;
              }
          }
          cout<<cnt<<" "<<next_char<<endl;
          cout<<curr->child[next_char]->prefix<<endl;
              if(cnt!=1 || curr->child[next_char]->prefix != totalwords ) break;
              // because root node pe 1 se jayda opening hai , means we have a words which start from different char
             // prefix must be equal to the total words
             ans+=(char)(next_char+'a');
             
             curr=curr->child[next_char]; 
          }
          return ans;
     }

 };
    string longestCommonPrefix(vector<string>& strs) {
         if(strs.size()==0) return "";
         if(strs.size()==1) return strs[0];
        trie*newnode=new trie();
     
      
        for(int i=0;i<strs.size();i++){
            
             newnode->insert(strs[i]);

        }
        return newnode->getLCP(strs.size());

    }
};
int main(){
    
}