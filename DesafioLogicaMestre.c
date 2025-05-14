#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta de país
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função auxiliar para exibir o nome do atributo
const char* nomeAtributo(int id) {
    switch (id) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para obter o valor de um atributo
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return -1;
    }
}

// Função para comparar dois atributos de duas cartas
int compararAtributo(Carta c1, Carta c2, int atributo) {
    float v1 = obterValor(c1, atributo);
    float v2 = obterValor(c2, atributo);

    // Densidade: menor valor vence
    if (atributo == 5)
        return v1 < v2 ? 1 : (v1 > v2 ? 2 : 0);
    else
        return v1 > v2 ? 1 : (v1 < v2 ? 2 : 0);
}

// Menu dinâmico que evita repetição de atributos
int escolherSegundoAtributo(int primeiro) {
    int segundo;
    do {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        for (int i = 1; i <= 5; i++) {
            if (i != primeiro)
                printf("%d. %s\n", i, nomeAtributo(i));
        }
        printf("Atributo: ");
        scanf("%d", &segundo);
        if (segundo == primeiro || segundo < 1 || segundo > 5)
            printf("Escolha inválida. Tente novamente.\n");
    } while (segundo == primeiro || segundo < 1 || segundo > 5);
    return segundo;
}

int main() {
    int opcao;

    // Cartas exemplo
    Carta pais1 = {"Brasil", 214000000, 8515767.0, 1.6, 30, 25.1};
    Carta pais2 = {"Alemanha", 83000000, 357386.0, 4.2, 45, 232.2};

    // Menu inicial
    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            int attr1, attr2;

            // Escolha do primeiro atributo
            printf("\nEscolha o primeiro atributo:\n");
            printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Demográfica\n");
            printf("Atributo: ");
            scanf("%d", &attr1);

            if (attr1 < 1 || attr1 > 5) {
                printf("Atributo inválido.\n");
                break;
            }

            // Escolha do segundo atributo (dinâmico)
            attr2 = escolherSegundoAtributo(attr1);

            // Comparações
            float valor1_1 = obterValor(pais1, attr1);
            float valor1_2 = obterValor(pais1, attr2);
            float valor2_1 = obterValor(pais2, attr1);
            float valor2_2 = obterValor(pais2, attr2);

            float soma1 = valor1_1 + valor1_2;
            float soma2 = valor2_1 + valor2_2;

            printf("\n--- Comparação ---\n");
            printf("%s vs %s\n", pais1.nome, pais2.nome);
            printf("%s: %.2f vs %.2f\n", nomeAtributo(attr1), valor1_1, valor2_1);
            printf("%s: %.2f vs %.2f\n", nomeAtributo(attr2), valor1_2, valor2_2);
            printf("Soma total de atributos:\n%s: %.2f\n%s: %.2f\n", pais1.nome, soma1, pais2.nome, soma2);

            if (soma1 > soma2)
                printf("Vencedor: %s\n", pais1.nome);
            else if (soma2 > soma1)
                printf("Vencedor: %s\n", pais2.nome);
            else
                printf("Empate!\n");

            break;
        }

        case 2:
            printf("\nRegras do Jogo:\n");
            printf("- Cada jogador compara duas cartas com dois atributos numéricos diferentes.\n");
            printf("- Para Densidade Demográfica, vence o menor valor.\n");
            printf("- Os outros atributos, vence o maior valor.\n");
            printf("- Após comparar os dois atributos, soma-se os valores: quem tiver a maior soma vence.\n");
            printf("- Em caso de soma igual, é empate.\n");
            break;

        case 3:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
