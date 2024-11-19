#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
void algoritmo(matrix m, vector expressao);

int main(void){

    int n, n_numbers; // n = lado da matriz, n_numbers = quantidade de números na expressao
    scanf("%d %d", &n, &n_numbers);

    matrix m(n, vector<int>(n, 0)); // matriz de n x n
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a;
            scanf("%d", &a);
            m[i][j] = a;
        }
    }
    
    vector<int> expressao(n_numbers);

    for (int i = 0; i < n_numbers; i++){
        int a;
        scanf("%d", &a);
        expressao[i] = a;
    }

    algoritmo(m, expressao);
    //solucao = algoritmo(m, n_numbers);
    //printf(solucao);

}

void algoritmo(matrix m, vector expressao){
    
}

