#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
void limpartela() {
	system ("pause");
	system ("cls");
}
int main () {
	setlocale(LC_ALL, "Portuguese");
	char usuario [50];
	char senha [50];
	char cadastro_usuario [50];
	char cadastro_senha [50];
	int menu;
	int i, j;
	int quantidade_alunos = 0;
	char aluno [100][50];
	char cpf [100][15];
	char data [100][15];
	char gmail [100][254];
	float peso [100];
	float altura [100];
	int objetivo [100];
	char objetivo_texto [100][50];
	char buscar_aluno[50];
	int encontrado = 0;
	int num_exercicio[100];
	char exercicio[100][20][50];
	int series[100][20];
	int repeticoes[100][20];

	//cadastrar o usuario
	printf ("=== Cadastro ===\n");
	printf ("Crie um usuário: ");
	fgets  (cadastro_usuario,50,stdin);
	cadastro_usuario[strcspn(cadastro_usuario,"\n")] = 0;
	printf ("Crie uma senha: ");
	fgets  (cadastro_senha,50,stdin);
	cadastro_senha[strcspn(cadastro_senha,"\n")] = 0;
	printf ("Cadastro realizado com sucesso!\n");
	system ("cls");
	do {
		//login
		printf ("=== Login ===\n");
		printf ("Usuário: ");
		fgets  (usuario,50,stdin);
		usuario[strcspn(usuario,"\n")] = 0;
		printf ("Senha: ");
		fgets  (senha,50,stdin);
		senha[strcspn(senha,"\n")] = 0;
		if (strcmp (usuario,cadastro_usuario) == 0 && strcmp (senha,cadastro_senha) == 0) {
			printf ("Login realizado!\n");
		} else {
			printf ("Usuário ou senha incorretos!\n");
			limpartela();
		}
	} while(strcmp(usuario,cadastro_usuario)!=0 || strcmp(senha,cadastro_senha)!=0);
	do {
		// MENU
		printf ("=== Menu ===\n");
		printf ("1- Cadastrar aluno \n");
		printf ("2- Lista de alunos \n");
		printf ("3- Buscar aluno \n");
		printf ("4- Criar treino \n");
		printf ("5- Ver treino do aluno\n");
		printf ("6- Sair\n");
		scanf ("%d", &menu);
		getchar();
		switch (menu) {
			case 1:
				i = quantidade_alunos;
				if (quantidade_alunos >= 100) {
					printf ("Limite de alunos atingido!\n");
				} else {
					printf ("=== Cadastrar Aluno ===\n");
					//nome
					printf ("Informe o nome do aluno:");
					fgets (aluno[i],50,stdin);
					aluno[i] [strcspn (aluno[i], "\n")] = 0;
					//CPF
					printf ("Informe seu CPF: ");
					fgets (cpf[i],15,stdin);
					cpf[i] [strcspn (cpf [i],"\n")] = 0;
					//data
					printf ("Informe a data de nascimento: ");
					fgets (data[i],15,stdin);
					data[i] [strcspn (data[i], "\n")] = 0;
					//gmail
					printf ("Informe seu Gmail: ");
					fgets (gmail[i],254,stdin);
					gmail[i] [strcspn (gmail[i], "\n")] = 0;
					//peso
					printf ("Informe seu peso: ");
					scanf ("%f",&peso[i]);
					getchar();
					//altura
					printf ("Informe sua altura: ");
					scanf ("%f", &altura[i]);
					getchar();
					//objetivo
					printf ("Informe seu objetivo: \n");
					printf ("1- Perder Peso \n");
					printf ("2- Ganhar Massa Muscular \n");
					printf ("3- Manter Corpo Estético \n");
					scanf ("%d", &objetivo[i]);
					getchar();
					switch (objetivo[i]) {
						case 1:
							strcpy (objetivo_texto[i], "Perder Peso");
							break;
						case 2:
							strcpy (objetivo_texto[i], "Ganhar Massa Muscular");
							break;
						case 3:
							strcpy (objetivo_texto[i], "Manter Corpo Estético");
							break;
						default:
							strcpy (objetivo_texto[i], "Não definido");
							break;
					}
					quantidade_alunos++;
					printf("Aluno cadastrado com sucesso!\n");
				}
				limpartela();
				break;
			case 2:
				printf ("=== Lista de Alunos ===\n");
				if (quantidade_alunos == 0) {
					printf ("Nenhum aluno cadastrado!\n");
				} else {
					for (i = 0; i < quantidade_alunos; i++) {
						printf ("Aluno %d \n" ,i + 1);

						printf ("Aluno: %s \n",aluno[i]);
						printf ("CPF: %s \n",cpf[i]);
						printf ("Data de Nascimento: %s \n",data[i]);
						printf ("Gmail: %s \n",gmail[i]);
						printf ("Peso: %.2f KG\n",peso[i]);
						printf ("Altura: %.2f M\n",altura[i]);
						printf ("Objetivo: %s \n",objetivo_texto[i]);
						printf ("----------------------------------\n");
					}
				}
				limpartela();
				break;
			case 3:
				encontrado = 0;
				printf ("=== Buscar Aluno ===\n");
				printf ("Informe o nome do aluno \n");
				fgets  (buscar_aluno,50,stdin);
				buscar_aluno[strcspn(buscar_aluno,"\n")] = 0;
				for (i = 0; i < quantidade_alunos; i++){
					if (strcmp(buscar_aluno, aluno[i]) == 0){
						encontrado = 1;
						printf ("Aluno Encontrado! \n");
						
						printf ("Aluno: %s \n",aluno[i]);
						printf ("CPF: %s \n",cpf[i]);
						printf ("Data de Nascimento: %s \n",data[i]);
						printf ("Gmail: %s \n",gmail[i]);
						printf ("Peso: %.2f KG\n",peso[i]);
						printf ("Altura: %.2f M\n",altura[i]);
						printf ("Objetivo: %s \n",objetivo_texto[i]);
						break;
					}
				}
				if (encontrado == 0){
					printf ("Aluno não encontrado! \n");
				}
				limpartela();
				break;
			case 4:
				printf ("=== Criar Treino ===\n");
				printf ("Informe o nome do aluno: ");
				fgets  (buscar_aluno,50,stdin);
				buscar_aluno[strcspn(buscar_aluno, "\n")] = '\0';
				encontrado = 0;
				for (i = 0; i < quantidade_alunos; i++){
					if (strcmp(buscar_aluno, aluno[i]) == 0){
						encontrado = 1;
						printf ("Aluno Encontrado! \n");
						
						printf ("Nome: %s\n",aluno[i]);
						printf ("Peso: %.2f KG\n",peso[i]);
						printf ("Altura: %.2f M\n",altura[i]);
						printf ("Objetivo: %s \n",objetivo_texto[i]);
						printf ("-------------------------------------\n");
						printf ("Quantos exercícios terá treino?\n");
						scanf ("%d",&num_exercicio[i]);
						getchar();
						for (j = 0; j < num_exercicio[i]; j++){
							printf ("\n============== Exercicio %d ==============\n", j + 1);
							printf ("Nome do exercício: \n");
							fgets  (exercicio[i][j],50,stdin);
							exercicio [i][j][strcspn(exercicio [i][j], "\n")] = '\0';
							getchar();
							printf ("Número de séries: \n");
							scanf  ("%d",&series [i][j]);
							printf ("Número de repetições: \n");
							scanf  ("%d",&repeticoes [i][j]);
							getchar();	
						}
						printf ("Treino cadastrado com sucesso!\n");
						break;
					}
				}
				if (encontrado == 0){
					printf ("Aluno não encontrado! \n");
				}
				limpartela();
				break;
			case 5:
				printf ("=== Ver Treinos === \n");
				printf ("Informe o nome do aluno! \n");
				fgets  (buscar_aluno,50,stdin);
				buscar_aluno [strcspn (buscar_aluno, "\n")] = 0;
				encontrado = 0;
				for (i = 0; i < quantidade_alunos; i++){
					if (strcmp (buscar_aluno, aluno[i]) == 0){
						encontrado = 1;
						printf ("Aluno encontrado! \n");
						printf ("Nome: %s \n", aluno[i]);
						printf ("Peso: %.2f KG\n", peso[i]);
						printf ("Altura: %.2f M\n", altura[i]);A
						printf ("Objetivo: %s \n",objetivo_texto[i]);
						for (j = 0; j < num_exercicio [i]; j++){
							printf ("Exercício: %s \n", exercicio [i][j]);
							printf ("Séries: %d \n", series[i][j]);
							printf ("Repetições: %d \n", repeticoes[i][j]);
						}
						break;
					}
				}
				if (encontrado == 0 ){
						printf ("Aluno não encontrado! \n");
				}
				limpartela();
				break;
			case 6:
				printf ("Saindo...\n");
				limpartela();
				break;
			default:
				printf ("Opção não identicada");
		}
	} while(menu != 6);
	return (0);
}
