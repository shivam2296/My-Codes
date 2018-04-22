#include<bits/stdc++.h>
using  namespace std;

int *dis;
vector <pair<pair<int,int>,int > > edges;

void allocate(int V)
{
   dis=new int[V];
}

void Initial_Weights(int V){
   for(auto i=0;i<V;i++){
      dis[i]=INT_MAX;
   }
}
void set_Weight(int vertex,int val)
{
   dis[vertex]=val;
}

void relax(int u,int v,int w){
   if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
      dis[v]=dis[u]+w;
   }
}

void print_weights(int V){
   cout<<"\nVertex\tDistance from source\n";
   for(auto i=0;i<V;i++){
      cout<<i<<"\t"<<dis[i]<<"\n";
   }
}

int main()
{
   int src,i,j,k,e,u,v,E,V,s,d,w;
   cout<<"Enter no. of vertex: ";
   cin>>V;
   allocate(V);

   cout<<"Enter no. of edges: ";
   cin>>E;

   cout<<"\nsource, destination and weight for "<<E<<" edges:";
   for(i=0;i<E;i++){
      cin>>s>>d>>w;
      edges.push_back({{s,d},w});
   }

   cout<<"\nEnter source: ";
   cin>>src;

   Initial_Weights(V);

   set_Weight(src,0);

   for(i=0;i<V-1;i++){
      for(j=0;j<E;j++){
            relax(edges[j].first.first,edges[j].first.second,edges[j].second);
      }
   }

   print_weights(V);
}
