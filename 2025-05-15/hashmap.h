#ifndef HASHMAP_H
#define HASHMAP_H
#define HASHMAP_SIZE 16

typedef struct EntryNode 
{
    char* key;
    void* val;
    struct EntryNode* next;
} EntryNode;


typedef struct HashMap 
{
    EntryNode** entries;
} HashMap;
EntryNode* init_entry(char* key, void* val);
HashMap* init_hashmap();
int hash(char* key);
void set(HashMap* hashmap, char* key, void* val);
void* get(HashMap* hashmap, char* key);
#endif