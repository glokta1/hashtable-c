#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 5

int ht[TABLE_SIZE];
int option = 0;

int hash(int key);
void insert(int key);
void search(int key);
void delete(int key);
void display();
void linear_probing();
void quad_probing();
void double_hashing();
void sep_chaining();
void handle_collisions(int option, int key, int address);

int main (void) {
    printf("Welcome!\n1) Linear probing\n2) Quadratic probing\n3) Double Hashing\n4) Separate Chaining\n");
    printf("\nSelect a collision resolution method: ");
    scanf("%d", &option);

    // initializing arrays with -1 to indicate unoccupied location
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht[i] = -1;
    }

    // initialize random number generator
    insert(5);
    insert(8);
    insert(6);
    insert(7);
    display();

}

void delete(int key) {

}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d:%d\n", i, ht[i]);
    }
}

void handle_collisions(int option, int key, int address) {
    switch (option) {
        case 1:
            linear_probing(key, address);
            break;
        case 2:
            quad_probing(key, address);
            break;
        case 3: 
            double_hashing(key, address);
            break;
        case 4:
            sep_chaining(key, address);
            break;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

// void insert(int key) {
//     int address = hash(key);
//     if (ht[address] == -1) {
//         ht[address] = key;
//     } else {
//         handle_collisions(1, key, address);
//     }

// }

void insert(int key) {
}

void linear_probing(int key, int address) {

}

void search(int key) {
}



