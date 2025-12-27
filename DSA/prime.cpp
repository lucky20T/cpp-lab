#include<iostream>
// ✅ Define function outside main
int checkprime(int n)
{
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            c++;
        }
    }
    return c;
}

int main()
{
    int ch = 1; // start with yes
    while (ch == 1) {
        int n;
        std::cout << "Enter any number: ";
        std::cin >> n;

        int c = checkprime(n);

        if (c == 2)
            std::cout << "Prime\n";
        else
            std::cout << "Not prime\n";

        std::cout << "Do you want to check another number? (1 for yes / 0 for no): ";
        std::cin >> ch;
    }

    std::cout << "Goodbye!\n";
    return 0;
}

// int ch;
// std::cout<<"Do you want to check another number? (1 for yes / 0 for no): ";
// std::cout<<"enter any number:";
// std::cin>>ch;

// while(ch==1)
// {
//     int checkprime(int n)
// {
//     int c=0;
//     for(int i=1;i<=n;i++){
//         if(n%i==0){
//             c++;
//         }
//     }
//     return c;

// }
// ;
// int main(){
//     int n,c;
//     std::cout<<"enter any number:";
//     std::cin>>n;
//     c=checkprime(n);
//     if (c==2){
//         std::cout<<"prime";
//     }
//     else{
//         std::cout<<"not prime";
//     }
    
// }
// }


// int checkprime(int n)