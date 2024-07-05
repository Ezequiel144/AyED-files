#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    FILE *f;
    f = fopen("data.txt", "r");
    char dateF;
    if (f != NULL)
    {
        return -1;
    }
    dateF = fgetc(f);

    while (!feof(f))
    {
        cout << dateF << endl;
        dateF = fgetc(f);
    }

    return 0;
}