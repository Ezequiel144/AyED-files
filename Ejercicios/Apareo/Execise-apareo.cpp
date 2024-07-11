#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct Parcial
{
    unsigned document;
    char name[30];
    unsigned note;
};

void showVect(Parcial[], const int);
int extractingData(FILE *, Parcial[]);
void conditionApareo(unsigned, unsigned);
void apareo(FILE *, FILE *);

int main()
{
    FILE *archParcialOne = fopen("Parcial-1.dat", "rb");
    FILE *archParcialTwo = fopen("Parcial-2.dat", "rb");

    Parcial alumnsParcialOne[20];
    Parcial alumnsParcialTwo[20];

    cout << "- Mostrando datos del archivo 1 -" << endl;
    int dimOne = extractingData(archParcialOne, alumnsParcialOne);
    showVect(alumnsParcialOne, dimOne);

    cout << "------------------------------------------------" << endl;
    cout << "- Mostrando datos del archivo 2 -" << endl;
    int dimTwo = extractingData(archParcialTwo, alumnsParcialTwo);
    showVect(alumnsParcialTwo, dimTwo);

    cout << "------------------------------------------------" << endl;
    cout << "- Condicion del alumno -" << endl;
    apareo(archParcialOne, archParcialTwo);
    fclose(archParcialOne);
    fclose(archParcialTwo);
    return 0;
}

void showVect(Parcial vect[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Documento -> " << vect[i].document << " | Nombre -> " << vect[i].name << " | Nota -> " << vect[i].note << endl;
    }
}

int extractingData(FILE *f, Parcial vect[])
{
    int cont = 0; /*
     Parcial aux;
     fread(&aux, sizeof(Parcial), 1, f);
     vect[0] = aux; */
    while (!feof(f))
    {
        fread(&vect[cont], sizeof(Parcial), 1, f);
        cont++;
    };
    return cont - 1;
}

void conditionApareo(unsigned note1, unsigned note2)
{
    if (note1 > 7 && note2 > 7)
    {
        cout << "Promociona" << endl;
    }
    else if (note1 > 5 && note2 > 5)
    {
        cout << "final" << endl;
    }
    else
    {
        cout << "recursa" << endl;
    }
}

void apareo(FILE *arch1, FILE *arch2)
{
    fseek(arch1, 0, SEEK_SET);
    fseek(arch2, 0, SEEK_SET);
    Parcial aux1, aux2;
    fread(&aux1, sizeof(Parcial), 1, arch1);
    fread(&aux2, sizeof(Parcial), 1, arch2);

    while (!feof(arch1) && !feof(arch2))
    {
        if (aux1.document < aux2.document)
        {
            cout <<"Documento -> "<< aux1.document <<" | Nombre: "<< aux1.name << endl;
            conditionApareo(aux1.note, aux2.note);
            fread(&aux1, sizeof(Parcial), 1, arch1);
        }
        else if (aux1.document > aux2.document)
        {
            cout << "Documento -> "<< aux2.document <<" | Nombre: "<< aux2.name << endl;
            conditionApareo(aux1.note, aux2.note);
            fread(&aux2, sizeof(Parcial), 1, arch2);
        }
        else /* (aux1.document == aux2.document) */
        {
            cout <<"Documento -> "<< aux2.document <<" | Nombre: "<< aux2.name << endl;
            conditionApareo(aux1.note, aux2.note);
            fread(&aux1, sizeof(Parcial), 1, arch1);
            fread(&aux2, sizeof(Parcial), 1, arch2);
        }
    }

    while (!feof(arch1))
    {
        cout <<"Documento -> "<< aux1.document <<" | Nombre: "<< aux1.name << endl;
        conditionApareo(aux1.note, 0);
        fread(&aux1, sizeof(Parcial), 1, arch1);
    }
    while (!feof(arch2))
    {
        cout <<"Documento -> "<< aux2.document <<" | Nombre: "<< aux2.name << endl;
        conditionApareo(0, aux2.note);
        fread(&aux2, sizeof(Parcial), 1, arch2);
    }
}