 //@$hivam
//Koi toh rok lo...!!!

#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* next[26];
    int word;
};

class Trie{
    Node* root;

    Node* add(Node* root,string key,int index)
    {
        if(root==NULL){
            root=new Node;
            memset(root->next,0,sizeof(root->next));
            root->word=0;
        }
        if(index==key.size()){
            (root->word)+=1;
            return root;
        }
        root->next[key[index]-'A']=add(root->next[key[index]-'A'],key,index+1);

        return root;
    }

    int lookup(Node* root, string key,int index)
    {
        if(root==NULL || index>key.length()){
            return 0;
        }
        if(index==key.length()&& (root->word)>0){
            return (root->word);
        }
        return lookup(root->next[key[index]-'A'],key,index+1);
    }
public:

    Trie(){
        root=NULL;
    }
    /*Adds str to the trie*/
    void add_str(string str){
        root=add(root,str,0);
    }
    /*Returns the frequency of str*/
    int find_str(string str){
        return lookup(root,str,0);
    }
};

int main()
{
    Trie T;
    T.add_str("SHIVAM");
    T.add_str("SHIVAM");
    T.add_str("APPLE");
    T.add_str("APPLE");
    T.add_str("APPLE");
    T.add_str("APPLE");

    cout<<"SHIVAM :"<<T.find_str("SHIVAM")<<endl;
    cout<<"APPLE :"<<T.find_str("APPLE")<<endl;
    cout<<"SAUMYA :"<<T.find_str("SAUMYA");
}
