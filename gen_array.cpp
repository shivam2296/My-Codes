#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Array{
    int size;
    T* arr;

public:
    Array(int sz):size(sz){
        arr=new T[size];
    }

    T& operator[](int n){
        if(n>=size){
            cout<<"Index out of bounds";
            exit(0);
        }
        else return arr[n];
    }

    T max_arr(){
        T max=arr[0];
        for(int i=0;i<size;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }

    void input_arr(){
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
    }
    void output_arr(){
        for(int i=0;i<size;i++){
            cout<<"arr["<<i<<"]="<<arr[i]<<"\n";
        }
    }
};

int main()
{
    int size=5;
    Array<float>A(size);

    A.input_arr();
    A.output_arr();

    cout<<"\n";
    cout<<"max="<<A.max_arr()<<"\n";

    Array<int>B(size);

    B.input_arr();
    B.output_arr();

    cout<<"\n";
    cout<<"max="<<B.max_arr()<<"\n";
}
