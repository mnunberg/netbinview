#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <arpa/inet.h>
#include <inttypes.h>

int main(int argc, char **argv)
{
    char *progname, *cmdname = NULL, *argstring = NULL;
    char resbuf[1024];
    unsigned long arg;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s: <ARG>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    progname = strdup(argv[0]);
    progname = basename(progname);

    if (argc == 2) {
        argstring = argv[1];
        cmdname = progname;

    } else {
        cmdname = argv[1];
        argstring = argv[2];
    }

    if (sscanf(argstring, "%lu", &arg) != 1) {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (!strcmp(cmdname, "htonl")) {
        sprintf(resbuf, "%" PRIu32 , htonl(arg));

    } else if (!strcmp(cmdname, "htons")) {
        sprintf(resbuf, "%" PRIu16, htons((unsigned short)arg));

    } else if (!strcmp(cmdname, "ntohl")) {
        sprintf(resbuf, "%" PRIu32, ntohl(arg));

    } else if (!strcmp(cmdname, "ntohs")) {
        sprintf(resbuf, "%h" PRIu16, ntohs((unsigned short)arg));

    } else {
        fprintf(stderr, "Invalid command. Invoke from symlink\n");
        exit(EXIT_FAILURE);

    }

    printf("%s\n", resbuf);
    exit(EXIT_SUCCESS);
}
