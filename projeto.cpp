#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<pair<int, int>>> pairmatrix;

char* algoritmo(matrix m, vector<int> expressao, int resultado);

int main(void){

    int n, n_numbers; // n = lado da matriz, n_numbers = quantidade de números na expressao
    int resultado;
    vector<int> expressao(n_numbers);

    
    matrix backtracking(n, vector<int>(n, 0));
    pairmatrix pairMatrix(n, std::vector<std::pair<int, int>>(n, {0, 0}));
    
    scanf("%d %d", &n, &n_numbers);
    
    matrix m(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            scanf("%d", &a);
            m[i][j] = a;
        }
    }


    for (int i = 0; i < n_numbers; i++){
        int a;
        scanf("%d", &a);
        expressao[i] = a;
    }

    scanf("%d", &resultado);


    algoritmo(m, expressao,resultado);
    //solucao = algoritmo(m, n_numbers);
    //printf(solucao);

}

char* algoritmo(matrix m, vector<int> expressao, int resultado){
    
    if(expressao.size() == 2){ // [2,1]
        if(m[expressao[0]][expressao[1]] == resultado){

            return "(%d,%d)", expressao[0], expressao[1];
        }
        return "",
    }
    /*exrpessao [-1]    m[x][1] = 3   |0 - 
    */
    if(esquerda){
        return "(algoritmo(m, expressao, resultado))" + " expressao[-1] )";
    }
    if(direita){
        return "(expressao[0] " + "( algoritmo(m, expressao, resultado))";
    }
   
}

