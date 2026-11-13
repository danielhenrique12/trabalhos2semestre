#include <stdio.h>
	int main(){
		int assentos[3][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		};
		int vetorMapa[5] = {1, 2, 3, 4, 5};
		int mapa;
		int linhas, fileiras;
		int opcao = -1;
		int reservado = 0;
		int assentosLivres;
		int assentosOcupados;

		float totalGeral = 0;
		float faturamento;
		float precos[3];

		for(int i = 0; i < 3; i++){

			printf("\n Digite o valor do ingresso da sessao %d: ", i + 1);
			scanf("%f", &precos[i]);

			while(precos[i] <= 0){

        	printf("\nValor invalido, tente novamente: ");
        	scanf("%f", &precos[i]);

    		}

		}


	do{
	
		printf("\n===MENU===\n");
		printf("1 - Mostrar mapa de assentos\n");
		printf("2 - Reservar assento\n");
		printf("3 - Cancelar reserva\n");
		printf("4 - Mostrar resumo das sessões\n");
		printf("0 - Encerrar\n");
		printf("Selecione a opcao desejada: \n");
		scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
		printf("Mapa dos assentos: \n");
		printf("Aqueles que estiverem com o numero 1 estao reservados, os que estiverem com 0 estao vazios.\n");
		printf("Assentos:");

			for(mapa = 0; mapa < 5; mapa++){

		printf("%4d", vetorMapa[mapa]);

			}

			printf("\n");

		for(linhas = 0; linhas < 3; linhas++){

			for(fileiras = 0; fileiras < 5; fileiras++){

				if(fileiras == 0){

					printf("Sessao %d:", linhas + 1);

				}

				printf("%4d", assentos[linhas][fileiras]);
			}

			printf("\n");

		}
			break;
		
		case 2: 

		reservado = 0;

			while(reservado == 0){

		printf("\n==Fazer a reserva==");
		printf("\nDigite a sessao e o numero do assento desejado: ");
		scanf("%d %d", &linhas, &fileiras);

		if(linhas <= 3 && linhas > 0 && fileiras <= 5 && fileiras > 0){

			if(assentos[linhas-1][fileiras-1] == 1){

				printf("\nAssento previamente reservado, insira outra sessao e/ou outro numero de assento. ");

			}
			else{

			assentos[linhas-1][fileiras-1] = 1;

			printf("\nReserva confirmada.");
			printf("\nValor da sessao: R$ %.2f", precos[linhas-1]);

			reservado = 1;

		}
		}
		else{

			printf("\nNumero de sessao ou de assento invalidos. ");

			reservado = 1;

		}
		}
			break;
			
		case 3:

		reservado = 0;

		while(reservado == 0){

			printf("\n==Cancelar reserva==");
			printf("\nDigite o numero da sessao e o assento: ");
			scanf("%d %d", &linhas, &fileiras);

			if(linhas <= 3 && linhas > 0 && fileiras <= 5 && fileiras > 0){

			if(assentos[linhas-1][fileiras-1] == 1){

				printf("\nCancelamento efetuado com sucesso. \n");

				assentos[linhas-1][fileiras-1] = 0;

				reservado = 1;
			}
			else{

			printf("\nNenhuma reserva foi feita ainda nesse assento dessa sessao. ");

			}
		}
		else{

			printf("\nNumero de sessao ou de assento invalidos. ");

			reservado = 1;
		}
		}

			break;
			
		case 4: 

			totalGeral = 0;

			printf("\n==Resumo das sessoes==");

			for(linhas = 0; linhas < 3; linhas++){

				assentosLivres = 0;
				assentosOcupados = 0;

            	for(fileiras = 0; fileiras < 5; fileiras++){

                	if(assentos[linhas][fileiras] == 0){

                    assentosLivres++;

                	}
                	else{

                    assentosOcupados++;

                	}
				}

					faturamento = assentosOcupados * precos[linhas];
					totalGeral = totalGeral + faturamento;

					printf("\n==Resumo da sessao %d==\n", linhas + 1);
					printf("\nAssentos livres: %d\n", assentosLivres);
					printf("\nAssentos ocupados: %d\n", assentosOcupados);
					printf("\nFaturamento da sessao: %.2f reais\n", faturamento);

			}
					printf("\nFaturamento total: %.2f reais\n", totalGeral);

			break;
			
		case 0:
			printf("\n Programa Encerrado.");
			break;
			
		default:
			printf("\nOpcao nao encontrada\n");
			break;
		}
	} while (opcao != 0);
	}
