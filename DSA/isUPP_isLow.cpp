#include<iostream>

int main(){
    char ch;
    std::cout<<"enter any letter:";
    std::cin>>ch;
    
    if(ch>='a' && ch<='z'){
        std::cout<<"isLower";
    }else{
        std::cout<<"isUpper";
    }
    return 0;
}