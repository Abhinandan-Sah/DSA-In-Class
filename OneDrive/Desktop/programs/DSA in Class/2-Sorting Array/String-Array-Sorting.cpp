// // You are using GCC
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// void bubbleSort(vector<string> &vec, int n)
// {
//     for (int i = 1; i < n; i++)
//     {
//         // cout<<endl<<"val(j)= "<<val<<endl;
//         bool flag = false;
//         for (int j = 0; j < n - i; j++)
//         {
//             string val = vec[j];
//             if ((j + 1) < n)
//             {
//                 string next = vec[j + 1];
//                 // cout<<endl<<"next(j)= "<<next<<endl;
//                 if (val[0] > next[0])
//                 {
//                     string temp = val;
//                     val = next;
//                     next = temp;
//                     flag = true;
//                 }
//             }
//         }
//         if (flag == false)
//         {
//             return;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cout << vec[i] << " ";
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<string> vec;
//     string input;
//     int i = 0;
//     while (i < n)
//     {
//         cin >> input;
//         vec.push_back(input);
//         i++;
//     }
//     bubbleSort(vec, n);
//     for (int i = 0; i < n; i++)
//     {
//         cout << vec[i] << " ";
//     }

//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void bubbleSort(vector<string>& vec, int n) {
    for (int i = 0; i < n - 1; i++) { // The loop should go up to n - 1
        bool flag = false;
        for (int j = 0; j < n - i - 1; j++) { // The inner loop should go up to n - i - 1
            string val = vec[j];
            string next = vec[j + 1];
            if (val[0] > next[0]) {
                swap(vec[j], vec[j + 1]); // Use swap to exchange elements
                
                flag = true;
            }
        }
        if (flag == false) {
            return;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> vec;
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        vec.push_back(input);
    }
    bubbleSort(vec, n);
    for (int i = 0; i < n; i++) {
        cout << vec[i] << " ";
    }
    return 0;
}
