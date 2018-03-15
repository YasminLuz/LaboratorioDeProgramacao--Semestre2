#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10


typedef struct auxiliar{ 
	int valor;
	struct auxiliar *prox;
}aux;


typedef struct lista{                                
    int capac; //capacidade total da estrutura
	unsigned int qnt;  //informa se ja criou estrutura em x posicao
    aux *vet2;	
}no;


int menu(void);
int submenu(int i);
void inicializa(no *vetor);
int inserir(no *vetor);
void imprimeprincipal(no *vetor);
//int vazia(aux* estrutura);
void limpar();

/*ajuda : https://www.vivaolinux.com.br/script/Vetor-de-lista
https://inf.ufes.br/~pdcosta/ensino/2012-2-estruturas-de-dados/slides/Aula9%28listas%29.pdf
*/
int main(void){
	
	//CRIA LISTA PRINCIPAL
	no vetor[TAM];//array de ponteiros com 10 posicoes fixas(lista estatica) para estruturas auxiliares

	//vetor->qnt = -1;//diferente de NULL, nenhuma posicoes ocupadas no inicio
	
	inicializa(vetor);
	   
	int opc, opd, cont = 0 , posicao = 0, tamanho = 0, num; 
    
    do{
    	volta: opc = menu();
    
		switch(opc){
			
			case 1:{    do{
						    opc = submenu(1);
						
							switch(opc){
								
								case 1:{	if(cont <= TAM){//verifica a possibilidade de overflow na lista principal
								
											  digite: printf("\nPosicao estrutura principal[1-10]: ");
									          scanf("%i",&posicao);
									        
									          posicao--;//de 0 a 9 programa
									         
											 	if ((posicao>9) || (posicao<0)){  //leitura para usuario e de 1 a 10
												 	printf("\nDigite um numero dentro da capacidade maxima/minima do vetor\n");
												 	goto digite;
												}		
											 											 	       			         
										        if (vetor[posicao].qnt == -1){ //se não tiver estrutura auxiliar criada nessa posicao, faca
										         
										            vetor[posicao].qnt++;//auxiliar criada e igual a -1
										            printf("%d",vetor[posicao].qnt);
											        cont++; 
											        
										            //fflush(stdin);
										         	printf("Tamanho vetor: ");
										         	scanf("%d", &vetor[posicao].capac);
										         	printf("CAPACID%d",vetor[posicao].capac);
										         	vetor[posicao].vet2 = (aux *) malloc(tamanho * sizeof(aux));
										         	//v2 = NULL;
										           // vetor[posicao].p = v2;//aponta para primeira posicao da estrutura auxiliar
										            printf("Lista criada!\n");
										            
													sleep(2);//espera tempo pra ler e depois apagar
										            limpar();
										            goto volta;//volta ao menu principal
									
											    } else{
												    printf("\nA lista ja foi criada!\n");
												    sleep(2);
										            limpar();
											        goto volta;
											 	}
											 
										    }else{
											       printf("\nO tamanho da lista foi atingido");
											       sleep(2);
										           limpar();
										           goto volta;
											}
										     
								        	//limpar();
										 break;	
										
										}
									
								case 2:{ inserir(&vetor[0]);
									      sleep(2);
										  limpar();
										  goto volta;
									     
										break;
										}
									
										
								case 3: goto volta; 		
								
									
								default:printf("\nDigite uma operacao valida!\n");	
							}
							
						}while(opc != 3);
					}
			    
				   
			case 2:{   do{
							opc = submenu(2);
						
							switch(opc){
									
									case 1:{imprimeprincipal(vetor);
											break;
									       }
									       
	                                case 2:{
											break;
									       }
									
									case 3:{
											break;
										   }
									
									case 4: goto volta; 
									
									default:printf("Digite uma operacao valida!\n"); 
																	       
							}
							
			     		}while(opc != 4);
				   }
			
			
			case 3:{    do{
							opc = submenu(3);
						
							switch(opc){
								
									case 1:{
										
											break;
									       }
									       
	                                case 2:{
											
											break;
									       }
									
									case 3:goto volta; 
									
							}
				
						}while(opc != 3);
						
						break;
				   }
			
			case 4:{
		
			  		    break;
			   	   }
		
			case 5:{   printf("Encerrado!\n"); 
			
				    	break;
				   }
			
			default: printf("Digite uma operacao valida!\n");break;	
		}
		
    //	limpar();
    	
	}while(opc != 5);
    
    //free(vetor);//para a lista sequencial

	return 1;
}


 void limpar(){
	system("cls");
}


//int vazia(aux *vet){
//	
//	if(vet->prox == NULL)
//		return 1;
//	else
//		return 0;
//	
//}


void inicializa(no *vetor){
   int x;
   for(x = 0; x < TAM; x++){ //inicializa todas as posicoes de uma so vez
     vetor[x].capac = -1;
   	 vetor[x].qnt = -1;
  	 vetor[x].vet2 = NULL;
  	// vetor[x].vet2.prox = NULL; 	
  	 
   }
}


int submenu(int i){
	 int opc;
	
	switch (i){ //qual submenu exibir a partir das entradas
		
		case 1: {printf("\n   [1] Criar lista \n"
			   "   [2] Inserir elemento \n"
			   "   [3] Voltar menu principal\n ");
		scanf("%i",&opc);
		
		break;
				}
				
	case 2:{printf("\n   [1] Todas as estruturas \n"
			   "   [2] Auxiliares ordenas \n"
			   "   [3] Todas as estruturas ordenadas\n"
			   "   [4] Voltar ao menu principal \n");
		scanf("%i",&opc);
		
		break;
	}
	
	case 3:{
			
		printf("\n   [1] Excluir elemento da lista auxiliar \n"
			   "   [2] Excluir da lista principal (apaga tudo) \n"
			   "   [3] Voltar ao menu principal");
		scanf("%i",&opc);
		
		break;
	}
	}		
return opc;
	
}


int menu(void){
    int opc;
    
    printf("                          SIMULACAO ESTRUTURA DE DADOS                                   \n");
	
	printf("1 - Inclusao \n"
	       "2 - Listagem  \n"
		   "3 - Exclusao \n"
		   "4 - Aumentar tamanho aux \n"
		   "5 - Sair\n ");
	scanf("%i",&opc);
	
	return opc;
}


 int inserir(no *vetor){
 	
 	int pos;
 	
   	printf("\nPosicao principal para inserir: ");
	scanf("%i", &pos);
	
	pos--;
	
	printf("QUANT%d\n",vetor[pos].qnt);
	printf("CAPAC%d\n",vetor[pos].capac);
	
	if ((pos>9) || (pos<0)){  //leitura para usuario e de 1 a 10
		printf("\nDigite um numero dentro da capacidade maxima/minima do vetor\n");
		return 0;
	}
		
	
	if(vetor[pos].qnt == vetor[pos].capac){
		printf("\nLista cheia!\n");
		return 0;
	}
	
		
 	if(vetor[pos].qnt == 0){//se tiver estrutura criada e for primeira entrada
 		fflush(stdin);
     	printf("\nNumero: ");
		scanf("%i", &vetor[pos].vet2->valor);
		vetor[pos].vet2->prox = NULL;
		
	    vetor[pos].qnt++;//ate chegar no tamanho declarado para a estrutura aux
	    return 1;
	    
	} else if (vetor[pos].qnt > 0){
		
		printf("\nNumero: ");
		scanf("%i", &vetor[pos].vet2->valor);
		vetor[pos].vet2->prox = vetor[pos].vet2;//aponta para a antiga posicao
		vetor[pos].qnt++;
		
	} else if (vetor[pos].qnt == -1){//se nao tiver aux criada nessa posicao, exiba a menssagem
	
		printf("Não existe estrutura criada nessa posicao");
	}

 }
 
void imprimeprincipal(no *vetor){
	int x, y;
	no aux[TAM];
	//aux = (no *) malloc (TAM*sizeof(no));
	
	for(x =0 ; x <TAM; x++){
		printf("vetor[%d]=%d \n ",x+1, vetor[x].qnt+1);
		 for()// for(y = x, aux = vetor; aux[y].vet2->prox != NULL; y++,aux = aux[y].vet2->prox)
			printf("vetor[%d]=d", vetor[x].vet2->valor);
	}
	
}