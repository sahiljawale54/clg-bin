#include <iostream>
#include <vector>

// Function to calculate Fibonacci numbers iteratively
std::vector<int> fibonacciIterative(int n) {
    if (n <= 0) {
        return std::vector<int>();
    } else if (n == 1) {
        return std::vector<int>{0};
    } else if (n == 2) {
        return std::vector<int>{0, 1};
    }

    std::vector<int> fibSeries{0, 1};
    for (int i = 2; i < n; ++i) {
        int nextNumber = fibSeries[i - 1] + fibSeries[i - 2];
        fibSeries.push_back(nextNumber);
    }

    return fibSeries;
}

// Function to calculate Fibonacci numbers recursively
int fibonacciRecursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

int main() {
    int n = 10;  // Change this to the desired number of Fibonacci numbers

    // Calculate and display the Fibonacci series using the iterative method
    std::cout << "Fibonacci Series (Iterative): ";
    std::vector<int> resultIterative = fibonacciIterative(n);
    for (int number : resultIterative) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Calculate and display the Fibonacci series using the recursive method
    std::cout << "Fibonacci Series (Recursive): ";
    for (int i = 1; i <= n; ++i) {
        int resultRecursive = fibonacciRecursive(i);
        std::cout << resultRecursive << " ";
    }
    std::cout << std::endl;

    return 0;
}
