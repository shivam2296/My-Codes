#include<bits/stdc++.h>
using namespace std;

int main()
{
   string str;
   char arr[100];
   char ch;

   ch=getc(stdin);                  //leaves the delimiter in the input stream
   cout<<"ch=getc(): "<<ch<<"\n";

   ch=getchar();                    //leaves the delimiter in the input stream
   cout<<"ch=getchar(): "<<ch<<"\n";

   cin.get(ch);
   cout<<"cin.get(ch): "<<ch<<"\n";    //leaves the delimiter in the input stream.

   cin.get(arr,100);
   cout<<"cin.get(r,100): "<<arr<<"\n";   //leaves the delimiter in the input stream.

   cin.getline(arr,100);     //old C style.    //doesn't leaves the delimiter in the stream.
   cout<<"cin.getline(r,100): "<<arr<<"\n";

   string S;
   getline(cin,S);                              //for string objects. doesn't leaves the delimiter in the stream.
   cout<<"getline(cin,S): "<<S<<"\n";

   gets(arr);
   cout<<"gets(r): "<<arr;                   //doesn't leaves the delimiter in the stream.
}
