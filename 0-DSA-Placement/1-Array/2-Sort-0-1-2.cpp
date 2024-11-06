#include<iostream>
#include<vector>
using namespace std;
//This is two pass solution(which means we are using 2 loops one after another)
void sortColors(vector<int>& nums) {
        int n= nums.size();
        // noz = number of zeros
        int noz=0; 
        // noo = number of one
        int noo=0;
        // notw = number of two
        int notw=0;

        for(int i=0; i<n ; i++){
            if(nums[i]==0) noz++;
            else if(nums[i]==1) noo++;
            else notw++;
        }

        for(int i=0; i<n; i++){
            if(i<noz) nums[i]=0;
            else if(i<(noz+noo)) nums[i]=1;
            else nums[i]=2;
        }
    }

// ************Another method where we are using Dutch National Flag Algorithm(only one loop)************
// ************Three pointers are used low, mid and high************

void dutchFlagAlgo(vector<int>&nums){
    int n= nums.size();
    int low=0;
    int mid=0;
    int high=n-1;

    while(mid<=high){
        if(nums[mid]==2){
            swap(nums[mid], nums[high]);
            high--;
        }
        else if(nums[mid]==0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else{
            mid++;
        }
    }
}   

int main()
{
    vector<int> v={1,0,0,1,0,1,0};
    sortColors(v);
    dutchFlagAlgo(v);
    return 0;
}