#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Maximo 20

struct Funcionario {
    char Nome[50];
    char Departamento[25];
    int ID;
    int Idade;
    float Salario;
    int Pcd;
} Funcionarios[Maximo];

bool isRunning = true;
int Contador = 0;

// Protótipos de funções
void MainMenu();
void CreateEmp();
void GetInfo();
void UpdateEmp();
void Delete();
void Perpetuar();
void Exit();

void MenuHandle() {
    int Opcao = 0;

    printf("Opcao: ");
    fflush(stdin);
    scanf("%d", &Opcao);

    switch (Opcao) {
        case 1:
            CreateEmp();
            break;
        case 2:
            UpdateEmp();
            break;
        case 3:
            GetInfo();
            break;
        case 4:
            Delete();
            break;
        case 5:
            Perpetuar();
            break;
        case 6:
            Exit();
            break;
        default:
            printf("Opcao invalida, por favor, digite uma opcao valida...\n\n");
            MainMenu();
    }
}

void MainMenu() {
    printf("\nDigite (1) para Cadastrar novo funcionario.\n");
    printf("Digite (2) para Alterar um cadastro.\n");
    printf("Digite (3) para Procurar um funcionario cadastrado.\n");
    printf("Digite (4) para Deletar um funcionario.\n");
    printf("Digite (5) para Salvar em um arquivo.\n");
    printf("Digite (6) para Encerrar o programa.\n");

    MenuHandle();
}

void CreateEmp() {
    int LocalOp = 0;

    if (Contador == Maximo) {
        printf("\nNumero maximo de funcionarios(as) cadastrados atingido!\n");
        return;
    }

    printf("----- Cadastro -----\n\n");

    printf("Digite o nome do funcionario(a): ");
    scanf("%s", Funcionarios[Contador].Nome);

    printf("Digite o Departamento do funcionario(a): ");
    scanf("%s", Funcionarios[Contador].Departamento);

    printf("Digite o ID do funcionario(a): ");
    scanf("%d", &Funcionarios[Contador].ID);

    printf("Digite a Idade do funcionario(a): ");
    scanf("%d", &Funcionarios[Contador].Idade);

    printf("Digite o Salario do funcionario(a): ");
    scanf("%f", &Funcionarios[Contador].Salario);

    printf("E PCD? (1) Sim | (2) Nao: ");
    scanf("%d", &Funcionarios[Contador].Pcd);

    Contador++;

    printf("\nCadastro realizado!\n\n");
}

void GetInfo() {
    printf("\n----- Funcionarios Cadastrados -----\n\n");

    for (int i = 0; i < Contador; i++) {
        printf("Nome: %s\n", Funcionarios[i].Nome);
        printf("Departamento: %s\n", Funcionarios[i].Departamento);
        printf("Id: %d\n", Funcionarios[i].ID);
        printf("Idade: %d\n", Funcionarios[i].Idade);
        printf("Salario: %.2f\n", Funcionarios[i].Salario);
        printf("Pcd: %s\n", (Funcionarios[i].Pcd == 1) ? "Sim" : "Nao");
        printf("\n");
    }
}

void UpdateEmp() {
    if (Contador == 0) {
        printf("Nenhum funcionario cadastrado...\n");
        return;
    }

    int OpAux = 0;

    printf("----- Alterar Cadastro -----\n\n");

    printf("Digite o ID do cadastro que deseja alterar: ");
    scanf("%d", &OpAux);

    for (int i = 0; i < Contador; i++) {
        if (Funcionarios[i].ID == OpAux) {
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

            switch (OpAux) {
                case 1:
                    printf("\nDigite o novo nome: ");
                    scanf("%s", Funcionarios[i].Nome);
                    printf("\nNome alterado...\n");
                    break;
                case 2:
                    printf("\nDigite o novo departamento: ");
                    scanf("%s", Funcionarios[i].Departamento);
                    printf("\Departamento alterado...\n");
                    break;
                case 3:
                    printf("\nDigite o novo ID: ");
                    scanf("%d", &Funcionarios[i].ID);
                    printf("\ID alterado...\n");
                    break;
                case 4:
                    printf("\nDigite a novo idade: ");
                    scanf("%d", &Funcionarios[i].Idade);
                    printf("\Idade alterada...\n");
                    break;
                case 5:
                    printf("\nDigite o novo salario: ");
                    scanf("%f", &Funcionarios[i].Salario);
                    printf("\Salario alterado...\n");
                    break;
                case 6:
                    printf("Alteracao PCD: (1) SIM - (2) NAO\n");
                    printf("Opcao: ");
                    scanf("%d", &Funcionarios[i].Pcd);
                    printf("Valor alterado com sucesso...\n");
                    break;
                case 7:
                    printf("Cancelando operacao...\n");
                    break;
                default:
                    printf("\nValor digitado invalido...\n");
                    break;
            }

            return;
        }
    }

    printf("Id nao encontrado.\n");
}

void Delete() {
    if (Contador == 0) {
        printf("Nenhum funcionario cadastrado...\n");
        return;
    }

    int PosAux = 0;

    printf("----- Exclusao de Funcionario -----\n\n");

    printf("Digite o ID a ser excluido: ");
    scanf("%d", &PosAux);

    if (PosAux > Contador || PosAux < 0) {
        printf("Valor digitado invalido...\n");
        return;
    }

    for (int i = PosAux; i < Contador; i++) {
        Funcionarios[i] = Funcionarios[i + 1];
    }

    Contador--;
    printf("Exclusao feita com sucesso...\n");
}

void Perpetuar() {
    FILE *Arquivo;
    char NomeLista[100];

    printf("Digite o nome do Arquivo: ");
    scanf("%s", NomeLista);

    Arquivo = fopen(NomeLista, "w");

    if (Arquivo == NULL) {
        printf("Erro ao abrir arquivo...\n");
        return;
    }

    for (int i = 0; i < Contador; i++) {
        fprintf(Arquivo, "Nome: %s\nDepartamento: %s\nId: %d\nIdade: %d\nSalario: %.2f\nE pcd: %d\n\n",
                Funcionarios[i].Nome, Funcionarios[i].Departamento, Funcionarios[i].ID,
                Funcionarios[i].Idade, Funcionarios[i].Salario, Funcionarios[i].Pcd);
    }

    fclose(Arquivo);

    printf("Arquivo salvo!\n");
}

void Exit() {
    printf("\n\nFinalizando...\n");
    isRunning = false;
}

int main() {
    while (isRunning) {
        MainMenu();
    }

    return 0;
}
