// #include<iostream>
// #include<string.h>
// #include<algorithm>
// using namespace std;

// union Employee
// {
//     int id;
//     char name[20];
//     char birth[10];
//     char join[10];
//     float salary;

//     void joinprint(){
//             cout<<"DOJ"<<": "<<join<<endl;

//     }
//     void birthPrint(){
//             cout<<"DOB"<<": "<<birth<<endl;

//     }
// };


// int main(){
//     Employee x;
//     int idnum;
//     cin>>idnum;
//     char nam[20];
//     cin.getline(nam,20 );
//      char dob[10];
//     cin.getline(dob, 10);
//     char doj[10];
//     cin.getline(doj, 10);
//     float sal;
//     cin>>sal;

//     x.id=idnum;
//     cout<<"Id"<<":"<<x.id<<endl;
    
//     strcpy(x.name,nam);
//     cout<<"Name: "<<x.name<<endl;
   
//     strcpy(x.birth, dob);
//     x.birthPrint();
  
    
//     strcpy(x.join, doj);
//     x.joinprint();
    
    
//     x.salary=sal;
//     cout<<"SALARY"<<": "<<x.salary<<endl;
//     return 0;
// }

#include <iostream>
#include <cstring> // Include this header for strcpy()
using namespace std;

union Employee
{
    int id;
    char name[30]; // Increased array size to 30 to account for null-terminator
    char birth[12]; // Increased array size to 12 to account for null-terminator
    char join[12]; // Increased array size to 12 to account for null-terminator
    float salary;

    void joinprint(){
        cout << "DOJ" << ": " << join << endl;
    }
    void birthPrint(){
        cout << "DOB" << ": " << birth << endl;
    }
};

int main(){
    Employee x;
    int idnum;
    cin >> idnum;
    cin.ignore(); // Add this line to ignore the newline character

    char nam[30];
    cin.getline(nam, 30);

    char dob[12];
    cin.getline(dob, 12);

    char doj[12];
    cin.getline(doj, 12);

    float sal;
    cin >> sal;

    x.id = idnum;
    cout << "Id" << ":" << x.id << endl;

    strcpy(x.name, nam);
    cout << "Name: " << x.name << endl;

    strcpy(x.birth, dob);
    x.birthPrint();

    strcpy(x.join, doj);
    x.joinprint();

    x.salary = sal;
    cout << "SALARY" << ": " << x.salary << endl;
    return 0;
}
