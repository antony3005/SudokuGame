#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Faz um Check point do jogo.
void salvarArquivo(bool matriz2, int matriz){
	int i, j;
	FILE * arquivo = fopen ("sudoku.txt", "w");
	if (arquivo == NULL){
		printf ("Erro ao escrever arquivo\n");
	}
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			fprintf (arquivo, "%i", matriz);
		}
	}
	fclose(arquivo);
}

int main(int argc, char *argv[]) {
	int i, j;
	int num = 0;
	int vidas = 5;
	int l = 0;
	int m = 0;
	int v = 0;
	
	//duas matrizes pois uma irá ter os valores e outra irá verificar se aquele valor ja foi achado ou nao
	//(usei bool mas poderia ter usado 0 e 1 tambem)
int matriz[4][4] = {4, 2, 1, 3,
					1, 3, 2, 4,
					3, 1, 4, 2,
					2, 4, 3, 1};
					
bool matriz2[4][4] = {false, false, true, false,
					  true, false, false, true,
					  true, true, true, false,
					  false, false, true, true};
					
do{
	//mostra a matriz (Jogo) e os itens que ja foram encontrados
	for (i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				printf ("|");
				if(matriz2[i][j] == false){
				printf (" %i ", matriz[i][j]);
				}else{
					// Se o item nao foi encontrado mostra ~ no lugar dele
					printf (" ~ ");
				}
				
			}
			
			printf ("\n");
		}
	//parte em que o jogador digita a posicao do item que ele acha que encontrou
	printf ("linha (0 - 3), coluna (0 - 3), valor (0 - 4):\n");
	printf ("linha: \n");
	scanf ("%i", &l);
	printf ("coluna: \n" );
	scanf ("%i", &m);
	printf ("valor: \n");
	scanf ("%i", &v);
	//faz a verificacao se os itens estao dentro dos parametros passados
	if(l > 3 || l < 0 || m > 3 || m < 0 || v < 0 || v > 4 ){
		printf ("Alguma entrada invalida\n");
		
	}
	//Se o jogador acertar mostra essa mensagem
	if(v == matriz[l][m]){
		printf ("Parabens voce acertou\n");
		for (i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				// e troca a posicao do array que tava true para false, agora mostrando o número oculto
				matriz2[l][m] = false;
				
			}
		}
	}else{
		//Mostra que o jogador erreu e decrementa a vida dele
		printf ("Voce errou\n");
		vidas--;
		printf ("voce ainda tem %i vidas\n", vidas);
		
			}
			/*verifica quantas posicoes do array ainda sao True e conta(esse trecho fiz pra poder me localizar e 
			saber se tava funcionando do jeito certo)*/
		for (i = 0; i < 4; i++){
			for(j = 0; j < 4; j++){
				if  (matriz2[i][j] == true){
					num++;
					
				}
			}
			
		}
		//Se nao tiver mais nenhum True no array de verificacao quer dizer que o jogador ganhou, logo ele exibe essa mensagem
		if(num == 0){
			printf ("Parabens, Voce ganhou!!");
			break;
		}
				/*esse trecho fiz pra poder me localizar e 
			saber se tava funcionando do jeito certo*/
					printf ("ainda faltam %i casas\n", num);
					//zera pra que a variavel num nao fique somando
					num = 0;
		
	}while(vidas >= 0);	
}
