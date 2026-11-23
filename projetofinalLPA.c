#include <stdio.h> /*Biblioteca principal da linguagem*/
#include <stdlib.h> /*Biblioteca para memoria dinamica*/
#include <string.h> /*Biblioteca para buscar nomes e validar textos*/
#include <time.h> /*Biblioteca para adicionar data e hora nos arquivos*/

    int calcularMedia(float n1, float n2){
        return (n1 + n2)/2;
    }
    
/*Definir uma struct para armazenar os dados do aluno em um mesmo ambiente e utilizando o termo "Aluno" para se referir a struct mais para frente*/
typedef struct{
    char nome[51];
    char curso[31];
    int matricula;
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
/*Função principal:*/
    int main(){
        int opcao; /*Declaracao da variavel responsavel por registrar o numero escrito pelo usuario para o programa rodar o que o usuario quer fazer*/
        Aluno a;
        float media;

/*Escreve o menu principal na tela do usuario em forma de laço, enquanto o usuario não escrever o 7 o programa vai rodando.*/

    do{printf("\nSistema escolar de notas: \n");
    printf("1 - Cadastrar aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Buscar aluno\n");
    printf("4 - Alterar dados de aluno\n");
    printf("5 - Excluir aluno\n");
    printf("6 - Gerar relatorio\n");
    printf("7 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

/*Menu switch, a variável opcao define qual 'case' estará sendo executada e o default informa o usuário do erro cometido.*/
    switch(opcao){
        case 1:

            printf("\nCadastro de alunos: \n");

            limpezaBuffer();

            printf("\nDigite o nome do aluno: ");
            fgets(a.nome, 51, stdin);

            printf("\nDigite o nome do curso: ");
            fgets(a.curso, 31, stdin);

            printf("\nDigite a matricula: ");
            scanf("%d", &a.matricula);

 /*Uso do dowhile para haver validacao de dados */           
            do{
            printf("Digite a primeira nota (0 a 10): ");
            scanf("%f", &a.n1);

            if(a.n1 < 0 || a.n1 > 10){
             printf("Nota invalida!\n");
            }

            }while(a.n1 < 0 || a.n1 > 10);

            do{
            printf("Digite a segunda nota (0 a 10): ");
            scanf("%f", &a.n2);

            if(a.n2 < 0 || a.n2 > 10){
             printf("Nota invalida!\n");
            }

            }while(a.n2 < 0 || a.n2 > 10);

            printf("\nAluno cadastrado com sucesso. ");

            media = calcularMedia(a.n1, a.n2);

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        default:
            printf("\nOpcao invalida, digite uma opcao valida:\n ");
    }
    }while(opcao != 7);
    
    }

