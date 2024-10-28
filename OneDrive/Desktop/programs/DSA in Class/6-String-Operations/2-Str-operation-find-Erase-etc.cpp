// Using find, substr and erase:
/* 
#include <iostream>
using namespace std;

int main()
{
    string sentence, word;
    size_t pos; // position of the space in the sentence
    cout << "Enter a sentence: ";
    getline(cin, sentence); // this will read the whole line
    while ((pos = sentence.find(' ')) != string::npos) // find the first space in the sentence
    {
        word = sentence.substr(0, pos); // extract the word before the space
        cout << "You entered: " << word << endl;
        sentence.erase(0, pos + 1); // erase the word and the space from the sentence
    }
    cout << "You entered: " << sentence << endl; // print the last word
    return 0;
}
*/
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;
// const max_num=100;
int main(){
    // vector<string>arr(100);
    
    // for(int i=0; i<arr.size(); i++){
    //     arr.push_back(arr[i]);
    // }
   
    // vector<string>arr(100);
    string str;
    getline(cin, str);
    string w;
    cin>>w;
    // cout<<"The word is: "<<str<<endl;
    // cout<<w;
    // for(int i=0; i<str)
    // cout<<strlen(str);
    // for(int i=0 ; i<arr.size(); i++){
    //     if(arr[i]==str){
    //         cout<<"The word '"<<str<<"' is present in the given sentence.";
    //     }
    // }
    //         cout<<"The word '"<<str<<"' is not present in the given sentence.";
    // vector<string> arr;
    // string str;
    // cout<<str[5];
    // cout<<str.size();
    string  str;
    
    
    return 0;
}
