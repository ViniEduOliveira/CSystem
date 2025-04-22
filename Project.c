#include <stdio.h>

int main(){
    
    float a1[100], a2[100], af[100], media;
    float med_sala = 0;
    float Media_Sala;
    int i;
    int Opcao = 0;
    char Nomes_Alu[100][20];
    
    for(i= 0; i <100; i++){
        printf("Aluno %d\n", i + 1);
        
        printf("Digite o nome do aluno %d: ", i + 1);
        getchar();
        scanf("%[^\n]", Nomes_Alu[i]);
        
        do{
            printf("Nota da Avaliação 1:");
            scanf("%f", &a1[i]);
        }while (a1[i] < 0|| a1[i] > 5);
        
        do{
            printf("Nota da Avaliação 2:");
            scanf("%f", &a2[i]);
        }while (a2[i] < 0|| a2[i] > 5);
        
         media = a1[i] + a2[i];
    
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
    				scanf("%f", &af[i]);
    			}while (af[i] < 0 || af[i] > 5);
     			
     			
    			 // Substituir a menor nota pela AF
    			if (a1[i]<a2[i]) {
    			 	a1[i]=af[i];
    			} else {
    			 	a2[i]=af[i];
    			} 
    			 
    			media = a1[i]+a2[i];
    			 
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
            med_sala += media;
        }
        
Media_Sala = med_sala / 100;
printf("\nMédia da turma: %.2f\n", Media_Sala);
    
    
    
    return 0;
}