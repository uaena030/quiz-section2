// you can slightly modify the sample code if you want

#include <stdio.h>
#include <stdlib.h>

struct tNode{
    int data;
    struct tNode *Lchild, *Rchild;
};

// Insert new data to Binary Search Tree.
struct tNode* insert(struct tNode *curNode, int newData) {
    struct tNode *newnode = (struct tNode *)malloc(sizeof(struct tNode));
    newnode -> data = newData;
    newnode -> Lchild = NULL;
    newnode -> Rchild = NULL;
    if(curNode == NULL){
        return newnode;
    }
    if (newData < curNode -> data){
        if (curNode -> Lchild == NULL){
            curNode -> Lchild = newnode;  
            //create new node, assign to Lchild and return
        }
        else{
            insert(curNode -> Lchild, newData);
            //call insert function with curNode->Lchild
        }
    }   
    else if(newData > curNode->data){
        if (curNode->Rchild == NULL){
            curNode -> Rchild = newnode;      
            //create new node, assign to Rchild and return
        }
        else{
            insert(curNode -> Rchild, newData);
            //call insert function with curNode->Rchild
        }
    }
    return curNode;
    /*
    // recursive version
    print curNode->data, if curNode->data > 0
    if newData is smaller than curNode->data {
        if curNode->Lchild is NULL
            create new node, assign to Lchild and return
        else
            call insert function with curNode->Lchild
    } 
    else if newData is greater than curNode->data {
        if curNode->Rchild is NULL
            create new node, assign to Rchild and return
        else
            call insert function with curNode->Rchild
    }
    */
}

void bigprint(struct tNode *plz, int key) {
    if (plz == NULL)
        return;

    if (plz -> data == key){
        printf("%d ", plz -> data);
        return;
    }
    if (key < plz -> data) {
        if(plz -> data != 0){
            printf("%d ", plz -> data);
        }
        bigprint(plz -> Lchild, key);
    }

    if (key > plz -> data) {
        if(plz -> data != 0){
            printf("%d ", plz -> data);
        }
        bigprint(plz -> Rchild, key);
    }
}

// To determine whether the target data exists in the tree
int find(struct tNode *curNode, int target){

    // If we find the target in curNode, return 1 (i.e. true).
    // If we reach NULL, it means we can't find the target, return 0 (i.e. false).
    // Otherwise, compare the target and the data of curNode to determine the target in which child (either Lchild or Rchild).
    
    //********************** You should write ********************//
    while(curNode != NULL){
        if(target < curNode -> data){
            curNode = curNode -> Lchild;
        }
        else if(target > curNode -> data){
            curNode = curNode -> Rchild;
        }
        else if(target == curNode -> data){
            return 1;
        }
    }
    return 0;
    //************************************************************//
}

void deleteTree(struct tNode* curNode){
    if (curNode == NULL) return;
    deleteTree(curNode->Lchild);
    deleteTree(curNode->Rchild);
    free(curNode);
}

int main(){
    int numQuery = 0;
    scanf("%d", &numQuery);

    struct tNode *root = (struct tNode *) malloc(sizeof(struct tNode));
    (*root) = (struct tNode) {.data = 0, .Lchild = NULL, .Rchild = NULL};
    // use a virtual node represent the root (store 0)

    for(int i = 0; i < numQuery; i++) {
        int operation_type, data;
        scanf("%d%d", &operation_type, &data);
        if(operation_type == 1) {
            // insert data
            // To find the target position where to insert, we start from root and compare the data of root and new data.
            insert(root, data);
            bigprint(root, data);
            printf("\n");
        } else if(operation_type == 2) {
            // To determine whether the target data exists in the tree.
            // To find the target data, we start from root and compare the data of root and new data like insert function.
            if(find(root, data)) {
                printf("%d is in tree\n", data);
            } else {
                printf("%d is not in tree\n", data);
            }
        }
    }
    // free memory
    deleteTree(root);
    return 0;
}