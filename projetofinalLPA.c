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
    float frequencia; /*Frequencia do aluno*/
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

            printf("Digite a frequencia: ");
            scanf("%f", &alunos[*qtd].frequencia);

            printf("\nAluno cadastrado com sucesso. ");

            fprintf(arquivo,"%s;", alunos[*qtd].nome);
	        fprintf(arquivo,"%s;", alunos[*qtd].curso);
	        fprintf(arquivo,"%d;", alunos[*qtd].matricula);
            fprintf(arquivo,"%f;", alunos[*qtd].n1);
            fprintf(arquivo,"%f;", alunos[*qtd].n2);
            fprintf(arquivo,"%f\n", alunos[*qtd].frequencia);

            (*qtd)++;

}

/* Le o arquivo alunos.txt ao iniciar o programa e carrega os registros no vetor.
   Recebe o vetor, a quantidade e a capacidade por ponteiro porque a funcao altera
   a quantidade e, quando o item 2 fizer o vetor crescer, tambem o vetor e a capacidade.
   Formato de cada linha: nome;curso;matricula;n1;n2;frequencia
   Se o arquivo nao existir, avisa e deixa o vetor vazio (o programa nao trava). */
void carregarAlunos(ALUNO **alunos, int *qtd, int *capacidade){
    FILE *arquivo = fopen("alunos.txt", "r");
    char linha[256];
    ALUNO temp;

    if (arquivo == NULL){
        printf("Arquivo alunos.txt nao encontrado. Iniciando com lista vazia.\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        /*Linha em branco nao e registro: so processa se a linha tiver conteudo*/
        if (linha[0] != '\n'){

            /*sscanf devolve quantos campos leu; se forem 6, a linha esta correta*/
            if (sscanf(linha, "%50[^;];%30[^;];%d;%f;%f;%f",
                       temp.nome, temp.curso, &temp.matricula,
                       &temp.n1, &temp.n2, &temp.frequencia) == 6){

                /*Vetor cheio: o crescimento do vetor (realloc) e do item 2 (Andre).
                  Ate la, a leitura para aqui para nao escrever fora da memoria.*/
                if (*qtd == *capacidade){
                    printf("Vetor cheio: registros restantes nao foram carregados.\n");
                    break;
                }

                (*alunos)[*qtd] = temp;
                (*qtd)++;
            }
            else{
                printf("Linha ignorada (formato invalido): %s", linha);
            }
        }
    }
/*Funcao simples de listagem de alunos que gera um loop que percorre cada posicao do vetor alunos e
escreve tudo na tela*/
    void listarAlunos(ALUNO alunos[], int qtd){

        for(int i = 0; i < qtd; i++){

            printf("\nNome do aluno %d: %s", alunos[i].nome);
            printf("\nCurso: %s", alunos[i].curso);
            printf("\nMatricula: %d", alunos[i].matricula);
            printf("\nPrimeira nota: %.2f", alunos[i].n1);
            printf("\nSegunda nota: %.2f", alunos[i].n2);
            printf("\nFrequencia: %.2f", alunos[i].frequencia);
            printf("\nMedia: %.2f\n", calcularMedia(alunos[i].n1, alunos[i].n2));

        }
}

/*Função principal:*/
    int main(){
        int opcao; /*Declaracao da variavel responsavel por registrar o numero escrito pelo usuario para o programa rodar o que o usuario quer fazer*/
        float media; /*Variavel que armazena a media*/
        int qtd = 0; /*Variavel que armazena a quantidade de alunos registrados*/
        int capacidade = 5; /*Variavel que armazena a quantidade inicial do vetor*/
        ALUNO *alunos = malloc(capacidade * sizeof(ALUNO)); /*malloc reserva memoria para o registro das informacoes*/
        FILE *arquivo = NULL; /*Declara um ponteiro do tipo FILE e inicializa com NULL*/

        /*Carrega os alunos ja gravados no arquivo para a memoria*/
        carregarAlunos(&alunos, &qtd, &capacidade);

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
    /*Se o usuario digitar algo que nao e numero, o scanf devolve 0: limpa o buffer e cai no default*/
    if (scanf("%d", &opcao) != 1){
        limpezaBuffer();
        opcao = 0;
    }

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
            listarAlunos(alunos, qtd);
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
     
