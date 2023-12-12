#include <iostream>
#include <windows.h>
#include <stack>

using namespace std;

struct Aluno
{
    string nome;
    int idade;
};

stack<Aluno> pilha;

void inserir(), remover(), listar();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls");

    cout << "   Turma SI 231" << endl
         << endl;
    cout << "1 - Inserir aluno" << endl;
    cout << "2 - Remover aluno" << endl;
    cout << "3 - Listar pilha" << endl;
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
    cout << "Insira a idade: ";
    cin >> aluno.idade;

    pilha.push(aluno);
    cout << endl
         << "Aluno adicionado." << endl;
}

void remover()
{
    system("cls");
    if (pilha.size() == 0)
    {
        cout << "Não foi possível remover pois sua pilha está vazia." << endl;
    }
    else
    {
        pilha.pop();
        cout << "Último aluno removido." << endl;
    }
}

void listar()
{
    system("cls");
    if (pilha.size() == 0)
    {
        cout << "Não foi possível listar pois sua pilha está vazia." << endl;
    }
    else
    {
        cout << "\tAlunos da turma" << endl
             << endl;

        stack<Aluno> pilhaAuxiliar = pilha;
        int contador = 1;

        while (!pilhaAuxiliar.empty())
        {
            Aluno pessoa = pilhaAuxiliar.top();
            cout << contador << "° - Nome: " << pessoa.nome << " | Idade: " << pessoa.idade << endl;
            pilhaAuxiliar.pop();
            contador++;
        }
        cout << endl;
    }
}