#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed");
    exit(1);
  } else if (rc == 0) {
    close(STDOUT_FILENO);
    open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    
    // now exec "wc"
    char *wc_args[3];
    wc_args[0] = strdup("wc");
    wc_args[1] = strdup("p4.c");
    wc_args[2] = NULL;
    execvp(wc_args[0], wc_args);
  } else {
      int rc_wait = wait(NULL);
  }
  
  return 0;
}
