//Gabriel Pacheco Santise Machado RA:26007914

#include <stdio.h>

void ordenarCrescente(int v[], int tamanho);
int buscaTerco(int v[], int n, int x);

int main() {
    int v[20] = {22, 32, 16, 66, 21, 7, 8, 3, 4, 9, 66, 71, 1, 2, 15, 17, 18, 55, 70, 44};

    printf("vetor: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", v[i]);
    }

    ordenarCrescente(v, 20);

    printf("\nvetor ordenado: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", v[i]);
    }
    int escolha;
    printf("\nEscolha qual digito deseja saber a posicao:");
    scanf("%d", &escolha);

    int posicao = buscaTerco(v, 20, escolha);

    if (posicao == -1) {
        printf("\nNao encontrado.");
    }

    printf("\nPosicao: %d", posicao);
}

int buscaTerco(int v[], int n, int x) {
    //v → vetor | l & r → posto dentro da função | n → tamanho | x → numero a ser encontrado
    int inicio = 0;
    int fim = n-1;
    if (v[inicio] == x) {
            return inicio;
        }else if (v[fim] == x) {
            return fim;
        }

    while (inicio <= fim && cont < 100) {
        int r = fim - (n/3);
        int l = inicio + (n/3);

        if (v[r] == x) {
            return r;
        }else if (v[l] == x) {
            return l;
        }

        if (v[r] < x) {
            inicio = r + 1;
        } 

        if (v[l] > x) {
            fim = l - 1;
        }
        
        if (v[l] < x && v[r] > x ) {
            inicio = l + 1;
            fim = r - 1;
        } 

        if (v[inicio] == x) {
            return inicio;
        }else if (v[fim] == x) {
            return fim;
        }
    }
    return -1;
}

void ordenarCrescente(int v[], int tamanho) {

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (v[j] > v[j+1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

}
