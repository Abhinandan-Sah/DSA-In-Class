
// C++ program to show the getline() with
// character array
#include <iostream>
using namespace std;
  
// Driver Code
int main()
{
    char str[100];
    cout << "Enter Your Name::";
  
    // see the use of getline() with array
    // str also replace the above statement
    // by cin >> str and see the difference
    // in output

    for(int i=0; i<3; i++){
        cin.getline(str, 100);
    }
    for(int i=0; i<3; i++){
        cout<<str;
    }

    cout << "\nYour Name is:: " << str;
    return 0;
}