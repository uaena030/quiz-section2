#include <stdio.h>
#define MAX_ARRAY_LENGTH 100

typedef struct {
    int contents[MAX_ARRAY_LENGTH]; 
    int power;
    /* determine the structure by yourself. e.g, container of data, index... */
} darray;

void initialize(darray *d);
void push_back(darray *d, int value);
int pop_back(darray *d);
int erase(darray *d, int position);
void insert(darray *d, int position, int value);
void clear(darray *d);
int sum(const darray *d);
int length(darray *d);

void initialize(darray *d) {//ok
    d->power = 0;
}

void push_back(darray* d, int value) {//ok
    d->contents[++d->power] = value;
}

int pop_back(darray* d) {//ok
    if(d->power > 0){
        int last = d->contents[d->power];
        --d->power;
        return last;
    }
    return 0;
}

int erase(darray *d, int position) {
    position++;
    if((d->power) >= position && position >= 1){
        for(int i = position; i < d->power; i++){
            d->contents[i] = d->contents[i + 1];
        }
        --d->power;
        return 1;
    }
    // return 1, if successfully erase the element.
    else
        return 0;
    // return 0, if fail erase the element.

}

void insert(darray *d, int position, int value) {//ok
    position++;//2
    if((d->power) >= position && position >= 1){
        int core;
        core = ++d->power;//6
        for(int i = core; i > position; i--){
            d->contents[i] = d->contents[i - 1];
        }
        d->contents[position] = value;
    }   
}

void clear(darray *d) {
    initialize(d);    
}

int sum(const darray *d) {//ok
    int summary = 0;
    for(int i = 1; i <= d->power; i++){
        summary += d->contents[i];
    }
    return summary;
}

int length(darray *d) {//ok
    int len = d->power;
    return len;
}

//YOU CAN'T MODIFY THE main() FUNCTION!!!
int main() {
    darray d;
    initialize(&d);
    int operation, param1, param2;
    while(scanf("%d", &operation)) {
        switch (operation)
        {
        case 1: //push_back
            scanf("%d", &param1);
            push_back(&d, param1);
            break;
        case 2: //pop_back
            printf("popped: %d\n", pop_back(&d));
            break;
        case 3: //erase
            scanf("%d", &param1);
            if(erase(&d, param1))
                printf("erase OK\n");
            else
                printf("erase not OK\n");
            break;
        case 4: //insert
            scanf(" %d %d ", &param1, &param2);
            insert(&d, param1, param2);
            break;
        case 5:
            clear(&d);
            break;
        case 6:
            printf("sum: %d\n", sum(&d));
            break;
        case 7:
            printf("length: %d\n", length(&d));
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}