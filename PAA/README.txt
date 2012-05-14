Para Rodar Cada Programa Faça:

Em cada pasta encontra se um caso enfrentando(short int, etc..)

O programa geraRandomicoXXXXX.cpp gera os números aleatórios para cada caso de teste necessário.
Para rodá-lo basta executar:
	- g++ -Wall geraRandomicoXXXXX.cpp
	- a.exe > numerosGerados.out

Para cada programa/Algoritmo é necessário executá-los de forma separada.
Cada programa ler o arquivo de entrada gerado.
Para rodá-los basta executar:
	- g++ -Wall algoritmo.cpp		//Exemplo: algoritmo = quicksort
	- a.exe < numerosGerados.out > saidadoAlgoritmo.out

Há no fim de cada algoritmo.cpp 3 linhas de impressão que estão comentadas. Para saber se o vetor está sendo ordenado corretamente, descomente-as.