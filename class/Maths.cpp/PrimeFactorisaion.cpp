#include<iostream>

int main(){
    int n,n2;
    std::cout<<"Enter any number:";
    std::cin>>n;
    std::cout<<"Enter number second:";
    std::cin>>n2;
// prime factorisation of n
    std::cout<<"Prime factorisation of "<<n<<" is: ";
    for(int i=2;i<=n;i++){
        while(n%i==0){
            std::cout<<i<<" ";
            n=n/i;
        }
    }
    std::cout<<"\nPrime factorisation of "<<n2<<" is: ";
    for(int i=2;i<=n2;i++){
        while(n2%i==0){
            std::cout<<i<<" ";
            n2=n2/i;
        }
    }
}