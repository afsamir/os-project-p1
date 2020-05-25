#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<stdbool.h>

char **get_info(int pid, int period)
{

    char **data = (char**)calloc (100, sizeof(char*));
    
    int buff_size = 100, data_size;
    char *str = (char *)calloc(100, sizeof(char));
    char *filename = (char *)calloc(100, sizeof(char));
    char *data_buf = (char*)calloc (buff_size, sizeof(char));
    char *fd_buf = (char*)calloc (buff_size, sizeof(char));

    sprintf(str, "pid: %d, period: %d", pid, period);
    sprintf(filename, "/proc/%d/status", pid);
    readlink("/proc/9942/fd/5", fd_buf, 100);

    int src = open(filename, O_RDONLY);
    if (src < 0)
    {
        printf("No source\n");
    }

    // while (true){
        data_size = read(src, data_buf, buff_size);
    //     if (data_size <= 0)
    //         break;
        
    //     printf("%s", data_buf);
    // }

    data[0] = data_buf;
    return data;
}
