#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define True 1

struct node{
    char *value;
    struct node *next;
    int total;
};
struct node *insert(struct node **list, char *n){
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = (char*)malloc(sizeof(char) * 1024);
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(1);
    }
    strcpy(new_node->value, n);
    new_node->total = 1;
    new_node->next = NULL;
    if(*list == NULL){
        *list = new_node;
    }
    else{
        struct node *prev = *list;
        while(prev->next != NULL){
            prev = prev->next;
        }
        prev->next = new_node;
    }
    return new_node;
};
struct node *search(struct node *list, char *n){
    struct node *p;
    for (p = list; p != NULL; p = p->next){
        if (strcmp(p->value , n) == 0){
            return p;
        }
    }
    return NULL;
}

int main(){
    struct node *list = NULL;
    struct node *nooo = NULL;
    char *strn = (char*)malloc(sizeof (char) * 1024);
    while(True){
        if(gets(strn) == NULL){
            nooo = list;
            while(nooo){
                printf("%s: %d\n", nooo->value, nooo->total);
                nooo = nooo->next;
            }
            return 0;
        }
        else if(*strn == '-'){
            int a;
            a = strlen(strn);
            *(strn + a) = '\0';
            for(int i = 0; i < a; i++){
                *(strn + i) = *(strn + i + 1);
            }
            nooo = search(list, strn);
            nooo->total -= 1;
        }
        else{
            *(strn + strlen(strn)) = '\0';
            nooo = search(list, strn);
            if(nooo != NULL){
                nooo->total += 1;
            }
            else{
                insert(&list, strn);
            }
        }
    }
    return 0;
}