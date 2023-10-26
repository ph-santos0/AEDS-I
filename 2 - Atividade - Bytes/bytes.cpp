#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    // bit = 0 ou 1 (binario)
    // 8 bits = 1 byte

    // char = 1 byte (8 bits)
    // bool = 1 byte
    // int = 4 bytes
    // string = 24 bytes
    // float = 4 bytes
    // double = 8 bytes

    struct teste
    {
        char nome[35];  // 35 bytes
        char sexo;      // 1 byte
        int idade[2];   // 8 bytes
        double salario; // 8 bytes
    };                  // total = 52 bytes

    teste b[5]; // 52 * 5 = 260

    int aux = 0;

    for (int i = 0; i < 5; i++)
    {
        aux += sizeof(b[i].nome);
        aux += sizeof(b[i].sexo);
        aux += sizeof(b[i].idade);
        aux += sizeof(b[i].salario);
    }
    cout << aux << endl;

    cout << endl
         << endl;
    return 0;
}