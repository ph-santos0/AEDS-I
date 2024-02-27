#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct Aluno
{
    string nome;
    int idade;
};

vector<Aluno> turma;

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

    int opcao;
    cin >> opcao;

    switch (opcao)
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
    cout << "Insira o nome: ";
    cin >> aluno.nome;
    cout << "Insira a idade: ";
    cin >> aluno.idade;

    turma.insert(turma.begin(), aluno);
    cout << endl
         << "Aluno adicionado no início da turma." << endl;
}

void inserirPosicao()
{
    system("cls");
    Aluno aluno;
    cout << "Insira o nome: ";
    cin >> aluno.nome;
    cout << "Insira a idade: ";
    cin >> aluno.idade;

    int posicao;
    cout << "Digite a posição: ";
    cin >> posicao;
    posicao = posicao - 1;

    turma.insert(turma.begin() + posicao, aluno);
    cout << endl
         << "Aluno adicionado na " << posicao + 1 << "° posição da turma." << endl;
}

void inserirFinal()
{
    system("cls");
    Aluno aluno;
    cout << "Insira o nome: ";
    cin >> aluno.nome;
    cout << "Insira a idade: ";
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
        cout << "Não foi possível remover pois sua turma está vazia." << endl;
    }
    else
    {
        turma.erase(turma.begin());
        cout << "Primeiro aluno removido." << endl;
    }
}

void removerPosicao()
{
    system("cls");
    if (turma.size() == 0)
    {
        cout << "Não foi possível remover pois sua turma está vazia." << endl;
    }
    else
    {
        int posicao;
        cout << "Digite a posição: ";
        cin >> posicao;
        posicao = posicao - 1;

        turma.erase(turma.begin() + posicao);
        cout << "Aluno da " << posicao + 1 << "° posição removido." << endl;
    }
}

void removerFinal()
{
    system("cls");
    if (turma.size() == 0)
    {
        cout << "Não foi possível remover pois sua turma está vazia." << endl;
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
        cout << "Não foi possível listar pois sua turma está vazia." << endl;
    }
    else
    {
        cout << "\tAlunos da turma" << endl
             << endl;
        for (int i = 0; i < turma.size(); i++)
        {
            cout << i + 1 << "° - Nome: " << turma[i].nome << " | Idade: " << turma[i].idade << endl;
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
