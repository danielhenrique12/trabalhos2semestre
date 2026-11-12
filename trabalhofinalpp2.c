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
		int sessao;
		int assento;
		int reservado = 0;
	
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
			while(reservado == 0){
		printf("\nDigite a sessao e o numero do assento desejado: ");
		scanf("%d %d", &linhas, &colunas);
		if(linhas<=3 && linhas>0 && colunas <= 5 && colunas > 0){
			if(assentos[linhas][colunas] == 1){
				
			}
			else{
			assentos[linhas][colunas] = 1;
			reservado = 1;
			}
		}
		}
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
	} while (opcao != 0);
	}
