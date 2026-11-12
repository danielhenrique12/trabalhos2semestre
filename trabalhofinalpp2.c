#include <stdio.h>
	int main(){
		int assentos[3][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
		};
		int linhas, fileiras;
		int opcao = -1;
		int sessao;
		int assento;
	
	while (opcao != 0){
	
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
		printf("Assentos:");
			for(mapa = 0; mapa < 5; mapa++){
		printf("%4d", vetorMapa[5] + (mapa+1));
			}
			printf("\n");
		for(linhas = 0; linhas < 3; linhas++){
			for(fileiras = 0; fileiras < 5; fileiras++){
				if(fileiras == 0){
					printf("Sessao %d:", linhas + 1);
				}
				printf("%4d", assentos[3][5]);
			}
			printf("\n");
		}
			break;
		
		case 2: 
			printf("");
			break;
			
		case 3:
			printf("");
			break;
			
		case 4: 
			printf("");
			break;
			
		case 0:
			printf("Encerrado");
			break;
			
		default:
			printf("Opcao nao encontrada");
			break;
		}
	}
	}
