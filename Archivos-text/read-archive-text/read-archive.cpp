#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    FILE *arch;
    char c;
    arch = fopen("read.txt", "r");

    if (!arch)
    {
        cout << "Error en el archivo" << endl;
        return -1;
    }

    while (!feof(arch))
    {
        c = fgetc(arch);
        cout<<c;
    }

    cout<<endl<<"Se termino de leer el archivo"<<endl;
    fclose(arch);

    return 0;
}