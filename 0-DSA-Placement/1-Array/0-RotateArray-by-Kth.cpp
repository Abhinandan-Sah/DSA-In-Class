#include <iostream>
#include <vector>
using namespace std;

void reverseFun(int s, int e, int *nums)
{
    while (s <= e)
    {
        swap(nums[s], nums[e]);
        s++;
        e--;
    }
};

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;

    // Handle case when k > n
    k = k % n;

    // If k is 0 or n, no rotation needed
    if (k == 0)
        return;

    reverseFun(0, n - k - 1, arr);
    reverseFun(n - k, n - 1, arr);
    reverseFun(0, n - 1, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}