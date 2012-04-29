/* Exercicio_6 -- Algoritmos e Estrutura de Dados I 
   DIOGO SOARES MOREIRA  
   Bacharelando em Ciência da Computação
   Universidade Federal do Amazonas  --  UFAM */


//ASSUNTO: ARQUIVOS.

/*Você foi contratado para desenvolver um conjunto de aplicativos para
manipular um controle acadêmico pessoal para cadastro e consulta de
notas de disciplinas (para ser utilizado por um determinado aluno). Cada
registro de nota do aluno contém os seguintes dados: Código (6
caracteres), Disciplina (20 caracteres), Média Final (double), Faltas (int).
Tais dados serão armazenados em um arquivo texto chamado Notas.txt
(banco de dados). Você irá desenvolver:
  Um programa para cadastrar uma nova nota: o programa pedirá do
    usuário os dados da nova nota e o cadastrará no final do banco de
    dados.
  Um programa para consultar uma nota: o programa pede do usuário
    o código da disciplina e imprime os dados desta disciplina (com a
    nota).
  Um programa para geração de um relatório com as notas do aluno
*/



//Obs: TESTADO APENAS NO LINUX-UBUNTU...não garanto funcionamento no windows.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100		//tamanho máximo da struct notas



/* struct com as informaçoes pedidas pela questão */
struct notas{
	char codigo[6];
	char disciplina[20];
	double media;
	int faltas;
} notas_lista[MAX];		//uma lista de tamanho MAX da struct.











void inicialista(void){		//função que inicia lista até 99. com 100 elementos livres.

	int t;

for(t=0; t<MAX; ++t){
notas_lista[t].codigo[0] = '\0';
}
}












int estah_cheia(void){		/*função que verifica se a lista do tipo struct notas está cheia. E retorna o espaço onde ela está vazia ou -1 se estiver 					  cheia*/
int t;

for(t=0; notas_lista[t].codigo[0] && t<MAX; t++)	

if(t==MAX)			//se ela estiver cheia ela retornará "-1".
return -1;


return t;			/*casp contrário ela retornará um primeiro elemento da lista que esteja vazio. Ex: se o notas.txt estiver zerado ele 					retornará zero.*/
}











int menu(void){			//função para o menu com retorno int, que é da escolha do usuário.

int x=0;			//variável inteira que guardará a opção escolhida pelo usuário.

printf("\t\t...:::...:::MENU:::...:::...\n");
printf("\t\t(1) Inserir\n");
printf("\t\t(2) Salvar\n");
printf("\t\t(3) Mostrar\n");
printf("\t\t(4) Carregar\n");
printf("\t\t(5) Sair do programa\n");


printf("\n\n\t\tDigite a opcao desejada: \n");
scanf("%d", &x);

return x;			//a função retorna o número da opção desejada, ou seja entre 1 e 5.
}








void inserir(){			//função que insere novos elementos na função.

int espaco;
espaco = estah_cheia();		//verifica se a lista está cheia.

if(espaco == -1){		//se estiver cheia ela retornará "-1"
	printf("\n\nLISTA CHEIA!!!!\n\n");
}
				//caso contrário, vc estará livre para inserir novos elementos.
printf("\nDigite o codigo: ");
scanf("%s", notas_lista[espaco].codigo);
printf("\nDigite a disciplina: ");
scanf("%s", notas_lista[espaco].disciplina);
printf("\nDigite a media final: ");
scanf("%lf", &notas_lista[espaco].media);
printf("\nDigite o num de faltas: ");
scanf("%d", &notas_lista[espaco].faltas);
}












void mostra(void){			//função que gera o relatório, ou seja mostra os elementos gravados no arquivo notas.txt.
					//a função tbm mostra a coeficiente, a média das faltas e o número de disciplinas cursadas.
	int x;
	double cont=0;
	int cont2=0;
	int cont_faltas=0;
	double coeficiente;
	double media_faltas;
for(x=0; x<MAX; x++){
	if(notas_lista[x].codigo[0]){
	printf("\t%s\n", notas_lista[x].codigo);
	printf("\t%s\n", notas_lista[x].disciplina);
	printf("\t%lf\n", notas_lista[x].media);
	printf("\t%d\n", notas_lista[x].faltas);
	printf("\n");
	cont += notas_lista[x].media;		//contador para o total da média.
	cont2++;				//contador para o num de disciplinas cursadas.
	cont_faltas += notas_lista[x].faltas;	//contador para as faltas.
	}
}
printf("\n");

coeficiente = cont/(double)cont2;		//cálculo do coeficiente.
media_faltas = (double)cont_faltas/(double)cont2;	//cálculo da média de faltas

printf("\tnúmero de disciplinas cursadas: %d\n", cont2);
printf("\tcoeficiente: %lf\n", coeficiente);
printf("\tA média de faltas é: %lf\n", media_faltas);

printf("\n\n\n");

}










void salvar(void){			//função que salva no arquivo notas.txt
	FILE *arq;
	int t;
	int s;

	arq = fopen("notas.txt", "w");	//abertura do arquivo em modo "w", ou seja de escrita em arquivo.
	

if(arq==NULL){				
	printf("ERRO!!! arquivo inexistente.");
	return;
}


for(t=0; t<MAX; t++){
	if(*notas_lista[t].codigo!=0){
		s = fwrite(&notas_lista[t], sizeof(struct notas) , 1,arq);
			if(s != 1){
				printf("\n\n\tErro na escrita!!!\n");	//se essa mensagem for exibida, então houve erro de gravação.
			}
			else{
				printf("\n\n\tArquivo Salvo com sucesso!!!!!!!!!\n\n");
			}
	}
}

fclose(arq);		//fechando o arquivo.
}				
	










void carregar(){		//carregamento de arquivo. (Obs: primeira coisa a se fazer ao compilar esse programa é carregar o arquivo.)


FILE *arq;
int i;
int s;

arq=fopen("notas.txt", "r");	//abertura do arquivo em modo "r", ou seja de leitura.

if(arq==NULL){
	printf("ERRO!!! arquivo inexistente.\n");
	return;
}
for(i=0; i<MAX; i++){
	s=fread(&notas_lista[i], sizeof(struct notas), 1, arq);
	if(s!=1){
		if(feof(arq))
			break;
		printf("erro de leitura do arquivo.");
		}
	}

fclose(arq);		//fechamento do arquivo. 
}














int main(){		//função principal.

	char escolha;	

	inicialista();	//inicia a lista struct notas.
	printf("\n\n\n");

for(;;){
	escolha = menu();     //área do MENU.
	switch(escolha){
		case 1:
			inserir();
			break;
		case 2:
			salvar();
			break;
		case 3:
			mostra();
			break;
		case 4:	
			carregar();
			break;
		case 5:
			exit(0);
	}
	}

printf("\n\n");
return 0;
//system("pause");

}


