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
         << "1 - Mega Sena" << endl
         << "2 – Chuva" << endl
         << "3 - Somar coluna da matriz" << endl
         << "4 – Somar linha da matriz" << endl
         << "5 – Somar diagonal" << endl
         << "6 – Quadrado Mágico" << endl
         << "7 - Converter número em X" << endl
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
                cout << "Obrigado por utilizar o sistema de matriz !" << endl
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
         << endl;

    int a[6], b[10], cont = 0;

    cout << "Insira o gabarito da Mega Sena: " << endl;
    for (int i = 0; i < 6; i++)
    {
        cin >> a[i];
    }

    cout << endl
         << "Insira a aposta a ser conferida: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> b[i];
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (b[i] == a[j])
            {
                cont++;
                a[j] = -1;
            }
        }
    }

    if (cont == 4)
    {
        cout << endl
             << "Você fez uma quadra! Marcou " << cont << " pontos." << endl;
    }
    else if (cont == 5)
    {
        cout << endl
             << "Você fez uma quina! Marcou " << cont << " pontos." << endl;
    }
    else if (cont == 6)
    {
        cout << endl
             << "Você fez uma sena! Marcou " << cont << " pontos." << endl;
    }
    else
    {
        cout << endl
             << "Você marcou " << cont << " pontos." << endl;
    }
}

int questao2()
{
    cout << "Questão 2" << endl
         << endl;

    int n;

    cout << "Insira a dimensão das matrizes: ";
    cin >> n;
    cout << endl;

    int m1[n][n], m2[n][n], m3[n][n];

    cout << "Valores da primeira matriz: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m1[i][j];
        }
    }

    cout << endl;

    cout << "Valores da segunda matriz: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m2[i][j];
        }
    }

    cout << endl
         << "Soma das matrizes: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
            cout << m3[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;
}

int questao3()
{
    cout << "Questão 3" << endl
         << endl;

    int m[3][3], c[3];

    cout << "Insira os números da matriz (3x3): " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        c[i] = m[0][i] + m[1][i] + m[2][i];
    }

    cout << endl
         << "Soma da coluna 1: " << c[0] << endl
         << "Soma da coluna 2: " << c[1] << endl
         << "Soma da coluna 3: " << c[2] << endl;
}

int questao4()
{
    cout << "Questão 4" << endl
         << endl;

    int m[3][3], l[3];

    cout << "Insira os números da matriz (3x3): " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        l[i] = m[i][0] + m[i][1] + m[i][2];
    }

    cout << endl
         << "Soma da linha 1: " << l[0] << endl
         << "Soma da linha 2: " << l[1] << endl
         << "Soma da linha 3: " << l[2] << endl;
}

int questao5()
{
    cout << "Questão 5" << endl
         << endl;

    int m[3][3], dp = 0, ds = 0;

    cout << "Insira os números da matriz (3x3): " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> m[i][j];

            if (i == j)
            {
                dp += m[i][j];
            }
            if (i + j == 2)
            {
                ds += m[i][j];
            }
        }
    }

    system("cls");

    cout << "Questão 5" << endl
         << endl;

    cout << "Matriz preenchida: " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << m[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl
         << "Soma da diagonal principal: " << dp << endl
         << "Soma da diagonal secundária: " << ds << endl;
}

int questao6()
{
    cout << "Questão 6" << endl
         << endl;

    int m[3][3], l[3], c[3], dp = 0, ds = 0;

    cout << "Insira os números da matriz (3x3): " << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> m[i][j];

            if (i == j)
            {
                dp += m[i][j];
            }
            if (i + j == 2)
            {
                ds += m[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        c[i] = m[0][i] + m[1][i] + m[2][i];
    }

    for (int i = 0; i < 3; i++)
    {
        l[i] = m[i][0] + m[i][1] + m[i][2];
    }

    cout << endl
         << "A matriz é um quadrado mágico? " << endl;

    if (dp == ds && c[0] == c[1] && c[1] == c[2] && l[0] == l[1] && l[1] == l[2] && dp == c[0] && c[0] == l[0])
    {
        cout << endl
             << "SIM" << endl;
    }
    else
    {
        cout << endl
             << "NÃO" << endl;
    }
}

int questao7()
{
    cout << "Questão 7" << endl
         << endl;

    char m0[5][4] = {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'};
    char m1[5][4] = {' ', ' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', 'X', 'X'};
    char m2[5][4] = {' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X'};
    char m3[5][4] = {' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X'};
    char m4[5][4] = {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X'};
    char m5[5][4] = {' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X'};
    char m6[5][4] = {' ', 'X', 'X', 'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'};
    char m7[5][4] = {' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' ', ' ', ' ', 'X', ' '};
    char m8[5][4] = {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X'};
    char m9[5][4] = {' ', 'X', 'X', 'X', ' ', 'X', ' ', 'X', ' ', 'X', 'X', 'X', ' ', ' ', ' ', 'X', ' ', 'X', 'X', 'X'};
    int num;

    cout << "Insira o número a ser exibido (0 a 9): ";
    cin >> num;
    cout << endl;

    if (num == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m0[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m1[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 2)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m2[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 3)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m3[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 4)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m4[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m5[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 6)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m6[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 7)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m7[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 8)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m8[i][j] << " ";
            }
            cout << endl;
        }
    }
    if (num == 9)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m9[i][j] << " ";
            }
            cout << endl;
        }
    }

    if (num < 0 || num > 9)
    {
        cout << endl
             << "Número invalido, tente um número de 0 a 9";
    }

    cout << endl
         << endl;
}