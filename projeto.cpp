#include <stdio.h>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<vector<pair<int, int>>>> cube;

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

char* algoritmo(int result, matrix m, vector<int> expressao, int n){
    
    matrix backtracking(n, vector<int>(n));
    cube bottomUp (n, vector<vector<pair<int,int>>>(n)); 
    //PARES (valor,k)
    for (int f = 0; f < n; ++f) {
        int i = 0;
        int j = f;
        while (j < n) {
            //base condition
            if(j == i){  //MUITO CUIDADO COM OS INDICES
                bottomUp[i][j].push_back(make_pair(expressao[i],-1));
            }else{
                for(int k = i; k < j; ++k){
                    for(int l = 0; l < n; ++l){
                        for(int r = 0; r < n; ++r){
                            //estranho
                            bottomUp[i][j].push_back(make_pair(m[bottomUp[i][j][l].first][bottomUp[k+1][j][r].first],k));
                        }

                    }
                }
            }



            ++i;
            ++j;
        }
    }
   
}

