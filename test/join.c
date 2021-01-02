#include <stdio.h>

#define PZS_IMPLEMENTATION
#include "../pzslib/pzs_join.h"

#define check_string(var) { printf("Variable | size | strlen | string\n%s | %lu | %lu | %s\n", #var, sizeof(var), strlen(var), var); }

int main(int argc, char const *argv[])
{
    int args_size = pzs_join(NULL, " x ", argc, argv);
    char args[args_size];
    pzs_join((char*)&args, " x ", argc, argv);

    check_string(args);

    return 0;
}
