/*	Biblioteca do Algoritmo de Ordena��o: BUBBLE SORT otimizado

	Autor: Alexandre Gadelha
	
	ORDENA��O POR BOLHA ou BUBBLE SORT possui uma implementa��o simples, mas que possui complexidade QUADR�TICA,
	sendo eficiente para MENORES entradas de dados.
	
	O m�todo de complexidade quadr�tica, tem base na Propriedade do Somat�rio em fun��o de I, conforme abaixo:
	
					Somat�rio de I com o I=1 at� N, que gera, (N^2 + N) / 2 em fun��o de N.
	
	Contudo, o �ltimo termo da sequ�ncia do Somat�rio, nunca ser� avaliado. Logo, assumindo at� N-1 e teremos N menos N.
	
	a) No MELHOR CASO, teremos uma complexidade LINEAR [O(n)] pelo fato de ser realizada apenas a verifica��o de todos os elementos do
	   Vetor apenas UMA vez. A vari�vel booleana "swapcontrol" que ir� controlar isso. Sem ela, o BUBBLE SORT, assumiria complexidade
	   QUADR�TICA mesmo no MELHOR CASO, pois as compara��es iriam ocorrer todas as vezes - embora n�o haveria trocas (swaps) de valores.
	
	b) No PIOR CASO, com as compara��es ocorrendo todas as vezes e com as trocas tamb�m, como o BUBBLE SORT n�o possui m�todos de otimiza��o
	   para o PIOR CASO, o algoritmo assumir� a complexidade natural dela - que � a QUADR�TICA [O(n^2)] em Nota��o Big O.
	   
	OBS: Aqui, temos a vers�o otimizada do BUBBLE SORT, mas existe uma vers�o mais simples do BUBBLE SORT sem a vari�vel de controle de swaps.
	     Pra esses modelos de BUBBLE SORT, a complexidade de custo � QUADR�TICA para o MELHOR CASO, tornando este igual ao SELECTION SORT em efici�ncia.
*/
void bubbleSort (int vetor[], int n)
{
	int i, j, alce;
	bool swapcontrol = true;
	
	for (i = 0; (swapcontrol && i < n-1); i++)
	{
		swapcontrol = false;
		
		for (j = n-1; j > i; j--)
		{
			if (vetor[j] < vetor[j-1])
			{
				alce = vetor[j-1];
				vetor[j-1] = vetor[j];
				vetor[j] = alce;
				swapcontrol = true;
			}
		}
	}
}
