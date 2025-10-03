#include <iostream>
#include <iomanip>
using namespace std;

void calcSalary(double salary) {
    double increase = 0.026;
    double retroPay = salary * increase * 6;
    double newSalary = salary * (1 + increase);

    cout << fixed << setprecision(2);
    cout << "Your retro pay for 6 months is: " << retroPay << endl;
    cout << "Your new salary is: " << newSalary << endl;
}

int main() {
    while (true) {
        cout << "Enter your salary: ";
        double salary;
        cin >> salary;

        calcSalary(salary);

        cout << "Do you want to calculate again? (YES for yes, NO for exit): ";
        string next;
        cin >> next;

        if (next == "no" || next == "NO" || next == "No") {
            break;
        }
    }
    return 0;
}
