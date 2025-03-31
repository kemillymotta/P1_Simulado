#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void removerElemento();
void buscarElemento();
void exibirMenorValor();

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 8) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada - P1";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Inserir elemento \n";
		cout << "5 - Remover elemento \n";
		cout << "6 - Buscar elemento \n";
		cout << "7 - Exibir menor valor \n";
		cout << "8 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4:  inserirElemento();
			break;
		case 5:  removerElemento();
			break;
		case 6:
			buscarElemento();
			break;

		case 7:
			exibirMenorValor();
			return;
		default:
			break;
		}
		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada

	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	// solicita o valor do novo elemento
	cout << "Digite o valor do novo elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	// verifica se o elemento já existe na lista
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == novo->valor) {
			cout << "Elemento duplicado \n";
			free(novo);
			return;
		}
		aux = aux->prox;
	}

	// insere o novo elemento no final da lista
	if (primeiro == NULL) {
		primeiro = novo;
	}
	else {
		aux = primeiro;
		while (aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = novo;
	}

	cout << "Elemento inserido \n";
}

void removerElemento() {
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	int valor;
	cout << "Digite o valor do elemento a ser removido: ";
	cin >> valor;
	NO* aux = primeiro;
	NO* anterior = NULL;
	while (aux != NULL) {
		if (aux->valor == valor) {
			if (anterior == NULL) {
				primeiro = aux->prox;
			}
			else {
				anterior->prox = aux->prox;
			}
			free(aux);
			cout << "Elemento removido \n";
			return;
		}
		anterior = aux;
		aux = aux->prox;
	}
	cout << "Elemento nao encontrado \n";
}

void buscarElemento()
{


}

void exibirMenorValor()
{

}
