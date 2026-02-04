#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int mid= n/2;

    for(int i=0; i<n ; i++ ){
        if (i<=mid){
            for(int j=0; j<n ; j++ ){
                if (j>=mid - i && j<= mid + i){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
        else{
            for(int j=0; j<n ; j++ ){
                if (j>= i - mid && j<= n - (i - mid) - 1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
    }
}