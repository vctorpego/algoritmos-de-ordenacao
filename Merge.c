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

int encontrarMenor(int a, int b)
{
    return (a > b) ? b : a;
}

void simpleMerge(struct Fabricante *vetor, int inicioSeg1, int fimSeg1, int inicioSeg2, int fimSeg2, struct Fabricante *resultado, int r)
{
    int indiceSeg1 = inicioSeg1;
    int indiceSeg2 = inicioSeg2;
    int k = r;
    int i;

    while ((indiceSeg1 <= fimSeg1) && (indiceSeg2 <= fimSeg2))
    {
        if (compararFabricantes(&vetor[indiceSeg1], &vetor[indiceSeg2]) < 0)
        {
            resultado[k] = vetor[indiceSeg1];
            indiceSeg1++;
        }
        else
        {
            resultado[k] = vetor[indiceSeg2];
            indiceSeg2++;
        }
        k++;
    }

    if (indiceSeg1 > fimSeg1)
    {
        for (i = indiceSeg2; i <= fimSeg2; i++)
        {
            resultado[k] = vetor[i];
            k++;
        }
    }
    else
    {
        for (i = indiceSeg1; i <= fimSeg1; i++)
        {
            resultado[k] = vetor[i];
            k++;
        }
    }
}

void mergePass(struct Fabricante *vetor, struct Fabricante *resultado, int n, int l)
{
    int p = 0;
    int q = p + l;
    int r = 0;
    int i;

    while (q < n)
    {
        simpleMerge(vetor, p, q - 1, q, encontrarMenor(q + l - 1, n - 1), resultado, r);
        r = r + 2 * l;
        p = q + l;
        q = p + l;
    }

    if (p < n)
    {
        for (i = p; i < n; i++)
        {
            resultado[i] = vetor[i];
        }
    }
}

void mergeSort(struct Fabricante *vetor, int tamanho)
{
    int segmento = 1;
    int paridade = 1;
    int i;
    struct Fabricante *resultado = malloc(sizeof(struct Fabricante) * tamanho);

    while (segmento < tamanho)
    {
        if (paridade)
        {
            mergePass(vetor, resultado, tamanho, segmento);
            paridade = 0;
        }
        else
        {
            mergePass(resultado, vetor, tamanho, segmento);
            paridade = 1;
        }
        segmento *= 2;
    }
    if (!paridade)
    {
        for (i = 0; i < tamanho; i++)
        {
            vetor[i] = resultado[i];
        }
    }

    free(resultado);
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

    mergeSort(vetor, n);
    escreverVetor(vetor, n);

    return 0;
}