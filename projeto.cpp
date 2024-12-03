#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <tuple>
#include <iostream>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<vector<tuple<int,int,int,int>>>> cube;

void algoritmo(int resultado, matrix m, vector<int> expressao,int n);
string backtracking(int i,int j,int result,cube bottomUp, vector<int> expression);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, n_numbers; // n = lado da matriz, n_numbers = quantidade de números na expressao
    int resultado;
    
    cin >> n >> n_numbers;
    

    vector<int> expressao(n_numbers);
    matrix m(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n_numbers; i++){
        cin >> expressao[i];
    }
    cin >> resultado;

    if(n_numbers == 1){
        if(expressao[0] == resultado){
            printf("1\n");
            printf("%d\n",expressao[0]);
        }
        else{
            printf("0\n");
        }
        return 0;
    }

    algoritmo(resultado, m, expressao ,n_numbers);
}

void algoritmo(int final_result, matrix m, vector<int> expressao, int n){
    

    cube bottomUp(n, vector<vector<tuple<int, int, int, int>>>(n));
    //NOTA: criar um vetor vazio N para depois usa lo para verificar se um certo resultado já foi colocado na matriz bottomUp
    //TUPLOS (valor,k,left,right)

    int colocados = 0; //numero de resultados colocados na matriz
    vector<int> resultados(n,0); //vetor para verificar se um certo resultado já foi colocado na matriz
    int resultado;
    for (int f = 0; f < n-1; ++f) { 
        int i = 0;
        int j = f;
        while (j < n) {
            //base condition
            if(j == i){ 
                bottomUp[i][j].push_back(make_tuple(expressao[i],-1,-1,-1));
            }
            else{
                for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
                    for(tuple <int,int,int,int> tuple1 : bottomUp[i][k]){ //talvez trocar
                        for(tuple <int,int,int,int> tuple2 : bottomUp[k+1][j]){
                            resultado = m[get<0>(tuple1)-1][get<0>(tuple2)-1];
                            if(resultados[resultado-1] == 0){ //se o resultado nao foi colocado
                            // elemento L da casa [i][k] da matriz a (+) elemento R da casa [k+1][j] da matriz e a colocar na casa [i][j] da matriz  
                                bottomUp[i][j].push_back(make_tuple(resultado, k,get<0>(tuple1),get<0>(tuple2)));
                                colocados++;
                                resultados[resultado-1] = 1;
                            }
                            else if (colocados == n){
                                k = i-1;
                            }
                        }
                    }
                }
            }
            colocados = 0;
            fill(resultados.begin(), resultados.end(), 0);
            ++i;
            ++j;
        }
    }
    int i = 0, j = n-1;
    for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
        for(tuple <int,int,int,int> tuple1 : bottomUp[i][k]){ //talvez trocar
            for(tuple <int,int,int,int> tuple2 : bottomUp[k+1][j]){
                if(m[get<0>(tuple1)-1][get<0>(tuple2)-1] == final_result){ 
                    bottomUp[i][j].push_back(make_tuple(final_result,k,get<0>(tuple1), get<0>(tuple2)));
                    printf("1\n");
                    printf("%s\n",backtracking(0,n-1,final_result,bottomUp,expressao).c_str());
                    return;
                }
            }
        }
    }
    printf("0\n");
    return;
}

string backtracking(int i,int j,int result,cube bottomUp, vector<int> expression){

    if(i == j){
        return to_string(expression[i]);
    }
    for(tuple<int,int,int,int> f : bottomUp[i][j]){
        if(get<0>(f) == result){
            int left_number = get<2>(f); 
            int right_number = get<3>(f);
            int k = get<1>(f);
            return "(" + backtracking(i,k,left_number,bottomUp,expression) + " " + backtracking(k+1,j,right_number,bottomUp,expression) + ")";
        }
    } 
    return "ERROR";
}
