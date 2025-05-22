// #include<iostream>
// int main(){
//     int arr[1000];
//     int c,c2;
//     c=0;
//     c2=0;
//     for(int i=0;i<1000;i++){
//         arr[i]=0;
//     }
//     while(c<100){
//         for(int i=0;i<1000;i++){
//             arr[i]==0?arr[i]=1:arr[i]=0;
//         }
//         for(int j=0;j<1000;j=j+2){
//             arr[j]==0?arr[j]=1:arr[j]=0;
//         }
//         for(int k=0;k<1000;k=k+3){
//             arr[k]==0?arr[k]=1:arr[k]=0;
//         }
//         c++;
//         }
        

    

    
//     for(int i=0;i<1000;i++){
//         if(arr[i]==1){
//             c2++;
//         }
//         std::cout<<c2;
//         std::cout<<arr[i];
//         std::cout<<"\n";
//     }
//     return 0;
// }
// 
#include <iostream>
#include <cmath>

int main() {
    int count = 0;

    for (int i = 1; i * i <= 1000; i++) { // Checking perfect squares
        count++;
    }

    std::cout << "Number of bulbs that remain ON: " << count << std::endl;
    return 0;
}

