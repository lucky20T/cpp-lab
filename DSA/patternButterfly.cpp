#include<iostream>
using namespace std;

int main(){
    int n=4;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        for(int j=0;j<(n*2)-(2*i);j++){
            cout<<" ";
        }
        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<"\n";

    }

    for(int i=n;i>0;i--){
        for(int j=i;j>0;j--){
            cout<<"*";
        }
        for(int j=0;j<(n*2)-(2*(i));j++){
            cout<<" ";
        }
       for(int j=i;j>0;j--){
            cout<<"*";
        }
        cout<<"\n";

    }
    return 0;
};