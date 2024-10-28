/*
Problem Statement



Alice is working on a project that requires sorting and displaying the frequency of elements in an array. She needs your help to write a program to sort an array of positive integers and display the elements sorted by frequency in descending order. If two elements have the same frequency, they should be sorted in ascending order of their values.



For this project, your task is to implement the logic of the merge sort and a recursive function.

Input format :
The first line contains an integer n, representing the number of elements in the array.

The second line contains n space-separated integers, arr[i].

Output format :
The output prints a single line containing the sorted elements of the array separated by spaces.

Code constraints :
max_n = 100

1 ≤ n ≤ 25

1 <= arr[i] <= 100

Sample test cases :
Input 1 :
6
1 1 2 3 3 3
Output 1 :
3 3 3 1 1 2 
Input 2 :
7
2 2 3 1 3 2 3
Output 2 :
2 2 2 3 3 3 1 
Input 3 :
6
1 2 3 1 2 3
Output 3 :
1 1 2 2 3 3 



*/

// You are using GCC
#include <iostream>

using namespace std;



const int MAX_N = 100;

int n;

void merge(int arr[], int left, int mid, int right) {
  int lInd=left;
  int rInd=mid+1;
  int tInd=left;
  int temp[100];
  while(lInd <= mid && rInd <= right){
      if(arr[lInd] < arr[rInd]){
          temp[tInd]=arr[lInd];
          lInd++;
      }
      else{
          temp[tInd]=arr[rInd];
          rInd++;
      }
      tInd++;
  }
  
  while(lInd<=mid){
      temp[tInd++]=arr[lInd++];
  }
  while(rInd<=right){
      temp[tInd++]=arr[rInd++];
  }
  
  for(int i=left; i<=right; i++){
      arr[i]=temp[i];
  }
}

void mergeSort(int arr[], int left, int right) {
    if(left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void countAndSortFrequency(int arr[], int n) {
    int freqArr[MAX_N][2] = {0};
    int values[MAX_N];

    int index = 0;
    for (int i = 0; i < n; i++) {
        int isAlreadyCounted = 0;
        for (int j = 0; j < index; j++) {
            if (values[j] == arr[i]) {
                freqArr[j][1]++;
                isAlreadyCounted = 1;
                break;
            }
        }
        if (!isAlreadyCounted) {
            values[index] = arr[i];
            freqArr[index][0] = arr[i];
            freqArr[index][1] = 1;
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (freqArr[i][1] < freqArr[j][1] || (freqArr[i][1] == freqArr[j][1] && freqArr[i][0] > freqArr[j][0])) {
                int temp = freqArr[i][0];
                freqArr[i][0] = freqArr[j][0];
                freqArr[j][0] = temp;

                temp = freqArr[i][1];
                freqArr[i][1] = freqArr[j][1];
                freqArr[j][1] = temp;
            }
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < freqArr[i][1]; j++) {
            cout << freqArr[i][0] << " ";
        }
    }
    cout << endl;
}

int main() {
    // int n;
    cin >> n;
    int arr[MAX_N];

    for (int i = 0; i < n; i++) cin >> arr[i];
    mergeSort(arr, 0, n-1);
    countAndSortFrequency(arr, n);

    return 0;
}