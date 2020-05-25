#include "driver.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    char *pid_tag = "--pid",
         *period_tag = "--period";

    int pid, period;

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], pid_tag) == 0)
            pid = atoi(argv[++i]);
        else if (strcmp(argv[i], period_tag) == 0)
            period = atoi(argv[++i]);
    }
    while (true)
    {
        printf("%s\n-----------------------------------------\n\n", get_info(pid, period)[0]);
        

        sleep(period);
    }
}
