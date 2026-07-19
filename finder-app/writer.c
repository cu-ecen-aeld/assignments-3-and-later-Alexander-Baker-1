#include <stdio.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        syslog(LOG_ERR, "Missing parameters");
        return 1;
    }

    char *writefile = argv[1];
    char *writestr = argv[2];

    openlog("writer", LOG_PID, LOG_USER);

    FILE *fptr;

    fptr = fopen(writefile, "w");

    if (fptr == NULL) {
        syslog(LOG_ERR, "File could not be created");
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    fputs(writestr, fptr);

    fclose(fptr);

    closelog();

    return 0;
}