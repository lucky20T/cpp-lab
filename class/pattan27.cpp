#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int nm=1;
    for(int i=n;i>0;i--){
        
        for(int j=0;j<i-1;j++){
            cout<<"  ";
        }
        
        for(int k=0;k<nm;k++){
            if(k<nm/2){
                cout<<k+1<<" ";
            }
            else{
                cout<<nm-k<<" ";
            } 
            
            
        }
        nm+=2;
        cout<<endl;    
    }

};