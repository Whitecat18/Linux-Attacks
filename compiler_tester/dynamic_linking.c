#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    int (*system_ptr)(const char *) = dlsym(RTLD_NEXT, "system");
    if (system_ptr == NULL) {
        fprintf(stderr, "Error: Unable to resolve 'system'\n");
        return 1;
    }

    system_ptr("ls -al");

    system_ptr("echo 'It Works'");

    return 0;
}
