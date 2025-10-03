#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void write_to_file(const string &fileName, const string &name, const string &family, const string &phonNum, const string &email) {
    ofstream File(fileName, ios::app); // lägg till i filen
    if (!File) {
        cout << "Kunde inte öppna filen!" << endl;
        return;
    }
    File << name << "," << family << "," << phonNum << "," << email << endl;
    File.close();
}

void read_from_file(const string &fileName) {
    ifstream File(fileName);
    if (!File) {
        cout << "Kunde inte öppna filen!" << endl;
        return;
    }

    string rad;
    cout << "\nInnehåll i " << fileName << ":\n";
    while (getline(File, rad)) {
        cout << rad << endl; // skriv ut varje rad
    }

    File.close();
}

int main() {
    string fileName = "PersonInfo.txt";
    string name, family, phonNum, email, addMore;

    while (true) {
        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter your family: ";
        cin >> family;

        cout << "Enter your phone number: ";
        cin >> phonNum;

        cout << "Do you want to add email? (or press Enter to skip): ";
        cin.ignore(); // rensa newline från tidigare cin
        getline(cin, email);

        write_to_file(fileName, name, family, phonNum, email);

        cout << "Do you want to add another person? (Yes/NO): ";
        cin >> addMore;
        if (addMore == "NO" || addMore == "no" || addMore == "No") {
            break;
        }
    }

    cout << "Do you want to see the saved info? (Yes/NO): ";
    cin >> addMore;
    if (addMore == "YES" || addMore == "Yes" || addMore == "yes") {
        read_from_file(fileName);
    }

    return 0;
}
