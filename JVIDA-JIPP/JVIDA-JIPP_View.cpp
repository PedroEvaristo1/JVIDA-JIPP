/*JVIDA-JIPP_View.cpp 
17/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_View.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int dimensao()
{
	do
	{
		int d;
		printf(" Digite o tamanho do mundo (minimo 10 e maximo 60): ");
		scanf("%d", &d);
		
		if(d < 10 || d > 60)
		{
			printf(" Tamanho invalido.\n");
			limpatela();
		}
		else
		{
			system("cls");
			return d;
		}
	}
	while(1);
}

int menu_geral()
{
	do
	{
		int op;
		
		printf("      Projeto JOGO DA VIDA      \n");
		printf(" ===============================\n");
		printf(" 1-Apresentar o Mundo\n");
		printf(" 2-Incluir/Excluir celulas vivas\n");
		printf(" 3-Iniciar simulacao\n");
		printf(" 4-Limpar o Mundo\n");
		printf(" 5-Sair\n");
		printf(" ===============================\n");
		printf(" Resp: ");
		scanf("%d", &op);
		
		if(op < 1 || op > 5)
		{
			printf("Opcao invalida.\n");
			limpatela();
		}
		else
		{
			
			return op;
		}
	}
	while(1);
}

void apresenta_mundo(char m[60][60], int dim)
{

    printf(" ============== Mundo ===========");
	for(int k = 0; k < (dim-10); k++)
	{
		printf("===");
	}
	printf("\n");
	printf("   ");
	for(int a = 0; a < dim; a++)
	{
		printf("%3d", a);
	}
	printf("\n");
	for(int i = 0; i < dim; i++)
	{
		printf("%3d", i);
		for(int j = 0; j < dim; j++)
		{
			printf("%3c", m[i][j]);
		}
		printf("\n");
	}
	printf(" ================================");
	for(int k = 0; k < (dim-10); k++)
	{
		printf("===");
	}
	printf("\n\n");
	
}

void apres_viz_morta(char m[60][60], int dim)
{
	char opcao;
	do
	{
		
	printf("\nDeseja que as celulas vizinhas-mortas sejam apresentadas? (S/N)\n");
	scanf(" %c", &opcao);
	opcao = toupper(opcao);
	
	if(opcao == 'S')
	{
		for(int i = 0; i < dim; i++)
	        for(int j = 0; j < dim; j++)
		        if(m[i][j] == 'O')
			    {
			    	if(m[i-1][j]== '.')
			    	   m[i-1][j] = '+';
			    	if(m[i-1][j-1]== '.')
			    	   m[i-1][j-1] = '+';
			    	if(m[i-1][j+1]== '.')
			    	   m[i-1][j+1] = '+';
			    	if(m[i][j-1]== '.')
			    	   m[i][j-1] = '+';
			    	if(m[i][j+1]== '.')
			    	   m[i][j+1] = '+';
			    	if(m[i+1][j]== '.')
			    	   m[i+1][j] = '+';
			    	if(m[i+1][j-1]== '.')
			    	   m[i+1][j-1] = '+';
			    	if(m[i+1][j+1]== '.')
			    	   m[i+1][j+1] = '+';
				}
    }
	
	else if(opcao == 'N')
	{
		for(int i = 0; i < dim; i++)
	        for(int j = 0; j < dim; j++)
		        if(m[i][j] == '+')
		            m[i][j] = '.';
	}
	else
	    printf("Resposta invalida\n");
	
	}while(opcao!='S' && opcao!='N');
}

void apresenta_mensagem(char m[500])
{
    printf("%s\n", m);
}

int coord_x()
{ 

	int l;
	
	printf("   Digite a linha desejada(60 para sair): ");
	scanf("%d", &l);
		
	return l;

}

int coord_y()
{
	
	int c;
	
	printf("   Digite a coluna desejada: ");
	scanf("%d", &c);
		
	return c;
	
}

char exclui(int li, int col)
{
	char r;
	
	printf("   Ja existe uma celula viva na posicao (%d,%d)\n", li, col);
	printf("   Deseja exclui-la? (S/N) ");
	scanf(" %c", &r);
	r = toupper(r);
	return r;
	
}

char continuar_insercao()
{
	char op;
	
	do
	{
		printf(" Deseja continuar a incluir ou excluir celulas? (S/N)\n");
		scanf(" %c", &op);
		op = toupper(op);
		if(op!='N' && op!='S')
	    {
	    	printf(" Opcao invalida\n");
	    	continue;
		}
		
		return op;
	}
	while(1);
	
}

void limpatela()
{
	printf(" ");
	system("pause");
	system("cls");
}

int geracoes()
{
	int ger;
	
	do
	{
	    printf("Quantas geracoes devem ser apresentadas?");
	    scanf(" %d", &ger);
	    if(ger<=0)
	    {
	    	printf(" Opcao invalida\n");
	    	continue;
		}
		
		return ger;
    }
    while(1);
}
