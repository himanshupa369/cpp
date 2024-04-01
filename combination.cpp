#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> factorialMemo;

// Function to calculate factorial with memoization
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    
    if(factorialMemo.find(n) != factorialMemo.end())
        return factorialMemo[n];
    
    int result = n * factorial(n - 1);
    factorialMemo[n] = result;
    return result;
}

// Function to calculate permutation
int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combination
int combination(int n, int r) {
    return permutation(n, r) / factorial(r);
}

int main() {
    int n, r;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Enter the value of r: ";
    cin >> r;

    if (n < 0 || r < 0 || r > n) {
        cout << "Invalid input. n and r should be non-negative integers and r should be less than or equal to n." << endl;
        return 1;
    }

    cout << "Permutation: " << permutation(n, r) << endl;
    cout << "Combination: " << combination(n, r) << endl;

    return 0;
}
