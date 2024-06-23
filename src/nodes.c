#include<dirent.h>
#include<sys/stat.h>
#include "nodes.h"

typedef struct Node {
    char* name;
    int is_dir;
    struct node *children[];
} Node_t;

struct Node* createNode(struct dirent d) {
    
}