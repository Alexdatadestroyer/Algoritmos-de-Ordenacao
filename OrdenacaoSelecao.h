/*	Biblioteca do Algoritmo de Ordena��o: SELECTION SORT

	Autor: Alexandre Gadelha
	
	ORDENA��O POR SELE��O ou SELECTION SORT possui uma implementa��o simples, mas que possui complexidade QUADR�TICA,
	sendo eficiente para MENORES entradas de dados.
	
	O m�todo de complexidade quadr�tica, tem base na Propriedade do Somat�rio em fun��o de I, conforme abaixo:
	
					Somat�rio de I com o I=1 at� N, que gera, (N^2 + N) / 2 em fun��o de N.
	
	Contudo, o �ltimo termo da sequ�ncia do Somat�rio, nunca ser� avaliado. Logo, assumindo at� N-1 e teremos N menos N.
	
	a) No MELHOR CASO, teremos uma complexidade ainda QUADR�TICA [O(n^2)] pelo fato das compara��es serem realizadas todas as vezes e as
	   trocas de elementos serem realizadas de forma maneira in�til UMA vez para cada opera��o de N-1 compara��es. Logo, teremos o efeito de
	   um somat�rio aqui que resultaria em [f(n) = (n^2 - n) / 2].
	
	b) No PIOR CASO, com as compara��es ocorrendo todas as vezes e com as trocas tamb�m, como o SELECTION SORT n�o possui m�todos de
	   otimiza��o para o PIOR CASO, o algoritmo assumir� a complexidade natural dele - que � a QUADR�TICA [O(n^2)] em Nota��o Big O.
	
	OBS: Como o MELHOR CASO e o PIOR CASO possuem a mesma complexidade QUADR�TICA, � correto afirma que o CASO M�DIO tamb�m � de complexidade
	     QUADR�TICA. Dos algoritmos de ordena��o mais simples de complexidade QUADR�TICA, � correto afirmar que o SELECTION SORT � O PIOR DELES!
*/
void selectionSort (int vetor[], int n)
{
	int i, j, menor, alce;
	
	for (i = 0; i < n-1; i++)
	{
		menor = i;
		
		for (j = i+1; j < n; j++)
		{
			if (vetor[j] < vetor[menor])
			{
				menor = j;
			}
		}
		alce = vetor[i];
		vetor[i] = vetor[menor];
		vetor[menor] = alce;
	}
}
