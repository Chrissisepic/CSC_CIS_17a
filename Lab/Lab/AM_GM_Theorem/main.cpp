#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;


float logAM(int arr[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double am = sum / n;
    return log(am); 
}


float logGM(int arr[], int n) {
    double sumLogs = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0) {
            cout << "Error: non-positive value found in array." << endl;
            return -1;
        }
        sumLogs += log(arr[i]);
    }
    double gm_log = sumLogs / n; 
    return gm_log;
}


int loadData(const string &filename, int arr[], int maxSize) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error opening " << filename << endl;
        return 0;
    }

    int val, count = 0;
    while (in >> val && count < maxSize) {
        arr[count++] = val;
    }

    in.close();
    return count;
}


int main() {
    int arr[1000];
    int n;
    string files[] = {"data10.txt", "data100.txt", "data1000.txt"};

    for (string file : files) {
        n = loadData(file, arr, 1000);
        if (n == 0) continue;

        float amLog = logAM(arr, n);
        float gmLog = logGM(arr, n);

        cout << "File: " << file << endl;
        cout << "Arithmetic Mean (log): " << amLog << endl;
        cout << "Geometric Mean (log): " << gmLog << endl;

        if (amLog >= gmLog)
            cout << "Confirmed: AM >= GM" << endl;
        else
            cout << "Error: AM < GM (should not happen!)" << endl;

        cout << "------------------------" << endl;
    }

    return 0;
}
