#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cliente
{
    char nome[100];
    char cpf[50];
};

struct Filme
{
    char nome_filme[100];
    double valor_filme;
    int ano;
    int codigo_filme;
    int disponivel;
};

struct Registro
{

    struct Filme Alugados;
    struct Cliente Comprador;
    double valor_aluguel;
};

struct Repositorio
{
    struct Cliente Clientes[100]; //////////////// sempre que for definir um campo de struct, usar letra minuscula
    struct Filme Filmes[100];
    struct Registro Registros[100];
    int prox_cliente;
    int prox_filme;
    int prox_aluguel;
};



///////////////////////////////////////////// FUNCOES PARA CRIACAO DE STRUCTS ///////////////////////////////////

struct Repositorio CriarRepositorio(struct Cliente *clientes, struct Filme *filmes, struct Registro *registros) /////////////////// Funcao para criar um struct do repositorio
{
    int i;
    struct Repositorio temp_repositorio;

    for (i = 0; i < sizeof(clientes) / sizeof(clientes[0]); i++)
    {
        temp_repositorio.Clientes[i] = clientes[i];
    }

    for (i = 0; i < sizeof(filmes) / sizeof(filmes[0]); i++)
    {
        temp_repositorio.Filmes[i] = filmes[i];
    }

    for (i = 0; i < sizeof(registros) / sizeof(registros[0]); i++)
    {
        temp_repositorio.Registros[i] = registros[i];
    }

    temp_repositorio.prox_cliente = 0;

    temp_repositorio.prox_filme = 0;

    temp_repositorio.prox_aluguel = 0;

    return temp_repositorio;
}

struct Cliente CriarCliente(char nome[], char cpf[]) /////////////////// Funcao para criar um struct de cliente
{
    struct Cliente temp_cliente;

    strcpy(temp_cliente.nome, nome);
    strcpy(temp_cliente.cpf, cpf);
    return temp_cliente;
}

struct Filme CriarFilme(char nome_filme[], double valor_filme, int ano) /////////////////// Funcao para criar um struct de filme
{
    struct Filme temp_filme;

    strcpy(temp_filme.nome_filme, nome_filme);
    temp_filme.valor_filme = valor_filme;
    temp_filme.ano = ano;
    return temp_filme;
}

struct Registro CriarRegistro(struct Filme *alugados, struct Cliente *comprador, double valor_aluguel) /////////////////// Funcao para criar um struct de registro
{
    struct Registro temp_registro;

    temp_registro.Alugados = *alugados;
    temp_registro.Comprador = *comprador;
    temp_registro.valor_aluguel = valor_aluguel;

    return temp_registro;

}



//////////////////////////////////////////// CLIENTE /////////////////////////////////////////////////////////

void CadastrarCliente(struct Repositorio *LocadoraHI, char nome[], char cpf[]) ////////////////// Funcao para cadastrar clientes
{
    strcpy(LocadoraHI->Clientes[LocadoraHI->prox_cliente].nome, nome);
    strcpy(LocadoraHI->Clientes[LocadoraHI->prox_cliente].cpf, cpf);
    LocadoraHI->prox_cliente++;
}

void VisualizarClientes_Geral(struct Repositorio *LocadoraHI) ////////////////////////// Funcao para visualizar todos os clientes
{
    int i;
    system("cls");
    printf("____________________ Locadora HI ____________________\n\n");
    printf("____________________| Clientes |_____________________\n\n");
    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {

        printf("Nome do cliente: %s\n\n", LocadoraHI->Clientes[i].nome);
        printf("CPF do cliente: %s\n\n", LocadoraHI->Clientes[i].cpf);
        printf("_____________________________________________________\n\n\n");
    }
}

void VisualizarCliente_Especifico(struct Repositorio *LocadoraHI) ///////////////////////// Funcao para visualizar clientes especificos
{
    int i;
    char cpf_cliente[15], erro = 0;
    printf("____________________ Locadora HI ____________________\n\n");
    printf("________________| CPF's Cadastrados |________________\n\n");
    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {

        printf("CPF do cliente: %s\n\n", LocadoraHI->Clientes[i].cpf);
    }
    printf("_____________________________________________________\n\n\n");

    printf("Informe o numero do cpf que deseja obter informacoes: \n");
    scanf("%s", cpf_cliente);
    system("cls");
    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {

        if (strcmp(LocadoraHI->Clientes[i].cpf, cpf_cliente) == 0)
        {
            erro = 1;
            printf("____________________ Locadora HI ____________________\n\n");
            printf("____________________| Clientes |_____________________\n\n");
            printf("Nome do cliente: %s\n\n", LocadoraHI->Clientes[i].nome);
            printf("CPF do cliente: %s\n\n", LocadoraHI->Clientes[i].cpf);
            printf("_____________________________________________________\n\n\n");
        }
    }
    if (erro == 0)
    {
        printf("________________ Locadora HI ________________\n\n");
        printf("             |CPF nao encontrado|\n");
        printf("_____________________________________________\n\n\n");
    }
}

void RemoverCliente(struct Repositorio *LocadoraHI) //////////////////////// Funcao para Remover cliente
{
    int i, j;
    char cpf_cliente[15], erro = 0;
    printf("________________ Locadora HI ________________\n\n");
    printf("____________ CPF's Cadastrados ______________\n\n");
    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {
        printf("Nome do cliente: %s\n", LocadoraHI->Clientes[i].nome);
        printf("CPF do cliente: %s\n\n", LocadoraHI->Clientes[i].cpf);
    }
    printf("_____________________________________________\n\n\n");

    printf("Informe o numero do cpf que deseja remover: \n");
    scanf("%s", cpf_cliente);
    system("cls");

    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {

        if (strcmp(LocadoraHI->Clientes[i].cpf, cpf_cliente) == 0)
        {
            erro = 1;
            for (j = i; j < LocadoraHI->prox_cliente; j++)
            {
                strcpy(LocadoraHI->Clientes[j].cpf, LocadoraHI->Clientes[j + 1].cpf);
                strcpy(LocadoraHI->Clientes[j].nome, LocadoraHI->Clientes[j + 1].nome);
                LocadoraHI->prox_cliente--;
            }
        }
    }
    if (erro == 0)
    {
        printf("________________ Locadora HI ________________\n\n");
        printf("             |CPF nao encontrado|\n");
        printf("_____________________________________________\n\n\n");
    }
}

void EditarCliente(struct Repositorio *LocadoraHI) ////////////////////////// Funcao para Editar clientes
{

    int i, j;
    char cpf_cliente[15], Novo_Nome[100], Novo_Cpf[100], erro = 0;
    printf("________________ Locadora HI ________________\n\n");
    printf("____________ Clientes Cadastrados ______________\n\n");
    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {
        printf("Nome do cliente: %s\n\n", LocadoraHI->Clientes[i].nome);
        printf("CPF do cliente: %s\n\n", LocadoraHI->Clientes[i].cpf);
        printf("________________________________________________\n\n\n");
    }

    printf("Informe o numero do cpf que deseja editar as informacoes: \n");
    scanf("%s", cpf_cliente);

    system("cls");

    for (i = 0; i < LocadoraHI->prox_cliente; i++)
    {

        if (strcmp(LocadoraHI->Clientes[i].cpf, cpf_cliente) == 0)
        {
            erro = 1;
            printf("Informe um novo nome para o cliente: \n");
            scanf(" %[^\n]", Novo_Nome);
            printf("Informe um novo cpf para o cliente: \n");
            scanf(" %[^\n]", Novo_Cpf);

            system("cls");
            strcpy(LocadoraHI->Clientes[i].nome, Novo_Nome);
            strcpy(LocadoraHI->Clientes[i].cpf, Novo_Cpf);

            printf("________________ Locadora HI ________________\n\n");
            printf("___________ Clientes Cadastrados ____________\n\n");
            printf("Nome do cliente: %s\n\n", Novo_Nome);
            printf("CPF do cliente: %s\n\n", Novo_Cpf);
            printf("_____________________________________________\n\n\n");
        }
    }
    if (erro = 0)
    {
        printf("________________ Locadora HI ________________\n\n");
        printf("             |CPF nao encontrado|\n");
        printf("_____________________________________________\n\n\n");
    }
}

void RegistrarCliente(struct Repositorio *LocadoraHI, char *nome, char *cpf) //////////////////// Funcao para deixar alguns clientes pré-cadastrados //////////////////////////
{
    strcpy(LocadoraHI->Clientes[LocadoraHI->prox_cliente].nome, nome);
    strcpy(LocadoraHI->Clientes[LocadoraHI->prox_cliente].cpf, cpf);
    LocadoraHI->prox_cliente++;
}



///////////////////////////////////////////// FILME ///////////////////////////////////////////////////////////

void CadastrarFilme(struct Repositorio *LocadoraHI, struct Filme *filme) ////////////////////////// Funcao para cadastrar  filmes
{
    int i;

    LocadoraHI->Filmes[LocadoraHI->prox_filme] = *filme;
    LocadoraHI->Filmes[LocadoraHI->prox_filme].disponivel = 0;

    if (LocadoraHI->prox_filme != 0)
    {
        LocadoraHI->Filmes[LocadoraHI->prox_filme].codigo_filme = LocadoraHI->Filmes[LocadoraHI->prox_filme - 1].codigo_filme + 1;
    }

    LocadoraHI->prox_filme++;
}

void VisualizarFilmes_Geral(struct Repositorio *LocadoraHI) ////////////////////////// Funcao para visualizar todos os filmes
{
    int i;
    system("cls");
    printf("____________________ Locadora HI ____________________\n\n");
    printf("________________| Filmes Cadastrados |_______________\n\n");
    for (i = 0; i < LocadoraHI->prox_filme; i++)
    {
        if (LocadoraHI->Filmes[i].disponivel == 0)
        {
            printf("Nome do filme: %s\n\n", LocadoraHI->Filmes[i].nome_filme);
            printf("Valor do filme: R$%.2lf\n\n", LocadoraHI->Filmes[i].valor_filme);
            printf("Ano de estreia do filme: %d\n\n", LocadoraHI->Filmes[i].ano);
            printf("Codigo do filme: #%d\n\n", LocadoraHI->Filmes[i].codigo_filme);
            printf("_____________________________________________________\n\n\n");
        }
    }
}

void VisualizarFilme_Especifico(struct Repositorio *LocadoraHI) ///////////////////////// Funcao para visualizar filmes especificos
{
    int i, Codigo_filme, erro = 0;
    printf("____________________ Locadora HI ____________________\n\n");
    printf("________________| Filmes Cadastrados |_______________\n\n");

    for (i = 0; i < LocadoraHI->prox_filme; i++) /////////// Apresentar os filmes cadastrados
    {

        printf("Codigo do filme: #%d\n\n", LocadoraHI->Filmes[i].codigo_filme);
    }
    printf("_____________________________________________________\n\n\n");

    printf("Informe o codigo do filme que deseja obter informacoes: \n");
    scanf("%d", &Codigo_filme);

    system("cls");

    for (i = 0; i < LocadoraHI->prox_filme; i++)
    {

        if (LocadoraHI->Filmes[i].codigo_filme == Codigo_filme)
        {
            erro = 1;
            printf("____________________ Locadora HI ____________________\n\n");
            printf("________________| Filmes Cadastrados |_______________\n\n");
            printf("Nome do filme: %s\n\n", LocadoraHI->Filmes[i].nome_filme);
            printf("Valor do filme: R$%.2lf\n\n", LocadoraHI->Filmes[i].valor_filme);
            printf("Ano de estreia do filme: %d\n\n", LocadoraHI->Filmes[i].ano);
            printf("Codigo do filme: #%d\n\n", LocadoraHI->Filmes[i].codigo_filme);
            printf("_____________________________________________________\n\n\n");
        }
    }
    if (erro = 0)
    {
        printf("________________ Locadora HI ________________\n\n");
        printf("             |CPF nao encontrado|\n\n");
        printf("_____________________________________________\n\n\n");
    }
}

void RemoverFilme(struct Repositorio *LocadoraHI) //////////////////////// Funcao para Remover Filme
{
    int i, j;
    int Codigo_filme, erro = 0;
    printf("____________________ Locadora HI ____________________\n\n");
    printf("_______________| Filmes Cadastrados |________________\n\n");
    for (i = 0; i < LocadoraHI->prox_filme; i++)
    {
        printf("Nome do filme: %s\n\n ", LocadoraHI->Filmes[i].nome_filme);
        printf("Codigo do filme: #%d\n\n", LocadoraHI->Filmes[i].codigo_filme);
        printf("_____________________________________________________\n\n\n");
    }

    printf("Informe o codigo do filme que deseja remover: \n");
    scanf("%d", &Codigo_filme);
    system("cls");

    for (i = 0; i < LocadoraHI->prox_filme; i++)
    {

        if (LocadoraHI->Filmes[i].codigo_filme == Codigo_filme)
        {
            erro = 1;
            for (j = i; j < LocadoraHI->prox_filme; j++)
            {
                strcpy(LocadoraHI->Filmes[j].nome_filme, LocadoraHI->Filmes[j + 1].nome_filme);
                LocadoraHI->Filmes[j].valor_filme = LocadoraHI->Filmes[j + 1].valor_filme;
                LocadoraHI->Filmes[j].ano = LocadoraHI->Filmes[j + 1].ano;
                LocadoraHI->Filmes[j].codigo_filme = LocadoraHI->Filmes[j + 1].codigo_filme - 1;

                LocadoraHI->prox_filme--;
            }
            printf("____________________ Locadora HI ____________________\n\n");
            printf("\t  Filme removido com sucesso! \n");
            printf("_____________________________________________________\n\n\n");
        }
    }
    if (erro = 0)
    {
        printf("________________ Locadora HI ________________\n\n");
        printf("           |Filme nao encontrado|\n");
        printf("_____________________________________________\n\n\n");
    }
}

void EditarFilme(struct Repositorio *LocadoraHI) ////////////////////////// Funcao para editar os filmes
{
    int i, j, erro = 0;
    char Nome_Filme[100];
    double Novo_Valor;
    int Novo_Ano, Codigo_filme;

    printf("____________________ Locadora HI ____________________\n\n");
    printf("_______________| Filmes Cadastrados |________________\n\n");
    for (i = 0; i < LocadoraHI->prox_filme; i++)
    {
        printf("Nome do filme: %s\n\n", LocadoraHI->Filmes[i].nome_filme);
        printf("Valor do filme: R$%.2lf\n\n", LocadoraHI->Filmes[i].valor_filme);
        printf("Ano de estreia do filme: %d\n\n", LocadoraHI->Filmes[i].ano);
        printf("Codigo do filme: #%d\n\n", LocadoraHI->Filmes[i].codigo_filme);
        printf("_____________________________________________________\n\n\n");
    }

    printf("Informe o codigo do filme que deseja editar as informacoes: \n");
    scanf("%d", &Codigo_filme);

    system("cls");

    for (i = 0; i < LocadoraHI->prox_filme; i++)
    {

        if (LocadoraHI->Filmes[i].codigo_filme == Codigo_filme)
        {
            erro = 1;
            printf("Informe um novo nome para o filme: \n");
            scanf(" %[^\n]", Nome_Filme);
            printf("Informe um novo valor para o filme: \n");
            scanf("%lf", &Novo_Valor);
            printf("Informe um novo ano de estreia para o filme: \n");
            scanf("%d", &Novo_Ano);

            system("cls");
            strcpy(LocadoraHI->Filmes[i].nome_filme, Nome_Filme);
            LocadoraHI->Filmes[i].valor_filme = Novo_Valor;
            LocadoraHI->Filmes[i].ano = Novo_Ano;

            printf("____________________ Locadora HI ____________________\n\n");
            printf("__________________| Filme Editado |__________________\n\n");
            printf("Nome do cliente: %s\n\n", Nome_Filme);
            printf("Valor do filme: R$%.2lf\n\n", Novo_Valor);
            printf("Ano de estreia do filme: %d\n\n", Novo_Ano);
            printf("Codigo do filme: #%d\n\n", LocadoraHI->Filmes[i].codigo_filme);
            printf("_____________________________________________________\n\n\n");
        }
    }
    if (erro = 0)
    {
        printf("________________ Locadora HI ________________\n\n");
        printf("            |Filme nao encontrado|\n\n");
        printf("_____________________________________________\n\n\n");
    }
}

void RegistrarFilme(struct Repositorio *LocadoraHI, char *nome_filme, double valor_filme, int ano) //////////////////// Funcao para deixar alguns filmes pré-cadastrados
{
    strcpy(LocadoraHI->Filmes[LocadoraHI->prox_filme].nome_filme, nome_filme);
    LocadoraHI->Filmes[LocadoraHI->prox_filme].valor_filme = valor_filme;
    LocadoraHI->Filmes[LocadoraHI->prox_filme].ano = ano;

    LocadoraHI->Filmes[LocadoraHI->prox_filme].disponivel = 0;

    if (LocadoraHI->prox_filme != 0)
    {
        LocadoraHI->Filmes[LocadoraHI->prox_filme].codigo_filme = LocadoraHI->Filmes[LocadoraHI->prox_filme - 1].codigo_filme + 1;
    }
    LocadoraHI->prox_filme++;
}



//////////////////////////////////////////// REGISTROS /////////////////////////////////////////////////////////

void AlugarFilme(struct Repositorio *LocadoraHI, struct Cliente *comprador, struct Filme *filmes, int dias) ////////////////////////// Funcao para alugar um filme
{

    double valor_aluguel = (filmes->valor_filme * 0.10 * dias) + filmes->valor_filme;

    struct Registro registro = CriarRegistro(filmes, comprador, valor_aluguel);

    LocadoraHI->Registros[LocadoraHI->prox_aluguel] = registro;


    ///////////////// *0.10 é uma taxa de 10% do valor do filme por dia

    system("cls");

    printf("____________________ Locadora HI ____________________\n\n");
    printf("______________| Informacoes do Pedido |______________\n\n");

    printf("Dados do filme: \n\n");
    printf("Nome do filme: %s\n\n", filmes->nome_filme);
    printf("Valor do filme: R$%.2lf\n\n", filmes->valor_filme);
    printf("Ano de estreia do filme: %d\n\n", filmes->ano);
    printf("Codigo do filme: #%d\n\n", filmes->codigo_filme);
    printf("_____________________________________________________\n\n\n\n\n");
    printf("Dados do cliente: \n\n");
    printf("Nome do cliente: %s\n\n", comprador->nome);
    printf("CPF do cliente: %s\n\n", comprador->cpf);
    printf("_____________________________________________________\n\n\n");
    printf("Dados do aluguel: \n\n");
    printf("Valor total do aluguel: R$%.2lf\n\n", valor_aluguel);
    printf("_____________________________________________________\n\n\n");

    LocadoraHI->prox_aluguel++;
}

void VisualizarPedido(struct Repositorio *LocadoraHI) ////////////////////////////////////////// Funcao para visualizar os pedidos
{
    int i, Codigo_filme;
    char cpf_cliente[100];
    printf("____________________ Locadora HI ____________________\n\n");
    printf("_________________| Lista de Pedidos |________________\n\n");

    for (i = 0; i < LocadoraHI->prox_aluguel; i++)
    {
        printf("Nome do filme: %s\n", LocadoraHI->Registros[i].Alugados.nome_filme);
        printf("CPF do cliente: %s\n\n", LocadoraHI->Registros[i].Comprador.cpf);
        printf("_____________________________________________________\n\n\n");
    }

    printf("Informe o CPF do cliente que deseja obter informacoes: \n");
    scanf("%s", cpf_cliente);

    system("cls");

    for (i = 0; i < LocadoraHI->prox_aluguel; i++)
    {

        if (strcmp(LocadoraHI->Registros[i].Comprador.cpf, cpf_cliente) == 0)
        {
            printf("____________________ Locadora HI ____________________\n\n");
            printf("________________| Informacoes do Pedido |____________\n\n");
            printf("Dados do Filme: \n\n");
            printf("Nome do filme: %s\n\n", LocadoraHI->Registros[i].Alugados.nome_filme);
            printf("Valor do filme: R$%.2lf\n\n", LocadoraHI->Registros[i].Alugados.valor_filme);
            printf("Ano de estreia do filme: %d\n\n", LocadoraHI->Registros[i].Alugados.ano);
            printf("Codigo do filme: #%d\n\n", LocadoraHI->Registros[i].Alugados.codigo_filme);
            printf("_____________________________________________________\n\n\n");
            printf("Dados do cliente: \n\n");
            printf("Nome do cliente: %s\n\n", LocadoraHI->Registros[i].Comprador.nome);
            printf("CPF do cliente: %s\n\n", LocadoraHI->Registros[i].Comprador.cpf);
            printf("_____________________________________________________\n\n\n");
        }
    }
}



//////////////////////////////////////////// PRÉ-CADASTRADOS /////////////////////////////////////////////////////////

void PreCadastrados(struct Repositorio *LocadoraHI) //////////////////////////////////////////// PRÉ-CADASTRADO
{
    RegistrarCliente(LocadoraHI, "Henrique de Almeida Silva", "578.637.364-17");
    RegistrarCliente(LocadoraHI, "Baixinho dos testes", "856.583.654-15");
    RegistrarCliente(LocadoraHI, "Luis Filipe Alves Pereira", "583.650.824-13");

    RegistrarFilme(LocadoraHI, "Homem-Aranha Sem Volta para Casa", 17, 2022);
    RegistrarFilme(LocadoraHI, "Beleza oculta", 15, 2016);
    RegistrarFilme(LocadoraHI, "Lendas do Crime", 13, 2015);
}


//////////////////////////////////////////// Print Final /////////////////////////////////////////////////////////

void Fim() ////////////////////////////////////////// Funcao para visualizar por quem foi desenvolvido o projeto
{
    printf("____________________ Locadora HI ____________________\n\n");
    printf("- Desenvolvido por: \n\n");
    printf(" Henrique de Almeida Silva. \n\n");
    printf(" version 0.2.0  \t-\t 20/04/2022\n");
    printf("_____________________________________________________\n\n");

}

int main()
{

    int i;

    char nome_cliente[100], nome_filme[100];
    char cpf_cliente[50], cpf_compras[100];
    double valor_filme;
    int opcao, ano_filme, Codigo_filme, dias, erro = 0;

    struct Filme Filmes;
    struct Cliente Comprador;

    struct Cliente clientes[100];
    struct Filme filmes[100];
    struct Registro registros[100];

    struct Repositorio LocadoraHI = CriarRepositorio(clientes, filmes, registros);

    LocadoraHI.Filmes[0].codigo_filme = 1;

    PreCadastrados(&LocadoraHI);

    do //////////////////////////// Menu - Principal
    {
        system("cls");
        printf("____________________ Locadora HI ____________________\n\n");
        printf("1 - Gerenciar clientes.\n");
        printf("2 - Gerenciar filmes.\n");
        printf("3 - Gerenciar registros.\n");
        printf("4 - Sair.\n");
        printf("_____________________________________________________\n\n");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            do ////////////////////////// Menu - clientes
            {
                printf("____________________ Locadora HI ____________________\n\n");
                printf("____________________| Clientes |_____________________\n\n");
                printf("1 - Cadastrar cliente.\n");
                printf("2 - Buscar todos os clientes.\n");
                printf("3 - Buscar cliente especifico.\n");
                printf("4 - Remover cliente.\n");
                printf("5 - Editar cliente.\n");
                printf("6 - Voltar para o menu.\n");
                printf("_____________________________________________________\n\n");
                scanf("%d", &opcao);
                system("cls");

                switch (opcao)
                {
                case 1:
                    printf("Digite o nome do cliente: ");

                    scanf(" %[^\n]", nome_cliente);

                    printf("Digite o cpf do cliente: ");
                    scanf(" %[^\n]", cpf_cliente);

                    erro = 0;

                    for (i = 0; i < LocadoraHI.prox_cliente; i++)
                    {
                        if (strcmp(LocadoraHI.Clientes[i].cpf, cpf_cliente) == 0)
                        {
                            erro = 1;
                            system("cls");
                            printf("________________ Locadora HI ________________\n\n");
                            printf("            |CPF ja cadastrado|\n");
                            printf("_____________________________________________\n\n\n");
                        }
                    }

                    if (erro == 0)
                    {

                        system("cls");

                        struct Cliente criar = CriarCliente(nome_cliente, cpf_cliente);
                        printf("____________________ Locadora HI ____________________\n\n");
                        printf("____________________| Clientes |_____________________\n\n");
                        printf("Nome do cliente: %s\n\n", criar.nome);
                        printf("CPF do cliente: %s\n\n", criar.cpf);
                        printf("_____________________________________________________\n\n");

                        CadastrarCliente(&LocadoraHI, nome_cliente, cpf_cliente);
                    }

                    system("pause");
                    system("cls");

                    break;
                case 2:
                    VisualizarClientes_Geral(&LocadoraHI);
                    system("pause");
                    system("cls");
                    break;

                case 3:
                    VisualizarCliente_Especifico(&LocadoraHI);
                    system("pause");
                    system("cls");

                    break;

                case 4:
                    RemoverCliente(&LocadoraHI);
                    system("pause");
                    system("cls");

                    break;

                case 5:
                    EditarCliente(&LocadoraHI);
                    system("pause");
                    system("cls");

                    break;

                default:
                    break;
                }

            } while (opcao != 6);

            break;

        case 2:
            do ////////////////////////// Menu - filmes
            {
                printf("____________________ Locadora HI ____________________\n\n");
                printf("_____________________| Filmes |______________________\n\n");
                printf("1 - Cadastrar filme.\n");
                printf("2 - Buscar todos os filmes.\n");
                printf("3 - Buscar filme especifico.\n");
                printf("4 - Remover filme.\n");
                printf("5 - Editar filme.\n");
                printf("6 - Voltar para o menu.\n");
                printf("_____________________________________________________\n\n");
                scanf("%d", &opcao);
                system("cls");

                switch (opcao)
                {
                case 1:

                    printf("Digite o nome do filme: ");
                    scanf(" %[^\n]", nome_filme);

                    erro = 0;

                    for (i = 0; i < LocadoraHI.prox_filme; i++)
                    {
                        if (strcmp(LocadoraHI.Filmes[i].nome_filme, nome_filme) == 0)
                        {
                            erro = 1;
                            system("cls");
                            printf("________________ Locadora HI ________________\n\n");
                            printf("            |Filme ja cadastrado|\n");
                            printf("_____________________________________________\n\n\n");
                        }
                    }

                    if (erro == 0)
                    {
                        printf("Digite o valor do filme: ");
                        scanf("%lf", &valor_filme);

                        printf("Digite o ano do filme: ");
                        scanf(" %d", &ano_filme);

                        system("cls");

                        struct Filme filme = CriarFilme(nome_filme, valor_filme, ano_filme);
                        printf("____________________ Locadora HI ____________________\n\n");
                        printf("_____________________| Filmes |______________________\n\n");
                        printf("Nome do filme: %s\n\n", nome_filme);
                        printf("Valor do filme: R$%.2lf\n\n", valor_filme);
                        printf("Ano de estreia do filme: %d\n\n", ano_filme);
                        printf("_____________________________________________________\n\n");
                        CadastrarFilme(&LocadoraHI, &filme);
                    }

                    system("pause");
                    system("cls");
                    break;

                case 2:
                    VisualizarFilmes_Geral(&LocadoraHI);
                    system("pause");
                    system("cls");
                    break;

                case 3:
                    VisualizarFilme_Especifico(&LocadoraHI);
                    system("pause");
                    system("cls");
                    break;

                case 4:
                    RemoverFilme(&LocadoraHI);
                    system("pause");
                    system("cls");
                    break;

                case 5:
                    EditarFilme(&LocadoraHI);
                    system("pause");
                    system("cls");
                    break;

                default:
                    break;
                }

            } while (opcao != 6);

            break;

        case 3:
            do ////////////////////////// Menu - Registros
            {
                erro = 0;
                printf("____________________ Locadora HI ____________________\n\n");
                printf("____________________| Registros |____________________\n\n");
                printf("1 - Alugar um filme.\n");
                printf("2 - Visualizar pedidos.\n");
                printf("3 - Voltar para o menu.\n");
                printf("_____________________________________________________\n\n");
                scanf("%d", &opcao);
                system("cls");

                switch (opcao)
                {
                case 1:

                    system("cls");
                    printf("____________________ Locadora HI ____________________\n\n");
                    printf("________________| Filmes Disponiveis |_______________\n\n\n");

                    for (i = 0; i < LocadoraHI.prox_filme; i++) /////////// Apresentar os filmes cadastrados
                    {
                        if (LocadoraHI.Filmes[i].disponivel == 0)
                        {

                            printf("Nome do filme: %s\n\n", LocadoraHI.Filmes[i].nome_filme);
                            printf("Valor do filme: R$%.2lf\n\n", LocadoraHI.Filmes[i].valor_filme);
                            printf("Ano de estreia do filme: %d\n\n", LocadoraHI.Filmes[i].ano);
                            printf("Codigo do filme: #%d\n\n", LocadoraHI.Filmes[i].codigo_filme);
                            printf("_____________________________________________________\n\n\n\n");
                        }
                    }

                    printf("Informe o codigo do filme que deseja fazer o pedido: \n");
                    scanf("%d", &Codigo_filme);

                    system("cls");

                    printf("____________________ Locadora HI ____________________\n\n");
                    printf("______________| Clientes Cadastrados |_______________\n\n");
                    for (i = 0; i < LocadoraHI.prox_filme; i++)
                    {

                        printf("Nome do cliente: %s\n\n", LocadoraHI.Clientes[i].nome);
                        printf("CPF do cliente: %s\n\n", LocadoraHI.Clientes[i].cpf);
                        printf("_____________________________________________________\n\n\n");
                    }

                    printf("Infome o seu cpf para continuar: \n");
                    scanf("%s", cpf_compras);

                    for (i = 0; i < LocadoraHI.prox_cliente; i++)
                    {
                        if (strcmp(LocadoraHI.Clientes[i].cpf, cpf_compras) == 0)
                        {
                        erro = 1;
                        system("cls");

                        printf("Infome a quantidade de dias que deseja alugar para completar o pedido: \n");
                        scanf("%d", &dias);

                        system("cls");

                        for (i = 0; i < LocadoraHI.prox_filme; i++)
                        {

                            if (LocadoraHI.Filmes[i].codigo_filme == Codigo_filme)
                            {

                                Filmes = LocadoraHI.Filmes[i];
                                LocadoraHI.Filmes[i].disponivel = 1;
                            }
                        }

                        for (i = 0; i < LocadoraHI.prox_cliente; i++)
                        {

                            if (strcmp(LocadoraHI.Clientes[i].cpf, cpf_compras) == 0)
                            {

                                Comprador = LocadoraHI.Clientes[i];
                        }
                    }

                    AlugarFilme(&LocadoraHI, &Comprador, &Filmes, dias);

                    system("pause");
                    system("cls");   
                            
                        }
                        
                    }

                    if (erro == 0)
                    {
                            system("cls");
                            printf("________________ Locadora HI ________________\n\n");
                            printf("            |CPF nao encontrado|\n");
                            printf("_____________________________________________\n\n\n");

                            system("pause");
                            system("cls");
                            
                            printf("____________________ Locadora HI ____________________\n\n");
                            printf("__________________| Novo Cadastro |__________________\n\n");
                            printf("Informe o nome do cliente que deseja cadastrar: \n");
                            scanf("%s", nome_cliente);
                            printf("Informe o CPF do cliente que deseja cadastrar: \n");
                            scanf("%s", cpf_compras);
                            printf("_____________________________________________________\n\n\n");

                            system("pause");
                            system("cls");

                            printf("____________________ Locadora HI ____________________\n\n");
                            printf("______________| Clientes Cadastrado |________________\n\n");
                            printf("Nome do cliente: %s\n\n", nome_cliente);
                            printf("CPF do cliente: %s\n\n", cpf_compras);
                            printf("_____________________________________________________\n\n\n");
                            CadastrarCliente(&LocadoraHI, nome_cliente, cpf_compras);
                            system("pause");
                            system("cls");
                    }
                    
                            

                    

                    break;

                case 2:
                    VisualizarPedido(&LocadoraHI);
                    system("pause");
                    system("cls");
                    break;

                default:
                    break;
                }

            } while (opcao != 3);

            break;

        default:

            break;
        }

    } while (opcao != 4);

    system("cls");
    Fim();

    return 0;
}
