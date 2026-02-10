#include<bits/stdc++.h>


//binary to decimal
int main(){
    int n;
    std::cout<<"Enter a Binary Number:";
    std::cin>>n;
    int res=0;
    int p=1;
    while(n>0){
        int r=n%10;
        res=res+r*p;
        p=p*2;
        n=n/10;
    }
    std::cout<<"Decimal Number is:"<<res;

}