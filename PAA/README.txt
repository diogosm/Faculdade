Para Rodar Cada Programa Fa�a:

Em cada pasta encontra se um caso enfrentando(short int, etc..)

O programa geraRandomicoXXXXX.cpp gera os n�meros aleat�rios para cada caso de teste necess�rio.
Para rod�-lo basta executar:
	- g++ -Wall geraRandomicoXXXXX.cpp
	- a.exe > numerosGerados.out

Para cada programa/Algoritmo � necess�rio execut�-los de forma separada.
Cada programa ler o arquivo de entrada gerado.
Para rod�-los basta executar:
	- g++ -Wall algoritmo.cpp		//Exemplo: algoritmo = quicksort
	- a.exe < numerosGerados.out > saidadoAlgoritmo.out

H� no fim de cada algoritmo.cpp 3 linhas de impress�o que est�o comentadas. Para saber se o vetor est� sendo ordenado corretamente, descomente-as.