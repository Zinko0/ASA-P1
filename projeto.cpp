#include <stdio.h>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<stack<pair<int, int>>>> cube;

char* algoritmo(int resultado, matrix m, int n);

int main(void){

    int n, n_numbers; // n = lado da matriz, n_numbers = quantidade de números na expressao
    int resultado;
    vector<int> expressao(n_numbers);
   
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


    algoritmo(resultado, m, n);

}

char* algoritmo(int result, matrix m, int n){
    
     matrix backtracking(n, vector<int>(n));
     cube bottomUp (n, vector<stack<pair<int,int>>>(n)); 
     
     for(int i = 0; i < n; ++i){
        
         for (int j = 0; j < n; ++j){

         }
     }
   
}

