#include <stdio.h>
#include <stdlib.h>
#include "../include/aluno.h"

// Implementaçao da função cadastro 
void cadastrar() {
    FILE *file = fopen("data/aluno.dat", "ab"); // Abre para anexar binario
    if (file == NULL) {
        printf("Erro ao abrir o arquivo! Verifique se a pasta 'data' existe.\n");
        return;
    }

    Aluno a; // Corrigido para Aluno (maiúsculo) conforme seu .h
    printf("\nID do Aluno: ");
    scanf("%d", &a.id); // Corrigido: aspas fechadas antes da vírgula
    getchar();

    printf("Nome: ");
    scanf("%[^\n]s", a.nome);
    getchar();

    printf("Media: ");
    scanf("%f", &a.media);
    getchar(); // Limpa o buffer após ler a média

    fwrite(&a, sizeof(Aluno), 1, file);
    fclose(file);
    printf("Aluno salvo com sucesso!\n");
}

// Implementaçao da função de listagem (Agora FORA da função cadastrar)
void listar() {
    FILE *file = fopen("data/aluno.dat", "rb");
    if (file == NULL) {
        printf("\nNenhum registro foi encontrado.\n");
        return;
    }

    Aluno a;
    printf("\n--- LISTAGEM DE ALUNOS ---\n");
    printf("%-5s %-20s %-5s\n", "ID", "NOME", "MEDIA");

    while (fread(&a, sizeof(Aluno), 1, file)) {
        printf("%-5d %-20s %-5.2f\n", a.id, a.nome, a.media);
    }

    fclose(file);
}