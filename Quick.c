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

int particao(struct Fabricante *vetor, int inicio, int fim)
{
    int i = inicio + 1;
    int f = fim;
    struct Fabricante pivo = vetor[inicio];

    while (i <= f)
    {
        if (i <= f && compararFabricantes(&vetor[i], &pivo) <= 0)
        {
            i++;
        }
        else if (i <= f && compararFabricantes(&vetor[f], &pivo) > 0)
        {
            f--;
        }
        else
        {
            swap(&vetor[i], &vetor[f]);
            i++;
            f--;
        }
    }

    swap(&vetor[inicio], &vetor[f]);
    return f;
}

void quickSort(struct Fabricante *vetor, int inicio, int fim)
{
    int meio;

    if (inicio < fim)
    {
        meio = particao(vetor, inicio, fim);

        quickSort(vetor, inicio, meio - 1);
        quickSort(vetor, meio + 1, fim);
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

    quickSort(vetor, 0, n - 1);
    escreverVetor(vetor, n);

    return 0;
}