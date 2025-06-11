#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

// Dados do aluno
typedef struct //Typedef serve para n�o escrever struct para declarar a vari�vel
{
	char Nome_Alu [20];
	int RGM;
	float A1, A2, AF, Media_Alu;
} Aluno;
	
	// Criei a vari�vel alunos
	Aluno alunos[100];

// Dados da sala
typedef struct
{
	float Media_sala;
	int Total_Alu;
} Sala;
	
	// Criei a vari�vel sala
	Sala sala;
	
// Op��o para caso o aluno seja aprovado ou reprovado
typedef struct
{
	int valor; 
	int menu;
	int executar;
} Valores;

	// Criei a vari�vel opcao
	Valores valores;

int main(){
	 
		setlocale(LC_ALL, "Portuguese");
		
		sala.Total_Alu =0;
		valores.executar = 1;
		
		// Fun��es CRUD
		while (valores.executar) {
	        printf("\nCSYSTEM: MENU\n");
	        printf("Quantidade de alunos j� cadastrados: %d\n", sala.Total_Alu);
	        printf("1. Cadastrar aluno\n");
	        printf("2. Atualizar nota\n");
	        printf("3. Listar alunos\n");
	        printf("4. Excluir aluno\n");
	        printf("0. Sair\n");
	        printf("Escolha uma op��o: ");
	        scanf("%d", &valores.menu);
	        printf("\n");
	        system("pause");
	        system("cls"); 
		
		switch(valores.menu)
		{
			case 0:
				{
					valores.executar = 0;	
				}
				break;
							
			case 1: 
				{
					printf("CSYSTEM - Cadastrar \n");
					// Caso tenha igual ou mais alunos cadastrados
					if(sala.Total_Alu >= 100)
					{
						printf("Limite de alunos atingidos\n");
						// Caso para cadastrar o aluno
					} else 
						{
							
							// Pedir as informa��es do aluno (Nome, RGM, A1, A2 e caso precise de AF)
							printf("Digite o nome do aluno: ");
							getchar();
							fgets(alunos[sala.Total_Alu].Nome_Alu, sizeof(alunos[sala.Total_Alu].Nome_Alu), stdin);
							alunos[sala.Total_Alu].Nome_Alu[strcspn(alunos[sala.Total_Alu].Nome_Alu, "\n")] = 0; //Para pular linha ap�s o fgets
							
							//alunos[sala.Total_Alu].Nome_Alu: onde o nome ser� armazenado.
							//sizeof: garante que n�o ser� lido mais do que o tamanho permitido no vetor.
							//stdin: l� da entrada padr�o (teclado).
						
							
							int RGM_novo;
							int RGM_duplicado;
							
							do {
							    RGM_duplicado = 0;
							    printf("Digite o RGM do aluno: ");
							    scanf("%d", &RGM_novo);
							
							    for (int RGM_pos = 0; RGM_pos < sala.Total_Alu; RGM_pos++) 
								{
							        if (alunos[RGM_pos].RGM == RGM_novo) 
									{
							            printf("Erro: J� existe um aluno com esse RGM.\n");
							            RGM_duplicado = 1;
							            break;
							        }
							    }
							} while (RGM_duplicado);
							
							alunos[sala.Total_Alu].RGM = RGM_novo;

					        
					        do{
					        	printf("Digite a nota da Avalia��o 1 (0 a 5): ");
					        	scanf("%f", &alunos[sala.Total_Alu].A1);
							} while (alunos[sala.Total_Alu].A1 < 0 || alunos[sala.Total_Alu].A1 > 5);
							
							do{
					        	printf("Digite a nota da Avalia��o 2 (0 a 5): ");
					        	scanf("%f", &alunos[sala.Total_Alu].A2);
							} while (alunos[sala.Total_Alu].A2 < 0 || alunos[sala.Total_Alu].A2 > 5);
							
							// M�dia do aluno
							alunos[sala.Total_Alu].Media_Alu = alunos[sala.Total_Alu].A1 + alunos[sala.Total_Alu].A2;
							
							// Op��es caso o aluno tenha a m�dia maior ou menor que 6
							if(alunos[sala.Total_Alu].Media_Alu >=6)
				        	{
				        		printf("Media: %.1f - Aprovado!\n", alunos[sala.Total_Alu].Media_Alu);
							} else
								{
										printf("media: %.1f - Fazer prova AF\n", alunos[sala.Total_Alu].Media_Alu);
					    			do {
					    				printf("Digite a nota da Avalia��o Final (0 A 5): ");
					    				scanf("%f", &alunos[sala.Total_Alu].AF);
					    			}while (alunos[sala.Total_Alu].AF < 0 || alunos[sala.Total_Alu].AF > 5);
					    			
					    			// Substituir a menor nota pela AF
					    			if (alunos[sala.Total_Alu].A1 < alunos[sala.Total_Alu].A2)
									{
					    			 	alunos[sala.Total_Alu].A1 = alunos[sala.Total_Alu].AF;
					    			} else 
										{
					    			 	alunos[sala.Total_Alu].A2 = alunos[sala.Total_Alu].AF;
					    				} 
					    			
					    			// Nova m�dia do aluno
					    			alunos[sala.Total_Alu].Media_Alu = alunos[sala.Total_Alu].A1 + alunos[sala.Total_Alu].A2;
					    			
					    			// Op��es caso novamente seja reprovado ou aprovado
					    			if (alunos[sala.Total_Alu].Media_Alu >= 6)
									{
					    			 	printf("Nova media do aluno: %.1f - Aprovado!\n", alunos[sala.Total_Alu].Media_Alu);
					    			} else 
										{
					    			 	printf("Nova media do aluno: %.1f - Reprovado!\n", alunos[sala.Total_Alu].Media_Alu);
					    				}
								}
							// Adicionar o aluno na m�dia da sala
						sala.Media_sala += alunos[sala.Total_Alu].Media_Alu;
							// Pr�ximo aluno
						sala.Total_Alu++;
							
						system("pause");
						system("cls"); 
						}
				}
				break;
			
			//Atualizar notas dos alunos	
			case 2:
				{					
					if(sala.Total_Alu == 0)
					{
						printf("Ainda n�o possui alunos cadastrados\n");
						break;
					}
					
					int UpRGM, encontrado = 0;
					printf("Digite o RGM do aluno que deseja atualizar: \n");
					scanf("%d", &UpRGM);
					
					for(int UpAlu = 0; UpAlu < sala.Total_Alu; UpAlu++)
					{
						if(alunos[UpAlu].RGM == UpRGM)
						{
							encontrado = 1;
							printf("Atualizando notas do aluno %s (RGM %d)\n", alunos[UpAlu].Nome_Alu, alunos[UpAlu].RGM);
							sala.Media_sala -= alunos[UpAlu].Media_Alu;
							
						do {
			                printf("Digite a nova nota da Avalia��o 1 (0 a 5): ");
			                scanf("%f", &alunos[UpAlu].A1);
			            } while (alunos[UpAlu].A1 < 0 || alunos[UpAlu].A1 > 5);
			            
			            do {
			                printf("Digite a nova nota da Avalia��o 2 (0 a 5): ");
			                scanf("%f", &alunos[UpAlu].A2);
			            } while (alunos[UpAlu].A2 < 0 || alunos[UpAlu].A2 > 5);
			            
			            
			            alunos[UpAlu].Media_Alu = alunos[UpAlu].A1 + alunos[UpAlu].A2;
								
										
							if(alunos[UpAlu].Media_Alu >=6)
							{
								printf("Media: %.1f - Aprovado!\n", alunos[UpAlu].Media_Alu);
							} else
								{
									printf("media: %.1f - Fazer prova AF\n", alunos[UpAlu].Media_Alu);
									do {
										printf("Digite a nota da Avalia��o Final (0 A 5): ");
										scanf("%f", &alunos[UpAlu].AF);
									}while (alunos[UpAlu].AF < 0 || alunos[UpAlu].AF > 5);
													    			
									// Substituir a menor nota pela AF
									if (alunos[UpAlu].A1 < alunos[UpAlu].A2)
									{ 
										alunos[UpAlu].A1 = alunos[UpAlu].AF;
									} else 
										{
											alunos[UpAlu].A2 = alunos[UpAlu].AF;
										} 
													    			
									// Nova m�dia do aluno
									alunos[UpAlu].Media_Alu = alunos[UpAlu].A1 + alunos[UpAlu].A2;
													    			
									// Op��es caso novamente seja reprovado ou aprovado
									if (alunos[UpAlu].Media_Alu >= 6)
									{
										printf("Nova media do aluno: %.1f - Aprovado!\n", alunos[UpAlu].Media_Alu);
									} else 
										{
											printf("Nova media do aluno: %.1f - Reprovado!\n", alunos[UpAlu].Media_Alu);
										}
								}	
							sala.Media_sala += alunos[UpAlu].Media_Alu;
						}
					}
					
					if(!encontrado)
					{
						printf("Aluno com RGM %d n�o encontrado.\n", UpRGM);
					}
					
				system("pause");
				system("cls"); 
				}
				break;
				
	
			//Listar alunos
			case 3:					
				{
					printf("CSYSTEM - Listagem\n");
					if(sala.Total_Alu == 0)
					{
						printf("Nenhum aluno cadastrado\n");	
					} else
						{
							printf("Lista de alunos \n");
							valores.valor = 0;
							for (valores.valor; valores.valor < sala.Total_Alu; valores.valor++)
							{
								printf("\nAluno %d \n", valores.valor+1);
								printf("Nome: %s \n", alunos[valores.valor].Nome_Alu);
								printf("RGM: %d \n", alunos[valores.valor].RGM);
								printf("Nota Final: %.1f \n", alunos[valores.valor].Media_Alu);
								
								if (alunos[valores.valor].Media_Alu >= 6)
								{
									printf("Situa��o: Aprovado \n");
								} else
									{
										printf("Situa��o: Reprovado \n");
									}
								}	
						}
				system("pause");
				system("cls"); 
				}
				break;
				
			//Excluir aluno	
			case 4:
				{
					int ExcluRGM, encontrado = 0;
					printf("\nCSYSTEM - Excluir\n");
					printf("Digite o RGM do aluno que deseja excluir: \n");
					scanf("%d", &ExcluRGM);
					
					for(int atual = 0; atual < sala.Total_Alu; atual++)
					{
						if(alunos[atual].RGM == ExcluRGM)
						{
							encontrado = 1;
							
							sala.Media_sala -= alunos[atual].Media_Alu;
							
							for (int novo = atual; novo < sala.Total_Alu - 1; novo++)
							{
								alunos[novo] = alunos [novo + 1];
							}
							
							sala.Total_Alu--;
			            printf("Aluno com o RGM %d exclu�do com sucesso.\n", ExcluRGM);
			            break;
						}
					}
					
					if(!encontrado)
					{
						 printf("Aluno com RGM %d n�o encontrado.\n", ExcluRGM);
			   		}
			    system("pause");
			    system("cls"); 
			}
			break;	
		}	
	}
	return 0;
}
