/******************************************************************************
    Instituto Federal do Triângulo Mineiro - Uberlândia Centro
    Licenciatura em Computação
    3º Período (2020/1)
    Estrutura de Dados - Clarimundo
    Alisson Fernandes de Paula
Lista 1 - Exercício 1
#IF.LC.3P.ED.L1.E1
Programa que exibe um menu (1-Cadastrar; 2-Excluir; 3-Exibir; 4-Sair; Escolha a
opção:), utilizando struct no cadastro (nome, rua, numero).
*******************************************************************************/

/*#####     IMPORTAÇÕES     #####*/

	//#include <stdio.h>
	#include <locale.h>
	#include <stdlib.h>
	#include <unistd.h>
	//#include <iostream>
	#include <cstring>
	#include <cstdio>

/*#####     FIM IMPORTAÇÕES     #####*/


/*#####     ESTRUTURAS     #####*/

	typedef struct Cadastrar { //===> Estrutura para cadastrar
		char nome[30];
		//string nome[30];
		char rua[50];
		//string rua[50];
		int numero;
	} Cadastrar; //===> FIM Estrutura para cadastrar
		
	Cadastrar cadastro; //===> Variável do tipo Cadastrar

/*#####     FIM ESTRUTURAS     #####*/


/*#####     FUNÇÕES     #####*/

	void confLingua() { //===> Função para língua portuguesa
		setlocale (LC_ALL,"portuguese");
		//setlinebuf(stdout);
		//setbuf(stdout, NULL);
	} //===> FIM Função para língua portuguesa
	
	void limparTela() { //===> Função para limpar a tela
		
		#ifdef __linux__
			system ("clear");
			//printf("\e[H\e[2J");
			//printf("\n\nSistema Operarional Linux/Unix.\n\n");
		
		#elif _WIN32
			system("cls");
			//printf("\n\nSistema Operacional Windows.\n\n");
		
		#else
	        printf("\n\nSistema Operacional não identificado.\n\n");
			fflush(stdout);
		#endif
	} //===>  FIM Função para limpar a tela
	
	void pausar() { //===> Função para pausar
		
		#ifdef __linux__
			system("read -p 'Press Enter to continue...' var");
			//printf("\n\nSistema Operarional Linux/Unix.\n\n");
		
		#elif _WIN32
			system("pause");
			//printf("\n\nSistema Operacional Windows.\n\n");
		
		#else
			printf("\n\nSistema Operacional não identificado.\n\n");
			fflush(stdout);
		#endif
		
	} //===> FIM Função para pausar
	
	void cadastrar() { //===> Função para cadastrar
		
		limparTela();
		
		printf("\n\n\tDigite o nome a ser cadastrado...:\t");
		fflush(stdout);
		scanf("%s", cadastro.nome);
		
		printf("\n\tDigite a rua.....................:\t");
		fflush(stdout);
		scanf("%s", cadastro.rua);
		
		printf("\n\tDigite o número..................:\t");
		fflush(stdout);
		scanf("%d", &cadastro.numero);
		
		limparTela();
		printf("\n\n\t\tCadastrado com sucesso.\n\n");
		fflush(stdout);
		sleep(1);
		limparTela();
		
	} //===> FIM Função para cadastrar
	
	void excluir(void) { //===> Função para excluir
		
		limparTela();
		printf("\n\n\t\tExcluindo...");
		fflush(stdout);
		sleep(1);
		
		strcpy(cadastro.nome, "");
		strcpy(cadastro.rua, "");
		cadastro.numero = 0;
		
		limparTela();
		printf("\n\n\t\tExcluído com sucesso.");
		fflush(stdout);
		sleep(1);
		limparTela();
		
	} //===> FIM Função para excluir
	
	void exibir() { //===> Função para exibir
		
		limparTela();
		
		printf("\n\n\tNome.......:\t%s", cadastro.nome);
		fflush(stdout);
		printf("\n\tEndereço...:\t%s, %d\n\n", cadastro.rua, cadastro.numero);
		fflush(stdout);
		
		pausar();
		limparTela();
		
	} //===> FIM Função para exibir
	
	void sair() { //===> Função para sair
		limparTela();
		printf("\n\n\t\tSaindo...\n\n");
		fflush(stdout);
		sleep(1);
	} //===> FIM Função para sair
	
	void invalida() { //===> Função para opção inválida
		limparTela();
		printf("\n\n\t\tOpção inválida, tente novamente.");
		fflush(stdout);
		sleep(2);
		limparTela();
	} //===> FiM Função para opção inválida
	
	void menu() { //===> Função para o menu
		
		int opcao;
		do {
			printf("\n\tDigite a opção desejada:");
			printf("\n\t\t1 - Cadastrar");
			printf("\n\t\t2 - Excluir");
			printf("\n\t\t3 - Exibir");
			printf("\n\t\t4 - Sair");
			printf("\n\n\tOpção: ");
			fflush(stdout);
			scanf("%d", &opcao);
			
			switch(opcao) {
				case 1:
					cadastrar();
					break;
				case 2:
					excluir();
					break;
				case 3:
					exibir();
					break;
				case 4:
					sair();
					break;
				default:
					invalida();
					break;
			}
		} while(opcao != 4);
	} //===> FIM Função para o menu


/*#####     FIM FUNÇÕES     #####*/


/*#####     PROGRAMA PRINCIPAL     #####*/

	int main() { //===> Função principal
		
		limparTela();
		
		confLingua();
		
		menu();
		
		limparTela();
		
		return 0;
		
	} //===> FIM Função principal

/*#####     FIM PROGRAMA PRINCIPAL     #####*/

