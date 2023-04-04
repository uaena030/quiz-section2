#include <stdio.h>
#include <string.h>

int count(char str[100]){
    int i = 0, n = 0;
    for(i = 0; i < 100; i++){
        if(str[i] != ' ' && str[i] != '\0'){
            n++;
        }
        else if(str[i] == '\0'){
            break;
        }
    }
    return n;
}

void reverse(char str[]){
    int i;
    for(i = strlen(str) - 1; i >= 0; i--){
        printf("%c", str[i]);
    }
    printf("\n");
}

int main(){
    char str1[100], str2[100];
    int ch;
    gets(str1);
    gets(str2);
    while(scanf("%d", &ch) != EOF){
        if(ch < 1 || ch > 6){
            printf("Error!\n");
        }
        else{
            if(ch == 1){
                printf("Reverse A: ");
                reverse(str1);
                printf("Reverse B: ");
                reverse(str2);
            }
            else if(ch == 2){
                int len;
                len = strlen(str1);
                printf("The length of A: %d\n", len);
                len = strlen(str2);
                printf("The length of B: %d\n", len);
            }
            else if(ch == 3){
                char str3[100];
                strcpy(str3, str1);
                printf("The string after concatenates: %s\n", strncat(str1, str2, sizeof(str1) - strlen(str1) - 1));
                strcpy(str1, str3);
            }
            else if(ch == 4){
                if(strcmp(str1, str2) > 0){
                    printf("A is greater than B.\n");
                }
                else if(strcmp(str1, str2) == 0){
                    printf("A is equal to B.\n");
                }
                else if(strcmp(str1, str2) < 0){
                    printf("A is less than B.\n");
                }
            }
            else if(ch == 5){
                int awhite = strlen(str1) - count(str1);
                printf("Whitespace of A: %d\n", awhite);
            }
            else if(ch == 6){
                int bwhite = strlen(str2) - count(str2);
                printf("Whitespace of B: %d\n", bwhite);
            }
        }
    }
    return 0;
}