#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int 
main(int argc,char *argv[])
{
    reset_syscall_count();
    for (int i = 0; i < 3; i++) {
            int pid = fork();
            if (pid == 0) {
                
                printf(1, "Child %d: PID=%d\n", i, getpid());
                exit();
            } else if (pid > 0) {
                
                printf(1, "Parent: Forked child with PID=%d\n", pid);
                wait();
            } else {

                printf(1, "Fork failed\n");
            }
        }


        printf(1, "fork() count: %d\n", get_syscall_count(0));
        printf(1, "wait() count: %d\n", get_syscall_count(1));
        printf(1, "exit() count: %d\n", get_syscall_count(2));

        // Reset the invocation counts
        reset_syscall_count();

        // Retrieve and print the counts after resetting
    

        printf(1, "Invocation counts after reset:\n");
        printf(1, "fork() count: %d\n", get_syscall_count(0));
        printf(1, "wait() count: %d\n", get_syscall_count(1));
        printf(1, "exit() count: %d\n", get_syscall_count(2));

        exit();   
    return 0;
}

