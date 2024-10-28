#include <iostream>
using namespace std;

int main()
{
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence); // this will read the whole line
    cout << "You entered: " << sentence << endl;
    return 0;
}