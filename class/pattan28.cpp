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
        
        for(int k=0;k<nm;k++){
            if(k<=nm/2){
                cout<<k+1+i<<" ";
            }
            else{
                cout<<k+1-i<<" ";
            }
              
        }
        nm+=2;
        cout<<endl;    
    }

};