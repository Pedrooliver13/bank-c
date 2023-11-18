#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum InitMenuEnum
{
    ACCESS_APP = 1,
};

enum MenuEnum
{
    DEPOSIT = 1,
    WITHDRAWAL = 2,
    BALANCE = 3,
    INVESTMENT_CALCULATOR = 4
};

void main()
{
    char userName[98] = "pipoca", password[98] = "1609";
    char currentUser[98], currentPassword[98];
    int balance = 0;
    bool isLogged = false;

    void login()
    {
        printf("..:: Login ::..\n");
        printf("Digite o nome do usuario: ");
        scanf("%s", &currentUser);

        printf("Digite sua senha: ");
        scanf("%s", &currentPassword);

        bool isCorrectLogin = strcmp(currentPassword, password) == 0 && strcmp(currentUser, userName) == 0;

        if (isCorrectLogin)
        {
            printf("\n>> Logado na conta: %s! <<\n\n", userName);
            isLogged = true;
            return;
        }

        printf("\n>> Login ou senha incorreta! <<\n\n");
        isLogged = false;
        login();
        return;
    }

    void showBalance()
    {
        printf("\nSeu saldo atual e: R$ %d\n\n", balance);
        return;
    }

    void calculateDeposit()
    {
        int value;

        printf("Quanto voce quer depositar? R$ ");
        scanf("%d", &value);
        balance = balance + value;
        printf("Seu saldo atual ficou: R$ %d\n\n", balance);

        return;
    }

    void calculateWithdrawal()
    {
        int value;

        if (balance == 0)
        {
            printf("\n>> Nao tem saldo suficiente! <<\n\n");
            return;
        }

        printf("Quanto voce quer sacar? R$ ");
        scanf("%d", &value);

        value = balance - value;

        if (value < 0)
        {
            printf("\n>> Nao tem saldo saldo suficiente! <<\n\n");
            return;
        }

        balance = value;
        printf("Seu saldo atual ficou: R$ %d\n\n", balance);
    }

    void calculateInvestment()
    {
        float valueInvestment, monthlyProfitability;

        printf("Digite o valor que deseja investir: R$ ");
        scanf("%f", &valueInvestment);

        if (valueInvestment > balance)
        {
            printf("\n>> Nao tem saldo suficiente! <<\n\n");
            return;
        }

        printf("Digite a rentabilidade mensal (porcentagem): ");
        scanf("%f", &monthlyProfitability);

        float monthlyReturn = (valueInvestment * monthlyProfitability) / 100;
        float annualReturn = monthlyReturn * 12;
        float total = valueInvestment + annualReturn;

        printf("Retorno mensal: R$  %.2f\n", monthlyReturn);
        printf("Retorno anual: R$ %.2f\n", annualReturn);
        printf("Total investido: R$ %.2f\n", valueInvestment);
        printf("Rentabilidade: R$ %.2f\n", annualReturn);
        printf("Total: R$ %.2f\n", total);
        return;
    }

    void menu()
    {
        int optionSelected, value;

        printf("..:: Menu ::..\n1 - Deposito\n2 - Saque\n3 - Saldo\n4 - Calculadora de investimento\n5 - Sair\n");
        scanf("%d", &optionSelected);

        switch (optionSelected)
        {
        case DEPOSIT:
            calculateDeposit();
            menu();
            break;
        case WITHDRAWAL:
            calculateWithdrawal();
            menu();
            break;
        case BALANCE:
            showBalance();
            menu();
            break;
        case INVESTMENT_CALCULATOR:
            calculateInvestment();
            menu();
            break;
        default:
            printf("Saiu!");
        }

        return;
    }

    void init()
    {
        int optionSelected;

        printf("..:: Banco ::..\n\n1 - Acessar sistema\n2 - Sair\n");
        scanf("%d", &optionSelected);

        if (optionSelected != ACCESS_APP)
        {
            printf("Saiu!");
            return;
        }

        login();

        if (isLogged)
        {
            menu();
        }

        return;
    }

    init();
    return;
}
