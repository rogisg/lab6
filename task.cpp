#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

class NotPrimeException : public invalid_argument {
    int invalid_num;
public:
    NotPrimeException(int num) : invalid_argument("Число не является простым"), invalid_num(num) {}
    void print() const {
        cout << what() << ": " << invalid_num << endl;
    }
};

class PrimeNumber {
    int value;
    bool is_prime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) return false;
        return true;
    }
public:
    PrimeNumber(int num) {
        if (!is_prime(num)) throw NotPrimeException(num);
        value = num;
    }
    int getValue() const { return value; }
};

int main() {
    try {
        PrimeNumber p1(7);
        cout << "Создано простое число: " << p1.getValue() << endl;
        
        PrimeNumber p2(10);
    }
    catch (const NotPrimeException& e) {
        e.print();
    }

    return 0;
}
