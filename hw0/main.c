#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/time.h>
#include <sys/resource.h>


/* Print error message and exit with error status. If PERR is not 0,
 *    display current errno status. */
static void
error_print (int perr, char *fmt, va_list ap)
{
    vfprintf (stderr, fmt, ap);
    if (perr)
        perror (" ");
    else
        fprintf (stderr, "\n");
    exit (1);
}

/*
* Print error message followed by errno status and exit
*    with error code. */
static void
perrf (char *fmt, ...)
{
    va_list ap;

    va_start (ap, fmt);
    error_print (1, fmt, ap);
    va_end (ap);
}

#define RESOURCE_NUMBER 3
int main() {
    struct rlimit lim;
    int resources[RESOURCE_NUMBER] = {RLIMIT_STACK, RLIMIT_NPROC,RLIMIT_NOFILE};
    char * resource_names[RESOURCE_NUMBER] = {"stack limit (bytes): ", "process limit: ", "max file descriptors: "};
    for(int i = 0; i < RESOURCE_NUMBER; ++i) {
        if(0 == getrlimit(resources[i], &lim)) {
            printf("%s %lld\n", resource_names[i], (long long)lim.rlim_cur);
        } else {
            perrf("cannot retrieve the resouce `%s'", resource_names[i]);
            return -1;
        }
    }
}
