#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int month, day, year;

public:

    Date(int m, int d, int y) {
        setMonth(m);
        setDay(d);
        year = y;
    }

    void setMonth(int m) {
        if (m < 1 || m > 12) {
            cout << "Invalid month. Setting to 1.\n";
            month = 1;
        } else {
            month = m;
        }
    }

    void setDay(int d) {
        if (d < 1 || d > 31) {
            cout << "Invalid day. Setting to 1.\n";
            day = 1;
        } else {
            day = d;
        }
    }


    void format1() {
        cout << month << "/" << day << "/" << year << endl;
    }

    void format2() {
        string months[] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

        cout << months[month - 1] << " " << day << ", " << year << endl;
    }

    void format3() {
        string months[] = {"January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December"};

        cout << day << " " << months[month - 1] << " " << year << endl;
    }
};

int main() {
    int m, d, y;

    cout << "Enter month: ";
    cin >> m;

    cout << "Enter day: ";
    cin >> d;

    cout << "Enter year: ";
    cin >> y;

    Date date(m, d, y);

    cout << "\nFormats:\n";
    date.format1();
    date.format2();
    date.format3();

    return 0;
}
