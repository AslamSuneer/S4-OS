#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    struct dirent *dptr; 
    int pid;
    pid = fork(); 

    if (pid < 0) { 
        printf("Fork failed\n");
        exit(1);
    } else if (pid == 0) { 
        printf("Child process Id: %d\n", getpid()); 
        if (execlp("ls", "ls", "-l", NULL) < 0) { 
            printf("Error in executing ls\n"); 
            exit(1);
        }
    } else {
        int status; 
        if (wait(&status) < 0) { 
            printf("Error in wait\n"); 
            exit(1); 
        }
        printf("Parent id %d\n", getpid());
        printf("Child process exited with status %d\n", WEXITSTATUS(status));
    }

    char buff[100];
    DIR *dirp;
    printf("Enter directory name: \n");
    scanf("%s", buff);

    if ((dirp = opendir(buff)) == NULL) {
        printf("Error in opening directory\n");
        exit(1);
    } else {
        while ((dptr = readdir(dirp)) != NULL) {
            printf("%s\n", dptr->d_name);
        }
    }

    closedir(dirp);

    return 0;
}
