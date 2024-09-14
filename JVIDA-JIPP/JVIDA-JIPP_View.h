/*JVIDA-JIPP_View.h 
17/10/2023
Igor Costa
Joao Avila Harduin
Pedro Evaristo de Oliveira
Priscilla de Souza Jardim
*/

int dimensao();  //recebe a dimensao do mundo digitada pelo usuario
int menu_geral();  //apresenta o menu de opcoes das acoes do jogo
int coord_x();  //recebe a linha de onde o usuario deseja inserir a celula
int coord_y();  //recebe a coluna de onde o usuario deseja inserir a celula
char exclui(int li, int col);  //confirma se o usuario deseja excluir a celula
void apresenta_mundo(char m[60][60], int dim);  //apresenta a matriz do mundo
void resp_invalida();  //mensagem padrao de resposta indevida do usuario
void limpatela();  //organiza melhor o codigo removendo acoes anteriores da tela
void apres_viz_morta(char m[60][60], int dim);
void apresenta_mensagem(char m[500]);
char continuar_insercao();
int geracoes();