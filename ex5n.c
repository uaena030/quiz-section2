#include <stdio.h>
#include <stdlib.h>

int my_strlen (const char* str);
char* my_strcpy(char* dest, const char* source);
char* my_strcat(char* dest, const char* source); 
int my_strcmp(const char* str1, const char* str2);

int main(){
    int i = 0, k, m = 0;
    char **str = (char**)malloc(sizeof(char*) * 100);
    for (int j = 0; j < 100; j++) {
        *(str + j) = (char*)malloc(sizeof(char) * 8192);
    }
    char *strn = (char*)malloc(sizeof (char) * 8192);
    while(gets(*(str + i))){   
        i++;
    }
    printf("number of sentence: %d\n", i);
    k = my_strlen(*(str + 0));
    my_strcpy(strn, *(str + 0));
    for(int j = 1; j < i; j++){
        if(my_strlen(*(str + j)) > k){
            k = my_strlen(*(str + j));
            m = j;
        }
        else if(my_strlen(*(str + j)) == k){
            int u;
            u = my_strcmp(*(str + j), *(str + m));
            if(u > 0){
                k = my_strlen(*(str + j));
                m = j;
            }
            else{
                continue;
            }
        }
        my_strcat(strn, *(str + j));
    }
    printf("longest sentence: %s\n", *(str + m));
    printf("longest length: %d\n", k + 1);
    printf("%s\n", strn);
    free(str);
    free(strn);
    return 0;
}

int my_strlen (const char* str){
    int i = 0, len = 0;
    while(*(str + i) != '\0'){
        len ++;
        i++;
    }
    return len;
}
char* my_strcpy(char* dest, const char* source){
    int i = 0;
    for(i = 0; i < my_strlen(source); i++){
        *(dest + i) = *(source + i);
    }
    *(dest + my_strlen(source)) = '\0';
    return dest;
}
char* my_strcat(char* dest, const char* source){
    int i, j = 0;    
    for(i = my_strlen(dest); i < my_strlen(dest) + my_strlen(source) + 1; i++){
        *(dest + i) = *(source + j);
        j++; 
    }
    *(dest + (my_strlen(dest) + my_strlen(source))) = '\0';
    return dest;
}
int my_strcmp(const char* str1, const char* str2){
    int i, re = 0, j;
    if(my_strlen(str1) > my_strlen(str2)){
        i = my_strlen(str2);
    }
    else{
        i = my_strlen(str1);
    }
    for(j = 0 ; j < i; j++){
        if(*(str1 + j) == *(str2 + j)){
            continue;
        }
        else if(*(str1 + j) > *(str2 + j)){
            re = 100;
            break;
        }
        else{
            re = -100;
            break;
        }
    }
    return re;
}