#include <stdio.h>
#include <string.h>

/*
 * Programa: Cadastro de Territórios
 * Descrição: Demonstra o uso de uma struct para agrupar dados de territórios.
 * Cada território possui nome, cor do exército e quantidade de tropas.
 * O programa permite cadastrar 5 territórios e exibir seus dados.
 *
 * Observações sobre entrada de strings:
 * - Usamos scanf com scanset (" %29[^\n]") para permitir espaços no nome
 *   e na cor, evitando problemas típicos de scanf("%s") que para na primeira
 *   whitespace. O especificador limita o número de caracteres para evitar
 *   overflow de buffer.
 */

#define MAX_TERRITORIOS 5

/* Definição da struct Territorio.
 * - nome: até 29 caracteres + caractere nulo
 * - cor: até 9 caracteres + caractere nulo
 * - tropas: número inteiro de tropas no território
 */
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

int main(void) {
    Territorio territorios[MAX_TERRITORIOS];

    printf("\n===============================\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");

    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("\n--- Cadastrando Territorio %d ---\n", i + 1);
        printf("Nome do Territorio: ");
        if (scanf(" %29[^\n]", territorios[i].nome) != 1) {
            territorios[i].nome[0] = '\0';
        }
        printf("Cor do Exercito: ");
        if (scanf(" %9[^\n]", territorios[i].cor) != 1) {
            territorios[i].cor[0] = '\0';
        }
        printf("Quantidade de Tropas: ");
        while (scanf("%d", &territorios[i].tropas) != 1) {
            int ch;
            while ((ch = getchar()) != EOF && ch != '\n');
            printf("Entrada invalida. Digite um numero inteiro para tropas: ");
        }
    }

    printf("\n===============================\n");
    printf("Territorios cadastrados:\n");
    for (int i = 0; i < MAX_TERRITORIOS; i++) {
        printf("--- Territorio %d ---\n", i + 1);
        printf("Nome do Territorio: %s\n", territorios[i].nome);
        printf("Cor do Exercito: %s\n", territorios[i].cor);
        printf("Quantidade de Tropas: %d\n", territorios[i].tropas);
    }
    printf("===============================\n");
    return 0;
}
