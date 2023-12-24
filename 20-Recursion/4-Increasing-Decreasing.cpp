#include<iostream>
using namespace std;

void increasingDecreasing(int n, int i){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    increasingDecreasing(n, i+1);
    if(i>1){
        cout<<i-1<<" ";
    }
}
int main()
{
     cout<<"Enter the value of n: "<<endl;
    int n; cin>>n;
    int i=1;
    increasingDecreasing(n,i);
    return 0;
}