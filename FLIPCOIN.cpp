 //@$hivam
//Koi toh rok lo...!!!
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ii int,int
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795028841971693993751
#define all(arr)  arr.begin(),arr.end()
#define FIND(arr,v) arr.find(v)!=arr.end()
#define FOR(i,arr,n) for(i=arr;i<n;i++)
#define nl cout<<"\n"
#define spc cout<<" "
#define check1 cout<<"#"
#define check2 cout<<"*"
#define reverse_pq priority_queue<int,vector<int>,greater<int> >
#define VECTOR vector<int>
#define SET set<int>
#define do_it_fast ios_base::sync_with_stdio (false);cin.tie(NULL)
#define N 500005

/** REMEMBER
1. next_permutarrtion(all(V1));
2. search(arrll(V1),all(V2))!=V1.end()
3. S1.find(S2)
4. lower_bound(all(V1),val);
5. find(all(V1),val);
6. copy(all(V1),dest_itr);
*/
int arr[N];
int tree[4*N];
bool lazy[4*N];

ll query(int node,int l,int r,int i,int j)              //query in [i,j]
{
    if(i > j || l > r || l > j || r < i) return 0;      //Wrong range

    if (lazy[node]){                                    //Node is lazy. update it first.
        tree[node] = (r-l+1)-tree[node];                //Update
        lazy[node] = 0;                                 //Node has been updated.
        lazy[node*2] = !lazy[node*2];                   //But, do not update children propagate the laziness.
        lazy[node*2+1] = !lazy[node*2+1];
    }

    if(l>=i && r<=j)return tree[node];          //Query lies exactly in range.

    ll v1=query(node*2,l,(l+(r-l)/2),i,j);      //Query left child.
    ll v2=query(node*2+1,(l+(r-l)/2)+1,r,i,j);  //Query right child.

    return v1+v2;                               //Return answer using query of left and right child.
}

void update(int node,int l,int r,int i,int j)  //update [i,j] with value
{
    if(lazy[node]){                             //If node is lazy. First, update it.
        tree[node] = r-l+1-tree[node];          //Update this node.
        lazy[node] = false;                     //Updated this node, not lazy now.
        lazy[node*2] = !lazy[node*2];           //Do not update children, set them as lazy.
        lazy[(node*2)+1] = !lazy[(node*2)+1];
    }

    if(i > j || l > r || l > j || r < i) return ;   //Wrong range

    if(l>=i && r<=j){                           //Update lies inside range.
        tree[node]=r-l+1-tree[node];            //Now, update.
        lazy[node*2]= !lazy[node*2];            //But do not update children, set them as lazy.
        lazy[node*2+1] =!lazy[node*2+1];
       return ;
    }

    update(node*2,l,(l+(r-l)/2),i,j);           //Update left child.
    update(node*2+1,(l+(r-l)/2)+1,r,i,j);       //Update right child.
    tree[node]=(tree[node*2]+tree[node*2+1]);   //Update current node using updated left and right child.
}

int main()
{
    int q,n,i,j,k;
    cin>>n>>q;

    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==0){
            update(1,0,n-1,b,c);
        }
        else{
            cout<<query(1,0,n-1,b,c)<<"\n";
        }
    }
}
