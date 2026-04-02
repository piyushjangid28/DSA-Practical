#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], even[n], odd[n];
    int e = 0, o = 0;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        if(arr[i] % 2 == 0) {
            even[e++] = arr[i];
        } else {
            odd[o++] = arr[i];
        }
    }

    for(int i = 0; i < e - 1; i++) {
        for(int j = 0; j < e - i - 1; j++) {
            if(even[j] > even[j + 1]) {
                int temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < o - 1; i++) {
        for(int j = 0; j < o - i - 1; j++) {
            if(odd[j] < odd[j + 1]) {
                int temp = odd[j];
                odd[j] = odd[j + 1];
                odd[j + 1] = temp;
            }
        }
    }

    cout << "Result (Even Asc + Odd Desc): ";

    for(int i = 0; i < e; i++) {
        cout << even[i] << " ";
    }

    for(int i = 0; i < o; i++) {
        cout << odd[i] << " ";
    }

    return 0;
}