#include<iostream>

int main(){
    int n,a,b;
    a=0;
    b=1;
    std::cout<<"enter the number of terms:";
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cout<<a<<" ";
        a=b;
        b+a;
    }
};