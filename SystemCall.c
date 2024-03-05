#include <dirent.h>

int main() {
    pid_t child_pid;
    int status;

 
    child_pid = fork();
    if(pid<0){
    printf("fork failed");
    exit(1);
    }

    else if (child_pid == 0) {
       
        printf("Child process id is : %d, parent process id is : %d\n", getpid(), getppid());
        exit(0);
    } else {
     
        printf("Parent process (PID: %d), is waiting for child process (PID:%d) to cpmplete\n", getpid(), child_pid);
        wait(&status);
        printf("Parent process: Child has terminated with status : %d\n", status);
    }

 
    DIR *dir = opendir(".");
    struct dirent *entry;

    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        printf(" %s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
