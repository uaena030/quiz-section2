#include <stdio.h>
#include <stdlib.h>

unsigned int getRangeBits(unsigned int A, int i, int j);
unsigned int concatenate(unsigned int A, int i, int j, unsigned int B, int x, int y);
unsigned int rushE(unsigned int M);

unsigned int rushE(unsigned int M){
    M = M ^ 3610409;
    return M;
}

unsigned int getRangeBits(unsigned int A, int i, int j){
    A >>= (i - 1);
    A <<= (32 - (j - i + 1));
    A >>= (32 - (j - i + 1));
    return A;
}

unsigned int concatenate(unsigned int A, int i, int j, unsigned int B, int x, int y){
    getRangeBits(A, i, j);
    getRangeBits(B, x, y);
    A <<= (y - x + 1);
    return (A + B);

}

int main(){
    int count;
    scanf("%d", &count);
    int C[count];
    unsigned int V[count + 1];
    V[0] = 520;
    for(int i = 0; i < count; i++){
        int M;
        scanf("%d", &M);
        C[i] = M ^ getRangeBits(rushE(V[i]), 1, 8);
        printf("%d ", C[i]);
        V[i + 1] = concatenate(V[i], 9, 32, C[i], 1, 8);
    }
    printf("\n");
    return 0;
}