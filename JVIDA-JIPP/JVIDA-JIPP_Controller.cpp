/*JVIDA-JIPP_Controller.cpp 
17/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

#include "JVIDA-JIPP_View.cpp"
#include "JVIDA-JIPP_Model.cpp"
#include "JVIDA-JIPP_Controller.h"
#include <time.h>

void comecar()
{	
	dime = dimensao();
	cria_mundo(dime);
	
	int resp;
	
	do
	{	
		resp = menu_geral();
		
		switch(resp)
		{
			case 1:
				{
				apres_viz_morta(mundo, dime);
				limpatela();
				apresenta_mundo(mundo, dime);
				limpatela();
				break;
			    }
			case 2:
				{
				limpatela();
				insere_cel(mundo, dime);
				break;
			    }
			case 3:
				{
				matriz_aux(dime, mundo);
				break;
			    }
			case 4:
				{
				cria_mundo(dime);
				apresenta_mensagem(" Mundo limpado com sucesso!\n");
				limpatela();
				break;
			    }
		}
	}
	while(resp != 5);
}

void cria_mundo(int dim)
{	
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			mundo[i][j] = '.';	//definicao de quarto vazio
		}
	}
}

void matriz_aux(int dim1, char m3[60][60])
{
	int count, count1, count2;
	
	count2=geracoes();
	do
	{
	
	count=0;
	count1=0;	
	for(int h = 0; h < dim1; h++)
	{
		for(int k = 0; k < dim1; k++)
		{
			aux[h][k] = '.';	
		}
	}
	
		            
	for(int i = 0; i < dim1; i++)
	           for(int j = 0; j < dim1; j++)
		          if(m3[i][j] == 'O')
		          {
		          	aux[i][j] = 'O';
		          	if(m3[i-1][j]== '.')
			    	   aux[i-1][j] = '+';
			    	if(m3[i-1][j-1]== '.')
			    	   aux[i-1][j-1] = '+';
			    	if(m3[i-1][j+1]== '.')
			    	   aux[i-1][j+1] = '+';
			    	if(m3[i][j-1]== '.')
			    	   aux[i][j-1] = '+';
			    	if(m3[i][j+1]== '.')
			    	   aux[i][j+1] = '+';
			    	if(m3[i+1][j]== '.')
			    	   aux[i+1][j] = '+';
			    	if(m3[i+1][j-1]== '.')
			    	   aux[i+1][j-1] = '+';
			    	if(m3[i+1][j+1]== '.')
			    	   aux[i+1][j+1] = '+';
				  }
				  
	for(int a = 0; a < dim1; a++)
	           for(int b = 0; b < dim1; b++)
		        {
				  if(aux[a][b] == '+')
				  {
				  	if(aux[a-1][b]== 'O')
				  	   count++;
			    	if(aux[a-1][b-1]== 'O')
			    	   count++;
			    	if(aux[a-1][b+1]== 'O')
			    	   count++;
			    	if(aux[a][b-1]== 'O')
			    	   count++;
			    	if(aux[a][b+1]== 'O')
			    	   count++;
			    	if(aux[a+1][b]== 'O')
			    	   count++;
			    	if(aux[a+1][b-1]== 'O')
			    	   count++;
			    	if(aux[a+1][b+1]== 'O')
			    	   count++;
			    	if(count==3)
			    	   aux[a][b] = 'O';
			       }
			       else if(aux[a][b] == 'O')
			       {
			       	 if(aux[a-1][b]== 'O')
				  	   count1++;
			    	if(aux[a-1][b-1]== 'O')
			    	   count1++;
			    	if(aux[a-1][b+1]== 'O')
			    	   count1++;
			    	if(aux[a][b-1]== 'O')
			    	   count1++;
			    	if(aux[a][b+1]== 'O')
			    	   count1++;
			    	if(aux[a+1][b]== 'O')
			    	   count1++;
			    	if(aux[a+1][b-1]== 'O')
			    	   count1++;
			    	if(aux[a+1][b+1]== 'O')
			    	   count1++;
			    	if(count==0 || count==1 || count>=4)
			    	   aux[a][b] = '.';
			    	}
			    }
			    
	for(int g = 0; g < dim1; g++)
	{
		for(int r = 0; r < dim1; r++)
		{
			if(aux[g][r]=='+')
			   aux[g][r] = '.';
			m3[g][r] = aux[g][r];	
		}
	}
	
	apresenta_mundo(m3, dim1);
	limpatela();
	count2--;
	
    }while(count2!=0);
}

void insere_cel(char m2[60][60], int dim2)
{	
	int l, c;
	char resp1, resp2;
	resp2 = 'S';
	for(int i = 0; i < dim2; i++)
	        for(int j = 0; j < dim2; j++)
		        if(m2[i][j] == '+')
		            m2[i][j] = '.';
	
	do
	{
		apresenta_mundo(m2, dim2);
		apresenta_mensagem(" Insercao:\n");
		l = coord_x();
		if(l==60)
		{
		   limpatela();
		   break;
	    }
		if(l < 0 || l >= dim2)
		{
			apresenta_mensagem("   Linha invalida.\n");
			limpatela();
			continue;
		}
		c = coord_y();
		
		if( c < 0 || c >= dim2)
		{
		    apresenta_mensagem("   Coluna invalida.\n");
		    limpatela();
		    continue;
	    }
	    
	    if(m2[l][c] == 'O')
	    {
		   do
		   {
			
			  resp1 = exclui(l,c);
			
			  if(resp1 == 'S')
			  {
				m2[l][c] = '.';
				limpatela();
				break;
			  }
			  else if(resp1 == 'N')
			  {
				limpatela();
				break;
		   	  }
		   	  else
			    apresenta_mensagem("   Resposta invalida.\n");
			    
		    }
		    while(1);
	    }
	    else
	    {
		   m2[l][c] = 'O';
		   limpatela();
	    }
	    apresenta_mundo(m2, dim2);
	    resp2 = continuar_insercao();
	    limpatela();
		    
	}
	while(resp2=='S');
}
	
