#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

// Function to partition the array for the deterministic Quick Sort
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Deterministic Quick Sort algorithm
void deterministicQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = deterministicPartition(arr, low, high);

        deterministicQuickSort(arr, low, pivot - 1);
        deterministicQuickSort(arr, pivot + 1, high);
    }
}

// Function to choose a random pivot for the randomized Quick Sort
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);

    return deterministicPartition(arr, low, high);
}

// Randomized Quick Sort algorithm
void randomizedQuickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = randomizedPartition(arr, low, high);

        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}
//function to diaply ele of arr
void display(const vector<int>& arr){
    for(auto val:arr){
        cout<<val<<" ";
    }
        cout<<endl;
}

int main() {
    srand(time(0)); // Initialize random seed

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> deterministicArr(n);
    vector<int> randomizedArr(n);

    // take input from user
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> deterministicArr[i];
        randomizedArr[i] = deterministicArr[i];
        }

    
    

    cout << "Array of size " << n << " created with random values." << endl;

    
    deterministicQuickSort(deterministicArr, 0, n - 1);
    //display sorted arr
    cout<<"Deterministic quick sort array is : \n";
    display(deterministicArr);

    randomizedQuickSort(randomizedArr, 0, n - 1);
    //display sorted arr 
    cout<<"\nRandomized quick sort array is : \n";
    display(randomizedArr);



    return 0;
}
