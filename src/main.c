#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<graphviz/gvc.h>
#include<sys/stat.h>
#include "nodes.h"
#include "graph.h"

const int MAX_SIZE = 255;

typedef struct {
    int dir_only;
    char* file_type;
    char* path;
    char* output_path;
} Args;

struct Node* createNode(struct dirent d);

int isDirectory(const char *path);

char* readArgString(int arg_num, char* argv[]);

int main (int argc, char *argv[]) {
    Args mArgs = {
        .dir_only = 0,
        .file_type = "png",
        .path = ".",
        .output_path = "."
    };

    bool was_input = false;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') { /* if option */
            switch (argv[i][1]) {
                case 'd':
                    mArgs.dir_only = true;
                    break;
                case 'T':
                    mArgs.file_type = readArgString(i, argv);
                    break;
            }
        } else if (!was_input) {
            mArgs.path = readArgString(i, argv);
            was_input = 1;
        } else {
            mArgs.output_path = readArgString(i, argv);
        }
    }

    printf("%d", mArgs.dir_only);
    printf("\n");
    puts(mArgs.file_type);
    puts(mArgs.path);
    puts(mArgs.output_path);

    
    free(mArgs.file_type);
    free(mArgs.path);
    free(mArgs.output_path);
    
    return 0;
}

int isDirectory(const char *path) {
    struct stat stats;
    stat(path, &stats);
    S_ISDIR(stats.st_mode) ? 1 : 0;
}

char* readArgString(int arg_num, char *argv[]) {
    char *option = (char*) malloc(MAX_SIZE*sizeof(char));
    if (argv[arg_num][0] != '-') {
        strcpy(option, &(argv[arg_num][0]));
    } else {
        strcpy(option, &(argv[arg_num][2]));
    }
    return option;
}



