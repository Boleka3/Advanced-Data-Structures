
#include <iostream>
using namespace std;

// Recursive
int Recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return Recursive(n - 1) + Recursive(n - 2);
}



// Matrix Exponentiation
void multiplyMatrix(int F[2][2], int M[2][2]) {
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void powerMatrix(int F[2][2], int n) {
    if (n <= 1)
        return;

    int M[2][2] = {{1, 1}, {1, 0}};

    powerMatrix(F, n / 2);
    multiplyMatrix(F, F);

    if (n % 2 != 0)
        multiplyMatrix(F, M);
}


int fibonacciMatrix(int n) {
    if (n == 0)
        return 0;

    int F[2][2] = {{1, 1}, {1, 0}};
    powerMatrix(F, n - 1);
    return F[0][0];
}


// Dynamic Programming
int fibonacciDynamic(int n) {

    if (n <= 1) {
        return n;
    }

    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}


int main() {

    int n, choice;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Choose how to calculate Fibonacci number:\n";
    cout << "1. Recursive\n";
    cout << "2. Matrix Exponentiation\n";
    cout << "3. Dynamic Programming\n";
    cout << "Enter your choice : ";
    cin >> choice;

    int result;
    switch (choice) {
        case 1:
            result = Recursive(n);
            cout << "Fibonacci using recursion: " << result << endl;
            break;
        case 2:
            result = fibonacciMatrix(n);
            cout << "Fibonacci using matrix exponentiation: " << result << endl;
            break;
        case 3:
            result = fibonacciDynamic(n);
            cout << "Fibonacci using dynamic programming: " << result << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
