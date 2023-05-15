#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de recursos de memomria
#include <locale.h> // biblioteca de aloca��o de texto por regi~]ap
#include <string.h>  // biblioteca respons�vel por cuidar da string

int registrar() // fun��o respons�vel por cadastro os usu�rios no sistema
{
	// inicio da cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser registrado "); //Respons�vel por copiar os valores da string. 
	scanf("%s", cpf); // Salvando na vari�vel string %s refere-se o string.
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); // salvo o valor da vari�vel.
	fclose(file); // fecha o aqruivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser registrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser registrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser registrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int remover()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); // Varrer tudo o usu�rio e salvar onde o usu�rio pedir.
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema\n");
		system("pause");
	}	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int erro()
{
	printf("Voc� errou a op��o!");
	system("pause");
}

int main()
	{	
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");
	
		printf("Qual menu voc� deseja:\n\n");
		printf("\t1 - Deseja remover o nome\n");
		printf("\t2 - Deseja consultar o nome\n");
		printf("\t3 - Deseja registrar o nome\n\n");
		printf("Digite a op��o desejada:");
	
		scanf("%d", &opcao);
	
		system("cls"); //respons�vel por limpar a tela.
	
	switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			remover() ; //chamada de fun��o.
			break;
		
			case 2:
			consultar(); //
			break;
		
			case 3:
			registrar();
			break;
		
			default:
			erro();
			break;	
		} //fim da sele��o
	}
	}
	

