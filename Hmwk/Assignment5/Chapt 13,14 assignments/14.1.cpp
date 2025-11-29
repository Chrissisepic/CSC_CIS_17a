#include <iostream>
#include <string>
using namespace std;

class Numbers {
private:
    int number;


    static string lessThan20[20];
    static string tens[10];

public:
    Numbers(int n) {
        if (n < 0) n = 0;
        if (n > 9999) n = 9999;
        number = n;
    }

    void print() {
        int num = number;

        if (num == 0) {
            cout << "zero";
            return;
        }


        if (num >= 1000) {
            cout << lessThan20[num / 1000] << " thousand ";
            num %= 1000;
        }

 
        if (num >= 100) {
            cout << lessThan20[num / 100] << " hundred ";
            num %= 100;
        }


        if (num >= 20) {
            cout << tens[num / 10] << " ";
            num %= 10;
        }


        if (num > 0) {
            cout << lessThan20[num] << " ";
        }
    }
};


string Numbers::lessThan20[20] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[10] = {
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

int main() {
    int num;

    cout << "Enter a number (0-9999): ";
    cin >> num;

    Numbers n(num);

    cout << "English: ";
    n.print();
    cout << endl;

    return 0;
}
