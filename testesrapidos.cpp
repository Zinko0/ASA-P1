#include <stdio.h>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<vector<pair<int, int>>>> cube;



int main(void){
    int n = 100;
    int counter = 1;
    matrix m(n, vector<int>(n, 0));
for(int i = 0; i < n; ++i){

        m[i][i] = counter;
        counter++;
        
    }

    for (int f = 1; f < n-1; ++f) { 
        int i = 0;
        int j = f;
        while (j < n) {
            m[i][j]= counter;
            ++i;
            ++j;
            counter++;
        }
    }

    int i = 0, j = n-1;
    for(int k = j - 1; k >= i; --k){ //começar o algoritmo com o maior K 
        m[i][j] = counter;
    }

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

}



