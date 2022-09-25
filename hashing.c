#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 5
#define DOUBLE_HASH_CONSTANT 3

int ht[TABLE_SIZE];
int option = 0;

int hash1(int key);
int hash2(int key);
void insert(int key);
void search(int key);
void delete(int key);
void display();
int generate_address(int option, int key, int i);

int main (void) {
    printf("Welcome!\n1) Linear probing\n2) Quadratic probing\n3) Double Hashing\n4) Separate Chaining\n");
    printf("\nSelect a collision resolution method [1-4]: ");
    scanf("%d", &option);

    // initializing arrays with -1 to indicate unoccupied location
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht[i] = -1;
    }

    // initialize random number generator
    insert(7);
    insert(12);
    insert(22);
    // delete(12);
    // insert(8);
    // insert(2);
    display();

}

void delete(int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int address = generate_address(option, key, i);

        if (ht[address] == key) {
            ht[address] = -1;
            return;
        }
    }
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d:%d\n", i, ht[i]);
    }
}

int generate_address(int option, int key, int i) {
    switch (option) {
        case 1:
            return (hash1(key)  + i) % TABLE_SIZE;
            break;
        case 2:
            return (hash1(key) + i*i) % TABLE_SIZE;
            break;
        case 3:
            return (hash1(key) + i*hash2(key)) % TABLE_SIZE;
            break;
    }
}

int hash1(int key) {
    return key % TABLE_SIZE;
}

int hash2(int key) {
    return DOUBLE_HASH_CONSTANT - (key % DOUBLE_HASH_CONSTANT);
}

void insert(int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int address = generate_address(option, key, i);

        if (ht[address] == -1) {
            ht[address] = key;
            return;
        }
    }
}

void search(int key) {
    int found = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        int address = generate_address(option, key, i);

        if (ht[address] == key) {
            found = 1;
            printf("%d was found!\n", key);
            break;
        }
    }

    if (found == 0) {
        printf("%d was NOT found\n", key);
    }
}



