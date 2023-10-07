#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Maximo 20

//declaração do struct principal de forma global
struct Funcionario
{
    char Nome[50];
    char Departamento[25];
    int ID;
    int Idade;
    float Salario;
    int Pcd;

} Funcionarios[Maximo];

//variaveis globais;
bool isRunning = true;
bool isRunning = true;
int Contador = 0;
int i = 0;

int main()
{
    //loop onde o programa principal vai rodar
    while(isRunning)
    {
        MainMenu();
    }

    return 0;
}


//funcao que cria novo funcionario;
void CreateEmp()
{
    int LocalOp = 0;

    if(Contador == 19)
    {
        printf("\nNumero maximo de funcionarios(as) cadastrados atingido!\n");
        return;
    }

    system("cls");

    printf("----- Cadastro -----\n\n");

    printf("Digite o nome do funcionario(a): ");
    fflush(stdin);
    fgets(Funcionarios[Contador].Nome, 40, stdin);

    printf("Digite o Departamento do funcionario(a): ");
    fflush(stdin);
    fgets(Funcionarios[Contador].Departamento, 20, stdin);

    printf("Digite o ID do funcionario(a): ");
    scanf("%d", &Funcionarios[Contador].ID);

    printf("Digite a Idade do funcionario(a): ");
    scanf("%d", &Funcionarios[Contador].Idade);

    printf("Digite o Salario do funcionario(a): ");
    scanf("%f", &Funcionarios[Contador].Salario);

    printf("E PCD? (1) Sim | (2) Nao: ");
    scanf("%d", &Funcionarios[Contador].Pcd);

    Contador++;

    printf("\n\nCadastro realizado!\n\n");
    system("PAUSE");
    system("cls");
}

//funcao que pega todos os funcionarios cadastrados;
void GetInfo()
{
    printf("\n----- Funcionarios Cadastrados -----\n\n");

    for (i = 0; i < Contador; i++)
    {
        printf("Nome: %s", Funcionarios[i].Nome);
        printf("Departamento: %s", Funcionarios[i].Departamento);
        printf("Id: %d\n", Funcionarios[i].ID);
        printf("Idade: %d\n", Funcionarios[i].Idade);
        printf("Salario: %0.2f\n", Funcionarios[i].Salario);
        if(Funcionarios[i].Pcd == 1)
        {
            printf("Pcd: Sim\n");
        }
        else if (Funcionarios[i].Pcd == 2)
        {
            printf("Pcd: Nao\n");
        }
        printf("\n");
    }

    system("PAUSE");
    system("cls");
}

//funcao que altera um funcionario cadastrado com base no ID
void UpdateEmp()
{
    if(Contador == 0)
    {
        system("cls");
        printf("Nenhum funcionario cadastrado...\n");
        return;
        system("PAUSE");
    }

    int OpAux = 0;

    system("cls");

    printf("----- Alterar Cadastro -----\n\n");

    printf("Digite o ID do cadastro que deseja alterar: ");
    scanf("%d", &OpAux);

    for(i = 0; i < Contador; i++)
    {
        if (Funcionarios[i].ID == OpAux)
        {
            printf("\nId encontrado....\n");
            printf("Informe qual campo deseja alterar: \n");
            printf("(1) - Nome\n");
            printf("(2) - Departamento\n");
            printf("(3) - Id\n");
            printf("(4) - Idade\n");
            printf("(5) - Salario\n");
            printf("(6) - Pcd\n");
            printf("(7) - Voltar\n");
            printf("Opcao: ");
            scanf("%d", &OpAux);

            //nome
            if(OpAux == 1)
            {
                printf("\nDigite o novo nome: ");
                fflush(stdin);
                fgets(Funcionarios[i].Nome, 40, stdin);

                system("cls");
                printf("\nNome alterado...\n");
                return;
                system("PAUSE");
            }
            //departamento
            else if (OpAux == 2)
            {
                printf("\nDigite o novo departamento: ");
                fflush(stdin);
                fgets(Funcionarios[i].Departamento, 20, stdin);

                system("cls");
                printf("\Departamento alterado...\n");
                return;
                system("PAUSE");
            }
            //id
            else if (OpAux == 3)
            {
                printf("\nDigite o novo ID: ");
                scanf("%d", &Funcionarios[i].ID);

                system("cls");
                printf("\ID alterado...\n");
                return;
                system("PAUSE");
            }
            //idade
            else if (OpAux == 4)
            {
                printf("\nDigite a novo idade: ");
                scanf("%d", &Funcionarios[i].Idade);

                system("cls");
                printf("\Idade alterada...\n");
                return;
                system("PAUSE");
            }
            //salario
            else if (OpAux == 5)
            {
                printf("\nDigite o novo salario: ");
                scanf("%f", &Funcionarios[i].Salario);

                system("cls");
                printf("\Salario alterado...\n");
                return;
                system("PAUSE");
            }
            //pcd
            else if (OpAux == 6)
            {
                printf("Alteracao PCD: (1) SIM - (2) NAO\n");
                printf("Opcao: ");
                scanf("%d", &Funcionarios[i].Pcd);

                system("cls");
                printf("Valor alterado com sucesso...\n");
                return;
                system("PAUSE");
            }
            else if (OpAux == 7)
            {
                system("cls");
                printf("Cancelando operacao...\n");
                return;
                system("PAUSE");
            }
            else
            {
                printf("\nValor digitado invalido...\n");
                return;
                system("PAUSE");
            }

            return;
            system("PAUSE");
        }
    }

    system("cls");
    printf("Id nao encontrado.\n");
    system("PAUSE");
}

//deleta um dos funcionarios por ID
void Delete()
{
    if(Contador == 0)
    {
        system("cls");
        printf("Nenhum funcionario cadastrado...\n");
        return;
        system("PAUSE");
    }

    int PosAux = 0;

    system("cls");

    printf("----- Exclusao de Funcionario -----\n\n");

    printf("Digite o ID a ser excluido: ");
    scanf("%d", &PosAux);

    if(PosAux > Contador || PosAux < 0)
    {
        system("cls");
        printf("Valor digitado invalido...\n");
        return;
        system("PAUSE");
    }

    for (i = PosAux; i < Contador; i++)
    {
        //excluir e atualizar a lista e retornar
        system("cls");

        Funcionarios[i] = Funcionarios[i + 1];

        //decrementando o tamanho da lista
        Contador--;

        printf("Exclusao feita com sucesso...\n");
    }
}

//salva o arquivo
void Perpetuar()
{
    FILE *Arquivo;
    char NomeLista[100];

    printf("Digite o nome do Arquivo: ");
    fflush(stdin);
    scanf("%s", NomeLista);

    Arquivo = fopen(NomeLista, "w");

    if (Arquivo == NULL)
    {
        system("cls");

        printf("Erro ao abrir arquivo...\n");
        return;
        system("PAUSE");
    }

    for (i = 0; i < Contador; i++)
    {
        fprintf(Arquivo, "Nome: %sDepartamento: %sId: %d\nIdade: %d\nSalario: %.2f\nE pcd: %d\n\n",
                Funcionarios[i].Nome, Funcionarios[i].Departamento, Funcionarios[i].ID,
                Funcionarios[i].Idade, Funcionarios[i].Salario, Funcionarios[i].Pcd);
    }

    //fechando o arquivo
    fclose(Arquivo);

    system("cls");
    printf("Arquivo salvo!\n");
    system("PAUSE");
}

//finaliza o programa
void Exit()
{
    printf("\n\nFinalizando...\n");
    isRunning = false;
}

//display functions
void MainMenu()
{
    printf("\nDigite (1) para Cadastrar novo funcionario.\n");
    printf("Digite (2) para Alterar um cadastro.\n");
    printf("Digite (3) para Procurar um funcionario cadastrado.\n");
    printf("Digite (4) para Deletar um funcionario.\n");
    printf("Digite (5) para Salvar em um arquivo.\n");
    printf("Digite (6) para Encerrar o programa.\n");

    MenuHandle();
}

//funcção que vai lidar com o input do user;
void MenuHandle()
{
    int Opcao = 0;

    printf("Opcao: ");
    fflush(stdin);
    scanf("%d", &Opcao);

    if(Opcao == 1)
    {
        CreateEmp();
    }
    else if (Opcao == 2)
    {
        UpdateEmp();
    }
    else if (Opcao == 3)
    {
        GetInfo();
    }
    else if (Opcao == 4)
    {
        Delete();
    }
    else if (Opcao == 5)
    {
        Perpetuar();
    }
    else if (Opcao == 6)
    {
        Exit();
    }
    else
    {
        system("cls");
        printf("Opcao invalida, por favor, digite uma opcao valida...\n\n");
        MainMenu();
    }
}
