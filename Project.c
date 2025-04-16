#include <stdio.h>

int main()
{
	//Definimos as variaveis 
    float A1, A2, media, AF;
    int Opcao =0;
    
    printf("Sistema de calculo - CSYSTEM\n");


    //Perguntar ao usuario as notas do aluno, tanto A1 como A2
    do{
        printf("Qual a nota da Avaliação 1 (0 a 5): ");
        scanf("%f", &A1);
    }while(A1<0 || A1>5);
    
    do{
        printf("Qual a nota da Avaliação 2 (0 a 5): ");
        scanf("%f", &A2);
    }while(A2<0 || A2>5);
    
    
    //Calcular a media das notas
    media= A1+ A2;
    
   	if (media >= 6) {
   		Opcao = 0;
	   } else {
	   	Opcao = 1;
	   }
    
    // Utilizar switch e case
    switch (Opcao) {
    	case 0:
    		printf("Media: %.1f - Aprovado!\n", media);
    		break;
	
	    //Opcao caso o aluno necessite fazer a AF
		case 1:
			printf("media: %.1f - Fazer prova AF\n", media);
			//Perguntar para o usuario a nota da AF
			do {
				printf("Digite a nota da Avaliação Final (0 A 5): ");
				scanf("%f", &AF);
			}while (AF < 0 || AF > 5);
 			
 			
			 // Substituir a menor nota pela AF
			if (A1 < A2) {
			 	A1 = AF;
			} else {
			 	A2 = AF;
			} 
			 
			media = A1 + A2;
			 
			 // Calcular a nova media 
			if (media >= 6) {
			 	printf("Nova media do aluno: %.1f - Aprovado!\n", media);
			} else {
			 	printf("Nova media do aluno: %.1f - Reprovado!\n", media);
			}
			break;
			 
		default:
			printf("Erro\n");
			break;
			 
	}		 
    return 0;
}
