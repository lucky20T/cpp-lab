#include<iostream>
#include<time.h>
void main(){
    srand( time (NULL));
    int num1 = rand();
    std:: cout<<num1;
}