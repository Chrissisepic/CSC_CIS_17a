#include <iostream>
#include <string>
using namespace std;

class RetailItem {
private:
    string description;
    int unitsOnHand;
    double price;

public:

    RetailItem(string d, int u, double p) {
        description = d;
        unitsOnHand = u;
        price = p;
    }


    void setDescription(string d) { description = d; }
    void setUnits(int u) { unitsOnHand = u; }
    void setPrice(double p) { price = p; }


    string getDescription() const { return description; }
    int getUnits() const { return unitsOnHand; }
    double getPrice() const { return price; }
};

int main() {

    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);


    cout << "--- Item 1 ---" << endl;
    cout << "Description: " << item1.getDescription() << endl;
    cout << "Units on Hand: " << item1.getUnits() << endl;
    cout << "Price: $" << item1.getPrice() << endl;

    cout << "\n--- Item 2 ---" << endl;
    cout << "Description: " << item2.getDescription() << endl;
    cout << "Units on Hand: " << item2.getUnits() << endl;
    cout << "Price: $" << item2.getPrice() << endl;

    cout << "\n--- Item 3 ---" << endl;
    cout << "Description: " << item3.getDescription() << endl;
    cout << "Units on Hand: " << item3.getUnits() << endl;
    cout << "Price: $" << item3.getPrice() << endl;

    return 0;
}
