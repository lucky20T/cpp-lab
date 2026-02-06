#include<iostream>
int isPrime(int a){
    int c=0;
    for(int i=2;i<a;i++){
        if(a%i==0){
            c++;
            break;
        }
        
    }
    return c;
};
int main(){
    int num;
    std::cout<<"enter any number:";
    std::cin>>num;
    if(isPrime(num)==0){
        std::cout<<"Prime";
    }
    else{
        std::cout<<"Not Prime";
    }
    

};

