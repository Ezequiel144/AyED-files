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

void ShowFile(FILE* );

int main()
{
    FILE *arch;
    arch = fopen("Parcial-1.dat", "ab");

    if (arch == NULL)
        cout << "No se pudo abrir el archivo" << endl;
    else
    {
        Parcial parcial;
        cout << "Documento: ";
        cin >> parcial.document;
        while (parcial.document != 0)
        {
            cout << "Nombre: ";
            cin >> parcial.name;
            cout << "Nota: ";
            cin >> parcial.note;

            fwrite(&parcial, sizeof(Parcial), 1, arch);

            cout << "Documento: ";
            cin >> parcial.document;
        }
        fclose(arch);
    }

    FILE *archRead = fopen("Parcial-1.dat", "rb");
    
    if (!archRead)
    {
        cout << "Error al abrir el archivo" << endl;
        return -1;
    }

    cout << "- Mostarndo lo que esta dentro del archivo despues de lo agregado -" << endl;

    ShowFile(archRead);

    return 0;
}


void ShowFile(FILE* f){
    Parcial parcialRead;
    fread(&parcialRead, sizeof(Parcial), 1, f);
    while (!feof(f))
    {
        cout << "Documento -> " << parcialRead.document << " Nombre -> " << parcialRead.name << " nota -> " << parcialRead.note << endl;
        fread(&parcialRead, sizeof(Parcial), 1, f);
    }

    fclose(f);
}