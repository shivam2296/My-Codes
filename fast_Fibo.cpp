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

/** REMEMBER
1. next_permutarrtion(all(V1));
2. search(arrll(V1),all(V2))!=V1.end()
3. S1.find(S2)
4. lower_bound(all(V1),val);
5. find(all(V1),val);
6. copy(all(V1),dest_itr);
*/
ll MAT[2][2]={1,1,1,0};

void fibo(ll n)
{
    if(n==0||n==1){
        return;
    }
    if(n&1){
        fibo(n/2);

        ll a=MAT[0][0]*MAT[0][0]+MAT[0][1]*MAT[1][0];
        ll b=MAT[0][0]*MAT[0][1]+MAT[0][1]*MAT[1][1];
        ll c=MAT[1][0]*MAT[0][0]+MAT[1][1]*MAT[1][0];
        ll d=MAT[1][0]*MAT[0][1]+MAT[1][1]*MAT[1][1];

        MAT[0][0]=a;
        MAT[0][1]=b;
        MAT[1][0]=c;
        MAT[1][1]=d;

        a=MAT[0][0]*1+MAT[0][1]*1;
        b=MAT[0][0]*1+MAT[0][1]*0;
        c=MAT[1][0]*1+MAT[1][1]*1;
        d=MAT[1][0]*1+MAT[1][1]*0;

        MAT[0][0]=a;
        MAT[0][1]=b;
        MAT[1][0]=c;
        MAT[1][1]=d;
    }
    else{
        fibo(n/2);

        ll a=MAT[0][0]*MAT[0][0]+MAT[0][1]*MAT[1][0];
        ll b=MAT[0][0]*MAT[0][1]+MAT[0][1]*MAT[1][1];
        ll c=MAT[1][0]*MAT[0][0]+MAT[1][1]*MAT[1][0];
        ll d=MAT[1][0]*MAT[0][1]+MAT[1][1]*MAT[1][1];

        MAT[0][0]=a;
        MAT[0][1]=b;
        MAT[1][0]=c;
        MAT[1][1]=d;
    }
}
int main()
{

    ll n;
    cout<<"Enter n: ";
    cin>>n;
    assert(n>0);
    fibo(n-1);
    cout<<"\n"<<n<<"th Fibonacci number is: "<<MAT[0][0]<<"\n";
}
