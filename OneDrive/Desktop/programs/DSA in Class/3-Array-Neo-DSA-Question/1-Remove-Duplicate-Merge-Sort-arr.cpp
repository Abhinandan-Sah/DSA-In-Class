#include<iostream>
#include<vector>
using namespace std;

void removeDuplicate(int arr[], int &n){
    for(int round=0; round<n-1; round++){
        int val=arr[round];
        for(int step=(round+1); step<n; step++){
            if(val==arr[step]){
                for(int i=step; i<n; i++){
                    arr[i]=arr[i+1];
                }
                step--;
                n--;
                //counting how many times size decrease for so it 
                //can be subtract from size of arr while printing
            }
        }
    }
    // cout<<endl<<"Value of n in func: "<<n;
}

void insertionSort(int arr[], int n){
    // for(int i=1; i<n; i++){
    //     int val=arr[i];
    //     int j=i-1;
    //     if(arr[j]>val){
    //     for(; j>=0;j--){
    //         arr[j+1]=arr[j];
    //     }
    //     }
    //     else{
    //         break;
    //     }
    //     arr[j+1]=val;
        
    // }

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
    int n;
    cin>>n;
    int arr1[n];
    for(int i=0; i<n; i++){
        cin>>arr1[i];
    }
    
    removeDuplicate(arr1, n);
    // n=n-c;

    // cout<<"After removing dupli for arr1: valofnis: "<<n<<endl;
    // for(int i=0; i<n; i++){
    //     cout<<arr1[i]<<" ";
    // }

    int m;
    cin>>m;
    int arr2[m];
    // vector<int>arr2(m);
    for(int i=0; i<m; i++){
        cin>>arr2[i];
    }

    // count=0;
    removeDuplicate(arr2, m);
    // m=m-d;

// cout<<endl<<"After removing dupli for arr1: valofnis: "<<m<<endl;
//     for(int i=0; i<m; i++){
//         cout<<arr1[i]<<" ";
//     }

    
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
    cout<<endl<<"After merging: ";
    for(int i=0; i<p; i++){
        cout<<arr3[i]<<" ";
    }

    insertionSort(arr3, p);
    // int count=0;
    // int c= removeDuplicate(arr3, n, count);
    // n=n-c;
    cout<<endl<<"After merge and sort"<<endl;
    for(int i=0; i<p; i++){
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    //Dividing array
    for(int i=0; i<n; i++){
        arr1[i]=arr3[i];
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    k=0;
    for(int i=n; i<p; i++){
        arr2[k]=arr3[i];
        cout<<arr2[k]<<" ";
        k++;
    }
    
    
    //printing
    // for(int i=0; i<n; )
    
    
    return 0;
}
