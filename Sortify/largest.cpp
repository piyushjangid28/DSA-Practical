#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = arr[0];
    int secondLargest = -1;

    for(int i = 1; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] != largest) {
            if(secondLargest == -1 || arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
    }

    cout << "Largest element: " << largest << endl;

    if(secondLargest == -1)
        cout << "Second largest element does not exist";
    else
        cout << "Second largest element: " << secondLargest;

    return 0;
}