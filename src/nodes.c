#include<dirent.h>
#include "nodes.h"

typedef struct Node {
    char* name;
    int is_dir;
    struct node *children[];
} Node_t;

struct Node* node_gen(struct dirent d) {

}