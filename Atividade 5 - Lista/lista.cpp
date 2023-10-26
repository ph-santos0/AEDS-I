#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

const int MAX_LIVROS = 100;

struct Livro
{
    int codigo;
    string nome;
    string editora;
    int ano;
};

struct ListaDeLivros
{
    int quantidade = 0;
    Livro livros[MAX_LIVROS];
};

ListaDeLivros lista;

void inserirInicio(Livro li);
void inserirFim(Livro li);
void inserirEmUmaPosicao(Livro li, int posicao);

void trocarPosicao();
void editarPosicao();

void importarLista();
void exportarLista();

void removerInicio();
void removerFim();
void removerDeUmaPosicao(int posicao);

Livro leDoTeclado();

int menu();

void mostrarLista();

int main()
{

    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao, posicao;
    Livro livro;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            system("cls");
            cout << "Inserir no início." << endl
                 << endl;
            livro = leDoTeclado();
            inserirInicio(livro);
            break;
        case 2:
            system("cls");
            cout << "Inserir em uma posição." << endl
                 << endl;
            livro = leDoTeclado();
            cout << "Em qual posicao? ";
            cin >> posicao;
            inserirEmUmaPosicao(livro, posicao);
            break;
        case 3:
            system("cls");
            cout << "Inserir no final." << endl
                 << endl;
            livro = leDoTeclado();
            inserirFim(livro);
            break;
        case 4:
            system("cls");
            cout << "Alterar posições." << endl
                 << endl;
            trocarPosicao();
            break;
        case 5:
            system("cls");
            cout << "Editar posição." << endl
                 << endl;
            editarPosicao();
            break;
        case 6:
            system("cls");
            cout << "Remover no início." << endl
                 << endl;
            removerInicio();
            break;
        case 7:
            system("cls");
            cout << "Remover no final." << endl
                 << endl;
            removerFim();
            break;
        case 8:
            system("cls");
            cout << "Remover em uma posição." << endl
                 << endl;
            cout << "Em qual posicao? ";
            cin >> posicao;
            removerDeUmaPosicao(posicao);
            break;
        case 9:
            system("cls");
            cout << "Importado!" << endl
                 << endl;
            importarLista();
            break;

        case 10:
            system("cls");
            cout << "Exportado!" << endl
                 << endl;
            exportarLista();
            break;

        case 11:
            system("cls");
            cout << "Lista completa." << endl
                 << endl;
            mostrarLista();
            break;
        case 0:
            system("cls");
            cout << "Obrigado por usar o programa!" << endl;
            break;
        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    } while (opcao != 0);
}

void inserirInicio(Livro li)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        for (int i = lista.quantidade; i > 0; i--)
        {
            lista.livros[i] = lista.livros[i - 1];
        }
        lista.livros[0] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}
void inserirFim(Livro li)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        lista.livros[lista.quantidade] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}
void inserirEmUmaPosicao(Livro li, int posicao)
{
    if (lista.quantidade < MAX_LIVROS)
    {
        for (int i = lista.quantidade; i > posicao; i--)
        {
            lista.livros[i] = lista.livros[i - 1];
        }
        lista.livros[posicao] = li;
        lista.quantidade = lista.quantidade + 1;
    }
}

void removerInicio()
{
    if (lista.quantidade > 0)
    {
        cout << "Removendo ";
        cout << lista.livros[0].codigo << ' ';
        cout << lista.livros[0].nome << endl;
        for (int i = 0; i < lista.quantidade; i++)
        {
            lista.livros[i] = lista.livros[i + 1];
        }
        lista.quantidade = lista.quantidade - 1;
    }
    cout << "Removido!" << endl
         << endl;
    system("pause");
}
void removerFim()
{
    if (lista.quantidade > 0)
    {
        cout << "Removendo ";
        cout << lista.livros[lista.quantidade - 1].codigo << ' ';
        cout << lista.livros[lista.quantidade - 1].nome << endl;
        lista.quantidade = lista.quantidade - 1;
    }
    cout << "Removido!" << endl
         << endl;
    system("pause");
}
void removerDeUmaPosicao(int posicao)
{
    if (lista.quantidade > 0 && posicao < lista.quantidade)
    {
        cout << "Removendo ";
        cout << lista.livros[posicao].codigo << ' ';
        cout << lista.livros[posicao].nome << endl;
        for (int i = posicao; i < lista.quantidade; i++)
        {
            lista.livros[i] = lista.livros[i + 1];
        }
        lista.quantidade = lista.quantidade - 1;
    }
    cout << "Removido!" << endl
         << endl;
    system("pause");
}

void mostrarLista()
{
    cout << "\tCONTEÚDO DA LISTA" << endl
         << endl;
    for (int i = 0; i < lista.quantidade; i++)
    {
        cout << lista.livros[i].codigo << " | ";
        cout << lista.livros[i].nome << " | ";
        cout << lista.livros[i].editora << " | ";
        cout << lista.livros[i].ano << endl;
    }
    cout << endl;
    system("pause");
}

void trocarPosicao()
{
    if (lista.quantidade >= 1)
    {
        int pos1, pos2;
        cout << "Qual deseja selecionar? (Posição 1) ";
        cin >> pos1;
        cout << "Qual posição deseja trocar? (Posição 2) ";
        cin >> pos2;

        if (pos1 > lista.quantidade || pos2 > lista.quantidade)
        {
            cout << "Posição inválida." << endl;
            return;
        }

        if (pos1 == pos2)
        {
            cout << "Você não pode trocar pela mesma posição." << endl;
            return;
        }

        Livro aux = lista.livros[pos1];
        lista.livros[pos1] = lista.livros[pos2];
        lista.livros[pos2] = aux;
        cout << "Posição trocada." << endl;
    }
}

void editarPosicao()
{
    if (lista.quantidade > 0)
    {
        int pos;
        cout << "Qual posição deseja editar? ";
        cin >> pos;

        if (pos > lista.quantidade)
        {
            cout << "Posição inválida." << endl;
            return;
        }

        Livro livro = leDoTeclado();
        lista.livros[pos] = livro;
        cout << "Posição editada." << endl;
    }
    system("pause");
}

void importarLista()
{
    ifstream arquivo("lista.txt", std::ios::in);
    if (arquivo.is_open())
    {
        ListaDeLivros lista2;
        lista = lista2;
        while (!arquivo.eof())
        {
            Livro livro;
            arquivo >> livro.codigo >> livro.nome >> livro.editora >> livro.ano;
            inserirFim(livro);
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
    system("pause");
}

void exportarLista()
{
    ofstream arquivo("lista.txt");
    if (arquivo.is_open())
    {
        for (int i = 0; i < lista.quantidade; i++)
        {
            arquivo << lista.livros[i].codigo << " ";
            arquivo << lista.livros[i].nome << " ";
            arquivo << lista.livros[i].editora << " ";
            arquivo << lista.livros[i].ano;
            if (i < lista.quantidade - 1)
            {
                arquivo << endl;
            }
        }

        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
    system("pause");
}

Livro leDoTeclado()
{
    Livro livro;
    cout << "Código: ";
    cin >> livro.codigo;
    cout << "Nome: ";
    cin >> livro.nome;
    cout << "Editora: ";
    cin >> livro.editora;
    cout << "Ano: ";
    cin >> livro.ano;
    return livro;
}

int menu()
{
    system("cls");
    int opcao;
    cout << "\tOpções" << endl
         << endl;
    cout << "1 - Inserir no início." << endl;
    cout << "2 - Inserir em uma posição." << endl;
    cout << "3 - Inserir no final." << endl;
    cout << "4 - Alterar posições." << endl;
    cout << "5 - Editar posição." << endl;
    cout << "6 - Remover no início." << endl;
    cout << "7 - Remover no final." << endl;
    cout << "8 - Remover em uma posição." << endl;
    cout << "9 - Importar lista." << endl;
    cout << "10 - Exportar lista." << endl;
    cout << "11 - Mostrar lista." << endl;
    cout << "0 - Sair." << endl
         << endl;
    cout << "Digite: ";
    cin >> opcao;
    return opcao;
}