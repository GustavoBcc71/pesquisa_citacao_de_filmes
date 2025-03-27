#include "cita_filmes.h"
#include "cita_filmes.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    CitaFilme citacoes[MAX_ENTRADAS];
    int total = CriaCitacoes("movie_quotes.txt", citacoes, MAX_ENTRADAS);

    /*if(criacao == 1) {
        printf("Arquivo carregado com sucesso.\n");
    }else if (criacao == -1) {
        
        printf("Erro ao carregar o arquivo.\n");
        
    }*/
    

    /*int entradas = 732;

    for(int i = 0;i<entradas;i++){

        exibir_citacoes(citacoes, i);
    }*/

   /* (total > 0) {
        exibir_citacoes(citacoes, total);
    }*/

    int a = 10;
    if(a>0){
    exibir_citacoes(citacoes, a);
    }

    return 0;
}