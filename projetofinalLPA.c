#include <stdio.h> /*Biblioteca principal da linguagem*/
#include <stdlib.h> /*Biblioteca para memoria dinamica*/
#include <string.h> /*Biblioteca para buscar nomes e validar textos*/
#include <time.h> /*Biblioteca para adicionar data e hora nos arquivos*/
#include <limits.h> /*Limite de capacidade*/
#include <stdint.h> /*SIZE_MAX*/

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

/* Item 2 - Alocacao dinamica: aumenta o vetor somente quando estiver cheio. */
int garantirCapacidade(ALUNO **alunos, int qtd, int *capacidade){
    if(qtd < *capacidade){
        return 1;
    }

    /* Evita estouro ao dobrar a capacidade e calcular os bytes. */
    if(*capacidade <= 0 || *capacidade > INT_MAX / 2 ||
       (size_t)(*capacidade) > SIZE_MAX / (2 * sizeof(ALUNO))){
        printf("Nao e possivel aumentar a capacidade.\n");
        return 0;
    }

    int novaCapacidade = *capacidade * 2;
    ALUNO *temporario = realloc(*alunos, (size_t)novaCapacidade * sizeof(ALUNO));
    if(temporario == NULL){
        printf("Erro ao aumentar a memoria.\n");
        return 0;
    }

    *alunos = temporario;
    *capacidade = novaCapacidade;
    return 1;
}

/*Funcao para preencher o cadastro, utilizado ao selecionar a opcao 1*/

void preencherCadastro(ALUNO alunos[], int *qtd, FILE *arquivo){

    int validacao; /*Variavel que valida o cadastro*/

            printf("\nCadastro de alunos: ");

            limpezaBuffer();

            printf("\nDigite o nome do aluno: ");
            scanf("%50[^\n]", alunos[*qtd].nome); /*Faz a leitura de 50 caracteres desconsiderando o \n*/

            limpezaBuffer();

            printf("\nDigite o nome do curso: ");
            scanf("%30[^\n]", alunos[*qtd].curso);

            limpezaBuffer();

            do{

                validacao = 0;

                printf("Digite a matricula: ");
                scanf("%d", &alunos[*qtd].matricula);

                for(int i = 0; i < *qtd; i++){

                    if(alunos[i].matricula == alunos[*qtd].matricula){
                        validacao = 1;
                        printf("Essa matricula ja existe! Tente novamente.\n");
                        break;
                    }
            }
            }while(validacao == 1);

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

            do{
                printf("Digite a frequencia (0 a 100): ");
                scanf("%f", &alunos[*qtd].frequencia);

                if(alunos[*qtd].frequencia < 0 || alunos[*qtd].frequencia > 100){

                    printf("Frequencia invalida!\n");

                }

            }while(alunos[*qtd].frequencia < 0 || alunos[*qtd].frequencia > 100);

            printf("\nAluno cadastrado com sucesso. ");

            fprintf(arquivo,"%s;", alunos[*qtd].nome);
	        fprintf(arquivo,"%s;", alunos[*qtd].curso);
	        fprintf(arquivo,"%d;", alunos[*qtd].matricula);
            fprintf(arquivo,"%f;", alunos[*qtd].n1);
            fprintf(arquivo,"%f;", alunos[*qtd].n2);
            fprintf(arquivo,"%f\n", alunos[*qtd].frequencia);

            (*qtd)++; /*Realiza a contagem dos alunos definndo seus lugares no vetor sem que substitua o anterior*/

}
/*Funcao para buscar o aluno pela matricula ou pelo nome*/
void buscarAlunos(ALUNO alunos[], int qtd){

    int opcao; /*Define se a busca vai ser por matricula ou por nome*/
    int matricula; /*Recebe a matricula digitada para comparar com a matricula registrada*/
    int encontrado = 0; /*Validador que retorna 1 se o aluno for encontrado e 0 caso nao seja*/
    char nome[51]; /*Recebe o nome digitado para comparar com o nome registrado*/
    int iguais; /*Variavel que encontra a semelhanca entre o que foi digitado e o que foi registrado retornando 1, caso seja diferente ele retorna 0*/

        printf("\nBuscar aluno:\n");
        printf("1 - Buscar pela matricula\n");
        printf("2 - Buscar pelo nome\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

    if(opcao == 1){

        printf("Digite a matricula: ");
        scanf("%d", &matricula);

        for(int i = 0; i < qtd; i++){ /*Loop que percorre matricula por matricula ate encontrar uma igual e retornar 1 com as informacoes*/

            if(alunos[i].matricula == matricula){

                encontrado = 1;

                printf("\nAluno encontrado!\n");
                printf("Nome: %s\n", alunos[i].nome);
                printf("Curso: %s\n", alunos[i].curso);
                printf("Matricula: %d\n", alunos[i].matricula);
                printf("Primeira nota: %.2f\n", alunos[i].n1);
                printf("Segunda nota: %.2f\n", alunos[i].n2);
                printf("Frequencia: %.2f\n", alunos[i].frequencia);
                printf("Media: %.2f\n", calcularMedia(alunos[i].n1, alunos[i].n2));

                break;
            }
        }
    }
    else if(opcao == 2){

        limpezaBuffer();

        printf("Digite o nome: ");
        scanf("%50[^\n]", nome);

        for(int i = 0; i < qtd; i++){ /*Loop que percorre os nomes ate encontrar um igual e retornar 1 caso tenha encontrado*/

            iguais = 1;

        for(int j = 0; nome[j] != '\0' || alunos[i].nome[j] != '\0'; j++){ 

            if(nome[j] != alunos[i].nome[j]){
                iguais = 0;
                break;
            }
        }

        if(iguais == 1){

                encontrado = 1;

                printf("\nAluno encontrado!\n");
                printf("Nome: %s\n", alunos[i].nome);
                printf("Curso: %s\n", alunos[i].curso);
                printf("Matricula: %d\n", alunos[i].matricula);
                printf("Primeira nota: %.2f\n", alunos[i].n1);
                printf("Segunda nota: %.2f\n", alunos[i].n2);
                printf("Frequencia: %.2f\n", alunos[i].frequencia);
                printf("Media: %.2f\n", calcularMedia(alunos[i].n1, alunos[i].n2));
            }
        }
    }
    else{

        printf("Opcao invalida!\n");
        return;
    }

    if(encontrado == 0){

        printf("Aluno nao encontrado!\n");

    }
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

                /* Se necessario, aumenta o vetor antes de armazenar o aluno. */
                if (!garantirCapacidade(alunos, *qtd, capacidade)){
                    printf("Carregamento interrompido por falta de memoria.\n");
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
                fclose(arquivo);
}
/*Funcao simples de listagem de alunos que gera um loop que percorre cada posicao do vetor alunos e
escreve tudo na tela*/
    void listarAlunos(ALUNO alunos[], int qtd){

        for(int i = 0; i < qtd; i++){

            printf("\nNome do aluno %d: %s", i+1, alunos[i].nome);
            printf("\nCurso: %s", alunos[i].curso);
            printf("\nMatricula: %d", alunos[i].matricula);
            printf("\nPrimeira nota: %.2f", alunos[i].n1);
            printf("\nSegunda nota: %.2f", alunos[i].n2);
            printf("\nFrequencia: %.2f", alunos[i].frequencia);
            printf("\nMedia: %.2f\n", calcularMedia(alunos[i].n1, alunos[i].n2));

        }
}
/*Funcao para alterar o cadastro dos alunos, semelhante a de cadastrar, mas com*/
    void alterarAlunos(ALUNO alunos[], int qtd){

        int indice; /*Variavel que encontra o aluno a ser alterado */
        int matriculaNova; /*Variavel que recebe a nova matricula*/
        int validacao; /*Variavel que encerra o loop caso a matricula nova seja valida*/

        FILE *arquivo;

            printf("Digite o indice do aluno que deseja alterar: ");
            scanf("%d", &indice);

        if(indice < 0 || indice >= qtd){ /*Condicao para validar o indice*/

            printf("Indice invalido!\n"); 
            return;

        }

            limpezaBuffer();
            /*Mesmo registro do cadastro com as mesmas condicoes*/
            printf("Digite nome correto: ");
            scanf("%50[^\n]", alunos[indice].nome);

            limpezaBuffer();

            printf("Digite o curso correto: ");
            scanf("%30[^\n]", alunos[indice].curso);

            do{ 

                validacao = 0;

                printf("Digite a matricula correta: ");
                scanf("%d", &matriculaNova);

                for(int i = 0; i < qtd; i++){ 

                    if(i != indice && alunos[i].matricula == matriculaNova){
                        validacao = 1;
                        printf("Essa matricula ja existe! Tente novamente.\n");
                        break;
                    }
                }
            }while(validacao == 1);

            alunos[indice].matricula = matriculaNova;

            do{ 
            printf("Digite a primeira nota (0 a 10): ");
            scanf("%f", &alunos[indice].n1);

            if(alunos[indice].n1 < 0 || alunos[indice].n1 > 10){
             printf("Nota invalida!\n");
            }

            }while(alunos[indice].n1 < 0 || alunos[indice].n1 > 10);

            limpezaBuffer();

            do{
            printf("Digite a segunda nota (0 a 10): ");
            scanf("%f", &alunos[indice].n2);

            if(alunos[indice].n2 < 0 || alunos[indice].n2 > 10){
             printf("Nota invalida!\n");
            }

            }while(alunos[indice].n2 < 0 || alunos[indice].n2 > 10);

            do{
                printf("Digite a frequencia (0 a 100): ");
                scanf("%f", &alunos[indice].frequencia);

                if(alunos[indice].frequencia < 0 || alunos[indice].frequencia > 100){
                    printf("Frequencia invalida!\n");
                }

            }while(alunos[indice].frequencia < 0 || alunos[indice].frequencia > 100);

            arquivo = fopen("alunos.txt", "w"); /*reescreve o arquivo com as informacoes novas*/

        if(arquivo == NULL){
            printf("Erro ao abrir o arquivo!\n");
            return;
        }

        for(int i = 0; i < qtd; i++){ /*Loop que reescreve todas as informacoes ja contendo as informacoes alteradas*/

            fprintf(arquivo, "%s;", alunos[i].nome);
            fprintf(arquivo, "%s;", alunos[i].curso);
            fprintf(arquivo, "%d;", alunos[i].matricula);
            fprintf(arquivo, "%f;", alunos[i].n1);
            fprintf(arquivo, "%f;", alunos[i].n2);
            fprintf(arquivo, "%f\n", alunos[i].frequencia);

        }

            fclose(arquivo);

            printf("Aluno alterado com sucesso.\n");
}
/*Funcao para excluir um registro*/
void excluirAluno(ALUNO alunos[], int *qtd){

    int matricula; /*Recebe a matricula que encontra o aluno a ser excluido*/
    int encontrado = 0; /*Mesma logica da busca, se encontrar o aluno ele valida a operacao */
    char confirmacao; /*Confirma se o usuario realmente quer excluir o aluno*/

    FILE *arquivo;

        printf("Digite a matricula do aluno que deseja excluir: ");
        scanf("%d", &matricula);

        for(int i = 0; i < *qtd; i++){ /*loop para percorrer os alunos um por um dentro da quantidade*/

            if(alunos[i].matricula == matricula){

                encontrado = 1;

                printf("Tem certeza que quer excluir esse aluno? (S/N): ");
                scanf(" %c", &confirmacao);

                if(confirmacao == 'S' || confirmacao == 's'){
                    /*Loop que percorre alunos para deslocar os alunos posteriores ao que foi 
                        excluido para as suas respectivas posicoes anteriores*/
                    for(int j = i; j < *qtd - 1; j++){ 
                            alunos[j] = alunos[j + 1];
                    }

                    (*qtd)--; /*Diminui a quantidade de alunos registrados toda vez que um aluno e excluido*/

                    arquivo = fopen("alunos.txt", "w");

                    if(arquivo == NULL){
                        printf("Erro ao abrir o arquivo!\n");
                        return;
                    }

                    for(int j = 0; j < *qtd; j++){

                        fprintf(arquivo, "%s;", alunos[j].nome);
                        fprintf(arquivo, "%s;", alunos[j].curso);
                        fprintf(arquivo, "%d;", alunos[j].matricula);
                        fprintf(arquivo, "%f;", alunos[j].n1);
                        fprintf(arquivo, "%f;", alunos[j].n2);
                        fprintf(arquivo, "%f\n", alunos[j].frequencia);

                    }

                    fclose(arquivo);

                    printf("Aluno excluido com sucesso!\n");

                }
                else{
                    printf("Exclusao cancelada.\n");
                }
                break;
            }
        }

        if(encontrado == 0){
            printf("Aluno nao encontrado!\n");
        }
}

// RELATORIO 

/*Escreve o relatorio em "saida": se for stdout aparece na tela,
se for um arquivo grava nele. O conteudo e igual nos dois*/
void imprimirRelatorio(FILE *saida, ALUNO alunos[], int qtd){

    float media;
    float soma= 0;
    float mediaGeral= 0;
    float maior = 0;
    float menor = 0;

    //Pega a data e a hora atuais
    time_t agora = time(NULL);
    struct tm *data = localtime(&agora);

    /*Estatisticas: percorre os alunos somando as medias e guardando a maior e a menor*/
    for(int i = 0; i < qtd; i++){

        media = calcularMedia(alunos[i].n1, alunos[i].n2);
        soma += media;

        if(i == 0 || media > maior){
            maior = media;
        }
        if(i == 0 || media < menor){
            menor = media;
        }
    }

    if(qtd > 0){
        mediaGeral = soma / qtd;
    }

    /*Cabecalho*/
    fprintf(saida, "\n======= RELATORIO =======\n");
    fprintf(saida, "Data: %02d/%02d/%04d\n\n", data->tm_mday, data->tm_mon + 1, data->tm_year + 1900);

    /*Tabela*/
    fprintf(saida, "%-10s %-25s %-8s %-8s\n", "Matricula", "Nome", "Media", "Freq");
    fprintf(saida, "--------------------------------------------------------\n");

    for(int i = 0; i < qtd; i++){
        fprintf(saida, "%-10d %-25.25s %-8.2f %-8.1f\n",
                alunos[i].matricula, alunos[i].nome,
                calcularMedia(alunos[i].n1, alunos[i].n2), alunos[i].frequencia);
    }

    fprintf(saida, "--------------------------------------------------------\n\n");

    /*Estatisticas*/
    fprintf(saida, "Total de alunos: %d\n", qtd);
    fprintf(saida, "Media geral:     %.2f\n", mediaGeral);
    fprintf(saida, "Maior media:     %.2f\n", maior);
    fprintf(saida, "Menor media:     %.2f\n", menor);

    /*Rodape*/
    fprintf(saida, "\n======= Fim do relatorio =======\n");
}

/*Gera o relatorio.txt e mostra na tela*/
void gerarRelatorio(ALUNO alunos[], int qtd){

    FILE *arquivo = fopen("relatorio.txt", "w");

    if(arquivo == NULL){
        printf("Erro ao criar o arquivo relatorio.txt\n");
        return;
    }

    imprimirRelatorio(arquivo, alunos, qtd); //grava no arquivo
    imprimirRelatorio(stdout, alunos, qtd);  //mostra na tela

    fclose(arquivo);

    printf("\nRelatorio gerado com sucesso!\n");
}


/*Função principal:*/
    int main(){

        int opcao; /*Declaracao da variavel responsavel por registrar o numero escrito pelo usuario para o programa rodar o que o usuario quer fazer*/
        int qtd = 0; /*Variavel que armazena a quantidade de alunos registrados*/
        int capacidade = 5; /*Variavel que armazena a quantidade inicial do vetor*/

        ALUNO *alunos = malloc(capacidade * sizeof(ALUNO)); /*malloc reserva memoria para o registro das informacoes*/

        if(alunos == NULL){
            printf("Erro ao alocar memoria!\n");
            return 1;
        }

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

            /* Pode atualizar o endereco de alunos; fazer antes de cadastrar. */
            if(!garantirCapacidade(&alunos, qtd, &capacidade)){
                break;
            }

            arquivo = fopen("alunos.txt", "a"); /*Abre o arquivo alunos.txt para que insira novos dados de alunos no relatorio*/

            /*Se o arquivo abrir, o programa compila, se nao a mensagem de erro aparece*/

            if(arquivo != NULL){
                preencherCadastro(alunos, &qtd, arquivo);
                fclose(arquivo);
            }
            else{
                printf("Falha na abertura do arquivo.\n");
            }

            break;
        case 2:
            listarAlunos(alunos, qtd);
            break;
        case 3:
            buscarAlunos(alunos, qtd);
            break;
        case 4:
            alterarAlunos(alunos, qtd);
            break;
        case 5:
            excluirAluno(alunos, &qtd);
            break;
        case 6:
			gerarRelatorio(alunos, qtd);
            break;
        case 7:
            break;
        default:
            printf("\nOpcao invalida, digite uma opcao valida:\n ");
    }
    }while(opcao != 7);
    free(alunos);
}
