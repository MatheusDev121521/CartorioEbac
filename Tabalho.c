#include <stdio.h>     //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>     //biblioteca de aloca��o de espa�o de mem�ria
#include <string.h>     //biblioteca respons�vel por cuidar da stings
#include <locale.h>     //biblioteca de aloca��es de texto por regi�o

int criar() //fun��o de registro de usu�rio
{
	//in�cio cria��o de vari�veis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//final de cria��o de vari�veis/string
	
	printf("\t_~Digite abaixo o CPF a ser cadastrado~_\n\n"); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,", "); //pula uma linha no arquivo
	fclose(file); //fecha o arquivo
	
	printf("\t_~Digite abaixo o nome a ser cadastrado~_\n\n"); //coletando informa��o do usu�rio
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualiza do arquivo
	fprintf(file,nome); //salva as letras da v�riavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file," "); //d� um espa�o no arquivo
	fclose(file); //fecha o arquivo
	
	printf("\t_~Digite abaixo o sobrenome a ser cadastrado~_\n"); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //ativando a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome); //salva as letras da vari�vel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,", "); //cria uma "," no arquivo com espa�o
	fclose(file); //fecha arquivo
	
	printf("\t_~Digite abaixo o cargo a ser cadastrado~_\n"); //coletando informa��es do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,cargo); //salva as letras da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //avisa o Sistema Operacional para pausar
}



int consultar() //fun��o de consulta sobre algum usu�rio
{
	
	setlocale(LC_ALL, "Portuguese"); //Avisa que os textos(printf) v�o estar em portugu�s
	
	//in�cio cria��o de vari�veis/string
	char cpf[50];
	char conteudo[200];
	//final da cria��o de vari�veis/string
	
	printf("\t_~Digite o CPF para consultar~_\n"); //coletando informa��es do usu�rio
	scanf("%s", cpf);

	FILE *file; //Avisa que deve entrar na biblioteca arquivos
	file = fopen(cpf, "r"); //Abrir aquivo e ler("r")
	
	//In�cio condi��o quando arquivo � nulo
	if(file == NULL)
	{
		printf("\tN�o encontramos o arquivo!.\n");
	} 
	//fim de condi��o quando arquivo � nulo
	
	//In�cio condi��o quando arquivo n�o � nulo
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\t_~Essas s�o as informa��es do usu�rio~_\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	//fim de condi��o quando arquivo � n�o � nulo
	
	system("pause"); //avisa o Sistema Operacional para pausar
	
}


int excluir() //fun��o de excluir algum usu�rio
{
	char cpf[50]; //vari�vel/string
	
	printf("\t_~Exclua um usu�rio digitando o CPF dele abaixo~_\n\n"); //coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	remove(cpf); //removendo registro
	
	FILE *file; //abrindo arquivo
	file = fopen(cpf, "r"); //lendo arquivo
	
	if(file == NULL)
	{
		printf("\tO usu�rio j� n�o se encontra no sistema ou n�o existe!\n\n"); //coletando informa��es do usu�rio
		system("pause"); //avisa o Sistema Operacional para pausar
	}


}


int main() //fun��o de in�cio de programa
{
	int opcao=0; //armazenar a escolha do usu�rio
	int laco=1; //vari�vel para loop de site
	
	for(laco=1;laco=1;) //loop do site
	{
		system("cls"); //excluir as mensagens anteriores
	
		setlocale(LC_ALL, "Portuguese");  //definir l�ngua
		
		//In�cio do Menu
		printf("\t_~Registros da EBAC~_\n\n\n");
		printf("Digite o n�mero de uma das op��es abaixo:\n\n");
		printf("\t1 - Criar usu�rio\n");
		printf("\t2 - Consultar usu�rios\n");
		printf("\t3 - Excluir usu�rio\n\n");
		printf("Op��o: "); 
		//Fim do Menu
	
		scanf("%d", &opcao); //Escanear a escolha o usu�rio e mandar ela para a vari�vel
	
		system("cls"); //Limpando as mensagens anteriores
			
			
		switch(opcao) //in�cio da sele��o
		{
			case 1:
			criar(); //direcionar para fun��o
			break;
				
			case 2:
			consultar(); //direcionar para fun��o			
			break;
				
			case 3:
			excluir(); //direcionar para fun��o
			break;
			
			default:
			printf("Esse n�mero n�o est� na lista!\n\n"); //caso coloque algum n�mero diferente do que aparece nas escolhas do menu
			system("pause"); //avisa o Sistema Operacional para pausar
			break;
			
		} //fim da sele��o
		

	} //fim do loop

}
