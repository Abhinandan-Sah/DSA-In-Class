#include <iostream>

using namespace std;

int main()
{
int n, i, j, edges, src_vrt, dest_vrt;
cout<<"Enter no. of vertices and edges: ";
cin>>n>>edges;
int adj[n][n]={0};
// for(i=0;i<n;i++){
// for(j=0;j<n;j++){
// adj[i][j]=0;
// }
// }

cout<<adj[0][0]<<endl;
cout<<"Input src and dest vertices of edges\n";
for(i=0;i<edges;i++){
cin>>src_vrt>>dest_vrt;
adj[src_vrt][dest_vrt] = 1;
}
cout<<"\nAdjacency matrix is:\n";
for(i=0;i<n;i++){
cout<<" ";
for(j=0;j<n;j++){
cout<<adj[i][j]<<'\t';
}
cout<<endl;
}
return 0;
}

