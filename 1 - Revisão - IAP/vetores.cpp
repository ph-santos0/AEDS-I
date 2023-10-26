#include <iostream>
#include <windows.h>

using namespace std;

int questao1(), questao2(), questao3(), questao4(), questao5(), questao6(), questao7();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao;
    system("cls");

    cout << "Digite o número da questão (1 a 7): " << endl
         << endl
         << "1 - Números inteiros de 1 a 50" << endl
         << "2 – Números inteiros de 1 a 100 em ordem decrescente" << endl
         << "3 - 100 primeiros números impares" << endl
         << "4 – Calcular metade de inteiros" << endl
         << "5 – Calcular quadrado de inteiros" << endl
         << "6 – Media de altura" << endl
         << "7 - Corrida" << endl
         << "0 – Sair" << endl
         << endl;

    cin >> opcao;

    switch (opcao)
    {
    case 0:
        int sair;
        do
        {
            system("cls");

            cout << "Realmente deseja sair ? (1 – Sim / 0 - Não)" << endl
                 << endl;
            cin >> sair;

            if (sair == 1)
            {
                system("cls");
                cout << "Obrigado por utilizar o sistema de vetores !" << endl
                     << endl;
                exit(0);
            }
            if (sair == 0)
            {
                main();
            }
        } while (sair < 0 || sair > 1);

    case 1:
        system("cls");
        questao1();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();
    case 2:
        system("cls");
        questao2();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();
    case 3:
        system("cls");
        questao3();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();
    case 4:
        system("cls");
        questao4();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();
    case 5:
        system("cls");
        questao5();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();
    case 6:
        system("cls");
        questao6();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();
    case 7:
        system("cls");
        questao7();
        cout << endl
             << endl
             << "Aperte qualquer tecla para voltar ao menu" << endl
             << endl;
        system("pause");
        main();

    default:
        cout << endl
             << "Você digitou uma opção inválida, tente novamente" << endl
             << endl;
        system("pause");
        main();
    }

    cout << endl
         << endl;
    return 0;
}

int questao1()
{
    cout << "Questão 1" << endl
         << endl
         << "Números inteiros de 1 a 50: " << endl
         << endl;

    int v[50];
    for (int i = 0; i < 50; i++)
    {
        v[i] = i+1;
        cout << v[i] << " ";
    }
}

int questao2()
{
    cout << "Questão 2" << endl
         << endl
         << "Números inteiros de 1 a 100 em ordem decrescente: " << endl
         << endl;

    int v[100];
    for (int i = 100; i > 0; i--)
    {
        v[i] = i;
        cout << v[i] << " ";
    }
}

int questao3()
{
    cout << "Questão 3" << endl
         << endl
         << "100 primeiros números impares: " << endl
         << endl;

    int v[100];

    for (int i = 1; i < 200; i += 2)
    {
        v[i / 2 + 1] = i;
    }

    for (int i = 1; i <= 100; i++)
    {
        cout << v[i] << " ";
    }
}

int questao4()
{
    cout << "Questão 4" << endl
         << endl
         << "Calcular metade de inteiros" << endl
         << endl;

    float v[10];

    cout << "Insira 10 números" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "° número: ";
        cin >> v[i];
        v[i] = v[i] / 2;
    }

    cout << endl
         << "A metade dos números é:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "° número: " << v[i] << endl;
    }
}

int questao5()
{
    cout << "Questão 5" << endl
         << endl
         << "Calcular quadrado de inteiros" << endl
         << endl;

    float v[10];

    cout << "Insira 10 números" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "° número: ";
        cin >> v[i];
        v[i] = v[i] * v[i];
    }

    cout << endl
         << "O quadrado dos números é:" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "° número: " << v[i] << endl;
    }
}

int questao6()
{
    cout << "Questão 6" << endl
         << endl
         << "Media de altura" << endl
         << endl;

    float v[10];

    cout << "Insira a altura dos 10 atletas em metros" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "° atleta: ";
        cin >> v[i];
    }
    cout << endl
         << "Atletas acima da média de altura:" << endl;

    for (int i = 0; i < 10; i++)
    {
        if (v[i] > 1.75)
        {
            cout << i + 1 << "° atleta com altura de " << v[i] << " metros" << endl;
        }
    }
}

int questao7()
{
    cout << "Questão 7" << endl
         << endl
         << "Corrida" << endl
         << endl;

    double runners[10][2];
    for (int i = 0; i < 10; i++)
    {
        cout << "Insira o tempo de corrida do " << i + 1 << "° corredor: ";
        cin >> runners[i][0];
        runners[i][1] = i;
    }

    double temp, temp2;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (runners[i][0] < runners[j][0])
            {
                temp = runners[i][0];
                runners[i][0] = runners[j][0];
                runners[j][0] = temp;
                temp2 = runners[i][1];
                runners[i][1] = runners[j][1];
                runners[j][1] = temp2;
            }
        }
    }

    cout << endl
         << "-------- Ranking --------" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << "° lugar - Atleta " << runners[i][1] + 1 << " - " << runners[i][0] << endl;
    }

    cout << endl
         << endl;
}