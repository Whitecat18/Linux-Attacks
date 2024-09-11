#include <stdio.h>

int main(){
    FILE *fp;
    char path[1035];

    fp = popen("ls -a", "r");
    if (fp == NULL) {
        printf("Failed to run command\n" );
        return 1;
    }

    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    pclose(fp);

}
