//Lista Simplesmente Encadeada.

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoRegistro {
	int valor;
	tipoRegistro *prox;
	tipoRegistro *ante;
}TRegistro;

typedef struct tipoLista {
	TRegistro *inicio;
	TRegistro *fim;
	int totalRegistros;
}TLista;


//=============================================================
void inicializa(TLista *L){
	L->inicio = NULL;
	L->fim = NULL;
	L->totalRegistros = 0;
}
//==============================================================
void insere(TLista *L, int numero){
	//insere n�mero na lista em ordem crescente.
	
	TRegistro *novo, *atual;
	int inserido = 0;
	
	novo = (TRegistro *)malloc(sizeof(TRegistro));
	novo->prox = NULL;
	novo->ante = NULL;
	novo->valor = numero;
	
	if(L->inicio == NULL){
		//Lista est� vazia.
		L->inicio = novo;
		L->fim = novo;	
		//inserir �nico elemento na Lista.	
	} else {
		//A Lista N�O est� vazia.
		atual = L->inicio;
		while(atual != NULL){
			if(atual->valor >= novo->valor ){
				//inserir novo antes de atual.
				if(atual->ante == NULL){
					//inserir no in�cio da lista.
					novo->prox = L->inicio;
					L->inicio = novo;	
				} else {
					//inserir no meio da Lista.
				    atual->ante = novo;		
				    novo->prox = atual;					
				}

				inserido = 1;
				break;
			}//if
			novo->ante = atual;
			atual = atual->prox;	
		}//while
		
		if(!inserido){
			//inserir novo no fim da lista.
			L->fim->prox = novo;
			L->fim = novo;
		}//if
	}
	
	L->totalRegistros++;
}
//==============================================================
void imprimeLista(TLista L){
	printf("\n\n\n\t\t=====| LISTA |======\n\n");
	TRegistro *atual = L.inicio;
	int cont = 0;
	
	while(atual != NULL){
		printf("\t(%d) - %d.\n",++cont, atual->valor);
		atual = atual->prox;
	}//while
	
	printf("\n\n");
	system("PAUSE");
}
//===============================================================
void exclue(TLista *L, int numero){
	TRegistro *atual, *anterior;
	int encontrado = 0;
	
	//busca por elemento com valor = numero...
	atual = L->inicio;
	anterior = NULL;
	
	while(atual != NULL){
		if(atual->valor == numero)	{
			encontrado = 1;

			if((atual == L->inicio)	&& (atual == L->fim)){
				//Excluindo o �nico elemento da lista.
				L->inicio = NULL;
				L->fim = NULL;
			} else if(atual == L->inicio){
				//Excluindo elemento no in�cio da lista.
				L->inicio = atual->prox;	
			} else if(atual == L->fim){
				//Excluindo o �ltimo elemento.
				L->fim = anterior;
				L->fim->prox = NULL;
			} else {
				//Excluindo um elemento no meio da Lista.
				anterior->prox = atual->prox;
			}//if
			
			free(atual); //Elimina��o do registro.
			break; //abandona while...
		}//if
		
		anterior = atual;
		atual= atual->prox;
		
	}//while
	
	if(encontrado){
		printf("\n\t\tRegistro EXCLUIDO com  SUCESSO!\n");
	} else {
		printf("\n\t\tRegistro NAO encontrado.\n\tImpossivel EXCLUIR!\n\t");
		printf("VALOR = %d\n", numero);
	}
	system("PAUSE");
}
//===============================================================

TLista lista;

void inicializa(TLista *L);
void insere(TLista *L, int numero);
void imprimeLista(TLista L);
void exclue(TLista *L, int numero);


int main(){
	inicializa(&lista);
	
	insere(&lista, 7);
	insere(&lista, 9);
	insere(&lista, 8);
	insere(&lista, 6);
	insere(&lista, 4);
	insere(&lista, 13);
	insere(&lista, 11);
	
	imprimeLista(lista);
	
	exclue(&lista, 4); //excluindo elemento no in�cio da lista
	exclue(&lista, 13); //excluindo o �ltimo elemento da lista
	exclue(&lista, 9); //excluindo elemento no meio da lista
	exclue(&lista, 21); //tentando excluir elemento inexistente na lista
	
	exclue(&lista, 7);
	exclue(&lista, 8);
	exclue(&lista, 6);
	exclue(&lista, 11);//excluindo o �nico elemento da lista.
	
	imprimeLista(lista);
}