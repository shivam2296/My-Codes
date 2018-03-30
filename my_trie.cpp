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
        if(root==NULL){             //Node is not present, so make a new one.
            root=new Node;
            memset(root->next,0,sizeof(root->next));        //Initialize it.
            root->word=0;
        }
        if(index==key.size()){                  //Index ends, so increment the words.
            (root->word)+=1;
            return root;
        }
        root->next[key[index]-'A']=add(root->next[key[index]-'A'],key,index+1);     //Add a child(str[index+1]) to str[index].
        return root;
    }

    int lookup(Node* root, string key,int index)
    {
        if(root==NULL){  //No node, but string is not finished.
            return 0;
        }
        if(index==key.length()){                //Lets check the no. words ending here.
            return (root->word);
        }
        return lookup(root->next[key[index]-'A'],key,index+1);  //Check the lower level.
    }

    bool check_child(Node* node)            //If current node has characters.
    {
        if(node==NULL){
            return true;
        }
        for(int i=0;i<26;i++){
            if(node->next[i]!=NULL)
                return false;
        }
        return true;
    }

    bool del(Node* root, string key,int index)
    {
        if(root==NULL){                     //There is no node, wrong node.
            return false;
        }

        else if(index==key.size()){                       //This is the point. Don't go further.
            if((root->word)==0){                    //No word ends here. Do not delete the upper levels.
                return false;
            }
            else if(root->word==1){                 //Only one word on this node.
                bool del_curr=check_child(root);    //Check if any child exists.
                if(del_curr){                       //No child exists, free to delete this node.
                    delete root;
                    root=NULL;
                    return true;                    //Delete and upper levels can also delete the nodes.
                }
                else {
                    root->word=0;                   //Child exists. Upper levels cannot delete the nodes.
                    return false;
                }
            }
            else {              //Many words are ending here.
                (root->word)-=1;                //Just delete one word and upper levels cannot delete their nodes.
                return false;
            }
        }

        else{
            bool del_curr=del(root->next[key[index]-'A'],key,index+1);   //Ask the lower node to delete.
            if(del_curr){           //Yes,the child says ->delete this node.
                delete root;
                root=NULL;
                return true;
            }
            else return false;
        }
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
    /*Deletes a copy of str if found*/
    bool del_str(string str){
        return del(root,str,0);
    }
};

int main()
{
    Trie T;
    T.add_str("SHIVAM");
    T.add_str("SHIVAM");
    T.add_str("SHIV");
    T.add_str("APPLE");
    T.add_str("APPLE");
    T.add_str("APPLE");
    T.add_str("A");

    cout<<"A :"<<T.find_str("A")<<endl;
    cout<<"SHIV :"<<T.find_str("SHIV")<<endl;
    cout<<"SHIVAM :"<<T.find_str("SHIVAM")<<endl;
    cout<<"APPLE :"<<T.find_str("APPLE")<<endl;
    cout<<"SAUMYA :"<<T.find_str("SAUMYA")<<endl;

    T.del_str("SHIVAM");
    T.del_str("SHIV");
    T.del_str("A");
    cout<<"\n***Deletion***\n\n";
    cout<<"A :"<<T.find_str("A")<<endl;
    cout<<"SHIV :"<<T.find_str("SHIV")<<endl;
    cout<<"SHIVAM :"<<T.find_str("SHIVAM")<<endl;
    cout<<"APPLE :"<<T.find_str("APPLE")<<endl;
    cout<<"SAUMYA :"<<T.find_str("SAUMYA")<<endl;
}
