 //@$hivam
#include<bits/stdc++.h>

using namespace std;

class Fibo{

    private:

        long long MAT[2][2];

        void run(long long n)
        {
            if(n==0 || n==1){
                return;
            }

        run(n/2);

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

    public:
    Fibo(){
        MAT[0][0]=1;
        MAT[0][1]=1;
        MAT[1][0]=1;
        MAT[1][1]=0;
    }

    long long fibo(long long N){
        run(N);
        return MAT[0][0];
    }
};
int main()
{
    long long n;
    cout<<"Enter n: ";
    cin>>n;
    assert(n>0);

    Fibo F;
    if(n==1){
       cout<<"\n"<<n<<" Fibonacci number is: "<<0<<"\n";
       return 0;
    }
    else if(n==2){
        cout<<"\n"<<n<<" Fibonacci number is: "<<1<<"\n";
        return 0;
    }
    else {
        cout<<"\n"<<n<<" Fibonacci number is: "<<F.fibo(n-2)<<"\n";
    }
}
