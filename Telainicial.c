#include <stdio.h> // Comunica��o com o usu�rio.
#include <stdlib.h> // Aloca��o em espa�o de mem�ria.
#include <locale.h> // Aloca��o de texto por regi�o.
#include <string.h> // Respons�vel pelas strings.
#include <stdbool.h> // Armazena os bools.


	// ========================================================
	
	int registro() //FUN��O DE REGISTRO.
	{ 
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
		// Cria��o das vari�veis.
		char arquivo[40]; 
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo [40];
		char confirmar [40];
		int loop = 1; 
	
		//----
		
		while (loop) // Come�o do loop.
		{
		
			printf("\n\tVoc� escolheu a op��o de registro!\n");
	
			printf("\n\tDigite o CPF que deseja registrar: "); // CPF.
			scanf("%s", cpf);
		
			strcpy(arquivo, cpf); // Copia os valores das strings.
	
			FILE *file; // Cria o arquivo no banco de dados.
			file = fopen(arquivo, "w"); // Cria o arquivo e escreve com o "W".
			fprintf(file, cpf); // Salva o valor da vari�vel.
			fclose(file); // Fecha o arquivo.
	
			file = fopen(arquivo,"a"); // V�rgula.
			fprintf(file,", ");
			fclose(file); // Fecha o arquivo.
	
	
			//----
			printf("\tDigite o nome que deseja registrar: "); // Nome.
			scanf("%s", nome);
	
			file = fopen(arquivo,"a");
			fprintf(file,nome);
			fclose(file); // Fecha o arquivo.
	
	
			//----
			file = fopen(arquivo,"a"); // V�rgula.
			fprintf(file,", ");
			fclose(file); // Fecha o arquivo.
	
	
			//----
			printf("\tDigite o sobrenome que deseja registrar: "); // Sobrenome.
			scanf("%s", sobrenome);
		
			file = fopen(arquivo,"a");
			fprintf(file,sobrenome);
			fclose(file); // Fecha o arquivo.
	
	
			//----
			file = fopen(arquivo,"a"); // V�rgula.
			fprintf(file,", ");
			fclose(file); // Fecha o arquivo.
		
	
			//----
			printf("\tDigite o cargo que deseja registrar: "); // Cargo.
			scanf("%s",cargo);
			printf("\n\n");
			
		
	
			file = fopen(arquivo,"a");
			fprintf(file,cargo);
			fclose(file); // Fecha o aqruivo.
	
	
			//---- REGISTRAR MAIS USU�RIOS.
			printf("\tDeseja registrar mais usu�rios?\n");
			printf("\tDigite 'sim' para registrar e 'n�o' para voltar ao menu: ");
		
			scanf("%s", confirmar); // L� o "sim".
		
			if (strcmp(confirmar, "sim") == 0 || strcmp(confirmar, "Sim") == 0) { // Confirma a escolha.
			
				loop = 1; // Volta pro loop.
				system("cls"); // Limpa a tela.
			
			}
			 	
			else { // Se n�o o loop � quebrado.
				
				printf("\n\n\t");
				loop = 0;	
				
			}
			
		}
		
		system("pause"); // Pausa a tela do registro.
	
	}
	
	// ========================================================
	
	int consulta() //FUN��O DE CONSULTA.
	{ 
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
		printf("\n\tVoc� escolheu consultar um nome!\n");
	
		// Cria��o das vari�veis.
		char cpf[40];
		char conteudo[250];
		char confirmar[40];
		int loop = 1;
		
		while (loop) // Come�o do loop;
		{
		
	
			printf("\n\tDigite o CPF a ser consultado: "); // CPF.
			scanf("%s",cpf); // "%s" Armazena a string.
	
			FILE *file; // Cria o arquivo no banco de dados.
			file = fopen(cpf,"r");
	
			//----
		
			if(file == NULL){ // Caso o nome consultado n�o exista.
	 
				printf("\n\tArquivo n�o localizado!\n");
		
			}
		
		
			while(fgets(conteudo,250, file) != NULL ) // Buscando informa��es.
			{
			
				printf("\n\tEssas s�o as informa��es do usu�rio:\n ");
				printf("\tCPF, Nome, Sobrenome e Cargo: %s",conteudo);
				printf("\n\n");
			
			}
		
			//----
		
			fclose(file); // Fecha o arquivo ap�s ler.
			
			
			//---- CONSULTAR MAIS USU�RIOS.
			printf("\tDeseja consultar mais usu�rios?\n");
			printf("\tDigite 'sim' para consultar e 'n�o' para voltar ao menu: ");
		
			scanf("%s", confirmar); // L� o "sim".
		
			if (strcmp(confirmar, "sim") == 0 || strcmp(confirmar, "Sim") == 0) { // Confirma a escolha.
			
				loop = 1; // Volta pro loop.
				system("cls"); // Limpa a tela.
			
			}
			 	
			else { // Se n�o o loop � quebrado.
				
				printf("\n\n\t");
				loop = 0;	
				
			}
		}
		
		system("pause"); // Pausa a tela da consulta.
	
	}
	
	// ========================================================
	
	int deletar(){ //FUN��O DE DELETAR.
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
			
		printf("\n\tVoc� escolheu deletar um nome.\n");
		
		// Cria��o das vari�veis.
		char cpf[40]; 
		char confirmacao[30]; // Armazena a confirma��o.
		bool confirme = false;
		char confirmar[40]; // Confirma��o do loop.
		int loop = 1;
		
		
		while (loop) 
		{
		
			printf("\n\tDigite o CPF a ser deletado: "); // Digite pra deletar.
			scanf("%s", cpf);
		
			printf("\n\tDigite 'confirmar' ou 'negar': ");
			scanf("%s", confirmacao); // Registra a string de confirmar.
		
			if (strcmp(confirmacao, "confirmar") == 0 || strcmp(confirmacao, "Confirmar") == 0 ) { //Confirma a escolha.
			
        		confirme = true;
    		}
    	
    		//----
    	
    		if (confirme == true){ // Se confirmar for digitado.
    		
    		
    			if(remove(cpf) == 0){ // CPF sendo removido.
    			
    			printf("\n\tConfirma��o recebida. Deletando usu�rio.");
    			printf("\n\n");
    		
    			
				}
    		
    			FILE *file;
    			file = fopen(cpf, "r");
    		
    			if(file == NULL){ // Se o arquivo n�o for encontrado.
    		
    			printf("\n\tO usu�rio n�o se encontra no sistema.\n"); // Mensagem de n�o se encontra no sistema.
    			
				}
			
    		} 	
		
			else {
			
        		printf("\n\tA��o cancelada pelo usu�rio.\n"); // Texto de cancelar a a��o.
        		printf("\n\n");
        	
    		}
    		
    		
    		//---- DELETAR MAIS USU�RIOS.
			printf("\n\tDeseja deletar mais usu�rios?\n");
			printf("\tDigite 'sim' para deletar e 'n�o' para voltar ao menu: ");
		
			scanf("%s", confirmar); // L� o "sim".
		
			if (strcmp(confirmar, "sim") == 0 || strcmp(confirmar, "Sim") == 0) { // Confirma a escolha.
			
				loop = 1; // Volta pro loop.
				system("cls"); // Limpa a tela.
			
			}
			 	
			else { // Se n�o o loop � quebrado.
				
				printf("\n\n\t");
				loop = 0;	
    		
    		}	
    	}
    	
		system("pause"); // Pausa do "delete."
		
	}
		

	// =========================================================!
	
	
int main() // Tela inicial.
{ 				
	
	setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
	// Cria��o das vari�veis.
	int escolha = 0;
	int comparacao;
	int loop = 1; 
	char senha[] ="a";
	
	
	printf("\n\n        --- Cart�rio da EBAC ---\n\n "); // Senha pra acesso.
	printf("\n\t Login de administrador.");
	printf("\n\t Digite sua senha: ");
	
	scanf("%s", senha); // L� a compara��o abaixo.
	comparacao = strcmp(senha,"admin");
	if(comparacao == 0 ) // Concede acesso se a compara��o for certa.
	{
	
	
	
	
			for(loop=1;loop=1;) // Loop da tela.
		{
		
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); // Definindo a lingua.
	
				printf("\n\n        --- Cart�rio da EBAC ---\n\n ");  // Come�o da interface do Menu.
				printf("\n    Escolha a op��o desejada do menu:\n\n");
	
				printf("\t 1 - Registrar nomes.\n");
				printf("\t 2 - Consultar nomes.\n");
				printf("\t 3 - Deletar nomes.\n\n ");
				printf("\t 4 - Sair do sistema.\n\n ");
				printf("\t N�mero de escolha: ");		// Fim da interface do Menu.
	
	
			scanf("%d",&escolha); // Armazena o n�mero e permite a escolha.
			system("cls"); // Limpa a tela.
	
			// Come�o da interface de sele��o. 
			switch(escolha){
			
				case 1: // Registrar nomes.
				registro();
				break;
			
				case 2: // Consultar nomes.
				consulta();
				break;
			
				case 3: // Apagar nomes.
				deletar();
				break;
			
				case 4: // Sair do sistema.
				printf("\n\tEncerrando o sistema!\n");
				return 0;
				break;
			
				default: //Op��o acima de 3 ou abaixo de 1: N�o dispon�veis.
				printf("\n\t Essa op��o n�o existe.\n");
				system("pause");
				break;
			
			}// Fim da interface de sele��o.
		}
	
	} 
	
	else
	printf("\n\t Senha incorreta!\n\n");
	
}	
	
	
