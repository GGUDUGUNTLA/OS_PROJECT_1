// #include "types.h"
// #include "stat.h"
// #include "user.h"

// int
// main(int argc, char *argv[]){

//     // printf(1, "%d \n", get_syscall_count(0));
//     // printf(1, "%d \n", get_syscall_count(1));
//     // printf(1, "%d \n", get_syscall_count(2));

//     // fork();
//     // //fork();
//     // //fork();



//     // printf(1, "%d \n", get_syscall_count(0));
//     // printf(1, "%d \n", get_syscall_count(1));
//     // printf(1, "%d \n", get_syscall_count(2));

    // return 0;

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main(int argc,char *argv[])
{

    for (int i = 0; i < 1; i++) {
        int pid = fork();
        if (pid == 0) {
            // Child process
            printf(1, "Child %d: PID=%d\n", i, getpid());
            exit();
        } else if (pid > 0) {
            // Parent process
            printf(1, "Parent: Forked child with PID=%d\n", pid);
            wait();
        } else {
            // Fork failed
            printf(1, "Fork failed\n");
        }
    }

    // Retrieve and print the invocation counts for fork(), wait(), and exit()

    int count_fork = get_syscall_count(0); // 0 corresponds to fork()
    int count_wait = get_syscall_count(1); // 1 corresponds to wait()
    int count_exit = get_syscall_count(2); // 2 corresponds to exit()

     printf(1, "Invocation counts:\n");
    printf(1, "fork() count: %d\n", count_fork);
    printf(1, "wait() count: %d\n", count_wait);
    printf(1, "exit() count: %d\n", count_exit);

    // Reset the invocation counts
    reset_syscall_count();

    // Retrieve and print the counts after resetting
    int count_fork_reset = get_syscall_count(0);
    int count_wait_reset = get_syscall_count(1);
    int count_exit_reset = get_syscall_count(2);

    printf(1, "Invocation counts after reset:\n");
    printf(1, "fork() count: %d\n", count_fork_reset);
    printf(1, "wait() count: %d\n", count_wait_reset);
    printf(1, "exit() count: %d\n", count_exit_reset);

    exit();

}

