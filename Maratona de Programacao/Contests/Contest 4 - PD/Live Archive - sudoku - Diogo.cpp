#include<stdio.h>
#include<map>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>

using namespace std;

string sudokuS;
//int sudoku[81];

class Sudoku{
    public:int sudoku[81];

    void resolveMain(){
        try{
            resolve(0);
        } catch(char* ex){}
    }

    void resolve(int n){
        if(n==81){
            throw (char*) "" ;      /** Migue para manter o loop de resolucao. **/
        }
        if(sudoku[n]>0){
            resolve(n+1);
            return;
        }

        /**for(int i = 0;i<81;i++){
            cout<<sudoku[i]<<" ";
            if((i+1)%9 == 0 && i>1) cout<<endl;
        }**/
        //cout<<endl;
        //system("pause");    system("pause");    system("pause");    system("pause");

        for(int i = 1;i<10;i++){
            if( checa(i, n) ){
                sudoku[n] = i;
                resolve(n+1);
                sudoku[n] = 0;
            }
        }
    }

    int checa(int valor, int n){
        int linha, coluna, linhaO, colunaO;

        linha = n/9;
        coluna = n%9;
        /** Verifica linha e coluna **/
        for(int i = 0;i<9;i++){
            if( sudoku[linha*9+i] == valor || sudoku[i*9 + coluna] == valor ) return 0;
        }

        /** Verifica bloco **/
        linhaO = linha/3;
        linhaO *= 3;
        colunaO = coluna/3;
        colunaO *= 3;
        for( int i = linhaO; i<linhaO+3 ; i++ ){
            for( int j = colunaO; j<colunaO+3; j++ ){
                if( sudoku[i*9 + j] == valor ){
                    return 0;
                }
            }
        }
        return 1;      /** Valor possivelmente valido **/
    }

};

int main(){

    int n;
    scanf("%d", &n);

    while(n!=0){
        Sudoku sud;
        string k;
        cin>>k;
        sudokuS.append(k);
        cin>>k;
        sudokuS.append(k);
        cin>>k;
        sudokuS.append(k);

        cin>>k;
        sudokuS.append(k);
        cin>>k;
        sudokuS.append(k);
        cin>>k;
        sudokuS.append(k);

        cin>>k;
        sudokuS.append(k);
        cin>>k;
        sudokuS.append(k);
        cin>>k;
        sudokuS.append(k);

        for(int i = 0;i<81;i++){
            sud.sudoku[i] = (int)sudokuS[i]-48;
        }

        sud.resolveMain();

        /** Visualizacao do sudoku **/
        for(int i = 0;i<81;i++){
            cout<<sud.sudoku[i]<<"";
            if((i+1)%9 == 0 && i>1) cout<<endl;
        }

        //cout<<sudoku[0]<<endl;
        sudokuS.clear();
        n--;
    }

}
