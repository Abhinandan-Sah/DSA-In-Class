#include <iostream>
using namespace std;

void split(string str, char del){
	// declaring temp string to store the curr "word" upto del
	string temp = "";

	for(int i=0; i<(int)str.size(); i++){
		// If cur char is not del, then append it to the cur "word", otherwise
		// you have completed the word, print it, and start a new word.
		if(str[i] != del){
			temp += str[i];
		}
		else{
			cout << temp << " ";
			temp = "";
		}
	}
	
	cout << temp;
}

int main() {

	string str = "geeks_for_geeks"; // string to be split
	char del = '_'; // delimiter around which string is to be split

	split(str, del);
	
	return 0;
}
