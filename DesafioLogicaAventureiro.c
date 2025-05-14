#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de país com seus atributos
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função responsável por comparar dois países com base no atributo escolhido
void compararCartas(Carta c1, Carta c2, int atributo) {
    printf("\nComparando: %s vs %s\n", c1.nome, c2.nome);

    // Seleciona o atributo escolhido e executa a comparação
    switch (atributo) {
        case 1: // População
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", c1.nome, c1.populacao);
            printf("%s: %d habitantes\n", c2.nome, c2.populacao);

            // Estrutura de decisão aninhada
            if (c1.populacao > c2.populacao)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 2: // Área
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", c1.nome, c1.area);
            printf("%s: %.2f km²\n", c2.nome, c2.area);

            if (c1.area > c2.area)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 3: // PIB
            printf("Atributo: PIB\n");
            printf("%s: %.2f trilhões USD\n", c1.nome, c1.pib);
            printf("%s: %.2f trilhões USD\n", c2.nome, c2.pib);

            if (c1.pib > c2.pib)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", c1.nome, c1.pontosTuristicos);
            printf("%s: %d\n", c2.nome, c2.pontosTuristicos);

            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        case 5: // Densidade demográfica (menor valor vence!)
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", c1.nome, c1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", c2.nome, c2.densidadeDemografica);

            if (c1.densidadeDemografica < c2.densidadeDemografica)
                printf("Vencedor: %s\n", c1.nome);
            else if (c2.densidadeDemografica < c1.densidadeDemografica)
                printf("Vencedor: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Atributo inválido!\n");
    }
}

int main() {
    int opcao;

    // Duas cartas de exemplo
    Carta pais1 = {"Brasil", 214000000, 8515767.0, 1.6, 30, 25.1};
    Carta pais2 = {"Alemanha", 83000000, 357386.0, 4.2, 45, 232.2};

    // Menu principal interativo
    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    // Switch principal que define a ação do menu
    switch (opcao) {
        case 1: {
            int atributo;

            // Menu para escolha do atributo de comparação
            printf("\nEscolha um atributo para comparação:\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos Turísticos\n");
            printf("5. Densidade Demográfica\n");
            printf("Atributo: ");
            scanf("%d", &atributo);

            // Chamada da função que compara as cartas
            compararCartas(pais1, pais2, atributo);
            break;
        }

        case 2:
            // Regras explicadas para o jogador
            printf("\nRegras do Jogo:\n");
            printf("- Cada carta representa um país com seus atributos.\n");
            printf("- Você escolhe um atributo para comparar.\n");
            printf("- A carta com o maior valor vence, exceto na densidade demográfica, onde vence o menor valor.\n");
            break;

        case 3:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
