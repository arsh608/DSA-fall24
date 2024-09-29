#include <iostream>
using namespace std;

int fibonacci(int num) {
    if (num <= 1) return num;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
    for (int i = 1; i <= 10; ++i)
        cout << "fibonacci(" << i << ") is " << fibonacci(i) << endl;

    return 0;
}
