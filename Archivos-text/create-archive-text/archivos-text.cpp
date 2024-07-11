#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{

    FILE *arc;
    char c[100];
    arc = fopen("data.txt", "w");
    if (arc == NULL)
        cout << "error";
    else
    {
        cout << "Se puedo ingresar al archivo" << endl;
        cout << "Escribir algo de texto: ";
        cin.getline(c,100);
        fputs(c,arc);
        cout << "Lo que se escribio fue: " << c << endl;
        fclose(arc);
    }

    return 0;
}