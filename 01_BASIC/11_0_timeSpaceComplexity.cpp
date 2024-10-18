#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// Function to find the maximum element in an array
int findMax(const vector<int>& arr) {
    int maxElement = arr[0]; // Assume first element is the max

    // Iterate through the array
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Update max if current element is larger
        }
    }
    
    return maxElement;
}

int main() {
    const int SIZE = 1000; // You can change this to see how it affects performance
    vector<int> arr(SIZE);

    // Fill the array with random numbers
    srand(time(0)); // Seed for random number generation
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }

    // Time the function
    clock_t start = clock();
    int maxElement = findMax(arr);
    clock_t end = clock();
    double timeTaken = double(end - start) / CLOCKS_PER_SEC;

    // Output the results
    cout << "Maximum Element: " << maxElement << endl;
    cout << "Time taken to find the maximum: " << timeTaken << " seconds\n";

    return 0;
}
