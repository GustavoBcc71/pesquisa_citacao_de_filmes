#include "cita_filmes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void RemoverLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void ProcessarString(char *str) {
    char *src = str, *dest = str;
    while (*src) {
        if (*src != '"') {
            *dest = tolower(*src);
            dest++;
        }
        src++;
    }
    *dest = '\0';
}

void substituir_delimitador(char *str) {
    char *pos;
    
    // Substituir ".,"
    pos = strstr(str, ".,");
    while (pos) {
        *pos = '#'; // Substitui '.' por '#'
        memmove(pos + 1, pos + 2, strlen(pos + 2) + 1);
        pos = strstr(pos + 1, ".,");
    }

    // Substituir "!,"
    pos = strstr(str, "!,");
    while (pos) {
        *pos = '#'; // Substitui "!" por ","
        memmove(pos + 1, pos + 2, strlen(pos + 2) + 1);
        pos = strstr(pos + 1, "!,");
    }

    // Substituir "?,"
    pos = strstr(str, "?,");
    while (pos) {
        *pos = '#'; // Substitui "?" por ","
        memmove(pos + 1, pos + 2, strlen(pos + 2) + 1);
        pos = strstr(pos + 1, "?,");
    }
}

void AdicionarVirgulaFinal(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] != ',') {
        str[len] = ',';
        str[len + 1] = '\0';
    }
}

int CriaCitacoes(const char *nome_arquivo, CitaFilme citacoes[], int max_entradas) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }
    
    int contador = 0;
    char linha[512];

    while (fgets(linha, sizeof(linha), arquivo) && contador < max_entradas) {
        RemoverLinha(linha);
        AdicionarVirgulaFinal(linha); // Garante que o último campo não seja perdido
        ProcessarString(linha);
        substituir_delimitador(linha);

        /*printf("%s\n\n", linha);*/

    
    
        char *frase = strtok(linha, "#");
        char *filme = strtok(NULL, "," );
        char *ano = strtok(NULL, ",");
        
        if (frase && filme && ano) {
            strncpy(citacoes[contador].frase, frase, MAX_FRASE - 1);
            citacoes[contador].frase[MAX_FRASE - 1] = '\0'; 

            strncpy(citacoes[contador].filme, filme, MAX_FILME - 1);
            citacoes[contador].filme[MAX_FILME - 1] = '\0'; 

            strncpy(citacoes[contador].ano, ano, MAX_ANO - 1);
            citacoes[contador].ano[MAX_ANO - 1] = '\0'; 

            contador++;
        }
    }

    fclose(arquivo);
    return contador;
}

void exibir_citacoes(const CitaFilme citacoes[], int total) {
    for (int i = 0; i < total; i++) {
        printf("Frase: %s \nFilme: %s\nAno: %s\n\n", citacoes[i].frase, citacoes[i].filme, citacoes[i].ano);
    }
}
