/*
#include <iostream>
using namespace std;

int main() {
    int* vektor = nullptr;  // pekare till dynamisk vektor
    int antal = 0;          // antal tal i vektorn
    int tal;                // tal som användaren matar in

    cout << "Mata in heltal (sluta med en bokstav eller 'q'):\n";

    // Läs in tal så länge användaren matar in siffror
    while (cin >> tal) {
        // Skapa en ny temporär vektor som är ett element större
        int* temp = new int[antal + 1];

        // Kopiera alla gamla värden till den nya vektorn
        for (int i = 0; i < antal; i++) {
            temp[i] = vektor[i];
        }

        // Frigör det gamla utrymmet
        delete[] vektor;

        // Låt pekaren peka på den nya vektorn
        vektor = temp;

        // Spara det nya talet i den sista platsen
        vektor[antal] = tal;

        // Öka antal
        antal++;

        cout << "Mata in nästa tal (eller avsluta med bokstav): ";
    }

    cout << "\nDu matade in följande tal:\n";
    for (int i = 0; i < antal; i++) {
        cout << vektor[i] << " ";
    }
    cout << endl;

    // Frigör dynamiskt minne
    delete[] vektor;
    vektor = nullptr;

    return 0;
}
*/ 



/*
//Det här är för project euler problem 1


#include <iostream>
using namespace std;

//Find the sum of all the multiples of 3 or 5 below 1000.

int main() {
    int sum = 0;

    // Finding multiples of 3 and 5 under 1000
    for(int i=0; i<1000; i++){
        if (i%3 == 0) sum += i;
        if (i%5 == 0) sum += i;
    }

    // Removing repeats from sum
    for(int i=0; i<1000; i=i+5){
        if (i%3 ==0) sum -= i;
    }


    printf("Answer of Sum = %d", sum );
    return 0;
}
*/