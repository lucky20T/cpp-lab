#include<iostream>
int main(){
    int a,b;
    std::cout<<"enter number A:";
    std::cin>>a;
    std::cout<<"enter number B:";
    std::cin>>b;
    for(int i=a-1;i>2;i--){
        if(a%i==0 && b%i==0){
            std::cout<<i;
            break;
        }
        
    };


};