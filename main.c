

#include <stdio.h>
#include <string.h>

#define TAM 20

typedef struct inicioAtendimento {
    
    char nome[50];
    int cpf;
    int setor;
    
} Cadastro;

Cadastro cadastro[TAM];

void solicitarAtendimento(int i) {
    
        
        printf("Opção - Registrar Atendimento\n");
        
        printf("Informe o seu nome\n");
        scanf("%[^\n]", cadastro[i].nome);
        fflush(stdin);
        
        printf("Informe o CPF\n");
        scanf("%d", &cadastro[i].cpf);
        fflush(stdin);
        
        printf("Informe o setor que deseja atendimento\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Física\n 4 - Gerente Pessoa Jurídica\n");
        scanf("%d", &cadastro[i].setor);
        fflush(stdin);

}

void listarAtendimentos(int i) {
    
    int j;
    
    if (i == 0) {
        
        printf("Não existem atendimentos Registrados.\n");
    }
    
    for (j=0; j<i; j++) {
        
        printf("Nome: %s\n", cadastro[j].nome);
        printf("CPF: %d\n", cadastro[j].cpf);
        switch (cadastro[j].setor) {
            case 1 : printf("1 - Abertura de Conta\n");
                break;
                
            case 2 : printf("2 - Caixa\n");
                break;
                
            case 3 : printf("3 - Gerente Pessoa Física\n");
                break;
                
            case 4 : printf("4 - Gerente Pessoa Jurídica\n");
                break;
                
            default: printf("Setor escolhido inexistente\n");
                
                break;
        };
        
        printf("===============================\n");
        
    }
     
     
}

void listarPorSetor(int i) {
    
    int j, busca, acha;
    
    acha = 0;
    
    printf("Informe o número do setor que deseja listar os atendimentos\n 1 - Abertura de Conta\n 2 - Caixa\n 3 - Gerente Pessoa Física\n 4 - Gerente Pessoa Jurídica\n");
    scanf("%d", &busca);
    fflush(stdin);
    
    if ((busca < 1) || (busca > 4)) {
        
        printf("Setor Inexistente\n");
    } else {
        
        for (j=0;j<i;j++) {
            
            if (busca == cadastro[j].setor) {
                
                printf("Nome: %s\n", cadastro[j].nome);
                printf("CPF: %d\n", cadastro[j].cpf);
                switch (cadastro[j].setor) {
                    case 1 : printf("1 - Abertura de Conta\n");
                        break;
                        
                    case 2 : printf("2 - Caixa\n");
                        break;
                        
                    case 3 : printf("3 - Gerente Pessoa Física\n");
                        break;
                        
                    case 4 : printf("4 - Gerente Pessoa Jurídica\n");
                        break;
                        
                    default: printf("Setor escolhido inexistente\n");
                        
                        break;
                };
                
                printf("===============================\n");
                
                acha = 1;
            }
        }
        
        if (acha == 0) {
            
            printf("Não existem atendimentos cadastrados neste Setor\n");
        }
        
    }
}

int main () {
    
    int opt, i, clientes;
    
    i = 0;
    clientes = 0;
    
    printf("Bem-vindo ao sistema de atendimento\n 1 - Solicitar Atendimento\n 2 - Listar Atendimentos Registrados\n 3 - Listar Atendimento por Setor\n 4 - Sair\n");
    scanf("%d", &opt);
    fflush(stdin);
    
    while (opt != 4) {
        
        switch (opt) {
            case 1 :
                if (i == TAM) {
                    
                    printf("Número máximo de atendimentos alcançados\n");
                } else {
                    solicitarAtendimento(i);
                    i++;
                }
                break;
              
            case 2 : listarAtendimentos(i);
                break;
                
            case 3 : listarPorSetor(i);
                break;
                
            case 4 : printf("Programa Finalizado");
                break;
                
            default: printf("Opção Indisponível\n");
                break;

        }
        
        
        printf("Bem-vindo ao sistema de atendimento\n 1 - Solicitar Atendimento\n 2 - Listar Atendimentos Registrados\n 3 - Listar Atendimento por Setor\n 4 - Sair\n");
        scanf("%d", &opt);
        fflush(stdin);

    }
    
    
}

