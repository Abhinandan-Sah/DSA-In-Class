//  #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// vector<int> merge_k_sorted_arrays(const vector<vector<int>>& arrays) {
//     vector<int> merged_array;
    
//     // Merge all arrays into a single vector
//     for (const vector<int>& array : arrays) {
//         merged_array.insert(merged_array.end(), array.begin(), array.end());
//     }
    
//     // Sort the merged vector in descending order
//     sort(merged_array.begin(), merged_array.end(), greater<int>());
    
//     return merged_array;
// }

// int main() {
//     int K;
//     cin >> K; // Number of sorted arrays
    
//     vector<vector<int>> arrays;
//     for (int i = 0; i < K; ++i) {
//         int n;
//         cin >> n; // Size of the current array
        
//         vector<int> array(n);
//         for (int j = 0; j < n; ++j) {
//             cin >> array[j]; // Elements of the current array
//         }
//         arrays.push_back(array);
//     }
    
//     vector<int> merged_array = merge_k_sorted_arrays(arrays);
    
//     // Print the merged array in descending order
//     for (int num : merged_array) {
//         cout << num << " ";
//     }
    
//     return 0;
// }

// #include<iostream>
// #include<iomanip>
// using namespace std;

// int main(){
//     int n1, n2;
//     int n3=n1+n2;
//     int arr1[n1], arr2[n2+n1];
//     cin>>n1>>n2;
//     for(int i=0; i<n1; i++){
//         cin>>arr1[i];
//     }
//     for(int i=0; i<n2; i++){
//         cin>>arr2[i];
//     }
//     int k=0;
//     for(int i=n2; i<n3; i++){
//         arr2[i]=arr1[k++];
//     }
//     float median=0;
//     int sum=0;
//     for(int i=0; i<n3; i++){
//         sum= sum+arr2[i];
//     }
//     median=sum/n3;
//     cout<<median;
//     return 0; 
// }

// #include<iostream>
// #include<iomanip>
// using namespace std;

// int main(){
//     int n1, n2;
//     cin>>n1;
//     cin>>n2;
//     int n3=n1+n2;
//     int arr1[n1], arr2[n3];
//     for(int i=0; i<n1; i++){
//         cin>>arr1[i];
//     }
//     for(int i=0; i<n2; i++){
//         cin>>arr2[i];
//     }
//     int k=0;
//     for(int i=n2; i<n3; i++){
//         arr2[i]=arr1[k];
//         k++;
//     }
//     int sum=0;
//     for(int i=0; i<n3; i++){
//         sum= sum+arr2[i];
//     }
//     float median=sum/n3;
//     cout<<fixed<<setprecision(2)<<median<<endl;

   
//     return 0; 
// }

#include<iostream>
#include<vector>
using namespace std;

void removeDuplicate(vector<int>arr, int n){
    for(int round=0; round<n-1; round++){
        int val=arr[round];
        for(int step=round+1; step<n; step++){
            if(val==arr[step]){
                arr.pop_back();
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr1(n);
    for(int i=0; i<n; i++){
        cin>>arr1[n];
    }
    removeDuplicate(arr1, n);
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    // int m;
    // cin>>m;
    // // int arr2[m];
    // vector<int>arr2(m);
    // for(int i=0; i<m; i++){
    //     cin>>arr2[m];
    // }
    // removeDuplicate(arr2, m);
    return 0;
}