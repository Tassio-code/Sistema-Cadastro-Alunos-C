#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int id;
    char nome[100];
    float media;
} Aluno;

//protótipos das funcões
void menu();
void cadastrar();
void listar();

#endif