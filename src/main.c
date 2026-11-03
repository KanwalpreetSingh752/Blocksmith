#include <stdio.h>
#include <stdlib.h>

struct Block{
    size_t size;   //size of the memory block
    int free;       //1 means free, 0 means allocated
    struct Block *next;     //Stores the address of another Block
};

int main(){
    struct Block *block = malloc(sizeof(struct Block));

    //checking if malloc succeeded
    if(block == NULL){
        return -1;
    }

    block->size = 100;
    block->free = 1;
    block->next = NULL;

    
    printf("Size: %zu\n", block->size);
    printf("Free: %d\n", block->free);
    printf("Next: %p\n", (void*)block->next);
    printf("Header size: %zu bytes\n", sizeof(struct Block));

    //After calling free, The pointer variable block still exists and retains its old address,
    // but the memory at that address is no longer valid for your use.
    //This is called a dangling pointer.
    free(block);

    //to make it null
    block = NULL;
    return 0;
    

    //double free vulnerability
    //if you call free on same ptr twice, The second free() is undefined behavior 
    //because you're attempting to release memory that has already been freed.
}

