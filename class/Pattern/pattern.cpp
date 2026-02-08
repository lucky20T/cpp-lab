// #include<iostream>

// int main(){
//     int n,i,j;
  
//     std::cout<<"Enter any number:";
//     std::cin>>n;

//     for(i=0;i<n;i++){
//         for(j=0;j<n;j++){
//             if(true){
//                 std::cout<<"*   ";
//             }
//             else{
//                 std::cout<<"    ";
//             }
//         }
//         std::cout<<"\n";
//     }
// }

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // 1️⃣ Top border
    for (int j = 0; j < n; j++) {
        cout << "* ";
    }
    cout << "\n";

    // 2️⃣ Upper inner part
    for (int i = 1; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || j == n - 1 || j == 1 || j == n - 2)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }

    // 3️⃣ Middle row
    for (int j = 0; j < n; j++) {
        if (j == 0 || j == n - 1)
            cout << "* ";
        else
            cout << "  ";
    }
    cout << "\n";

    // 4️⃣ Lower inner part
    for (int i = n / 2 + 1; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0 || j == n - 1 || j == 1 || j == n - 2)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }

    // 5️⃣ Bottom border
    for (int j = 0; j < n; j++) {
        cout << "* ";
    }
    cout << "\n";

    return 0;
}

