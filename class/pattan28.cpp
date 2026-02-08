#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int nm=1;
    for(int i=0;i<n;i++){
        
        for(int j=n;j>i;j--){
            cout<<"  ";
        }
        
        for(int k=0;k<=nm/2;k++){
            
            cout<<k+1+i<<" ";
        }
        for(int l=nm;l>(nm/2)+1;l--){
            cout<<l-1<<" ";
        }
        nm+=2;
        cout<<endl;    
    }

};