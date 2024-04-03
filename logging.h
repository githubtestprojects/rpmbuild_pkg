#ifndef LOGGING_H_
  #define LOGGING_H_

#define LOGGING_FILE "../log/foo.log"

#include <stdio.h>

FILE *openlog(void);
int logmessage(FILE *fp, char *message);
void closelog(FILE *fp);

#endif
