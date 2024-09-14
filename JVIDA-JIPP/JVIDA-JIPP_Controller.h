/*JVIDA-JIPP_Controller.h 
17/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

void comecar();  //inicia o programa
void cria_mundo(int dim);  //preenche a matriz da dimensao desejada com '.'
void insere_cel(char m2[60][60], int dim2);  //insere uma celula no mundo trocando '.' por 'O' ou exclui uma celula existente
void matriz_aux(int dim1, char m3[60][60]);
