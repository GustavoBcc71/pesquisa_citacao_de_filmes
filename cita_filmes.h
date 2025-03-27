#ifndef CITA_FILMES_H
#define CITA_FILMES_H

#define MAX_FRASE 256
#define MAX_FILME 128
#define MAX_ANO 5
#define MAX_ENTRADAS 732

typedef struct {
    char frase[MAX_FRASE];
    char filme[MAX_FILME];
    char ano[MAX_ANO];
} CitaFilme;

void RemoverLinha(char *str);
int CriaCitacoes(const char *nome_arquivo, CitaFilme citacoes[], int max_entradas);
void exibir_citacoes(const CitaFilme citacoes[], int total);
void ProcessarString(char *str);
void substituir_delimitador(char *str);
void AdicionarVirgulaFinal(char *str);
#endif // CITA_FILME_H