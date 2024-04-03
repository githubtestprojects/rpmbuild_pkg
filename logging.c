#include "logging.h"
#include <time.h>

FILE *openlog(void) {
    FILE *fp;
    fp = fopen(LOGGING_FILE, "a");
    if (fp == NULL) fprintf( stderr, "Unable to open \"%s\" log file\n", LOGGING_FILE);
    return fp;
}

int logmessage(FILE *fp, char *message){
    time_t timer;
    char timestamp[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    return fprintf(fp, "%s - %s", timestamp, message);
}

void closelog(FILE *fp){
    fclose(fp);
}
