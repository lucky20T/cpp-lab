#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int mid= n/2;

    for (int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            if (row+col==mid || col-row==mid || row-col==mid || row+col==n-1+mid){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}