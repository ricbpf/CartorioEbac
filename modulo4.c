#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de recursos de memomria
#include <locale.h> // biblioteca de alocação de texto por regi~]ap
#include <string.h>  // biblioteca responsável por cuidar da string

int registrar() // função responsável por cadastro os usuários no sistema
{
	// inicio da criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser registrado "); //Responsável por copiar os valores da string. 
	scanf("%s", cpf); // Salvando na variável string %s refere-se o string.
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo, "w"); // cria o arquivo e "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variável.
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); // Varrer tudo o usuário e salvar onde o usuário pedir.
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema\n");
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
		printf("Não foi possivel abrir o arquivo, não localizado");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int erro()
{
	printf("Você errou a opção!");
	system("pause");
}

int main()
	{	
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");
	
		printf("Qual menu você deseja:\n\n");
		printf("\t1 - Deseja remover o nome\n");
		printf("\t2 - Deseja consultar o nome\n");
		printf("\t3 - Deseja registrar o nome\n\n");
		printf("Digite a opção desejada:");
	
		scanf("%d", &opcao);
	
		system("cls"); //responsável por limpar a tela.
	
	switch(opcao) //inicio da seleção do menu
		{
			case 1:
			remover() ; //chamada de função.
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
		} //fim da seleção
	}
	}
	

