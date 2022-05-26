/* Verificar o saldo de uma conta corrente - (ponto flutuante)
Serviço para realizar deposito numa conta corrente - 
Serviço de saque de uma conta corrente - */
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

char* getpassword() {

    static char password[6];
    int i;
    for (i = 0; i < 6; i++) {
        password[i] = getch();
        printf("*");
    }
    getch();
    return password;
}

struct Account {
        int number;
        char user[30];
        char password[6];
        float balance; 
};
        
int main() { setlocale(LC_ALL, "Portuguese");
    
    int op, i;
    struct Account a1;
    float saldo = 2500;
    float deposito, value, retirar;
    
    
    printf("Seja bem vindo!");
    printf("Por favor, escolha uma das opções abaixo: \n");
    
    restart:
    printf("1 > Entrar na conta <\n");
    printf("2 > Criar nova conta <\n");
    scanf("%i", &op);
    
    switch (op) {
        case 1:
            system("cls");
            printf("Por favor, digite as seguintes informações:\n");
            printf("Usuário: ");
            scanf("%s", a1.user);
            printf("Senha: ");
            strcpy(a1.password, getpassword());
            system("cls");
            goto next;
        break;
        case 2:
            system("cls");
            printf("Por favor, insira as seguintes informações:\n");
                printf("Crie um usuário: ");
                scanf("%s", a1.user);
                printf("Crie uma senha: ");
                strcpy(a1.password, getpassword());
                printf("\nConfirme a senha: ");
                char confpassword[6];
                strcpy(confpassword, getpassword());
                if (strcmp(a1.password, confpassword) != 0) {
                    printf("\nSenha incorreta!");
                    getch();
                }
                system("cls");
                goto restart;
        default:
        printf("ERRO\n");
        system("cls");
        goto restart;
    }
    
    next:
    do{
        printf("\nQual operação será executada?\n\n");
        printf("1 > Verificar saldo <\n\n");
        printf("2 > Realizar depósito <\n\n");
        printf("3 > Realizar saque <\n\n");
        printf("0 > Sair <\n\n");
        scanf("%i", &i);
        
        switch (i) {
        case 1:
            printf("Seu saldo atual é de: R$%.2f", saldo);
            Sleep(2000);
            system("cls");
        break;
        case 2:
            printf("");
            printf("Digite o valor que será depositado: ");
            scanf("%f", &deposito);
            saldo += deposito;
            printf("Seu saldo: %.2f", saldo);
            Sleep(2000);
            system("cls");
        break;
        case 3:
            printf("Digite o valor que será retirado: ");
            scanf("%f", &retirar);
            saldo -= retirar;
            printf("Seu saldo : %.2f", saldo);
            Sleep(2000);
            system("cls");
        break;
    }
    
    } while(i != 0);
    
return 0;
}
