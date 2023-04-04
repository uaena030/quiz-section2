#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define criminal_len 15
#define crime_len 20
#define total_criminal 10

struct crime{
    char cname[total_criminal][crime_len];
    int date[total_criminal], penalty[total_criminal];  
};
struct criminal{
    char clname[criminal_len];
    struct crime note;
    int clcount;
};
int main(){
    int command = 1, i = 0;
    int j = 0;
    struct criminal total[total_criminal];
    for(int i = 0; i < total_criminal; i++){
        total[i].clcount = 0;
    }
    while(command != 0){
        printf("Enter a command: ");
        scanf("%d",&command);
        switch(command){
            case 1:{
                printf("Enter a criminal's name: ");
                scanf("%s", total[i].clname);
                printf("Created new criminal data (number %d).\n", i);
                i++;//嫌犯總數
                break;
            }
            case 2:{
                printf("Enter a number of the criminal: ");
                scanf("%d",&j);
                printf("Enter crime: ");
                scanf("%s", total[j].note.cname[total[j].clcount]);
                printf("Enter date: ");
                scanf("%d",&total[j].note.date[total[j].clcount]);
                printf("Enter penalty: ");
                scanf("%d",&total[j].note.penalty[total[j].clcount]);
                total[j].clcount++;//入獄次數
                break;
            }
            case 3:{
                int k;
                printf("Enter a number of the criminal: ");
                scanf("%d", &k);
                printf("Name: %s\n====================\n", total[k].clname);
                for(int count = 0; count < total[k].clcount; count++){
                    printf("Year: %d, Crime: %s, Penalty: %d months\n", total[k].note.date[count], total[k].note.cname[count], total[k].note.penalty[count]);
                }
                printf("====================\n");
                break;
            }
        }   
    }
    return 0;
}