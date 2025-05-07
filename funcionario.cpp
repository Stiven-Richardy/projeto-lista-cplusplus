#include <iostream>

using namespace std;

struct Funcionario {
	int prontuario;
	string nome;
	double salario;
};

struct Lista {
	Funcionario *funcionario;
	Lista *ant;
};

Lista* init() {
	return NULL;
}

bool isEmpty(Lista* lista) {
	return (lista == NULL);
}

Lista* insert(Funcionario* funcionario, Lista* listaFuncionario) {
	Lista* novoFuncionario = new Lista();
	
	novoFuncionario->funcionario = funcionario;
	novoFuncionario->ant = listaFuncionario;
	
	return novoFuncionario;
}

Lista* find(int prontuario, Lista* lista) {
    Lista* aux;
	aux = lista;
	
	while (aux != NULL && aux->funcionario->prontuario != prontuario) {
		aux = aux->ant;
	}
	
	return aux;
}

Lista* remove(int prontuario, Lista* lista) {
	Lista* aux;
	Lista* apoio = NULL;
	aux = lista;
	
	while(aux != NULL && aux->funcionario->prontuario != prontuario) {
		apoio = aux;
		aux = aux->ant;
	}
	
	if(aux == NULL) {
		return lista;
	}
	
	if(apoio == NULL) {
		lista = aux->ant;
	} else {
		apoio->ant = aux->ant;
	}
	
	free(aux);
	return lista;
}

void print(Lista* lista) {
	Lista* aux;
	aux = lista;
	double total = 0;
	cout << "-----------" << endl;
	
	while(aux != NULL)
	{
		cout << "| Prontuario: " << aux->funcionario->prontuario << endl
 	 	 	 << "| Nome: " << aux->funcionario->nome << endl
		 	 << "| R$: " << aux->funcionario->salario << endl;
        total += aux->funcionario->salario;
		aux = aux->ant;
	}
	cout << "Total: " << total << endl;
	cout << "-----------" << endl;
}

int main(int argc, char** argv) {
	Lista *listaFuncionario;
	listaFuncionario = init();
		
	int opcao;
	while(opcao != 0) {
		cout << "Selecione a opcao: ";
		cin >> opcao;
		
		int prontuario;
		switch(opcao) {
			case 0: {
				cout << "Programa finalizado!" << endl;
				break;
			}
			case 1: {
				string nome;
				double salario;
	
				cout << "Digite o prontuario: ";
				cin >> prontuario;
	
				while(find(prontuario, listaFuncionario) != NULL) {
					cout << "Erro! Tente novamente: ";
					cin >> prontuario;
				}
				cin.ignore();
	
				cout << "Digite o nome: ";
				getline(cin, nome);
		
				cout << "Digite o salario: ";
				cin >> salario;
				cin.ignore();
				
				Funcionario* criar = new Funcionario;
				criar->prontuario = prontuario;
				criar->nome = nome;
				criar->salario = salario;
				
				listaFuncionario = insert(criar, listaFuncionario);
				cout << "Funcionario cadastrado" << endl;	
				break;
			}
			case 2: {
				cout << "Digite o prontuario: ";
				cin >> prontuario;
				cin.ignore();
				
				if(find(prontuario, listaFuncionario) == NULL) {
					cout << "Erro!" << endl;
				} else {
					listaFuncionario = remove(prontuario, listaFuncionario);
					cout << "Funcionario removido" << endl;	
				}
				break;
			}
			case 3: {
				cout << "Digite o prontuario: ";
				cin >> prontuario;
				cin.ignore();
				
				Lista* pesquisar = find(prontuario, listaFuncionario);
				
				if(pesquisar == NULL) {
					cout << "Erro!" << endl;
				} else {
					cout << "| Prontuario: " << pesquisar->funcionario->prontuario << endl
 	 	 	 	 	 	 << "| Nome: " << pesquisar->funcionario->nome << endl
		 	 	 	 	 << "| R$: " << pesquisar->funcionario->salario << endl;
				}
				break;
			}
			case 4:{
				print(listaFuncionario);
				break;
			}
			default:
				cout << "Opcao invalida!" << endl;
		}
	}
	
	return 0;
}