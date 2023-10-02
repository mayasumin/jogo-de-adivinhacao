#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("--------------------------------------\n");
    printf("* Bem-vindo ao nosso jogo de adivinhacao *\n");
    printf("--------------------------------------\n");
    printf("Sera que voce consegue adivinhar o numero secreto?\n\n");

    int segundos = time(0);
    srand(segundos); 
    int numerobase = rand();    
    int numerosecreto = numerobase % 100;
    
    int chute;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("Niveis de dificuldade:\n");
    printf("(1) Facil: 20 tentativas\n");
    printf("(2) Medio: 10 tentativas\n");
    printf("(3) Dificil: 5 tentativas\n");
    printf("Escolha o nivel de dificuldade: ");
    scanf("%d", &nivel);

    int numerodetentativas;
    switch(nivel) {
        case 1: 
            numerodetentativas = 20;
            break;
        case 2:
            numerodetentativas = 10;
            break;
        default:
            numerodetentativas = 5;
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++) {
        printf("** Tentativa %d **\n", tentativas);
        printf("Hora de advinhar o numero secreto. Faca o seu chute: ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("ERROR!\n");
            printf("Nada de numeros negativos! Tente novamente\n");
            continue;
        }

        int acertou = (numerosecreto == chute);
        int maior = (numerosecreto > chute);

        if(acertou) {
            break;
        }
        else if(maior) {
            printf("Voce errou, mas nao desanime. Tente novamente!\n");
            printf("Vou de dizer um segredo: o numero secreto e maior que seu chute\n");
        } else {
            printf("Voce errou, mas nao desanime. Tente novamente!\n");
            printf("Vou de dizer um segredo: o numero secreto e menor que seu chute\n");
        }

        tentativas++;

        double pontosperdidos = abs(chute - numerosecreto)/(double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("----------------- FIM DE JOGO -----------------\n"); 
    
    if(acertou) {
        printf("VITORIA!\n");
        printf("Voce acertou em %d tentativas\n", tentativas-1);
        printf("Sua pontuacao total foi de %.1f\n", pontos);
    } else {
        printf("Voce perdeu! Tente novamente\n");
        printf("O numero secreto era %d\n",numerosecreto);
    }
}