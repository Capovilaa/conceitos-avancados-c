/*
Defina os tipos de variáveis adequados para cada situalção (normal, vetor, estrutura, vetor de estrutura)

1) Ler quantidade indeterminada de valores até digitar 0 -> 1x simples
2) Somar as notas de uma prova até que o usuário digite -1 -> 2x simples
3) Preciso mostrar as notas de uma prova que ficaram abaixo da média da prova -> 1x vetor 3x simples
4) Preciso ler o código, a idade, a nota da prova 1 e a nota da prova 2 de 40 alunos -> 1x estrutura 1x simples
5) Mostrar os dados dos alunos com a nota da prova 2 acima da média -> 1x vetor de estrutura 2x simples
6) Enunciado anterior, mas não sabemos a quantidade de alunos -> 3x simples 1x lista ligada 2x apontadores
*/

#include <stdio.h>
#include <stdlib.h>

struct tipoAluno {
	int ra, idade;
	float p1, p2;
	struct tipoAluno * prox;	
};

int main(void){
	// VARIAVEIS
	int qtd = 0;
	float media, soma = 0;
	struct tipoAluno * lista = NULL, * aux;
	
	// ENTRADA DE DADOS
	do{
		// verificacao de memoria
		if(!(aux = malloc(sizeof(struct tipoAluno)))){
			printf("Sem memoria \n");
			exit(1);
		}
		
		printf("Digite a nota da prova 2: ");
		scanf("%f", & (aux -> p2));
		
		// verifica se usuario nao quer parar programa para pedir demais informacoes
		if(aux -> p2 >= 0){
			printf("Digite a nota da prova 1: ");
			scanf("%f", & (aux -> p1));
			printf("Digite o RA: ");
			scanf("%d", & (aux -> ra));
			printf("Digite a idade: ");
			scanf("%d", & (aux -> idade));
			
			aux -> prox = lista;
			lista = aux;
			qtd++; // incrementa quantidade de alunos
			soma = soma + aux -> p2; //	incrementa nota geral das provas
		}
	}while(aux -> p2 >= 0);
	
	
	// PREPARACAO PARA SAIDA DE DADOS
	free(aux); // libera bloco caso o usuario pare o programa
	media = soma/qtd; // calcula media
	aux = lista;
	
	
	// SAIDA DE DADOS
	while(aux != NULL){
		// se estiver acima da media mostrar todos os dados
		if(aux -> p2 > media){
			printf("RA = %d", aux -> ra);
			printf("Idade = %d", aux -> idade);
			printf("P1 = %f", aux -> p1);
			printf("P2 = %f", aux -> p2);
		}
		aux = aux -> prox;
	}		
	
	
	// PERCORRE STRUCT PARA LIBERAR ELE
	aux = lista;
	while(aux != NULL){
		lista = aux -> prox;
		free(aux);
		aux = aux -> prox;
	}
		
	return 0;
}