#ifndef CONFIG_H_
  #define CONFIG_H_

#define CONFIG_FILE "../etc/foo.conf"
#include <stdio.h>

struct settings {
  char behavior[255];
};

int loadconfig(struct settings *config, FILE *logfp);

#endif
