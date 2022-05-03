#include<iostream>

using namespace std;

int power1(int a, int n) {

    if (n == 0) {
        return 1;
    }
    return a  * power1(a, n - 1);
}

int power2(int a, int n) {
    if (n == 0) {
        return 1;
    }

    int SmallAns = power2(a, n / 2);

    if (n % 2 == 0) {
        return SmallAns * SmallAns;

    } else {

        return SmallAns * SmallAns * a;
    }
}

int main() {
    int a, b;
    cout << "Input: " << "\n Enter Two numbers to use first function:\n";
    cin >> a >> b;
    cout << "Output: " << power1(a, b) << "\n";

    cout << "________________________________\n"
            "Input: " << "\n Enter Two numbers to use second function:\n";
    cin >> a >> b;
    cout << "Output: " << power2(a, b) << "\n";

}


