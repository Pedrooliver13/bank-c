#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
    GRUPO:
    NOME: PEDRO HENRIQUE DE OLIVEIRA RA: 20230623
    NOME: ERICK LUIZ ROMUALDO GOLASQUI RA: 20230094
    NOME: KATHYLEN CRISTINA TAVARES DE SOUZA RA: 20231115
    NOME: BEATRIZ LOPES ANTUNES RA: 20231705
 */

/*
    Conceitos utilizados!
    * S do solid: funções com responsabilidade única
    * cleanCode: Nomear as nossas condições e variaveis, e utilizar enum's
    * Recursividade: Capacidade de executar um método dentro dele mesmo, ou seja, dentro da função *menu eu conseguiria chamar a função *menu novamente.
 */

enum InitMenuEnum
{
    /* Enum utilizado na função init(), com ela damos um significado para o valor 1 */
    ACCESS_APP = 1,
};

enum MenuEnum
{
    /* Enum utilizado na função menu(), com ela damos um significado para os valores digitados */
    DEPOSIT = 1,
    WITHDRAWAL = 2,
    BALANCE = 3,
    INVESTMENT_CALCULATOR = 4
};

void main()
{
    char userName[98] = "pipoca", password[98] = "1609"; // usuario já cadastrado
    char currentUser[98], currentPassword[98];           // valores que vão ser digitados
    int balance = 0;                                     // saldo da conta, inicia sempre como 0
    bool isLogged = false;                               // função para ser se o usuário está logado, se sim, damos acesso ao sistema.

    void login()
    {
        /* Função responsavel pelo login, ou seja, nela que vamos digitar para fazer o login */

        printf("..:: Login ::..\n");
        printf("Digite o nome do usuario: ");
        scanf("%s", &currentUser);

        printf("Digite sua senha: ");
        scanf("%s", &currentPassword);

        bool isCorrectLogin = strcmp(currentPassword, password) == 0 && strcmp(currentUser, userName) == 0; // varivavel retorna true caso o usuário acerte o login

        if (isCorrectLogin)
        {
            /* Aqui dá acesso ao usuário para o resto do sistema */
            printf("\n>> Logado na conta: %s! <<\n\n", userName);
            isLogged = true;
            return;
        }

        printf("\n>> Login ou senha incorreta! <<\n\n");
        isLogged = false;
        login(); /* Recursividade, para caso o usuário erre o login e o sistema não feche */
        return;
    }

    void showBalance()
    {
        /* Função para mostrar o total de saldo */
        printf("\nSeu saldo atual e: R$ %d\n\n", balance);
        return;
    }

    void calculateDeposit()
    {
        /* função para adicionar um valor ao saldo do usuário */

        int value;

        printf("\nQuanto voce quer depositar? R$ ");
        scanf("%d", &value);
        balance = balance + value;
        printf("Seu saldo atual ficou: R$ %d\n\n", balance);

        return;
    }

    void calculateWithdrawal()
    {
        /* Função para calcular o saque, ou seja, dependendo do valor que o usuário digita */

        int value;

        if (balance == 0)
        {
            printf("\n>> Nao tem saldo suficiente! <<\n\n");
            return;
        }

        printf("\nQuanto voce quer sacar? R$ ");
        scanf("%d", &value);

        value = balance - value; /* calcula o saldo apos o saque */

        if (value < 0)
        {
            printf("\n>> Nao tem saldo saldo suficiente! <<\n\n");
            return;
        }

        balance = value; /* atualiza o saldo */
        printf("Seu saldo atual ficou: R$ %d\n\n", balance);
    }

    void calculateInvestment()
    {
        /* Função para calcular o investimento, ou seja, apos o usuário digitar o quanto ele quer investir, vai retorna os valores de retorno */
        float valueInvestment, monthlyProfitability;

        printf("\nDigite o valor que deseja investir: R$ ");
        scanf("%f", &valueInvestment);

        if (valueInvestment > balance)
        {
            printf("\n>> Nao tem saldo suficiente! <<\n\n");
            return;
        }

        printf("Digite a rentabilidade mensal (porcentagem): ");
        scanf("%f", &monthlyProfitability);

        float monthlyReturn = (valueInvestment * monthlyProfitability) / 100; /* Calcula o retorno mensal */
        float annualReturn = monthlyReturn * 12;                              /* Calcula o retorno anual */
        float total = valueInvestment + annualReturn;                         /* Calcula o total de retorno */

        printf("Retorno mensal: R$  %.2f\n", monthlyReturn);
        printf("Retorno anual: R$ %.2f\n", annualReturn);
        printf("Total investido: R$ %.2f\n", valueInvestment);
        printf("Rentabilidade: R$ %.2f\n", annualReturn);
        printf("Total: R$ %.2f\n\n", total);
        return;
    }

    void menu()
    {
        /* Função de menu, nela você digita qual ação do sistema você quer que ele faça. */
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
            printf("\nSaiu!");
        }

        return;
    }

    void init()
    {
        /* Função responsável por iniciar o projeto, ela é responsável por toda a execução */

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
