/*	Biblioteca do Algoritmo de Ordena��o: QUICK SORT

	Autor: Alexandre Gadelha
	
	ORDENA��O R�PIDA ou QUICK SORT possui uma implementa��o via Fun��es Recursivas. Devido a sua complexidade QUADR�TICA, n�o se torna
	muito eficiente para grandes entradas. Contudo, para entradas pequenas e medianas, possui complexidade LINEAR�TMICA e se torna
	mais relevante.
	
	Da mesma forma que o INSERTION SORT, QUICK SORT utiliza o m�todo de "Dividir pra conquistar" por meio de Fun��es Recursivas
	a definir divis�es chamadas de PARTI��ES e um centro referencial que chamamos de PIV�.
	
	a) No MELHOR CASO, teremos a complexidade LINEAR�TMICA sendo [O(n log n)], pois, mesmo o Vetor j� estando ordenado, pode-se dizer
	   que a Divis�o deste ainda ocorrer� (Processo de cria��o de PARTI��ES) at� que reste APENAS UM elemento nas Parti��es para declarar
	   o fim do processo. A troca ser� realizada de forma in�til do PIV� com ele mesmo, uma vez que NENHUM Valor � Esquerda seria MAIOR que
	   ele e NENHUM Valor � Direita seria MENOR que o PIV�.
	   
	   Logo, as vari�veis de controle "I" e "J" caminhariam livremente at� o PIV� sem interrup��es a n�o ser a troca do PIV� com ele mesmo.
	   Essa caminhada das vari�veis de controle, define parte da complexidade ser Linear.   
	
	b) No PIOR CASO, o algoritmo assume a complexidade QUADR�TICA sendo [O(n^2)], tendo em vista que haveria uma Varredura Linear no Vetor
	   em forma de somat�rio. Contudo, esses casos s�o raros de acontecer e seria poss�vel APENAS se o PIV� fosse colocado em UM DOS EXTREMOS.
	   
	   Na maioria das vezes, acaba assumindo complexidade LINEAR�TMICA mesmo [O(n log n)], pois sempre haver� trocas durante o processo de
	   varredura da Parti��o.
	
	OBS: Assim como o SHELL SORT depende fortemente do GAP sendo INST�VEL, QUICK SORT tamb�m � assim e depende da posi��o que o PIV� est�
	     configurado pra assumir (Geralmente, fica no MEIO). QUICK SORT � mais dif�cil de implementar por utilizar Fun��es Recursivas mas
		 pode chegar a ser mais eficiente que o SHELL SORT e costuma ser aclamado como o algoritmo de ordena��o mais r�pido que existe.	 
*/

/*------------------------ EXPLICA��O DAS PARTES DO QUICK SORT ABAIXO -----------------------*/

/* Procedimento essencial do algoritmo. Aqui, ser� feita a Varredura Linear da Parti��o criada em an�lise a verificar se os Valores a Esquerda do
   PIV� s�o MENORES que ele e se os Valores da Direita do PIV� s�o MAIORES que ele. Caso positivo, a Parti��o j� est� ordenada e o PIV� realizar� a
   troca com ele mesmo. Caso contr�rio, as posi��es de UM elemento da Esquerda e de UM elemento da Direita, s�o evidenciadas e os Valores ser�o trocados.
   
   A Varredura Linear s� ir� acabar quando as Vari�veis de extremos din�micos "&I" e "&J" SE CRUZAREM (I > J). */

void percorreParticao (int esqParc, int dirParc, int &i, int &j, int vetor[])
{
	int pivot, alce;
	
	i = esqParc;
	j = dirParc;
	
	pivot = vetor[(i+j)/2];				// Defini��o do PIV� como Ponto Central do Vetor
	
	do
	{
		/* Percorrer elementos � Esquerda do PIV� da Esquerda para a Direita (i++) */
		
		while (vetor[i] < pivot)
		{
			i++;
		}
		
		/* Percorrer elementos � Direita do PIV� da Direita para a Esquerda (j--) */
		
		while (vetor[j] > pivot)
		{
			j--;
		}
		
		/* Depois das Vari�veis "I" e "J" estiverem evidenciadas, deve-se realizar a troca de elementos ou do PIV� com ele mesmo */
		
		if (i <= j)
		{
			alce = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = alce;
			
			i++;
			j--;
		}
				
	}while (i <= j);
}
/*-------------------------------------------------------------------------------------------*/

/* Procedimento-c�rebro do algoritmo. Aqui, criam-se Parti��es com base nos extremos do Vetor fornecidos e/ou recebidos do Procedimento
   "percorreParticao" que ir� retornar as posi��es dos extremos din�micos (Vari�veis "I" e "J") da Esquerda e da Direita, respectivamente. */

void criaParticao (int extEsq, int extDir, int vetor[])
{
	int i, j;
	
	percorreParticao (extEsq, extDir, i, j, vetor);
	
	if (extEsq < j)
	{
		criaParticao (extEsq, j, vetor);
	}
	
	if (extDir > i)
	{
		criaParticao (i, extDir, vetor);
	}
}
/*-------------------------------------------------------------------------------------------*/

/* Procedimento-chave do QUICK SORT. Aqui, ser�o definidos os EXTREMOS do Vetor para ser colocado na Primeira Parti��o.
   Depois, os extremos v�o se reduzindo e novas Parti��es s�o criadas se necess�rio. */

void quickSort (int vetor[], int n)
{
	int esquerda, direita;
	
	esquerda = 0;
	direita = n-1;
	
	criaParticao (esquerda, direita, vetor);
}
/*-------------------------------------------------------------------------------------------*/
