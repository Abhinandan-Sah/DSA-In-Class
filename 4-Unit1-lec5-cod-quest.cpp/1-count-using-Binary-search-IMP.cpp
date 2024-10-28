/* 
#include<iostream>
using namespace std;


int binarySearch(int arr[], int n, int k){
    int s=0; 
    int e=n-1; 
    int mid= (s+e)/2;
    int index=0;
    while(s<=e){
        if((arr[mid-1] < k && k < arr[mid+1]) || arr[mid]==k){
            return mid;
        }
        else if(arr[mid]>k){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    if(1<=n<=10){
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int k;
        cin>>k;
        int index=binarySearch(arr, n, k);
        cout<<index<<endl;
        int c=0;
        int x=0;
        if(index!=-1){
        for(int i=index; i>=0; i--){
            c++;
        }
        cout<<c;
        }else{
            cout<<x;
        }
    }
    
    return 0;
}

*/

// optmize of solution
/*
#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int k){
    int s=0; 
    int e=n-1; 
    // int mid= (s+e)/2;
    // int index=0;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(arr[mid] <= k){
            s= mid+1;
        }
        else{
            e=mid-1;
        }

    }
    return s;
}

int main(){
    int n;
    cin>>n;
    
    if(1<=n && n <= 10){
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
            if( arr[i] < -100 || arr[i] > 100){
                cout<<0;
                return 0;
            }
        }
        int k;
        cin>>k;
        if(k < -100 || k > 100) {
            cout<< 0;
            return 0;
        }
        int index=binarySearch(arr, n, k);
        cout<<index;
        // int c=0;
        // int x=0;
        // if(index!=-1){
        // for(int i=index; i>=0; i--){
        //     c++;
        // }
        // cout<<c;
        // }else{
        //     cout<<x;
        // }
    }
    
    return 0;
}
*/

#include<iostream>
using namespace std;

int main(){
    int m;
    int n;
    cin>>m;
    cin>>n;
    int target;
    cin>>target;
    if(1<=m && m<=10 && 1<=n && n<=10){
        int arr[m][n];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }
        int p=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]==target){
                    cout<<"["<<i<<"]"<<"["<<j<<"]";
                    p=1;
                }
            }
        }
        
        if(p==0){
            cout<<"Element not found";
        }
        
    }
    
    return 0;
}



