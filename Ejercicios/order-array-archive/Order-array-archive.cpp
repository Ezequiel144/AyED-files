#include <iostream>
#include <stdio.h>

using namespace std;

struct Parcial
{
    unsigned document;
    char name[30];
    unsigned note;
};

int extractingData(FILE *, Parcial[]);
void showArray(Parcial[], const int);
void sort(Parcial[], const int);

int main()
{
    FILE *arch = fopen("Parcial-1.dat", "rb");
    const int dim = 50;
    Parcial alumns[dim];

    int realDimArray = extractingData(arch, alumns);

    sort(alumns,realDimArray);
    cout << "- Mostrando vector ordenado -" << endl;
    showArray(alumns, realDimArray);
    return 0;
}

void sort(Parcial vect[], const int dim)
{
    Parcial aux;
    for (int i = 0; i < dim - 1; i++)
    {
        for (int j = i + 1; j < dim; j++)
        {
            if (vect[i].document < vect[j].document)
            {
                aux = vect[i];
                vect[i] = vect[j];
                vect[j] = aux;
            }
        }
    }
}

int extractingData(FILE *f, Parcial vect[])
{
    int cont = 0;

    fread(&vect[cont], sizeof(Parcial), 1, f);
    while (!feof(f))
    {
        cont++;
        fread(&vect[cont], sizeof(Parcial), 1, f);
    }

    return cont;
}

void showArray(Parcial vect[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << vect[i].document << " - " << vect[i].name << " - " << vect[i].note << endl;
    }
}
