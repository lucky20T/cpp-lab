#include<iostream>
using namespace std;

int main(){
    int age;
    cout<<"enter the age:";
    cin>>age;
    // age >= 18 ? cout<<"audiat":cout<<"kid";
    cout<<(age >= 18 ? "man":"boy");
    return 0;
}