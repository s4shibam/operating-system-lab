// Q. Create a child process using fork() and then
// use wait()

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int f;
	
	printf ("Before fork!\n");
	f = fork();	
	
	// The creation of the process was unsuccessful
	if (f < 0){
		
		printf ("Error occurred!\n");
	}
	
	// Child process
	else if (f == 0){
	
		printf ("This is Child Process!\n");
		printf ("Child: Child Process pid: %d\n", getpid());
		printf ("Child: Parent Process pid: %d\n", getppid());
	}
	
	// Parent process
	else {
	
		// Parent process will wait until execution of the child process
		wait(NULL);
		printf ("This is Parent Process!\n");
		printf ("Parent: Parent Process pid: %d\n", getpid());
		printf ("Parent: Child Process pid: %d\n", f);
	}
	
	// This part will be executed by both child & parent 
	printf ("This is common!\n");
}

/*
	Output:
	
	s4shibam@SHIBAM:~/OS$ gcc 7_Wait_In_Process.c
	s4shibam@SHIBAM:~/OS$ ./a.out
	Before fork!
	This is Child Process!
	Child: Child Process pid: 1980
	Child: Parent Process pid: 1979
	This is common!
	This is Parent Process!
	Parent: Parent Process pid: 1979
	Parent: Child Process pid: 1980
	This is common!
	s4shibam@SHIBAM:~/OS$ 
	
*/
