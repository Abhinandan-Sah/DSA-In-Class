#include<iostream>
using namespace std;

int printSum(int n, int sum){
    if(n==0){
        return sum;
    }
    sum+=n;
    printSum(n-1, sum);
}
int main()
{
     cout<<"Enter the value of n: "<<endl;
    int n; cin>>n;
    int sum=0;
    cout<<printSum(n, sum);
    
    return 0;
}