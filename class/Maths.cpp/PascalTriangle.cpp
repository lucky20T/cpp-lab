#include<iostream>
#include<vector>
int main(){
    int n;
    std::cout<<"Enter a Number:";
    std::cin>>n;
    std::vector<int> v(n,0);
    v[0]=1;
    
//pascal triangle
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         int res=1;
    //         for(int k=1;k<=j;k++){
    //             res=res*(i-k+1)/k;
    //         }
    //         std::cout<<res<<" ";
    //     }
    //     std::cout<<"\n";
    // }

    for(int i=1;i<n;i++){
        for(int j=1;j<=i;j++){
            int t=v[j]+v[j-1];
            v[j+1]=t;
            
            std::cout<<t;

        }
        std::cout<<"\n";
    }
    


}