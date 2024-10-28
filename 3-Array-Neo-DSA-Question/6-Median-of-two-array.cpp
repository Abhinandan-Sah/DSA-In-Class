#include<iostream>
#include<iomanip>
using namespace std;

void insertionSort(int arr[], int n){
    for(int round=1; round<(n-1); round++){
        int val=arr[round];
        int j=round-1;
        for(; j>=0; j--){
            if(arr[j]>val){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        
        arr[j+1]=val;
    }
}

int main(){
    // int n1, n2;
    // cin>>n1;
    // cin>>n2;
    // int n3=n1+n2;
    // if((0<=n1<=100 && 0<=n2<=100 && n3<=100 )){
    // // int n3=n1+n2;
    // int arr1[n1], arr2[n2], arr3[n3];
    // for(int i=0; i<n1; i++){
    //     cin>>arr1[i];
    // }
    // for(int i=0; i<n2; i++){
    //     cin>>arr2[i];
    // }
    
    // for(int i=0; i<n1; i++){
    //     arr3[i]=arr1[i];
    
    // }
    // int k=0;
    // for(int i=n1; i<n3; i++){
    //     arr3[i]=arr2[k];
    //     k++;
    // }
    
    // insertionSort(arr3, n3);
    // float median;
    // float sum=0;
    // for(int i=0; i<n3; i++){
    //     sum= sum+arr3[i];
    // }
    // median=(sum/n3);
    // // cout<<fixed<<setprecision(1)<<median;
    
    // cout<<median<<endl;
    // }
    
    int n1;
    cin>>n1;
    int n2;
    cin>>n2;
    int arr1[n1];
    for(int i=0; i<n1; i++){
        cin>>arr1[i];
    }
   
    int arr2[n2];
    for(int i=0; i<n2; i++){
        cin>>arr2[i];
    }
    if(n1<=100 && n2<=100 && n1>=0 && n2>=0 && (n1+n2)<=100){
        int n3=n1+n2;
        int arr3[n3];
        for(int i=0; i<n1; i++){
            arr3[i]=arr1[i];
        }
        int k=0; 
        for(int i=n1; i<n3; i++){
            arr3[i]=arr2[k];
            k++;
        }
        insertionSort(arr3, n3);
        double median;
        // float sum=0; 
        // for(int i=0; i<n3; i++){
        //     sum=sum+arr3[i];
        // }
        if(n3%2==0){
            int mid1=arr3[(n3-1)/2];
            int mid2=arr3[n3/2];
            median=(double)(mid1+mid2)/2.0;
        }
        else{
            median=(double)arr3[n3/2];
        }
        
        cout<<median<<endl;
    }
    else{
        cout<<"invalid input";
    }
    return 0; 
}
