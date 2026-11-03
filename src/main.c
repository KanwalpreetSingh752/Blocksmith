#include <stdio.h>

struct Block{
    size_t size;   //size of the memory block
    int free;       //1 means free, 0 means allocated
    struct Block *next;     //Stores the address of another Block
};

int main(){
    struct  Block block;
    
    block.size = 100;
    block.free = 1;
    block.next = NULL;

    printf("Size: %zu\n", block.size);
    printf("Free: %d\n", block.free);
    printf("Next: %p\n", (void*)block.next);
    printf("Header size: %zu bytes\n", sizeof(struct Block));

    return 0;
    
}