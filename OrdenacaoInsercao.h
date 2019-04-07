/*	Biblioteca do Algoritmo de Ordena��o: INSERTION SORT

	Autor: Alexandre Gadelha
	
	ORDENA��O POR INSER��O ou INSERTION SORT possui uma implementa��o simples, mas que possui complexidade QUADR�TICA,
	sendo eficiente para MENORES entradas de dados.
	
	O m�todo de complexidade quadr�tica, tem base na Propriedade do Somat�rio em fun��o de I, conforme abaixo:
	
					Somat�rio de I com o I=1 at� N, que gera, (N^2 + N) / 2 em fun��o de N.
	
	Contudo, o �ltimo termo da sequ�ncia do Somat�rio, nunca ser� avaliado. Logo, assumindo at� N-1 e teremos N menos N.
	
	a) No MELHOR CASO, teremos uma complexidade LINEAR [O(n)] pelo fato das compara��es dentro do WHILE serem realizadas apenas UMA vez
	   para cada N-1 posi��es do Vetor em quest�o a ser verificado, retornando FALSE nem chegando a entrar no WHILE.
	
	b) No PIOR CASO, com as compara��es ocorrendo todas as vezes e com as trocas tamb�m, o INSERTION SORT assume complexidade QUADR�TICA
	   de Nota��o Big O [O(n^2)]. Contudo, a novidade dos algoritmos de ordena��o como esse que possui o efeito de um somat�rio, � que as
	   trocas s�o realizadas em sincronia com as compara��es do WHILE.
	   
	   Se uma compara��o der FALSE, aquele Primeiro Valor armazenado que serviu de compara��o dentro do WHILE [Vari�vel "val"] ir� justamente
	   para a posi��o J+1 do Vetor que deu FALSE ou para a posi��o 0 deste Vetor se todas as trocas forem realizadas at� J chegar ao valor "-1".
	
	OBS: Existe um vers�o oficial melhorada do INSERTION SORT que possui complexidade LINEAR�TMICA [O(n log n)], ou seja, a complexidade mais
	     eficiente dos algoritmos de ordena��o. O nome dele � SHELL SORT.
*/
void insertionSort (int vetor[], int n)
{
	int i, j, val;
	
	for (i = 1; i < n; i++)
	{
		j = i-1;
		val = vetor[i];
		
		while (j >= 0 && vetor[j] > val)
		{
			vetor[j+1] = vetor[j];
			j--;
		}
		
		vetor[j+1] = val;
	}
}
