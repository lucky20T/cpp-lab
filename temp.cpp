#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    char ch = 'a';

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < j + 1; i++) {
            cout << ch;
        }
        ch++;          // move to next character
        cout << endl;
    }

    return 0;
}
