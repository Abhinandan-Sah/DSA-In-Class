#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid = (s + e) / 2;

    while (s < e)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
            
            {
                s= mid+1;
            }

        mid = (s + e) / 2;
    }
    return -1;
}
int main()
{
    int arr[100];
    int n;
    cout << "Enter the size of an array" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int item;
    cout << "Enter element you want to Find" << endl;
    cin >> item;

    int val = binarySearch(arr, n, item);
    if (val == -1)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element found at index: " << val;
    }

    return 0;
}