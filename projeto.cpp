#include <stdio.h>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<vector<tuple<int,int,int,int>>>> cube;

void algoritmo(int resultado, matrix m, vector<int> expressao,int n);

int main(void){

    int n, n_numbers; // n = lado da matriz, n_numbers = quantidade de números na expressao
    int resultado;
    
    scanf("%d %d", &n, &n_numbers);

    vector<int> expressao(n_numbers);
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

    algoritmo(resultado, m, expressao ,n_numbers);

}

int backtracking(int i,int j,int result,cube bottomUp, vector<int> expression){
    int size = expression.size();
    int left_number;
    int right_number;
    int k;
    if(size == 1){
        return expression[0];
    }
    for(int f = 0; f < size; ++f){
        if(get<0>(bottomUp[i][j][f]) == result){
            left_number = get<2>(bottomUp[i][j][f]); 
            right_number = get<3>(bottomUp[i][j][f]);
            k = get<1>(bottomUp[i][j][f]);
            
        }
        break;
    }

    //NAO SEI SE ISTO É EFICIENTE
    vector<int> left_expression(expression.begin(), expression.begin() + k);
    vector<int> right_expression(expression.begin() + k + 1, expression.end());
    
    printf("(%d  %d)",backtracking(0,k,left_number,bottomUp,left_expression),backtracking(k+1,size,right_number,bottomUp,right_expression));
    
}


void algoritmo(int result, matrix m, vector<int> expressao, int n){
    

    cube bottomUp (n, vector<vector<tuple<int,int,int,int>>>(n)); 
    //NOTA: criar um vetor vazio N para depois usa lo para verificar se um certo resultado já foi colocado na matriz bottomUp
    //TUPLOS (valor,k,left,right)
    for (int f = 0; f < n; ++f) { //NAO VAMOS AVERIGUAR A CASA [0][n-1] QUE É O RESULTADO
        int i = 0;
        int j = f;
        while (j < n) {
            //base condition
            if(j == i){  //MUITO CUIDADO COM OS INDICES
                bottomUp[i][j].push_back(make_tuple(expressao[i],-1,-1,-1));
            }
            else if( i != 0 && j != n-1){
                for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
                    for(int r = 0; r < n; ++r){
                        for(int l = 0; l < n; ++l){
                            // elemento L da casa [i][k] da matriz a (+) elemento R da casa [k+1][j] da matriz e a colocar na casa [i][j] da matriz  
                            bottomUp[i][j].push_back(make_tuple(m[get<0>(bottomUp[i][k][l])][get<0>(bottomUp[k+1][j][r])], k, get<0>(bottomUp[i][k][l]), get<0>(bottomUp[k+1][j][r])));
                            printf("(%d, %d, %d, %d) intermedio\n",result, k, get<2>(bottomUp[i][j][l]), get<3>(bottomUp[i][j][r]));
                        }
                    }
                }
            }else{
                for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
                    for(int r = 0; r < n; ++r){
                        for(int l = 0; l < n; ++l){
                            if(m[get<0>(bottomUp[i][k][l])][get<0>(bottomUp[k+1][j][r])] == result){ //podemos otimizar isto
                                bottomUp[i][j].push_back(make_tuple(result,k,get<0>(bottomUp[i][k][l]), get<0>(bottomUp[k+1][j][r])));
                                printf("(%d, %d, %d, %d) final\n",result, k, get<2>(bottomUp[i][j][l]), get<3>(bottomUp[i][j][r]));
                                //backtracking(0,n-1,result,bottomUp,expressao);
                                return;
                            }
                        }
                    }
                }
            }
            ++i;
            ++j;
        }
    }
}

