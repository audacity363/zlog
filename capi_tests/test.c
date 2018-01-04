#include <stdio.h>
#include <stdlib.h>

#include "conf.h"
#include "rule.h"

void addRule() {
    zlog_rule_t *a_rule = NULL;

    printf("Env ptr: [%p]\n", zlog_env_conf);

    a_rule = zlog_rule_new_test("my_cat.INFO >stdout",
			zlog_env_conf->levels,
			zlog_env_conf->default_format,
			zlog_env_conf->formats,
			zlog_env_conf->file_perms,
			zlog_env_conf->fsync_period,
			&(zlog_env_conf->time_cache_count));
    printf("a_rule: [%p]\n", a_rule);

    printf("add: [%d]\n", zc_arraylist_add(zlog_env_conf->rules, a_rule));

}
