#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char value[30];
    int sscore;
};

int compare_parts(const void *p,   const void *q){
    return (((struct node *) q) -> sscore - ((struct node *) p) -> sscore);
}

int main(){
    int a;
    printf("Number of records you want to key in:");
    scanf("%d",&a);
    struct node mat[a];
    for(int i = 0; i < a; i++){
        printf("Enter name & score:");
        scanf("%s %d", mat[i].value, &(mat[i].sscore));
    }
    qsort(mat, a, sizeof(struct node), compare_parts);
    printf("name score\n");
    for(int i = 0; i < a; i++){
        printf("%s %d\n", mat[i].value, mat[i].sscore);
    }
    return 0;
}