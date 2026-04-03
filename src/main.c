#include <stdio.h>
#include <stdlib.h>
#include "../include/aluno.h" // Importante para o main conhecer a struct

int main() {
    int opcao;

    do {
        printf("\n--- SISTEMA DE CADASTRO ---\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Listar Alunos\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch(opcao) {
            case 1: 
                cadastrar(); 
                break;
            case 2: 
                listar(); 
                break;
            case 0: 
                printf("Saindo...\n"); 
                break;
            default: 
                printf("Opcao invalida!\n");
                break;
        }
    } while(opcao != 0); // O while fica aqui, colado na chave do 'do'

    return 0;
}