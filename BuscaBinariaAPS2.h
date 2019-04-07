/*	Biblioteca do Algoritmo de Pesquisa de Dados: Busca Bin�ria de um Array

	Autor: Alexandre Gadelha
	
	Com a Letra a ser buscada informada na Fun��o Principal ou via Fun��o comum, acha-se o �NDICE desse
	elemento primeiro no Vetor pra depois realizar a Busca Bin�ria com base no �NDICE deste.
	
	Se N�O for encontrado o elemento no Vetor, nenhum �NDICE ser� obtido e a Busca N�O ir� ocorrer.
*/
void binarySearchArray (char vetor[], int &extEsq, int &extDir, int indiletra)
{
	int indipivot;
	
	indipivot = (extEsq + extDir) / 2;
	
	if (extEsq <= extDir)
	{
		if (indiletra == indipivot)
		{
			printf ("\n\nA Letra [%c] informada foi encontrada na posi��o %d durante a Busca Bin�ria no Vetor!", vetor[indiletra], indipivot);
		}
		else if (indiletra > indipivot)
		{
			indipivot++;
			binarySearchArray (vetor, indipivot, extDir, indiletra);
		}
		else
		{
			indipivot--;
			binarySearchArray (vetor, extEsq, indipivot, indiletra);
		}
	}
}

void indexElementSearch (char vetor[], char letra)
{
	int tamanho, extEsq, extDir, i, indice;
	bool achou = false;
	
	tamanho = strlen (vetor);
	extEsq = 0;
	extDir = tamanho-1;
						
	for (i = 0; vetor[i] != '\0'; i++)
	{
		if (letra == vetor[i])
		{
			indice = i;
			achou = true;
			break;
		}
	}
	
	if (!achou)
	{
		printf ("\n\nA Letra [%c] informada N�O foi encontrada no Vetor e nem foi poss�vel buscar seu �ndice!", letra);
	}
	else
	{
		binarySearchArray (vetor, extEsq, extDir, indice);
	}
}
