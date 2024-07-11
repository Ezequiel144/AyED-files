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

int loadingData(Parcial[], const int);
void showVect(Parcial[], const int);
void writeArch(Parcial[], const int, FILE *);
void readingFile(Parcial[], const int, FILE *);

int main()
{
    FILE *arch = fopen("archivo-binary.dat", "wb");
    const int dimAlum = 100;
    Parcial alum[dimAlum];

    cout << "- Parcial de alumnos -" << endl;

    int dimRealAlum = loadingData(alum, dimAlum);

    cout << "----------------------------------------------" << endl;
    cout << "- Mostrando el listado de alumnos -" << endl;
    showVect(alum, dimRealAlum);

    cout << "Escribiendo archivo" << endl;
    writeArch(alum, dimRealAlum, arch);
    fclose(arch);

    FILE *f = fopen("archivo-binary.dat", "rb");
    Parcial alumRead[dimRealAlum];

    readingFile(alumRead,dimRealAlum,f);

    cout << "----------------------------------------------" << endl;
    cout << "- Mostrando lo que esta en el archivo binario -" << endl;
    showVect(alumRead, dimRealAlum);
    fclose(f);
    return 0;
}

void readingFile(Parcial vect[], const int dim, FILE *f)
{
    for (int i = 0; i < dim; i++)
    {
        fread(&vect[i], sizeof(Parcial), 1, f);
    }
}

void writeArch(Parcial vect[], const int dim, FILE *f)
{
    for (int i = 0; i < dim; i++)
    {
        fwrite(&vect[i], sizeof(Parcial), 1, f);
    }
}

void showVect(Parcial vect[], const int dim)
{
    for (int i = 0; i < dim; i++)
    {
        cout << "Documento -> " << vect[i].document << " | Nombre -> " << vect[i].name << " | Nota -> " << vect[i].note << endl;
    }
}

int loadingData(Parcial vect[], const int dim)
{
    unsigned auxDocument;
    int cont = 0;

    cout << "Numero de documento(DNI): ";
    cin >> auxDocument;

    for (int i = 0; i < dim; i++)
    {
        if (auxDocument == 0)
        {
            break;
        }
        vect[i].document = auxDocument;
        cout << "Nombre de alumno: ";
        cin >> vect[i].name;
        cout << "Nota de alumno: ";
        cin >> vect[i].note;
        cont++;
        cout << "Numero de documento(DNI): ";
        cin >> auxDocument;
    }

    return cont;
}