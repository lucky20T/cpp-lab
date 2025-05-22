#include<iostream>

int checkprime(int n);
int main(){
    int n,c;
    std::cout<<"enter any number:";
    std::cin>>n;
    c=checkprime(n);
    if (c==2){
        std::cout<<"prime";
    }
    else{
        std::cout<<"not prime";
    }
    
}
int checkprime(int n){
    int c=0;
    for(int i=1;i<=n;i++){
        if(i%n==0){
            c++;
        }
    }
    return c;

}