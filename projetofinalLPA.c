#include <stdio.h> /*Biblioteca principal da linguagem*/
#include <stdlib.h> /*Biblioteca para memoria dinamica*/
#include <string.h> /*Biblioteca para buscar nomes e validar textos*/
#include <time.h> /*Biblioteca para adicionar data e hora nos arquivos*/

/*Definir uma struct para armazenar os dados do aluno em um mesmo ambiente e utilizando o termo "Aluno" para se referir a struct mais para frente*/
typedef struct{
    int matricula;
    char nome[51];
    char curso[31];
    float n1;
    float n2;
}Aluno;

/* Função que descarta o "\n" apos o usuario escrever e apertar o enter, para que o arquivo nao armazene lixo, é a limpeza do buffer, 
isso acontece quando tem um scanf e o fgets vem em seguida, o scanf capta somente o numero inteiro, 
o fgets capta qualquer caracter e isso pode prejudicar leituras posteriores */
void limpezaBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
    }
}

void menuPrincipal(void){ /*Escreve o menu principal na tela do usuario*/
    printf("\nSistema escolar de notas: \n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Alterar aluno\n");
    printf("5 - Excluir aluno\n");
    printf("6 - Gerar um relatorio\n");
    printf("7 - Sair\n");
    printf("Escolha uma opcao: ");
}
    int main(){

    }