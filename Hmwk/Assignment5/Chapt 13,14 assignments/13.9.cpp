#include <iostream>
using namespace std;

class Population {
private:
    int population;
    int births;
    int deaths;

public:

    Population(int p, int b, int d) {
        if (p < 1) p = 1;
        if (b < 0) b = 0;
        if (d < 0) d = 0;

        population = p;
        births = b;
        deaths = d;
    }


    void setPopulation(int p) {
        if (p < 1) p = 1;
        population = p;
    }

    void setBirths(int b) {
        if (b < 0) b = 0;
        births = b;
    }

    void setDeaths(int d) {
        if (d < 0) d = 0;
        deaths = d;
    }


    double getBirthRate() const {
        return (double)births / population;
    }


    double getDeathRate() const {
        return (double)deaths / population;
    }
};

int main() {
    int pop, b, d;

    cout << "Enter population: ";
    cin >> pop;

    cout << "Enter number of births: ";
    cin >> b;

    cout << "Enter number of deaths: ";
    cin >> d;

    Population stats(pop, b, d);

    cout << "\nBirth rate: " << stats.getBirthRate() << endl;
    cout << "Death rate: " << stats.getDeathRate() << endl;

    return 0;
}
