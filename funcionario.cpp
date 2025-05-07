#include <iostream>
#include <locale.h>
#include <string>
#include <conio.h>

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
	
	while(aux != NULL)
	{
		cout << "| Prontuário: " << aux->funcionario->prontuario << endl
 	 	 	 << "| Nome: " << aux->funcionario->nome << endl
		 	 << "| Salário: R$" << aux->funcionario->salario << endl
			 << string(37, '-') << endl;
        total += aux->funcionario->salario;
		aux = aux->ant;
	}
	
	cout << "Total: R$" << total << endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	Lista *listaFuncionario;
	listaFuncionario = init();
	
	cout << string(37, '=') << endl
	 	 << string(8, ' ') << "BANCO DE FUNCIONÁRIOS" << endl
       	 << string(37, '=') << endl
       	 << "| Bem-vindo ao banco de funcionários \n| da Stiven's Company." << endl
		 << string(37, '=') << endl
		 << "Pressione qualquer tecla..." << endl;
	_getch();
	system("cls");
	
	int opcao;
	while(opcao != 0) {
		cout << string(37, '=') << endl
			<< string(8, ' ') << "BANCO DE FUNCIONÁRIOS" << endl
			<< string(37, '=') << endl
			<< "| Selecione a opção desejada: \n| 0. Sair \n| 1. Incluir \n| 2. Remover \n| 3. Pesquisar \n| 4. Listar" << endl
			<< string(37, '=') << endl
			<< "Digite o número da opção: ";
		cin >> opcao;
		
		while(opcao < 0 || opcao > 4) {
			cout << "Opção inválida! Digite novamente: ";
			cin >> opcao;
		}
				
		int prontuario;
		Lista* pesquisar;
		switch(opcao) {
			case 0: {
				system("cls");
				
				cout << string(37, '=') << endl
	 	 	 	 	 << string(8, ' ') << "BANCO DE FUNCIONÁRIOS" << endl
       	 	 	 	 << string(37, '=') << endl
					 << "| Programa finalizado." << endl
					 << string(37, '=') << endl;
					 
				break;
			}
			case 1: {
				system("cls");
				
				string nome;
				double salario;
	
				cout << string(37, '=') << endl
	 	 	 	 	 << string(8, ' ') << "CADASTRAR FUNCIONÁRIO" << endl
       	 	 	 	 << string(37, '=') << endl
					 << "| Digite o prontuário: ";
				cin >> prontuario;
	
				while(find(prontuario, listaFuncionario) != NULL) {
					cout << "| Prontuário em uso, digite novamente: ";
					cin >> prontuario;
				}
				cin.ignore();
	
				cout << "| Digite o nome: ";
				getline(cin, nome);
		
				cout << "| Digite o salario: ";
				cin >> salario;
				cin.ignore();
				
				Funcionario* criar = new Funcionario;
				criar->prontuario = prontuario;
				criar->nome = nome;
				criar->salario = salario;
				
				listaFuncionario = insert(criar, listaFuncionario);
				cout << "| Funcionario cadastrado." << endl
				     << string(37, '=') << endl
				     << "Pressione qualquer tecla..." << endl;
				_getch();
				
				system("cls");	
				break;
			}
			case 2: {
				system("cls");
				
				cout << string(37, '=') << endl
	 	 	 	 	 << string(9, ' ') << "REMOVER FUNCIONÁRIO" << endl
       	 	 	 	 << string(37, '=') << endl
       	 	 	 	 << "| Digite o prontuário: ";
				cin >> prontuario;
				cin.ignore();
				
				pesquisar = find(prontuario, listaFuncionario);
				if(pesquisar == NULL) {
					cout << "| Prontuário não encontrado." << endl;
				} else {
					listaFuncionario = remove(prontuario, listaFuncionario);
					cout << "| Prontuário: " << pesquisar->funcionario->prontuario << endl
						 << "| Nome: " << pesquisar->funcionario->nome << endl
						 << "| Funcionário removido." << endl;	
				}
				cout << string(37, '=') << endl
				     << "Pressione qualquer tecla..." << endl;
				_getch();
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				
				cout << string(37, '=') << endl
	 	 	 	 	 << string(8, ' ') << "PESQUISAR FUNCIONÁRIO" << endl
       	 	 	 	 << string(37, '=') << endl
					 << "| Digite o prontuario: ";
				cin >> prontuario;
				cin.ignore();
				
				pesquisar = find(prontuario, listaFuncionario);
				if(pesquisar == NULL) {
					cout << "| Prontuário não encontrado." << endl;
				} else {
					cout << "| Prontuário: " << pesquisar->funcionario->prontuario << endl
						 << "| Nome: " << pesquisar->funcionario->nome << endl
						 << "| Salário: " << pesquisar->funcionario->salario << endl;
				}
				
				cout << string(37, '=') << endl
				     << "Pressione qualquer tecla..." << endl;
				_getch();
				
				system("cls");
				break;
			}
			case 4:{
				system("cls");

				cout << string(37, '=') << endl
	 	 	 	 	 << string(8, ' ') << "LISTA DE FUNCIONÁRIOS" << endl
       	 	 	 	 << string(37, '=') << endl;
				print(listaFuncionario);
				cout << string(37, '=') << endl
					 << "Pressione qualquer tecla..." << endl;
				_getch();
				
				system("cls");
				break;
			}
		}
	}
	
	return 0;
}
