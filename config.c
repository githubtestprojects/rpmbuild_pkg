#include <stdlib.h>
#include <string.h>
#include "config.h"
#include "logging.h"

int loadconfig(struct settings *config, FILE  *logfp) {
    FILE * fp;
    char * line = NULL;
    char *key;
    char *value;
    size_t len = 0;
    ssize_t read;
    int status = 0;

    fp = fopen(CONFIG_FILE, "r");
    if (fp == NULL) {
        fprintf( stderr, "Unable to open \"%s\" file\n", CONFIG_FILE);
        return -1;
    }
    while ( (read=getline(&line, &len, fp) ) != -1 ) {
        key=strtok(line, "=");
        value=strtok(NULL, "\n");
        if(strcmp(key, "behavior")==0) {
           if (strcmp(value,"kind") !=0 && strcmp(value,"aggressive")!=0) {
             fprintf( stderr, "invalid value \"%s\" for setting behavior: can be either \"kind\" or \"aggressive\"\n", value);
             logmessage(logfp, "invalid value for setting behavior: can be either \"kind\" or \"aggressive\"\n");
             status=-1;
           }
           strncpy(config->behavior, value, 255);
        }
    }
    fclose(fp);
    if (line) free(line);
    return status; 
}
