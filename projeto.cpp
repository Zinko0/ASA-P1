#include <stdio.h>
#include <string>
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
            vector<int> left_expression(expression.begin(), expression.begin() + k);
            vector<int> right_expression(expression.begin() + k + 1, expression.end());
            printf("k: %d,left_number: %d, right_number:%d\n",k,left_number,right_number);  
    
            printf("(%d  %d)",backtracking(0,k,left_number,bottomUp,left_expression),backtracking(k+1,size-1,right_number,bottomUp,right_expression));
            break;
        }
    }

    return 1000;
}


void algoritmo(int final_result, matrix m, vector<int> expressao, int n){
    

    cube bottomUp(n, vector<vector<tuple<int, int, int, int>>>(n, vector<tuple<int, int, int, int>>(n)));
    //NOTA: criar um vetor vazio N para depois usa lo para verificar se um certo resultado já foi colocado na matriz bottomUp
    //TUPLOS (valor,k,left,right)

    int colocados = 0; //numero de resultados colocados na matriz
    vector<int> resultados(n,0); //vetor para verificar se um certo resultado já foi colocado na matriz
    int resultado;
    int matrix_i, matrix_j;
    for (int f = 0; f < n; ++f) { //NAO VAMOS AVERIGUAR A CASA [0][n-1] QUE É O RESULTADO
        int i = 0;
        int j = f;
        while (j < n) {
            //base condition
            if(j == i){  //MUITO CUIDADO COM OS INDICES
                bottomUp[i][j][0] = make_tuple(expressao[i],-1,-1,-1);
                printf("(%d, %d, %d, %d) base\n",get<0>(bottomUp[i][j][0]), get<1>(bottomUp[i][j][0]), get<2>(bottomUp[i][j][0]), get<3>(bottomUp[i][j][0]));
            }
            else if( i != 0 || j != n-1){
                for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
                    for(int r = 0; r < n; ++r){
                        for(int l = 0; l < n; ++l){
                            printf("i: %d, j: %d, k: %d, l: %d, r: %d\n",i,j,k,l,r);
                            matrix_i = get<0>(bottomUp[i][k][l]);
                            matrix_j = get<0>(bottomUp[k+1][j][r]);
                            if(matrix_i == 0){
                                break;
                            }
                            else if (matrix_j == 0){
                                r = n;
                                break;
                            }
                            
                            resultado = m[matrix_i-1][matrix_j-1];
                            printf("resultado: %d\n",resultado);
                            if(resultados[resultado] == 0){ //se o resultado nao foi colocado
                            // elemento L da casa [i][k] da matriz a (+) elemento R da casa [k+1][j] da matriz e a colocar na casa [i][j] da matriz  
                                bottomUp[i][j][colocados] = make_tuple(resultado, k, matrix_i, matrix_j);
                                colocados++;
                                resultados[resultado-1] = 1;
                                printf("(%d, %d, %d, %d) : indice [%d][%d]\n",m[get<0>(bottomUp[i][k][l])-1][get<0>(bottomUp[k+1][j][r])-1], k, get<2>(bottomUp[i][j][l]), get<3>(bottomUp[i][j][r]),i,j);
                            }
                            else if (colocados == n-1){
                                l = n;
                                r = n; //condiçaõ para sair do ciclo
                                k = i-1;
                            }
                        }
                    }
                    colocados = 0;
                    fill(resultados.begin(), resultados.end(), 0);
                }
            }else{
                for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
                    for(int r = 0; r < n; ++r){
                        for(int l = 0; l < n; ++l){
                            if(m[get<0>(bottomUp[i][k][l])-1][get<0>(bottomUp[k+1][j][r])-1] == final_result){ 
                                bottomUp[i][j][0] = make_tuple(final_result,k,get<0>(bottomUp[i][k][l]), get<0>(bottomUp[k+1][j][r]));
                                printf("(%d, %d, %d, %d) final\n",final_result, k, get<2>(bottomUp[i][j][l]), get<3>(bottomUp[i][j][r]));
                                printf("(%s)",backtracking(0,n-1,final_result,bottomUp,expressao));
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

