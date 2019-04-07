/*	Biblioteca do Algoritmo de Ordena��o: SHELL SORT

	Autor: Alexandre Gadelha
	
	ORDENA��O SHELL ou SHELL SORT possui uma implementa��o derivada do INSERTION SORT, mas que se torna mais eficiente que ele.
	SHELL SORT possui complexidade LINEAR�TMICA (LINEAR + LOGAR�TMICA) sendo bem eficiente para entradas maiores e o mais
	eficiente algoritmo de ordena��o existente.
	
	O m�todo de complexidade linear�tmica, tem base na seguinte na fus�o entre o m�todo linear e logar�tmico. Linear pois se trata de
	percorrer o Vetor e logar�tmico por utilizar o m�todo de "Dividir pra conquistar" semelhante a uma constru��o de �rvore Bin�ria.
	
	a) No MELHOR CASO, teremos uma complexidade LINEAR�TMICA de Nota��o [O(n log n)], pois, embora o Vetor j� esteja ordenado, ser�o
	   necess�rias verifica��es de Valores no processo de Divis�o do Vetor, n�o sendo apenas no final de maneira linear. Como o SHELL
	   SORT depende fortemente do GAP (Vari�vel "gap"), o processo de verifica��o de Valores no processo de Divis�o do Vetor pode demorar,
	   contudo, � esperado que PELO MENOS UMA VARREDURA seja feita durante esse processo, antes da varredura linear.
	
	   Na varredura linear, a verifica��o ser� realizada N-1 vezes assumindo o comportamento do INSERTION SORT.
	
	b) No PIOR CASO, pode-se dizer que SHELL SORT ainda se trata de um Problema Aberto (Open Problem). Pra alguns estudiosos, a complexidade
	   na Nota��o Big O � [O(n^1.5)], pra outros � [O(n^1.25)] e num PIOR CASO mais terr�vel, chegou-se obter a complexidade {O[n (log2)^2 n]}
	   onde o Logaritmo assume exponencia��o QUADR�TICA na BASE 2 de N.
	   
	   Contudo, como geralmente desprezamos a BASE do Logaritmo que n�o faz diferen�a, num PIOR CASO mais terr�vel, pode-se dizer que a complexidade
	   ainda � [O(n log n)] de maneira geral, sendo a mais aceita at� os dias atuais.
	   
	   A respeito de compara��es e trocas, no INSERTION SORT, ter�amos um efeito de somat�rio [O(n^2)]. No SHELL SORT, n�o ter�amos esse efeito pelo
	   fato das trocas que seriam realizadas no processo de Divis�o do Vetor antes da Varredura Linear. Isso mant�m a complexidade LINEAR�TMICA.
	   
	OBS: Dos algoritmos de complexidade eficiente, SHELL SORT � o mais f�cil de implementar e pode chegar a ser mais eficiente que o QUICK SORT em certos
	     casos devido a sua complexidade QUADR�TICA. Contudo, o algoritmo � INST�VEL, pois depende fortemente do GAP (Vari�vel "gap").
*/
void shellSort (int vetor[], int n)
{
	int gap = 1, i, j, alce;
	
	do
	{
		gap = (gap * 3) + 1;
		
	}while (gap < n);
	
	do
	{
		gap /= 3;
		
		for (i = gap; i < n; i++)
		{
			j = i;
			alce = vetor[i];
			
			while (j >= gap && vetor[j-gap] > alce)
			{
				vetor[j] = vetor[j-gap];
				j -= gap;
			}
			
			vetor[j] = alce;
		}
		
	}while (gap != 1);
}
