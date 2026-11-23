#include <stdio.h> /*Biblioteca principal da linguagem*/
#include <stdlib.h> /*Biblioteca para memoria dinamica*/
#include <string.h> /*Biblioteca para buscar nomes e validar textos*/
#include <time.h> /*Biblioteca para adicionar data e hora nos arquivos*/

/*Função para calculo de media*/
    float calcularMedia(float n1, float n2){
        return (n1 + n2)/2;
    }

    
/*Definir uma struct para armazenar os dados do aluno em um mesmo ambiente e utilizando o termo "Aluno" para se referir a struct mais para frente*/
typedef struct{
    char nome[51];
    char curso[31];
    int matricula;
    float n1;
    float n2;
}ALUNO;

/* Função que descarta o "\n" apos o usuario escrever e apertar o enter, para que o arquivo nao armazene lixo, é a limpeza do buffer, 
isso acontece quando tem um scanf e o fgets vem em seguida, o scanf capta somente o numero inteiro, 
o fgets capta qualquer caracter e isso pode prejudicar leituras posteriores */

void limpezaBuffer(void){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){
    }
}

/*Funcao para preencher o cadastro, utilizado ao selecionar a opcao 1*/

void preencherCadastro(ALUNO alunos[], int *qtd, FILE *arquivo){
            printf("\nCadastro de alunos: ");

            limpezaBuffer();

            printf("\nDigite o nome do aluno: ");
            scanf("%50[^\n]", alunos[*qtd].nome); /*Faz a leitura de 50 caracteres desconsiderando o \n*/

            limpezaBuffer();

            printf("\nDigite o nome do curso: ");
            scanf("%30[^\n]", alunos[*qtd].curso);

            limpezaBuffer();

            printf("\nDigite a matricula: ");
            scanf("%d", &alunos[*qtd].matricula);

            limpezaBuffer();

 /*Uso do dowhile para haver validacao de dados */           
            do{
            printf("Digite a primeira nota (0 a 10): ");
            scanf("%f", &alunos[*qtd].n1);

            if(alunos[*qtd].n1 < 0 || alunos[*qtd].n1 > 10){
             printf("Nota invalida!\n");
            }

            }while(alunos[*qtd].n1 < 0 || alunos[*qtd].n1 > 10);

            limpezaBuffer();

            do{
            printf("Digite a segunda nota (0 a 10): ");
            scanf("%f", &alunos[*qtd].n2);

            if(alunos[*qtd].n2 < 0 || alunos[*qtd].n2 > 10){
             printf("Nota invalida!\n");
            }

            }while(alunos[*qtd].n2 < 0 || alunos[*qtd].n2 > 10);

            printf("\nAluno cadastrado com sucesso. ");

            fprintf(arquivo,"%s;", alunos[*qtd].nome);
	        fprintf(arquivo,"%s;", alunos[*qtd].curso);
	        fprintf(arquivo,"%d;", alunos[*qtd].matricula);
            fprintf(arquivo,"%f;", alunos[*qtd].n1);
            fprintf(arquivo,"%f\n", alunos[*qtd].n2);

            (*qtd)++;

}
/*Função principal:*/
    int main(){
        int opcao; /*Declaracao da variavel responsavel por registrar o numero escrito pelo usuario para o programa rodar o que o usuario quer fazer*/
        float media; /*Variavel que armazena a media*/
        int qtd = 0; /*Variavel que armazena a quantidade de alunos registrados*/
        int capacidade = 5; /*Variavel que armazena a quantidade inicial do vetor*/
        ALUNO *alunos = malloc(capacidade * sizeof(ALUNO)); /*malloc reserva memoria para o registro das informacoes*/
        FILE *arquivo = NULL; /*Declara um ponteiro do tipo FILE e inicializa com NULL*/

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

            arquivo = fopen("alunos.txt", "a"); /*Abre o arquivo alunos.txt para que insira novos dados de alunos no relatorio*/

            /*Se o arquivo abrir, o programa compila, se nao a mensagem de erro aparece*/
            if (arquivo != NULL){
                preencherCadastro(alunos, &qtd, arquivo); /*preenche os dados*/
                fclose(arquivo); /*fecha o arquivo*/
            }
            else{
            printf("Falha na abertura do arquivo. \n");
            }

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

