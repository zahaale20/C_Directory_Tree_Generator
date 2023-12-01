#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void tree(const char *dir, int level) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if ((dp = opendir(dir)) == NULL) {
        perror("Error: Cannot open directory");
        return;
    }
}

int main(int argc, char *argv[]) {
    int arg_start = 1;

    tree(argv[1], 0);
    return 0;
}