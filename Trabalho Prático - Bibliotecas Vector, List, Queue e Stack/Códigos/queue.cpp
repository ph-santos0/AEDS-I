#include <iostream>
#include <windows.h>
#include <queue>

using namespace std;

struct Aluno
{
    string nome;
    int ra;
};

queue<Aluno> fila;

void inserir(), remover(), listar();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls");

    cout << "   Fila do Refeitório" << endl
         << endl;
    cout << "1 - Inserir aluno no final da fila" << endl;
    cout << "2 - Retirar o primeiro aluno da fila" << endl;
    cout << "3 - Listar fila" << endl;
    cout << "0 - Sair" << endl
         << endl;
    cout << "Digite uma opção: ";

    int opcao;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
    {
        inserir();
        system("pause");
        main();
        break;
    }
    case 2:
    {
        remover();
        system("pause");
        main();
        break;
    }
    case 3:
    {
        listar();
        system("pause");
        main();
        break;
    }
    case 0:
    {
        system("cls");
        cout << "Obrigado por utilizar o programa." << endl;
        cout << endl
             << endl;
        return 0;
        break;
    }
    default:
    {
        cout << endl
             << "Opção inválida." << endl;
        system("pause");
        main();
        break;
    }
    }
}

void inserir()
{
    system("cls");
    Aluno aluno;
    cout << "Insira o nome: ";
    cin >> aluno.nome;
    cout << "Insira o RA: ";
    cin >> aluno.ra;

    fila.push(aluno);
    cout << endl
         << "Aluno adicionado no final da fila." << endl;
}

void remover()
{
    if (fila.size() == 0)
    {
        cout << endl
             << "Não foi possível prosseguir pois sua fila está vazia." << endl;
    }
    else
    {
        system("cls");
        fila.pop();
        cout << "Primeiro aluno entrou no refeitório e saiu da fila." << endl;
    }
}

void listar()
{
    if (fila.size() == 0)
    {
        cout << endl
             << "Não foi possível listar pois sua fila está vazia." << endl;
    }
    else
    {
        system("cls");
        cout << "   Fila do Refeitório" << endl
             << endl;
        queue<Aluno> filaAuxiliar = fila;
        int contador = 1;
        while (!filaAuxiliar.empty())
        {
            Aluno aluno = filaAuxiliar.front();
            cout << contador << "° - Nome: " << aluno.nome << " | RA: " << aluno.ra << endl;
            filaAuxiliar.pop();
            contador++;
        }

        cout << endl;
    }
}