#include <stdio.h>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
void algoritmo(matrix m, int n_numbers);

int main(void){

    int n, n_numbers; // n = lado da matriz, n_numbers = quantidade de números na expressao
    scanf("%d %d", &n, &n_numbers);

    matrix m(n, vector<int>(n, 0)); // matriz de n x n
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &m[i][j]);
        }
    }

    algoritmo(m, n_numbers);
    //solucao = algoritmo(m, n_numbers);
    //printf(solucao);

}

void algoritmo(matrix m, int n_numbers){
    
}