#include <iostream>
#include <windows.h>
#include <list>

using namespace std;

struct Aluno
{
    string nome;
    int idade;
};

list<Aluno> turma;

void inserirInicio(), inserirPosicao(), inserirFinal(), removerInicio(), removerPosicao(), removerFinal(), listar(), resetar();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls");

    cout << "\tTurma SI 231" << endl
         << endl;
    cout << "1 - Inserir aluno no inicio" << endl;
    cout << "2 - Inserir aluno em uma posição" << endl;
    cout << "3 - Inserir aluno no final" << endl;
    cout << "4 - Remover aluno no inicio" << endl;
    cout << "5 - Remover aluno em uma posição" << endl;
    cout << "6 - Remover aluno no final" << endl;
    cout << "7 - Listar turma" << endl;
    cout << "8 - Resetar" << endl;
    cout << "0 - Sair" << endl
         << endl;
    cout << "Digite uma opção: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
    {
        inserirInicio();
        system("pause");
        main();
        break;
    }
    case 2:
    {
        inserirPosicao();
        system("pause");
        main();
        break;
    }
    case 3:
    {
        inserirFinal();
        system("pause");
        main();
        break;
    }

    case 4:
    {
        removerInicio();
        system("pause");
        main();
        break;
    }
    case 5:
    {
        removerPosicao();
        system("pause");
        main();
        break;
    }
    case 6:
    {
        removerFinal();
        system("pause");
        main();
        break;
    }
    case 7:
    {
        listar();
        system("pause");
        main();
        break;
    }
    case 8:
    {
        resetar();
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

void inserirInicio()
{
    system("cls");
    Aluno aluno;
    cout << "Digite o nome: ";
    cin >> aluno.nome;
    cout << "Digite a idade: ";
    cin >> aluno.idade;

    turma.push_front(aluno);
    cout << endl
         << "Aluno adicionado no início da turma." << endl;
}

void inserirPosicao()
{
    system("cls");
    Aluno aluno;
    cout << "Digite o nome: ";
    cin >> aluno.nome;
    cout << "Digite a idade: ";
    cin >> aluno.idade;

    int posicao;
    cout << "Digite a posição: ";
    cin >> posicao;
    posicao = posicao - 1;

    list<Aluno>::iterator init = turma.begin();
    advance(init, posicao);
    turma.insert(init, aluno);
    cout << endl
         << "Aluno adicionado na " << posicao + 1 << "° posição da turma." << endl;
}

void inserirFinal()
{
    system("cls");
    Aluno aluno;
    cout << "Digite o nome: ";
    cin >> aluno.nome;
    cout << "Digite a idade: ";
    cin >> aluno.idade;

    turma.push_back(aluno);
    cout << endl
         << "Aluno adicionado no final da turma." << endl;
}

void removerInicio()
{
    system("cls");
    if (turma.size() == 0)
    {
        cout << "Não foi possível remover pois a turma está vazia." << endl;
    }
    else
    {
        turma.pop_front();
        cout << "Primeiro aluno removido." << endl;
    }
}

void removerPosicao()
{
    system("cls");
    if (turma.size() == 0)
    {
        cout << "Não foi possível remover pois a turma está vazia." << endl;
    }
    else
    {
        int posicao;
        cout << "Digite a posição: ";
        cin >> posicao;
        posicao = posicao - 1;

        list<Aluno>::iterator init = turma.begin();
        advance(init, posicao);
        turma.erase(init);
        cout << "Aluno da " << posicao + 1 << "° posição removido." << endl;
    }
}

void removerFinal()
{
    system("cls");
    if (turma.size() == 0)
    {
        cout << "Não foi possível remover pois a turma está vazia." << endl;
    }
    else
    {
        turma.pop_back();
        cout << "Último aluno removido." << endl;
    }
}

void listar()
{
    system("cls");
    if (turma.size() == 0)
    {
        cout << "Não foi possivel listar pois sua turma está vazia" << endl;
    }
    else
    {
        cout << "\tAlunos da turma" << endl
             << endl;
        list<Aluno>::iterator it;
        int contador = 1;
        for (it = turma.begin(); it != turma.end(); ++it)
        {
            cout << contador << "° - Nome: " << it->nome << " | Idade: " << it->idade << endl;
            contador++;
        }
        cout << endl;
    }
}

void resetar()
{
    system("cls");
    turma.clear();
    cout << "Turma resetada." << endl;
}