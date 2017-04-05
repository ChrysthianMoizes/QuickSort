#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct subTerra
{
	char nome[30];
	float densidade;
	float visao;
};

void swap(subTerra *a, subTerra *b) {
	subTerra tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int comparar(subTerra *v, int ini, int fim) {
	subTerra aux;
	aux = v[ini];

	if (strcmp(aux.nome, v[fim].nome) < 0) {
		return -1;
	}
	else if (strcmp(aux.nome, v[fim].nome) == 0) {
		if (aux.densidade == v[fim].densidade) {
			if (aux.visao < v[fim].visao) {
				return -1;
			}			
		}else if (aux.densidade < v[fim].densidade) {
			return -1;
		}
		else {
			return 1;
		}
		return 1;
	}
	return 1;
}

int particao(subTerra *vetor, int inicio, int fim) {
	subTerra pivo;
	pivo = vetor[inicio];
	int i = inicio + 1, f = fim;
	while (i <= f) {		
		if (comparar(vetor,i, inicio) == -1) {
			i++;
		}		
		else if (comparar(vetor,inicio ,fim) == -1) {
			f--;
		}	
		else
		{			
			swap(&vetor[i], &vetor[f]);
			i++;
			f--;						
		}
	}
	vetor[inicio] = vetor[f];
	vetor[f] = pivo;
	return f;
}

void quickSort(subTerra *v, int ini, int fim) {
	int meio;
	if (ini < fim) {
		meio = particao(v, ini, fim);
		quickSort(v, ini, meio);
		quickSort(v, meio + 1, fim);
	}
}

int main() {

	struct subTerra sub[7];
	int i, tam = 7;

	strcpy(sub[0].nome, "Cratos\0");
	sub[0].densidade = (float)30.2;
	sub[0].visao = (float)16;

	strcpy(sub[1].nome, "Alis\0");
	sub[1].densidade = (float)23.5;
	sub[1].visao = (float)32;

	strcpy(sub[2].nome, "Harry\0");
	sub[2].densidade = (float)20.3;
	sub[2].visao = (float)8;

	strcpy(sub[3].nome, "Trynda\0");
	sub[3].densidade = (float)3;
	sub[3].visao = (float)64;

	strcpy(sub[6].nome, "Amumu\0");
	sub[6].densidade = (float)29;
	sub[6].visao = (float)128;

	strcpy(sub[5].nome, "Harry\0");
	sub[5].densidade = (float)23.3;
	sub[5].visao = (float)9;

	strcpy(sub[4].nome, "Jung\0");
	sub[4].densidade = (float)23.3;
	sub[4].visao = (float)3;

	quickSort(sub, 0, 6);
	for (i = 0; i < tam; i++) {
		printf("Nome: %s \n", sub[i].nome);
		printf("Densidade de Escuridao: %f \n", sub[i].densidade);
		printf("Visao: %f \n \n", sub[i].visao);
	}
	getchar();

	return 0;
}
