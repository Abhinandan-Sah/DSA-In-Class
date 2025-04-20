#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {7,1,2,5,8,4,9,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;
    int i=1;
    int j=4;
    int maxSum = INT_MIN;
    int maxIdx=0;
    int prevSum =0;
    for(int i=0; i<k; i++){
        prevSum+=arr[i];
    }
    
    while(j<n){
        int currSum = prevSum + arr[j] - arr[i-1];
        if(maxSum < currSum){
            maxSum = currSum;
            maxIdx = i;
        }
        prevSum = currSum;
        i++; 
        j++;
    }
    cout<<"MaxSum= "<<maxSum<<endl;
    cout<<"MaxIndex= "<<maxIdx;

    return 0;
}