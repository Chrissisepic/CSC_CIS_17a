#include <iostream>
#include <string>
using namespace std;

class PersonalInfo {
private:
    string name;
    string address;
    int age;
    string phone;

public:

    void setName(string n) { name = n; }
    void setAddress(string a) { address = a; }
    void setAge(int ag) { age = ag; }
    void setPhone(string p) { phone = p; }


    string getName() const { return name; }
    string getAddress() const { return address; }
    int getAge() const { return age; }
    string getPhone() const { return phone; }
};

int main() {
    PersonalInfo me, friend1, family2;


    me.setName("Christopher");
    me.setAddress("482 Palm Grove Ave, Riverside, CA");
    me.setAge(20);
    me.setPhone("(951) 555-2384");


    friend1.setName("Ana");
    friend1.setAddress("1298 Hillcrest Drive, Moreno Valley, CA");
    friend1.setAge(19);
    friend1.setPhone("(951) 555-7193");


    family2.setName("Brenda");
    family2.setAddress("764 Sunrise Court, Perris, CA");
    family2.setAge(39);
    family2.setPhone("(951) 555-4410");


    cout << "----- My Info -----\n";
    cout << "Name: " << me.getName() << endl;
    cout << "Address: " << me.getAddress() << endl;
    cout << "Age: " << me.getAge() << endl;
    cout << "Phone: " << me.getPhone() << endl;

    cout << "\n----- Friend 1 Info -----\n";
    cout << "Name: " << friend1.getName() << endl;
    cout << "Address: " << friend1.getAddress() << endl;
    cout << "Age: " << friend1.getAge() << endl;
    cout << "Phone: " << friend1.getPhone() << endl;

    cout << "\n----- Family Member Info -----\n";
    cout << "Name: " << family2.getName() << endl;
    cout << "Address: " << family2.getAddress() << endl;
    cout << "Age: " << family2.getAge() << endl;
    cout << "Phone: " << family2.getPhone() << endl;

    return 0;
}
