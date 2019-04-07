/*	Biblioteca do Tipo Abstrato de Dado: �rvore Bin�ria de Busca SEM BALANCEAMENTO

	Autor: Alexandre Gadelha
	
	Opera��es da �rvore Bin�ria de Busca apresentadas aqui:
	
	a) Opera��o de RESET (Limpeza da �rvore toda).
	b) Processo de Limpeza da �rvore de Busca (Se estiver na opera��o de RESET).
	c) Inserir Valor na �rvore que N�O SEJA REPETIDO.
	d) Percurso Pr�-ordem da �rvore: RAIZ, SAE, SAD.
	e) Percurso Ordem Sim�trica da �rvore: SAE, RAIZ, SAD.
	f) Percurso P�s-ordem da �rvore: SAE, SAD, RAIZ.
	g) Pesquisa de Valores na �rvore de Busca.
	h) Identifica��o e prepara��o para o processo de remo��o de elemento da �rvore.
	i) Remo��o real do elemento da �rvore onde o resultado final seja N� FOLHA ou N� de GRAU 1.
	
	OBS 1: No processo de remo��o de um N� de GRAU 2, faremos o processo de obter o MENOR � DIREITA
	       DO VALOR A SER REMOVIDO (O Menor Valor da SAD deste elemento). Contudo, se quis�ssemos
	       obter o MAIOR ELEMENTO � ESQUERDA DESTE VALOR (O Maior Valor da SAE deste elemento), tamb�m
	       daria certo.
	     
	       Caso n�o haja uma SAE ou SAD pr�xima do Valor em quest�o de acordo com o processo escolhido,
	       dever� ser feito um tratamento espec�fico a pegar o mais pr�ximo elemento ativo dele, em
	       outras palavras, aquele filho ativo (Elemento Esquerda da SAE ou Elemento Direita da SAD).
	
	OBS 2: Vari�vel Global (_blocos) ir� contar quantos Blocos de Mem�ria foram removidos no total
	       durante o processo de Limpeza da �rvore Bin�ria de Busca.
*/

int _blocos = 0;

struct BinaryTreeSearch
{
	char letra;
	struct BinaryTreeSearch *left, *right;
};

struct BinaryTreeSearch *root = NULL;

void removerLetraReal (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, char letra)
{
	struct BinaryTreeSearch *NoExcluido;
	
	/* IF: Caso de exclus�o de elemento que seja N� FOLHA (GRAU 0). Nesse caso, apenas redireciona-se o Ponteiro da Esquerda ou
	       da Direita do elemento ancestral, de acordo com o seu Valor em compara��o a ele, pra NULL (IF-ELSE internos).
		   
		   No caso exclusivo da RAIZ, esta passar� a apontar pra NULL, uma vez que a �rvore estar� VAZIA!
		   
		   OBS: O Ponteiro "NoExcluido" recebe o elemento da �rvore a ser exclu�do DEPOIS das opera��es do IF principal!
	   
	   ELSE: Caso de exclus�o de elemento que seja N� de GRAU 1, possuindo apenas UM FILHO. Nesse caso, � verificado qual elemento
	         estar� dispon�vel para tomar seu lugar, sendo a Esquerda dele ou a Direita (IF-ELSE em Condi��o Tern�ria superior).
			 O elemento dispon�vel ser� apontado pelo elemento ancestral da Esquerda ou da Direita dependendo de seu Valor perante
			 a ele (IF-ELSE em Condi��o Tern�ria inferior) num processo parecido com o da exclus�o de um N� FOLHA.
			 
		     No caso exclusivo da RAIZ, esta passar� a apontar pra esse elemento ("NoAtual" depois da mudan�a) sendo da Esquerda ou da
		     Direita do elemento a ser exclu�do posteriormente ("NoAtual" antes da mudan�a. Agora, na vari�vel "NoExcluido").
		     
		     OBS: O Ponteiro "NoExcluido" recebe o elemento da �rvore a ser exclu�do ANTES das opera��es do ELSE principal!
	   
	    Depois de realizadas as devidas opera��es antes da exclus�o, o elemento � finalmente eliminado da �rvore Bin�ria de Busca. O
	    antigo elemento "NoAtual" foi atribu�do ao Ponteiro "NoExcluido" pra ser poss�vel as opera��es e tamb�m pra exclus�o dar certo! */
	
	if ((!NoAtual->left) && (!NoAtual->right))
	{		
		if (NoAtual == root)						// Caso espec�fico da exclus�o da RAIZ da �rvore
		{
			root = NULL;
		}
		else										// Para todos os outros casos de exclus�o de elementos...
		{
			(NoAtual->letra < NoAncestral->letra) ? (NoAncestral->left = NULL) : (NoAncestral->right = NULL);
		}
		
		NoExcluido = NoAtual;
		printf ("\n\nA Letra [%c], que � um N� FOLHA, foi exclu�da com sucesso!", letra);
	}
	else
	{
		NoExcluido = NoAtual;
		
		if (NoAtual == root)						// Caso espec�fico da exclus�o da RAIZ da �rvore
		{
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			root = NoAtual;
		}
		else										// Para todos os outros casos de exclus�o de elementos...
		{	
			(!NoAtual->left && NoAtual->right) ? (NoAtual = NoAtual->right) : (NoAtual = NoAtual->left);
					
			(NoAtual->letra < NoAncestral->letra) ? (NoAncestral->left = NoAtual) : (NoAncestral->right = NoAtual);
		}
		printf ("\n\nA Letra [%c], que � um N� DE GRAU 1, foi exclu�da com sucesso!", letra);
	}
	free (NoExcluido);
}

void removerLetraArvoreBusca (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, char letra)
{
	struct BinaryTreeSearch *NoProfundo;
	char alce;
	
	while (NoAtual)
	{
		if (letra < NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->left;
		}
		else if (letra > NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	if (NoAtual)
	{
		if ((NoAtual->left) && (NoAtual->right))
		{
			NoAncestral = NoAtual;
			NoProfundo = NoAtual->right;
			
			printf ("\n\nA Letra [%c] � um N� DE GRAU 2 na �rvore: � achar um substituto e excluir na segunda fase...", letra);
			
			if (!NoProfundo->left)						// Caso exclusivo de car�ncia de elementos MENORES na SAD da �rvore Bin�ria
			{
				alce = NoProfundo->letra;
				NoProfundo->letra = NoAncestral->letra;
				NoAncestral->letra = alce;
				
				NoAncestral->right = NoProfundo->right;
				
				printf ("\n\nA Letra [%c] foi removida diretamente com sucesso da �rvore de Busca!", letra);
				free (NoProfundo);
			}
			else										// Casos comuns onde, geralmente, h� elementos MENORES na SAD da �rvore Bin�ria
			{
				while (NoProfundo->left)
				{
					NoAncestral = NoProfundo;
					NoProfundo = NoProfundo->left;
				}
				
				alce = NoProfundo->letra;
				NoProfundo->letra = NoAtual->letra;
				NoAtual->letra = alce;
				
				removerLetraReal (NoAncestral, NoProfundo, letra);
			}
		}
		else
		{
			removerLetraReal (NoAncestral, NoAtual, letra);
		}
	}
	else
	{
		printf ("\n\nA Letra [%c] informada n�o foi encontrada para a sua remo��o!", letra);
	}
}

struct BinaryTreeSearch *pesquisaLetraArvoreBusca (struct BinaryTreeSearch *NoAtual, char letra)
{
	while (NoAtual)
	{
		if (letra < NoAtual->letra)
		{
			NoAtual = NoAtual->left;
		}
		else if (letra > NoAtual->letra)
		{
			NoAtual = NoAtual->right;
		}
		else
		{
			break;
		}
	}
	
	if (!NoAtual)
	{
		return NULL;
	}
	else
	{
		return NoAtual;
	}
}

void ordemSimetricaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{		
		ordemSimetricaArvoreBusca (NoAtual->left);
		
		if (NoAtual->letra == root->letra)
		{
			printf ("%c", NoAtual->letra);
		}
		else if (NoAtual->letra < root->letra)
		{
			printf ("%c, ", NoAtual->letra);
		}
		else
		{
			printf (", %c", NoAtual->letra);
		}
		
		ordemSimetricaArvoreBusca (NoAtual->right);
	}
}

void preOrdemArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		if (NoAtual->letra == root->letra)
		{
			printf ("%c", NoAtual->letra);
		}
		else
		{
			printf (", %c", NoAtual->letra);
		}
		
		preOrdemArvoreBusca (NoAtual->left);
		preOrdemArvoreBusca (NoAtual->right);
	}
}

void posOrdemArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		posOrdemArvoreBusca (NoAtual->left);
		posOrdemArvoreBusca (NoAtual->right);
		
		if (NoAtual->letra == root->letra)
		{
			printf ("%c", NoAtual->letra);
		}
		else
		{
			printf ("%c, ", NoAtual->letra);
		}
	}
}

void inserirElementoArvoreBusca (struct BinaryTreeSearch *NoAncestral, struct BinaryTreeSearch *NoAtual, char letra)
{
	while (NoAtual)
	{
		if (letra < NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->left;
		}
		else if (letra > NoAtual->letra)
		{
			NoAncestral = NoAtual;
			NoAtual = NoAtual->right;
		}
		else
		{
			printf ("\n\nN�O SER�O permitidas Letras Iguais na �rvore de Busca: Letra [%c] j� presente!", letra);
			break;
		}
	}
	
	if (!NoAtual)
	{
		NoAtual = (struct BinaryTreeSearch *) malloc (sizeof (struct BinaryTreeSearch));
		NoAtual->letra = letra;
		NoAtual->left = NULL;
		NoAtual->right = NULL;
		
		if (!NoAncestral)
		{
			root = NoAtual;
			printf ("\n\nLetra [%c] foi adicionada diretamente na RAIZ da �rvore!", letra);
		}
		else
		{
			if (NoAtual->letra < NoAncestral->letra)
			{
				NoAncestral->left = NoAtual;
				printf ("\n\nLetra [%c] foi adicionada � ESQUERDA de [%c]", letra, NoAncestral->letra);
			}
			else
			{
				NoAncestral->right = NoAtual;
				printf ("\n\nLetra [%c] foi adicionada � DIREITA de [%c]", letra, NoAncestral->letra);
			}
		}
	}
}

void limpezaArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		limpezaArvoreBusca (NoAtual->left);
		limpezaArvoreBusca (NoAtual->right);
		free (NoAtual);
		_blocos++;
	}
}

void resetArvoreBusca (struct BinaryTreeSearch *NoAtual)
{
	if (NoAtual)
	{
		limpezaArvoreBusca (NoAtual);
		
		printf ("\n\nForam removidos %d Blocos de Mem�ria da �rvore de Busca!", _blocos);
		root = NULL;
		_blocos = 0;
	}
}
