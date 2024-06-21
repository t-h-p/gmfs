#include<stdio.h>
#include<dirent.h>
#include<graphviz/gvc.h>
#include<sys/stat.h>

typedef struct Node {
    char* name;
    bool is_dir;
    struct node *children[];
} Node_t;

struct Args_s {
    bool dir_only;
    char* path_name;
} Args_default = {false, "."}; /* Initialize as "Args mInstance = Args_default;"*/

typedef struct Args_s Args;

int main (int argc, char *argv[]) {

    Args mArgs = Args_default;

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') { /* if option */
            switch (argv[i][1]) {
                case 'd':
                    mArgs.dir_only = true;
            }
        } else {
            for (int j = 0; argv[i][j] != '\0'; j++) {
                mArgs.path_name += argv[i][j];
            }
        }
    }
    return 0;
}
