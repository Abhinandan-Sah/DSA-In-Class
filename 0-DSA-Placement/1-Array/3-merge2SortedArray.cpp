#include<iostream>
#include<vector>
using namespace std;

vector<int> mergeArray(vector<int>arr1, vector<int>arr2){
    int n=arr1.size();
    int m=arr2.size();
    vector<int>res(n+m);
    int i=0; //for arr1;
    int j=0; //for arr2;
    int k=0; //for res;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            res[k]=arr1[i];
            i++;
        }
        else{
            res[k]=arr2[j];
            j++;
        }
        k++;
    };
    if(i==n){ // means array1 is empty
        while(j<m){
            res[k]=arr2[j];
            j++; k++;
        }
    }
    if(j==m){ // means array1 is empty
        while(i<n){
            res[k]=arr1[i];
            i++; k++;
        }
    }
    
    return res;
    
}

int main()
{
    vector<int> arr1;
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    vector<int> arr2;
    arr2.push_back(5);
    arr2.push_back(6);
    arr2.push_back(7);
    arr2.push_back(8);
    
    vector<int> v= mergeArray(arr1, arr2);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << endl;

    return 0;
}