#include <iostream>
#include <string>
using namespace std;

class DayOfYear {
private:
    int day; 

    static string months[12];
    static int monthDays[12];

public:

    DayOfYear(int d) {
        if (d < 1) d = 1;
        if (d > 365) d = 365;
        day = d;
    }


    DayOfYear(string monthName, int dayOfMonth) {
        int monthIndex = -1;


        for (int i = 0; i < 12; i++) {
            if (months[i] == monthName) {
                monthIndex = i;
                break;
            }
        }

        if (monthIndex == -1) {
            cout << "Invalid month name.\n";
            exit(0);
        }


        if (dayOfMonth < 1 || dayOfMonth > monthDays[monthIndex]) {
            cout << "Invalid day for " << monthName << endl;
            exit(0);
        }

 
        int total = dayOfMonth;
        for (int i = 0; i < monthIndex; i++) {
            total += monthDays[i];
        }

        day = total;
    }


    void print() {
        int temp = day;
        int m = 0;

        while (temp > monthDays[m]) {
            temp -= monthDays[m];
            m++;
        }

        cout << months[m] << " " << temp;
    }


    DayOfYear operator++() {
        day++;
        if (day > 365) day = 1;
        return *this;
    }


    DayOfYear operator++(int) {
        DayOfYear temp = *this;
        day++;
        if (day > 365) day = 1;
        return temp;
    }


    DayOfYear operator--() {
        day--;
        if (day < 1) day = 365;
        return *this;
    }


    DayOfYear operator--(int) {
        DayOfYear temp = *this;
        day--;
        if (day < 1) day = 365;
        return temp;
    }
};


string DayOfYear::months[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int DayOfYear::monthDays[12] = {
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
};

int main() {
 
    DayOfYear d("March", 14);

    cout << "Starting date: ";
    d.print();
    cout << endl;

    ++d;
    cout << "After prefix ++ : ";
    d.print();
    cout << endl;

    d++;
    cout << "After postfix ++ : ";
    d.print();
    cout << endl;


    --d;
    cout << "After prefix -- : ";
    d.print();
    cout << endl;


    d--;
    cout << "After postfix -- : ";
    d.print();
    cout << endl;

    return 0;
}
