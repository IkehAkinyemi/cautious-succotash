#include <fcntl.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
	int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC | S_IRWXU);
	assert(fd > -1);
	int rc = write(fd, "Hello, world!\n", 15);
	assert(rc == 15);
	close(fd);
	return 0;
}