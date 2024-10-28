// #include<iostream>
// // #include<cmath>
// #include<math.h>
// using namespace std;

// struct Line{
//     int x1;
//     int x2;
//     int y1;
//     int y2;
    
//     // void distance(){
//     //     cout<<"Distance: ";
//     //     int d;
//     //     d=sqrt((pow((x2-x1), 2)+pow((y2-y1), 2)), 2);
//     //     cout<<d;
//     // }
// };

// int main(){
//     int x1, y1, x2, y2;
//     cin>>x1>>y1;
//     cin>>x2>>y2;
    
//     struct Line l;
//     l.x1=x1;
//     l.y1=y1;
//     l.x2=x2;
//     l.y2=y2;
//     // l.distance();

    
    
    
//     return 0;
// }


#include<iostream>
#include<string>
using namespace std;

union AccountData{
  string holderNam;
  int accNum;
  float accBal;
  
  void deposit(float dep){
      accBal=accBal+dep;
      cout<<"Amount deposited successfully."<<endl;
  }
  
  void withdraw(float withdraw){
      if(accBal >= withdraw){
          accBal=accBal-withdraw;
          cout<<"Amount withdraw successfully."<<endl;
      }
      else{
          cout<<"Insufficient balance. Withdrawal failed"<<endl;
      }
  }
  
  void details(){
      cout<<"Account holder's name: "<<holderNam;
      cout<<"Account number: "<<accNum;
      cout<<"Balance: "<<accBal;
  }
};

int main(){
    
    union AccountData a;
    string holderName;
    cin>>holderName;
    int accNum;
    cin>>accNum;
    float accBal;
    cin>>accBal;
    float dep;
    cin>>dep;
    float withdraw;
    cin>>withdraw;
    
    if(holderName.size()<=50 && accNum>=0 && accBal>=0 && dep>=0 && withdraw>=0){
        a.holderNam=holderName;
        a.accNum=accNum;
        a.accBal=accBal;
        a.deposit(dep);
        a.withdraw(withdraw);
        a.details();
    }
    
    return 0;
}