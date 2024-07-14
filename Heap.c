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

int filhoEsquerda(int raiz)
{
    return raiz * 2 + 1;
}

int filhoDireita(int raiz)
{
    return raiz * 2 + 2;
}

void heapify(struct Fabricante *vetor, int n, int raiz)
{
    int esquerda = filhoEsquerda(raiz);
    int direita = filhoDireita(raiz);
    int max;

    if (esquerda > n - 1)
    {
        return n;
    }
    else if (direita > n - 1)
    {
        max = esquerda;
    }
    else
    {
        if (compararFabricantes(&vetor[esquerda], &vetor[direita]) > 0)
        {
            max = esquerda;
        }
        else
        {
            max = direita;
        }
    }

    if (compararFabricantes(&vetor[max], &vetor[raiz]) > 0)
    {
        swap(&vetor[max], &vetor[raiz]);
        heapify(vetor, n, max);
    }
}

void construirHeap(struct Fabricante *vetor, int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(vetor, n, i);
    }
}

void heapSort(struct Fabricante *vetor, int n)
{
    int i;

    construirHeap(vetor, n);

    for (i = n - 1; i > 0; i--)
    {
        swap(&vetor[i], &vetor[0]);
        heapify(vetor, i, 0);
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

    heapSort(vetor, n);
    escreverVetor(vetor, n);

    return 0;
}