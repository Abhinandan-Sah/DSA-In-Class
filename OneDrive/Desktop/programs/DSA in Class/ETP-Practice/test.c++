// // #include<iostream>
// // using namespace std;

// // int main(){

// //     // int i=1;
// //     // // cout<<i;
// //     // // char c='A';
// //     // // char s=c;
// //     // // cout<<s;

// //     // int n;
// //     // // cout<<"Enter the value of n: "<<endl;
// //     // // cin>>n;
// //     // n=5;
// //     // char s='A';
// //     // while(i<=n){
// //     //     int j=1;
// //     //     char c;
// //     //     while (j<=n)
// //     //     {
// //     //         c=s;
// //     //         cout<<c<<" ";
// //     //         j++;
// //     //         c++;
// //     //     }
// //     //     s++;
// //     //     i++;
        
        
// //     // }

// //     int n;
// //     cout<<"Enter you name";
// //     cin>>n;
// //     cout<<n;

    
// //     return 0;
// // }

// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// int main() {
//     // std::vector<std::string> list_1;
//     // std::vector<std::string> list_2;
//     // // int n; 
//     // // std::cin>>n;
//     // for (int i = 0; i < 3; ++i) {
//     //     std::string input;
//     //     std::cin >> input;
//     //     list_1.push_back(input);
//     // }
//     // // int m; 
//     // // std::cin>>m;
//     // for (int j = 0; j < 2; ++j) {
//     //     std::string input;
//     //     std::cin >> input;
//     //     list_2.push_back(input);
//     // }

//     // std::vector<std::string> final_list;
//     // final_list.reserve(list_1.size() + list_2.size());
//     // final_list.insert(final_list.end(), list_1.begin(), list_1.end());
//     // final_list.insert(final_list.end(), list_2.begin(), list_2.end());

//     // for (const std::string &k : final_list) {
//     //     std::cout << k << std::endl;
//     // }

//     // vector<string>arr;
//     // for(int i=1; i<=3; i++){
//     //     cout<<"Enter "<<i<<"st sentence: "<<endl;
//     //     string inp;
//     //     cin>>inp;
//     //     arr.push_back(inp);
        
//     // }
//     // for(int i=0; i<3; i++){
//     //     cout<<arr[i]<<" ";
//     // }

//     string inp;
//         cin>>inp;
//         cout<<inp;

//    return 0;
// }

#include<iostream>
#include<vector>
#include<string>
using namespace std;
// const max_num=100;
int main(){
    vector<string>arr;
    cout<<arr.size();
    for(int i=0; i<arr.size(); i++){
        cin>>arr[i];
    }
    string str;
    cin>>str;
    for(int i=0 ; i<arr.size(); i++){
        if(arr[i]==str){
            cout<<"The word '"<<str<<"' is present in the given sentence.";
        }
    }
            cout<<"The word '"<<str<<"' is not present in the given sentence.";
        
    
    return 0;
}
