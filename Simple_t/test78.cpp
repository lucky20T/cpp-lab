#include <iostream>
#include <conio.h> // For Turbo C++ compatibility
using namespace std;


void main() {
     // Clear screen (specific to Turbo C++)

    int arr[10], size, key, low, high, mid, found = 0;

    cout << "Enter the number of elements in the array (max 10): ";
    cin >> size;

    cout << "Enter the elements in sorted order:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> key;

    // Initialize variables for binary search
    low = 0;
    high = size - 1;

    // Perform binary search
    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            cout << "Element " << key << " found at index " << mid << ".\n";
            found = 1; // Mark as found
            break;    // Exit the loop
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    if (!found) {
        cout << "Element " << key << " not found.\n";
    }

    // Wait for a key press (Turbo C++ specific)
}
