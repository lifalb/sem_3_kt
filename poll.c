#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv){
	if(argc < 2){
		printf("Expected more than one param, got %d", argc);
		return -1;
	}
	struct pollfd* fdsPoll = (struct pollfd*) calloc(argc - 1, sizeof(struct polldf));
	for(int i = 0; i < argc - 1; i++){
		fdsPoll[i].fd = open(argv[i+1], O_NONBLOCK);
		if(fdsPoll[i].fd == -1)
			printf("mistake when trying top open %d file", i);
		fdsPoll[i].events = POLLIN;
	}
	
	char* files_content = (char*) calloc((argc - 1) * 1000, sizeof(char));
	while(poll(fdsPoll, argc - 1, -1) != -1){
		for(int i = 0; i < argc - 1; i++){
			if(fdsPoll[i].revents & POLLIN){
				size_file_content = read(fdsPoll[i].fd, files_contetn[i*1000], 1000);
				if(size_file_content > 0){
					buf[i*1000+size_file_content] = '\0';
					printf("fifo: %s\: %s", argv[i+1], files_content[i*1000];					
			}
		}
	free(fdsPoll);
	free(files_content);
	return 0;
}


