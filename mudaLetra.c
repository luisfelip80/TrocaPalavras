
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mm();

int main () {
	mm();
	FILE *arq, *novo;
	
	int i,marc=0,marc_1,marc_2,gatilho=0,ui,b,y,u,pk,g;
	int w=-1,j,ch=1,ll,cont=0; 
	char arquivo[50]="luis",f,c='n',Linha[1000],copy[60];
	char  encontrar [100],palavra [100], substituir[100];

	printf("Nome ou local do Arquivo: ");
	scanf(" %s", arquivo);
	printf("\nMostrar conteudo? S|N : ");			
	scanf(" %c",&f);
	
	if(f=='S' || f=='s'){
		arq=fopen(arquivo, "r");
		if(arq!=NULL){
			printf("\n\n");
			while(!feof(arq)){
				strcpy(Linha,"");
				fgets(Linha,999,arq);
				printf("%d| %s",cont,Linha);
				cont++;
			}	
		}
		else {
			printf("Arquivo Nao encontrado!\n");
			exit (0);
		}

		printf("\n\n\n");	
		fclose(arq);
	}	
	strcpy(Linha,"");	

		while(ch!=0){
			
			arq=fopen(arquivo, "r");

			if(arq!=NULL){

				printf("\nArquivo aberto.\n");

				novo=fopen("novo.txt","wt");
				printf("%s/Procurar por: ",arquivo);
				scanf(" %[^\n]", palavra);
				printf("\n%s/Trocar para: ",arquivo);
				scanf(" %[^\n]", substituir);

				while(!feof(arq)){
					strcpy( encontrar , palavra );
					strcpy(Linha,"");
					fgets(Linha,199,arq);
		    		//printf("Procurar pela primeira letra de %s\n",encontrar );
					for ( b=0; Linha[b] != '\0' ; b++){	
						u=0;
						ui=1;
						//printf("Testando Letras...\n");
						if(Linha[b] == encontrar[0]){
							//printf("%c\n",Linha[b]);
							marc_2=b;
							marc=b;
							u=0;
							ui=0;

							strcpy(encontrar,palavra);
							for (pk = 0; encontrar [pk] != '\0' ; pk++){
								u++;
								if(Linha[marc] == encontrar [pk]){
									ui++;
									//printf("%c",encontrar[pk]);
								}
								marc++;
							}
							//printf("\n");			
							if (ui==u){
								//printf("Palavra encontrada: u %d b %d %s\n",u,b, encontrar);
								y=0;
								g= b +(ui);
								
								while(Linha[g]!='\0'){
									copy [y] = Linha[g];
									y++;
									g++;
								}
								copy[y]='\0';
								Linha[b] = '\0' ;
								//printf("Linha: %s\n",Linha);
								//printf("\n");
								//printf("b %d\n", b);
								strcat(Linha,substituir);
								
								strcat(Linha,copy);
								//printf("Pronto!\n");
								
							}
						}
					}
					
						fprintf(novo, "%s", Linha);
						strcpy(Linha,"");					
				}
				fclose(novo);
				fclose(arq);

				printf("\nDeseja ver alteracoes antes de salvar? S|N :");
				scanf(" %c", &f);
				if(f=='S' || f=='s'){
					novo = fopen("novo.txt", "r");
					cont=0;
					if(arq!=NULL){
						printf("\n\n");
						while(!feof(novo)){
							strcpy(Linha,"");
							fgets(Linha,999,novo);
							printf("%d- %s",cont,Linha);
							cont++;
						}		
					}
					fclose(novo);
					printf("\n\n");		
				}

				printf("Deseja salvar? S|N :");
				scanf(" %c",&f);
				if (f=='s' || f == 'S'){
					remove(arquivo);
					rename("novo.txt",arquivo);	
					printf("\nSalvo!\n");
				}
				else {
					remove("novo.txt");
					printf("\n");
				}

				printf("Deseja sair? S|N :");
				scanf(" %c", &c);
				
				strcpy(Linha,"");
				if(c=='S' || c=='s'){
					return 0;
				}
			}
		else {
		printf("Erro.\n");
		printf("Arquivo: ");
		scanf(" %s", arquivo);
		}
	}

	
	system("pause");
	return 0;	
}


void mm(){
	printf("\n\n");
printf("\t\t\t############################################################\n");
printf("\n");	
printf("\t\t\t     PROGRAMA PARA TROCAR LETRAS E PALAVRAS EM DOCUMENTO    \n");
printf("\t\t\t                        27/10/2017                          \n");
printf("\t\t\t               LUIS FELIPE MIRANDA DA SILVA                 \n");
printf("\t\t\t            UFPE CIN - ENGENHARIA DA COMPUTAÇÃO             \n");
printf("\t\t\t               LIVRE ACESSO AO CONHECIMENTO.                \n");
printf("\n");
printf("\t\t\t############################################################\n");
printf("\n\n");
}