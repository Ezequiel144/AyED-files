#include <iostream>
#include <stdio.h>

using namespace std;

struct Parcial
{
    unsigned document;
    char name[30];
    unsigned note;
};

void showVect(Parcial[], const int);
void loadingArchive(FILE *, Parcial[], const int);

int main()
{
    FILE *archOne = fopen("Parcial-1.dat", "wb");
    FILE *archTwo = fopen("Parcial-2.dat", "wb");

    const int dimOne = 3;
    const int dimTwo = 5;

    Parcial alumnsVectOne[dimOne] = {{111, "Juan", 3}, {222, "Pepe", 8}, {333, "Ana", 6}};
    Parcial alumnsVectTwo[dimTwo] = {{222, "Pepe", 8}, {300, "Prdro", 3}, {333, "Ana", 6}, {666, "Rosa", 5}, {777, "Carlos", 2}};

    showVect(alumnsVectOne, dimOne);
    cout << "---------------------------------------" << endl;
    showVect(alumnsVectTwo, dimTwo);

    cout<<"Cargando los datos a los archivos"<<endl;
    loadingArchive(archOne,alumnsVectOne,dimOne);
    loadingArchive(archTwo,alumnsVectTwo,dimTwo);
    fclose(archOne);
    fclose(archTwo);

    return 0;
}

void showVect(Parcial vect[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Documento -> " << vect[i].document << " | Nombre -> " << vect[i].name << " | Nota -> " << vect[i].note << endl;
    }
}

void loadingArchive(FILE *f, Parcial vect[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        fwrite(&vect[i], sizeof(Parcial), 1, f);
    }
}
