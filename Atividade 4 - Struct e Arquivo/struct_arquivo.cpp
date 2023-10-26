#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;
struct dados
{
    string nome;
    int idade, filhos;
    double salario;
    char sexo;
};

dados d[10];

void manual(), importar();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls");
    cout << "Banco de dados de habitantes de Rio Vermelho" << endl
         << endl;
    cout << "1 - Digitar dados manualmente" << endl
         << "2 - Importar de arquivo .txt" << endl
         << "3 - Sair" << endl
         << endl;

    int op = 0;
    cin >> op;
    if (op == 1)
    {
        manual();
    }
    else if (op == 2)
    {
        importar();
    }
    else if (op == 3)
    {
        system("cls");
        cout << "Obrigado por usar o programa!" << endl;
        exit(0);
    }
    else
    {
        main();
    }

    cout << endl
         << endl;
    return 0;
}

void manual()
{
    system("cls");

    ofstream arquivo("dados.txt");

    for (int i = 0; i < 10; i++)
    {
        cout << "Habitante " << i + 1 << endl
             << endl;
        cout << "Insira o nome: ";
        cin >> d[i].nome;
        cout << "Insira o salario: ";
        cin >> d[i].salario;
        cout << "Insira o idade: ";
        cin >> d[i].idade;
        cout << "Insira o numero de filhos: ";
        cin >> d[i].filhos;
        cout << "Insira o sexo (M ou F): ";
        cin >> d[i].sexo;
        cout << endl
             << endl;

        arquivo << d[i].nome << endl;
        arquivo << d[i].salario << endl;
        arquivo << d[i].idade << endl;
        arquivo << d[i].filhos << endl;
        arquivo << d[i].sexo << endl;
    }

    importar();

    arquivo.close();
}

void importar()
{
    system("cls");

    ifstream arquivo("dados.txt");

    for (int i = 0; i < 10; i++)
    {
        arquivo >> d[i].nome;
        arquivo >> d[i].salario;
        arquivo >> d[i].idade;
        arquivo >> d[i].filhos;
        arquivo >> d[i].sexo;
    }

    cout << "Importado!" << endl
         << endl;

    system("pause");
    arquivo.close();

    double mfilhos = 0, msalario = 0, contm = 0, contms = 0, percent = 0;
    int maior = 0;

    // Calculo da media de salario
    for (int i = 0; i < 10; i++)
    {
        msalario += d[i].salario;
    }
    msalario = msalario / 10;

    // Calculo da media de filhos
    for (int i = 0; i < 10; i++)
    {
        mfilhos += d[i].filhos;
    }
    mfilhos = mfilhos / 10;

    // Descobrir maior salario
    for (int i = 0; i < 10; i++)
    {
        if (d[maior].salario < d[i].salario)
        {
            maior = i;
        }
    }

    // Porcentagem de mulheres
    for (int i = 0; i < 10; i++)
    {
        if (d[i].sexo == 'F')
        {
            contm++;
        }
        if (d[i].sexo == 'F' && d[i].salario > 1000)
        {
            contms++;
        }
    }

    percent = 100 / contm * contms;

    int op;
    do
    {
        system("cls");
        cout << "Média salarial da população: " << msalario << endl;
        cout << "Média de filhos da população: " << mfilhos << endl;
        cout << "Maior salario da população: " << d[maior].salario << endl;
        cout << "Percentual de mulheres com salario acima de R$ 1000: " << percent << "%" << endl
             << endl;
        cout << "Deseja exportar médias em medias.txt?" << endl;
        cout << "1 - Sim / 2 - Não" << endl
             << endl;
        cin >> op;

        if (op == 1)
        {
            ofstream arquivo("medias.txt");

            arquivo << "Média salarial da população: " << msalario << endl;
            arquivo << "Média de filhos da população: " << mfilhos << endl;
            arquivo << "Maior salario da população: " << d[maior].salario << endl;
            arquivo << "Percentual de mulheres com salario acima de R$ 1000: " << percent << "%";

            arquivo.close();

            system("cls");
            cout << "Exportado!" << endl
                 << endl;
            system("pause");
            main();
        }
        if (op == 2)
        {
            main();
        }
    } while (op < 1 || op > 2);
}