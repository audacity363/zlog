#include <stdio.h>
#include <stdlib.h>

#include "zlog.h"

int addRule();

int main() {
    int rc = 0;
    zlog_category_t *c;

    if((rc = zlog_init(NULL)) != 0) {
       fprintf(stderr, "Init failed\n");
       return(-1);
    }

    if(addRule() != 0) {
        return(-1);
    }
    
    if((c = zlog_get_category("my_cat")) == NULL) {
        fprintf(stderr, "Could not get cat\n");
        return(-2);
    }

    zlog_info(c, "Hello World");
    zlog_debug(c, "Hello World2");

    zlog_fini();
}
