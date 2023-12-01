#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>


int show_hidden = 0;  // flag for showing hidden files
int show_size = 0;    // flag for showing file sizes


void tree(const char *dir, int level) {
   DIR *dp;
   struct dirent *entry;
   struct stat statbuf;

   if ((dp = opendir(dir)) == NULL) {
       perror("Error: Cannot open directory");
       return;
   }

   chdir(dir);
   while ((entry = readdir(dp)) != NULL) {
       lstat(entry->d_name, &statbuf);

       // skip hidden files unless show_hidden is set
       if (!show_hidden && entry->d_name[0] == '.') continue;

       // skip '.' and '..'
       if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
           continue;

       // print the directory or file name with proper indentation/spacing/format
       for(int i = 0; i < level; i++){
           printf("|%s", "   ");
       }
       printf("|-- %s", entry->d_name);


       // print size if show_size is flagged
       if (show_size) {
           printf(" [size: %ld]", statbuf.st_size);
       }
       printf("\n");


       if (S_ISDIR(statbuf.st_mode)) {
           // Recursively call tree for subdirectories
           tree(entry->d_name, level + 1);
       }
   }
   chdir("..");
   closedir(dp);
}


int main(int argc, char *argv[]) {
   int arg_start = 1;

   // parse command-line switches
   for (int i = 1; i < argc; i++) {
       if (strcmp(argv[i], "-a") == 0) {
           show_hidden = 1;
           arg_start++;
       } else if (strcmp(argv[i], "-s") == 0) {
           show_size = 1;
           arg_start++;
       } else {
           break;
       }
   }

   // determine the directory to start from
   char *topdir = (arg_start < argc) ? argv[arg_start] : ".";

   printf("%s", topdir);
   
   if (show_size) {
       struct stat statbuf;
       if (lstat(topdir, &statbuf) != -1) {
           printf(" [size: %ld]", statbuf.st_size);
       }
   }

   printf("\n");

   tree(topdir, 0);

   return 0;
}
