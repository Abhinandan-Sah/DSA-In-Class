#include<iostream>
#include<vector>
using namespace std;

// This problem can be solve using 2 method 
// 1) using loops
// 2) using 2 pointer approach

void Loop(vector<int>&v){
    int countZeros=0;
    int countOnes=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]==0){
            countZeros++;
        }
        else{
            countOnes++;
        }
    }

    for(int i=0; i<v.size(); i++){
        if(i<countZeros){
            v[i]=0;
        }
        else{
            v[i]=1;
        }
    }
}

void twoPointer(vector<int>&v){
    int s=0; 
    int e=v.size()-1;
    while(s<e){
        if(v[s]==0) s++;
        if(v[e]==1) e--;
        if(s>e){
            break;
        }
        if(v[s]==1 && v[e]==0){
            v[s]=0;
            v[e]=1;
            s++;
            e--;
        }
    }
}

int main()
{
    vector<int> v={1,0,0,1,0,1,0};
    Loop(v);
    twoPointer(v);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}