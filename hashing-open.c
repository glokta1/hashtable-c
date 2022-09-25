#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

struct Node {
    int value;
    struct Node* next;
};

// initialize an array of pointers to nodes
struct Node* ht[TABLE_SIZE];

int hash(int key);
void insert(int key);
void search(int key);
void display();

int main(void) {

    insert(1);
    insert(2);
    insert (5);
    insert (10);
    display();
}

// display hashtable
void display() {
    struct Node* p;
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d: ", i);
        for (p = ht[i]; p != NULL; p = p->next) {
            printf("%d ", p->value);
        }
        printf("\n");
    }
}

// inserts elements at beginning of linked list
void insert(int key) {
    // calculate address of key
    int address = hash(key);

    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->value = key;
    new_node->next = ht[address];
    ht[address] = new_node;
}


int hash(int key) {
    return key % TABLE_SIZE;
}