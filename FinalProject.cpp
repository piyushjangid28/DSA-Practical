#include <iostream>
using namespace std;

/* ================= LINKED LIST ================= */

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(int value) {
    Node *temp = head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void displayList() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

/* ================= MERGE SORT ================= */

void merge(int arr[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[100];

    while (i <= m && j <= r) {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* ================= QUICK SORT ================= */

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ================= BINARY SEARCH ================= */

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

/* ================= MAIN MENU ================= */

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Linked List Operations\n";
        cout << "2. Sorting (Merge / Quick)\n";
        cout << "3. Binary Search\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int subChoice, val;
            do {
                cout << "\n--- Linked List ---\n";
                cout << "1. Insert\n2. Delete\n3. Display\n0. Back\n";
                cin >> subChoice;

                switch (subChoice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> val;
                    insertNode(val);
                    break;
                case 2:
                    cout << "Enter value to delete: ";
                    cin >> val;
                    deleteNode(val);
                    break;
                case 3:
                    displayList();
                    break;
                }
            } while (subChoice != 0);
            break;
        }

        case 2: {
            int n, arr[100], type;
            cout << "Enter size: ";
            cin >> n;

            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "1. Merge Sort\n2. Quick Sort\n";
            cin >> type;

            if (type == 1)
                mergeSort(arr, 0, n - 1);
            else
                quickSort(arr, 0, n - 1);

            cout << "Sorted Array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        }

        case 3: {
            int n, arr[100], key;
            cout << "Enter size: ";
            cin >> n;

            cout << "Enter sorted elements:\n";
            for (int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "Enter value to search: ";
            cin >> key;

            int result = binarySearch(arr, n, key);

            if (result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found\n";

            break;
        }

        }

    } while (choice != 0);

    return 0;
}