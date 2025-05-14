#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Remover pontos e vírgulas de uma string
void removerSeparadores(char* str) {
    char temp[strlen(str) + 1];
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != '.' && str[i] != ',') {
            temp[j++] = str[i];
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

// Entrada de dados de uma cidade
void entradaCidade(char *estado, char *codigo, char *nomeCidade, int *populacao, float *area, float *pib, int *pontosTuristicos) {
    printf("Digite a letra do estado (A-H): ");
    scanf(" %c", estado);

    printf("Digite o código da cidade (ex: A01): ");
    scanf(" %s", codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %49[^\n]", nomeCidade);

    char strPopulacao[50], strArea[50], strPib[50];

    printf("Digite a população da cidade: ");
    scanf(" %s", strPopulacao);
    removerSeparadores(strPopulacao);
    *populacao = atoi(strPopulacao);

    printf("Digite a área da cidade (km²): ");
    scanf(" %s", strArea);
    removerSeparadores(strArea);
    *area = strtof(strArea, NULL);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf(" %s", strPib);
    removerSeparadores(strPib);
    *pib = strtof(strPib, NULL);

    printf("Digite o número de pontos turísticos: ");
    scanf(" %d", pontosTuristicos);
}

int main() {
    // Dados da primeira carta
    char estado1, codigo1[4], nome1[50];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    // Dados da segunda carta
    char estado2, codigo2[4], nome2[50];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    // Entrada
    printf("Digite os dados da primeira cidade!\n");
    entradaCidade(&estado1, codigo1, nome1, &populacao1, &area1, &pib1, &pontosTuristicos1);

    printf("\nDigite os dados da segunda cidade!\n");
    entradaCidade(&estado2, codigo2, nome2, &populacao2, &area2, &pib2, &pontosTuristicos2);

    // Cálculo de atributos derivados
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1e9) / populacao1;
    float pibPerCapita2 = (pib2 * 1e9) / populacao2;

    // Exibição dos dados
    printf("\n--- Dados das Cartas ---\n");
    printf("Carta 1: %s (%s - %c)\n", nome1, codigo1, estado1);
    printf("População: %d | Área: %.2f km² | PIB: %.2f bi | Pontos Turísticos: %d\n", populacao1, area1, pib1, pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km² | PIB per capita: %.2f\n", densidade1, pibPerCapita1);

    printf("\nCarta 2: %s (%s - %c)\n", nome2, codigo2, estado2);
    printf("População: %d | Área: %.2f km² | PIB: %.2f bi | Pontos Turísticos: %d\n", populacao2, area2, pib2, pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km² | PIB per capita: %.2f\n", densidade2, pibPerCapita2);

    // Comparação baseada em POPULAÇÃO 
    printf("\n--- Comparação de Cartas (Atributo: População) ---\n");
    printf("Carta 1 - %s: %d habitantes\n", nome1, populacao1);
    printf("Carta 2 - %s: %d habitantes\n", nome2, populacao2);

    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nome1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome2);
    } else {
        printf("Resultado: Empate entre as cartas!\n");
    }

    return 0;
}
