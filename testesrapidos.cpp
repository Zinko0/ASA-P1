#include <stdio.h>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

typedef vector<vector<int>> matrix;
typedef vector<vector<vector<pair<int, int>>>> cube;



int main(void){
    int n = 10;
    int counter = 1;
    matrix m(n, vector<int>(n, 0));
    for (int f = 0; f < n-1; ++f){
        int i = 0;
        int j = f;
        while (j < n){
            m[i][j] = counter;
            ++counter;
            ++i;
            ++j;
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;

}



