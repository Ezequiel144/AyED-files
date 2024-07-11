#include <iostream>

using namespace std;

int main()
{
    FILE * archRead = fopen("modification.txt", "r");
    
    char c;
    char write[500]; 
    while (!feof(archRead))
    {
        c = fgetc(archRead);
        cout<<c;
    }


    cout<<endl<<"Que vas a responder: ";
    cin.getline(write,500);
    cout<<"Procesando..."<<endl;


    FILE * archWrite = fopen("modification.txt", "w");
    /* fseek(archWrite,sizeof(archWrite),SEEK_SET); */
    fputs(write,archWrite);
    fclose(archRead);
    fclose(archWrite);
    cout<<"listo. mirar el archivo "<<endl;
    return 0;
}