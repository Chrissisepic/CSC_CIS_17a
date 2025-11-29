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

    void print() {
        int remaining = day;
        int monthIndex = 0;


        while (remaining > monthDays[monthIndex]) {
            remaining -= monthDays[monthIndex];
            monthIndex++;
        }


        cout << months[monthIndex] << " " << remaining << endl;
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
    int d;

    cout << "Enter a day of the year (1-365): ";
    cin >> d;

    DayOfYear date(d);

    cout << "Converted: ";
    date.print();

    return 0;
}
