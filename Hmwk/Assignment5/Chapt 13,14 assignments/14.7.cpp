#include <iostream>
#include <string>
using namespace std;

class Month {
private:
    string name;
    int monthNumber;

    static string monthNames[12];

public:

    Month() {
        monthNumber = 1;
        name = "January";
    }

  
    Month(string m) {
        int found = -1;
        for (int i = 0; i < 12; i++) {
            if (monthNames[i] == m) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            cout << "Invalid month name." << endl;
            exit(0);
        }

        monthNumber = found + 1;
        name = m;
    }

  
    Month(int num) {
        if (num < 1 || num > 12) {
            cout << "Invalid month number." << endl;
            exit(0);
        }

        monthNumber = num;
        name = monthNames[num - 1];
    }

  
    void setMonthNumber(int num) {
        if (num < 1 || num > 12) return;
        monthNumber = num;
        name = monthNames[num - 1];
    }

    void setMonthName(string m) {
        for (int i = 0; i < 12; i++) {
            if (monthNames[i] == m) {
                name = m;
                monthNumber = i + 1;
                return;
            }
        }
    }


    int getMonthNumber() const { return monthNumber; }
    string getMonthName() const { return name; }

  
    Month operator++() {
        monthNumber++;
        if (monthNumber > 12) monthNumber = 1;
        name = monthNames[monthNumber - 1];
        return *this;
    }

   
    Month operator++(int) {
        Month temp = *this;
        monthNumber++;
        if (monthNumber > 12) monthNumber = 1;
        name = monthNames[monthNumber - 1];
        return temp;
    }


    Month operator--() {
        monthNumber--;
        if (monthNumber < 1) monthNumber = 12;
        name = monthNames[monthNumber - 1];
        return *this;
    }

 
    Month operator--(int) {
        Month temp = *this;
        monthNumber--;
        if (monthNumber < 1) monthNumber = 12;
        name = monthNames[monthNumber - 1];
        return temp;
    }


    friend ostream& operator<<(ostream &out, const Month &m) {
        out << m.name << " (" << m.monthNumber << ")";
        return out;
    }


    friend istream& operator>>(istream &in, Month &m) {
        string input;
        in >> input;

        bool ok = false;

        for (int i = 0; i < 12; i++) {
            if (Month::monthNames[i] == input) {
                m.name = input;
                m.monthNumber = i + 1;
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << "Invalid month name." << endl;
            exit(0);
        }

        return in;
    }
};


string Month::monthNames[12] = {
    "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};

int main() {

    Month m1("March");
    Month m2(12); 
    Month m3;   

    cout << "m1: " << m1 << endl;
    cout << "m2: " << m2 << endl;
    cout << "m3: " << m3 << endl;

    cout << "\nTesting ++ and --\n";

    ++m1;
    cout << "After ++m1: " << m1 << endl;

    m2++;
    cout << "After m2++: " << m2 << endl;

    --m3;
    cout << "After --m3: " << m3 << endl;

    m3--;
    cout << "After m3--: " << m3 << endl;

    return 0;
}
