#include <stdio.h>
#include <string.h>

struct Fabricante
{
    char nome[50];
    char nacionalidade[50];
    int anoFundacao;
};

int compararFabricantes(const struct Fabricante *f1, const struct Fabricante *f2)
{
    int resultado = strcmp(f1->nome, f2->nome);

    if (resultado == 0)
        resultado = strcmp(f1->nacionalidade, f2->nacionalidade);

    if (resultado == 0)
        resultado = f1->anoFundacao - f2->anoFundacao;

    return resultado;
}

void swap(struct Fabricante *a, struct Fabricante *b)
{
    struct Fabricante temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void shakeSort(struct Fabricante *vetor, int n)
{
    int i, inicio = 0, fim = n - 1, trocou = 0;

    while (trocou == 0 && inicio < fim)
    {
        trocou = 1;

        // Passagem da esquerda para a direita
        for (i = inicio; i < fim; i++)
        {
            if (compararFabricantes(&vetor[i], &vetor[i + 1]) > 0)
            {
                swap(&vetor[i], &vetor[i + 1]);
                trocou = 0;
            }
        }

        fim--;

        // Passagem da direita para a esquerda
        for (i = fim; i > inicio; i--)
        {
            if (compararFabricantes(&vetor[i], &vetor[i - 1]) < 0)
            {
                swap(&vetor[i], &vetor[i - 1]);
                trocou = 0;
            }
        }

        inicio++;
    }
}

void escreverVetor(struct Fabricante *vetor, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Fabricante[%d]:\n", i);
        printf("Nome: %s\n", vetor[i].nome);
        printf("Nacionalidade: %s\n", vetor[i].nacionalidade);
        printf("Ano de Fundacao: %d\n", vetor[i].anoFundacao);
        printf("\n");
    }
}

int main()
{
    struct Fabricante vetor[] = {

        {"Tesla", "Estados Unidos", 2003},
        {"Volvo", "Suecia", 1927},
        {"Ferrari", "Italia", 1947},
        {"Fiat", "Italia", 1976},
        {"Nissan", "Japao", 1933},
        {"Volkswagen", "Alemanha", 1953},
        {"Ford", "Estados Unidos", 1903},
        {"Gurgel", "Brasil", 1969},
        {"Mitsubishi", "Japao", 1870},
        {"Peugeot", "Franca", 1810},
        {"Chevrolet", "Franca", 1911},
        {"Lamborghini", "Italia", 1963},
        {"BMW", "Alemanha", 1916},
        {"Mercedes-Benz", "Alemanha", 1926},
        {"Audi", "Alemanha", 1909},
        {"Hyundai", "Coreia do Sul", 1967}

    };

    int n = sizeof(vetor) / sizeof(vetor[0]);

    shakeSort(vetor, n);
    escreverVetor(vetor, n);

    return 0;
}