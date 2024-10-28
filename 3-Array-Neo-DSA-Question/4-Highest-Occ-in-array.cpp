// This is a OptimizedSolution

/*
#include <iostream>

#define MAX_SIZE 100
using namespace std;

int main() {
    int size1,size2,i,j;
    cin>>size1;
    int array1[size1];
    for(i = 0; i < size1;i++)
      cin>>array1[i];
    cin>>size2;
    int array2[size2];
    for(j = 0; j < size2;j++)
     cin>>array2[j];

    int mergedArray[MAX_SIZE]; // The merged array can have a maximum size
    int mergedSize = 0; // Keeps track of the size of the merged array

    // Merge the arrays
    for (int i = 0; i < size1; i++) {
        mergedArray[mergedSize] = array1[i];
        mergedSize++;
    }

    for (int i = 0; i < size2; i++) {
        mergedArray[mergedSize] = array2[i];
        mergedSize++;
    }

    // Count the occurrences of each element
    int count[MAX_SIZE] = {0}; // Initialize count array with zeros

    for (int i = 0; i < mergedSize; i++) {
        count[mergedArray[i]]++;
    }

    // Find the most repeated elements and print them once

    int maxCount = 0;

    for (int i = 0; i < mergedSize; i++) {
        if (count[mergedArray[i]] > maxCount) {
            maxCount = count[mergedArray[i]];
        }
    }

    for (int i = 0; i < mergedSize; i++) {
        if (count[mergedArray[i]] == maxCount) {
            cout<<mergedArray[i] <<" ";
            count[mergedArray[i]] = 0; // Reset count to avoid printing duplicates
        }
    }

    cout<<endl;

    return 0;
}

*/

// 2-> THis is My brute force solution

/*
#include<iostream>
using namespace std;

void countHigFreq(int arr[], int n){

    int p=n; 
    int arr1[100];
    
    for(int i=0 ;i<n; i++){
        arr1[i]=arr[i];
    }
    int count=0; 
    int maxCount=0; 
    int i; 
    
    for(i=0; i<n; i++){
        count=1;
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                count++;
                for(int k=j; k<n; k++){
                    arr[k]=arr[k+1];
                }
            
            n=n-1;
            j=j-1;
            }
        }
    
        if(count>=maxCount){
            maxCount=count;
        }
     
    }
    
    int x;
    int c=0;
    for(x=0; x<p; x++){
        c=1;
        for(int y=x+1; y<p; y++){
            if(arr1[x]==arr1[y]){
                c++;
                for(int z=y; z<p; z++){
                    arr1[z]=arr1[z+1];
                }
                p--;
                y--;
            }
        }
        if(c==maxCount){
            cout<<arr1[x]<<" ";
        }
    }
    
}

int main(){
    int n; 
    cin>>n; 
    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    int m;
    cin>>m;
    int arr2[m];
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }
    int p=n+m;
    int arr3[p];
    for(int i=0; i<n; i++){
        arr3[i]=arr1[i];
    }
    int k=0; 
    for(int i=n; i<p; i++){
        arr3[i]=arr2[k];
        k++;
    }
    
    countHigFreq(arr3, p);
    
    return 0;
}
*/