#include <iostream>
using namespace std;

class Inventory {
private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

public:
  
    Inventory() {
        itemNumber = 0;
        quantity = 0;
        cost = 0.0;
        totalCost = 0.0;
    }


    Inventory(int num, int qty, double c) {
        setItemNumber(num);
        setQuantity(qty);
        setCost(c);
        setTotalCost();
    }


    void setItemNumber(int num) {
        if (num < 0) num = 0;
        itemNumber = num;
    }

    void setQuantity(int qty) {
        if (qty < 0) qty = 0;
        quantity = qty;
    }

    void setCost(double c) {
        if (c < 0) c = 0.0;
        cost = c;
    }

    void setTotalCost() {
        totalCost = quantity * cost;
    }


    int getItemNumber() const { return itemNumber; }
    int getQuantity() const { return quantity; }
    double getCost() const { return cost; }
    double getTotalCost() const { return totalCost; }
};

int main() {
    int number, qty;
    double price;

    cout << "Enter item number: ";
    cin >> number;

    cout << "Enter quantity: ";
    cin >> qty;

    cout << "Enter cost per unit: ";
    cin >> price;

    Inventory item(number, qty, price);

    cout << "\nItem Summary:\n";
    cout << "Item Number: " << item.getItemNumber() << endl;
    cout << "Quantity: " << item.getQuantity() << endl;
    cout << "Cost per Unit: $" << item.getCost() << endl;
    cout << "Total Cost: $" << item.getTotalCost() << endl;

    return 0;
}
