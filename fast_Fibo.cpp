 //@$hivam
//Koi toh rok lo...!!!
#include<bits/stdc++.h>

using namespace std;

long long MAT[2][2]={1,1,1,0};

void fibo(long long n)
{
    if(n==0||n==1){
        return;
    }
        fibo(n/2);

        long long a=MAT[0][0]*MAT[0][0]+MAT[0][1]*MAT[1][0];
        long long b=MAT[0][0]*MAT[0][1]+MAT[0][1]*MAT[1][1];
        long long c=MAT[1][0]*MAT[0][0]+MAT[1][1]*MAT[1][0];
        long long d=MAT[1][0]*MAT[0][1]+MAT[1][1]*MAT[1][1];

        MAT[0][0]=a;
        MAT[0][1]=b;
        MAT[1][0]=c;
        MAT[1][1]=d;

   if(n&1){
        long long a=MAT[0][0]*1+MAT[0][1]*1;
        long long b=MAT[0][0]*1+MAT[0][1]*0;
        long long c=MAT[1][0]*1+MAT[1][1]*1;
        long long d=MAT[1][0]*1+MAT[1][1]*0;

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
