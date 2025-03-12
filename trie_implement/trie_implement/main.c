//
//  main.c
//  trie_implement
//
//  Created by Ege Kaya on 12/03/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Trie {
    char* string;
    struct Trie* next_word;
} Trie;

Trie* trieCreate() {
    Trie* new_trie = (Trie*)malloc(sizeof(Trie));
    if (!new_trie) return NULL;
    new_trie->string = NULL;
    new_trie->next_word = NULL;
    return new_trie;
}

void trieInsert(Trie* obj, char* word) {
    if (!obj) return;
    Trie* inserted_trie = (Trie*)malloc(sizeof(Trie));
    if (!inserted_trie) return;
    inserted_trie->string = strdup(word);
    inserted_trie->next_word = NULL;

    Trie* temp = obj;
    while (temp->next_word) {
        temp = temp->next_word;
    }
    temp->next_word = inserted_trie;
}

bool trieSearch(Trie* obj, char* word) {
    if (!obj) return false;
    Trie* temp = obj->next_word;
    while (temp) {
        if (strcmp(temp->string, word) == 0)
            return true;
        temp = temp->next_word;
    }
    return false;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    if (!obj) return false;
    Trie* temp = obj->next_word;
    while (temp) {
        if (strncmp(temp->string, prefix, strlen(prefix)) == 0)
            return true;
        temp = temp->next_word;
    }
    return false;
}

void trieFree(Trie* obj) {
    if (!obj) return;
    Trie* temp = obj;
    while (temp) {
        Trie* next = temp->next_word;
        if (temp->string) free(temp->string);
        free(temp);
        temp = next;
    }
}

int main(void) {
    Trie* obj = trieCreate();
    trieInsert(obj, "apple");
    printf("Search 'apple': %d\n", trieSearch(obj, "apple"));
    printf("Search 'app': %d\n", trieSearch(obj, "app"));
    printf("Prefix 'app': %d\n", trieStartsWith(obj, "app"));
    trieInsert(obj, "app");
    printf("Search 'app' after inserting: %d\n", trieSearch(obj, "app"));
    trieFree(obj);
    return 0;
}
