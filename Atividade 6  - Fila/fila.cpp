#include <iostream>
#include <windows.h>
#include <fstream>
#include <limits>

using namespace std;

const int MAX_PEDIDOS = 20;

struct Pedido
{
    string nome;
    int mesa;
    string descricao;
};

struct FilaDePedidos
{
    int quantidade = -1;
    Pedido pedido[MAX_PEDIDOS];
};

FilaDePedidos pedidos;

void inserirPedido(Pedido pedido), removerPedido(), mostrarPedidos(), proximoPedido(), salvarPedidos(), lerPedidos();
Pedido leDoTeclado();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao;
    do
    {
        system("cls");

        if (pedidos.quantidade > -1)
        {
            cout << "\tPedido Atual" << endl
                 << endl;
            cout << "Nome: " << pedidos.pedido[0].nome << endl;
            cout << "Mesa: " << pedidos.pedido[0].mesa << endl;
            cout << "Descrição: " << pedidos.pedido[0].descricao << endl
                 << endl;
        }

        cout << "\tOpções" << endl
             << endl;
        cout << "1- Adicionar pedido" << endl;
        cout << "2- Remover pedido" << endl;
        cout << "3- Ver proximo pedido" << endl;
        cout << "4- Ver todos os pedidos" << endl;
        cout << "5- Importar pedidos" << endl;
        cout << "6- Exportar pedidos" << endl;
        cout << "0- Fechar programa" << endl
             << endl;

        cout << "Digite: ";
        cin >> opcao;
        switch (opcao)
        {
        case 1:
        {
            system("cls");
            cout << "\tAdicionar pedido" << endl;
            Pedido novoPedido = leDoTeclado();
            inserirPedido(novoPedido);
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\tRemover pedido" << endl;
            removerPedido();
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "\tVer proximo pedido" << endl;
            proximoPedido();
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\tVer todos os pedidos" << endl;
            mostrarPedidos();
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            cout << "\tImportar pedidos" << endl;
            lerPedidos();
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            cout << "\tExportar pedidos" << endl;
            salvarPedidos();
            system("pause");
            break;
        }
        case 0:
        {
            system("cls");
            cout << "\tFechar programa" << endl;
            system("pause");
            break;
        }
        }
    } while (opcao != 0);

    cout << endl
         << endl;
    return 0;
}

Pedido leDoTeclado()
{
    Pedido pedido;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, pedido.nome);
    cout << "Mesa: ";
    cin >> pedido.mesa;
    cout << "Descrição: ";
    cin.ignore();
    getline(cin, pedido.descricao);
    return pedido;
}

void inserirPedido(Pedido pedido)
{
    // -1 | 20
    if (pedidos.quantidade < MAX_PEDIDOS)
    {
        pedidos.quantidade++; // 0
        pedidos.pedido[pedidos.quantidade] = pedido;
    }
    else
    {
        cout << "Não é possível adicionar mais pedidos." << endl;
    }
}

void removerPedido()
{
    if (pedidos.quantidade > -1)
    {
        for (int i = 0; i <= pedidos.quantidade; i++)
        {
            pedidos.pedido[i] = pedidos.pedido[i + 1];
        }
        pedidos.quantidade--;
    }
    else
    {
        cout << "Não possui pedidos para remover." << endl;
    }
}

void mostrarPedidos()
{
    for (int i = 0; i <= pedidos.quantidade; i++)
    {
        cout << "--------- Pedido " << i + 1 << " ---------" << endl;
        cout << "Nome: " << pedidos.pedido[i].nome << endl;
        cout << "Mesa: " << pedidos.pedido[i].mesa << endl;
        cout << "Descrição: " << pedidos.pedido[i].descricao << endl;
    }
    cout << endl;
}

void proximoPedido()
{
    if (pedidos.quantidade > 0)
    {
        cout << "--------- Pedido 2 ---------" << endl;
        cout << "Nome: " << pedidos.pedido[1].nome << endl;
        cout << "Mesa: " << pedidos.pedido[1].mesa << endl;
        cout << "Descrição: " << pedidos.pedido[1].descricao << endl
             << endl;
    }
    else
    {
        cout << "Não possui próximos pedidos." << endl;
    }
}

void salvarPedidos()
{
    if (pedidos.quantidade > -1)
    {
        ofstream file("pedidos.txt");
        if (file.is_open())
        {
            for (int i = 0; i <= pedidos.quantidade; i++)
            {
                if (i == pedidos.quantidade)
                {
                    file << pedidos.pedido[i].nome << endl;
                    file << pedidos.pedido[i].mesa << endl;
                    file << pedidos.pedido[i].descricao;
                }
                else
                {
                    file << pedidos.pedido[i].nome << endl;
                    file << pedidos.pedido[i].mesa << endl;
                    file << pedidos.pedido[i].descricao << endl;
                }
            }
            file.close();
        }
        else
        {
            cout << "Não foi possível abrir o arquivo para salvar os pedidos." << endl;
        }
    }
    else
    {
        cout << "Não possui pedidos para salvar." << endl;
    }
}

void lerPedidos()
{
    ifstream file("pedidos.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            Pedido pedido;
            getline(file, pedido.nome);
            file >> pedido.mesa;
            file.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(file, pedido.descricao);
            inserirPedido(pedido);
        }
        file.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo para ler os pedidos." << endl;
    }
}