#include <iostream>
#include <string>

using namespace std;

struct Item
{
    int idade;
    string nome;
    Item *proximo;
};

struct Fila
{
    Item *primeiro = NULL;
    Item *ultimo = NULL;
};
Fila *L = NULL;

void criarLista()
{
    L->primeiro = new Item;
    L->ultimo = L->primeiro;
    L->primeiro->proximo = NULL;
}
int vazia()
{
    return (L->primeiro == L->ultimo);
}

void inserir()
{
    Item *x = new Item;

    cout << "Digite um nome: ";
    cin >> x->nome;
    cout << "Digite a idade: ";
    cin >> x->idade;

    L->ultimo->proximo = x;
    L->ultimo = x;
    L->ultimo->proximo = NULL;
}

void remover()
{
    if (!vazia())
    {
        Item *aux = L->primeiro->proximo;
        cout << endl
             << "+++ REMOVENDO +++" << endl;
        cout << aux->nome << " " << aux->idade << endl
             << endl;
        L->primeiro->proximo = aux->proximo;
        if (aux == L->ultimo)
        {
            L->ultimo = L->primeiro;
        }
        delete aux;
    }
    else
    {
        cout << endl
             << "Vazia" << endl;
    }
}

void mostrar()
{
    Item *aux;
    aux = L->primeiro->proximo;
    while (aux != NULL)
    {
        cout << "Nome: " << aux->nome << " "
             << "Idade: " << aux->idade << endl;
        aux = aux->proximo;
    }
}

int menu()
{
    int opcao;
    cout << "\tOpcoes" << endl;
    cout << "1. Inserir" << endl;
    cout << "2. Remover" << endl;
    cout << "3. Mostrar" << endl;
    cout << "0. Sair" << endl
         << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}

int main()
{
    int opcao;
    L = new Fila;
    criarLista();
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            inserir();
            break;
        case 2:
            remover();
            break;
        case 3:
            mostrar();
            break;
        case 0:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Selecione uma opção válida!" << endl;
            break;
        }
    } while (opcao != 0);
    return 0;
}