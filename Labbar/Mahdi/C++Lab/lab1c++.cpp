#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    int * vector = nullptr;
    int antalNumber=0;

    cout<<"Mata in ditt tal avluta med en'bokstav'"<<endl;
    int num;
    while (cin>>num)
    {
        int* NewArray= new int[antalNumber +1];//öka index på vectorn
        for (int i = 0; i<antalNumber; i++)
        {
            NewArray[i]=vector[i];//vi ska spara den gamla listan/veckotrn här
        }
            //lägga till nytt tall
        NewArray[antalNumber]=num;
        delete[]vector;
        vector=NewArray;
        antalNumber++;
    }
    cout<<"Inmatade: ";
    for(int i = 0; i<antalNumber; i++)
    {
        cout<<vector[i]<<"\t";
    }
    cout<<endl;

    delete[]vector;
    vector=nullptr;

    return 0;
}