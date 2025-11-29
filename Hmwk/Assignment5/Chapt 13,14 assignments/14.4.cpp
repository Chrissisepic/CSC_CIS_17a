#include <iostream>
using namespace std;

class NumDays {
private:
    double hours;  
    double days;    

    void updateDays() {
        days = hours / 8.0;
    }

public:

    NumDays(double h = 0) {
        if (h < 0) h = 0;
        hours = h;
        updateDays();
    }

   
    void setHours(double h) {
        if (h < 0) h = 0;
        hours = h;
        updateDays();
    }

 
    double getHours() const { return hours; }
    double getDays() const { return days; }


    double operator+(const NumDays &right) {
        return hours + right.hours;
    }


    double operator-(const NumDays &right) {
        return hours - right.hours;
    }


    NumDays operator++() {
        hours++;
        updateDays();
        return *this;
    }


    NumDays operator++(int) {
        NumDays temp = *this;
        hours++;
        updateDays();
        return temp;
    }


    NumDays operator--() {
        hours--;
        if (hours < 0) hours = 0;
        updateDays();
        return *this;
    }


    NumDays operator--(int) {
        NumDays temp = *this;
        hours--;
        if (hours < 0) hours = 0;
        updateDays();
        return temp;
    }
};

int main() {
    NumDays a(12);  
    NumDays b(8);   

    cout << "A hours: " << a.getHours() << "  days: " << a.getDays() << endl;
    cout << "B hours: " << b.getHours() << "  days: " << b.getDays() << endl;

    cout << "\nA + B hours = " << (a + b) << endl;
    cout << "A - B hours = " << (a - b) << endl;

    cout << "\nTesting ++ and --\n";

    ++a;
    cout << "After prefix ++ on A: " << a.getHours() << " hours\n";

    a++;
    cout << "After postfix ++ on A: " << a.getHours() << " hours\n";

    --a;
    cout << "After prefix -- on A: " << a.getHours() << " hours\n";

    a--;
    cout << "After postfix -- on A: " << a.getHours() << " hours\n";

    return 0;
}
