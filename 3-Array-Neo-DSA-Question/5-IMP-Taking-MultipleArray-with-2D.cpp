#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
void insertionSort(int arr[], int n){

    for(int round=1; round<n; round++){

        //storing 2 vale of arr in val
        int val=arr[round];
        int j=round-1;
        for(; j>=0; j--){
            
            // compare
            if(arr[j]>val){
                //shift
                arr[j+1]=arr[j];
            }
            else{
                //rukna hai
                break;
            }
        }

        arr[j+1]=val;

    }
}


int main(){
    // int k; 
    // cin>>k; 
    // int t=k;
    // int n;
    // int arr[100][100];
    // int dummyArr[k];

    // //The totalSize refers to final array to be created
    // int totalSize=0;

    // for(int i=0; i<k; i++){
    //     cin>>n;
    //     dummyArr[i]=n;
    //         totalSize+=n;
    //     // cout<<endl;
    //     for(int j=0; j<n; j++){
    //         cin>>arr[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<endl<<endl;
    
    // int e;
    // int finalArray[totalSize];
    // int f=0;
    // for(int i=0; i<t; i++){
    //     e=dummyArr[i];
    //     for(int j=0; j<e; j++){
    //         finalArray[f]=arr[i][j];
    //         f++;
    //     }
    // }
    // insertionSort(finalArray, totalSize);
    // // sort(finalArray.begin(), finalArray.end());
    //  for(int i=totalSize; i>=0; i--){
    //     cout<<finalArray[i]<<" ";
    // }

    int k; 
    cin>>k; 
    int t=k; 
    int n;
    int arr[100][100];
    int dummyArr[k];
    
    int totalSize=0; 
    for(int i=0; i<k; i++){
        cin>>n;
        dummyArr[i]=n;
        totalSize+=n;
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
        // cout<<endl;
    }
    // cout<<endl<<endl;
    
    int e;
    int finalArray[totalSize];
    int f=0;
    
    for(int i=0; i<t; i++){
        e=dummyArr[i];
        for(int j=0; j<e; j++){
            finalArray[f]=arr[i][j];
            f++;
        }
    }

    for(int i=0; i<totalSize; i++){
        cout<<finalArray[i]<<" ";
    }
    cout<<endl;
    
    insertionSort(finalArray, totalSize);
    
    for(int i=totalSize; i>=0; i--){
        cout<<finalArray[i]<<" ";
    }
    

    return 0;
}