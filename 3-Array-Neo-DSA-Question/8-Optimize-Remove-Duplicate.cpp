#include<bits/stdc++.h>
using namespace std;
void findFrequency(int* arr, int size)
{
    int visited[size] = {0};
    for(int i=0; i<size; i++)
    {
        if(visited[i]!=1)
        {
            int count = 1;
            for(int j=i+1; j<size; j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    visited[j]=1;
                }
            }
            if(count==1){
            cout<<arr[i]<<" - "<<count<<" time"<<endl;
            }
            else{
                cout<<arr[i]<<" - "<<count<<" times"<<endl;
            }
        }
    }
}
int main()
{
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+size);
    findFrequency(arr,size);
    return 0;
}