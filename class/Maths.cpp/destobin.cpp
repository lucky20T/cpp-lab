#include<iostream>

// Fucntion to convert decimal to binary
void decToBin(int n){
    int res=0;
    int p=1;
    while(n>0){
        int r=n%2;
        res=res+r*p;
        p=p*10;
        n=n/2;
    }
    std::cout<<"Binary Number is:"<<res;

}
int main(){
    int n;
    std::cout<<"Enter a Decimal Number:";
    std::cin>>n;
    decToBin(n);
}