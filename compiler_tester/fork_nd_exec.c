#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	
	if(pid == -1){
		perror("fork");
		return 1;
	}else if(pid == 0){
	// LS - Example
	//	execl("/bin/ls", "ls", "-la", NULL);
		execl("/bin/echo", "echo", "It", "Works", NULL);
		perror("execl");
		return 1;
	}else{
		int status;
		waitpid(pid, &status, 0);
	}
}
