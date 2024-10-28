#include <iostream>

#define MAX_SIZE 100000
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