#include <stdio.h>
#include <stdlib.h>

#include "conf.h"
#include "rule.h"

int addRule() {
    zlog_rule_t *a_rule = NULL;

    printf("Env ptr: [%p]\n", zlog_env_conf);

    new_rule_setting_t settings;

    strcpy(settings.category, "my_cat");
    strcpy(settings.level, ".DEBUG");
    strcpy(settings.file_path, ">stdout");

    if((a_rule = zlog_rule_new_capi(
			zlog_env_conf->levels,
			zlog_env_conf->default_format,
			zlog_env_conf->formats,
			zlog_env_conf->file_perms,
			zlog_env_conf->fsync_period,
			&(zlog_env_conf->time_cache_count),
            settings)) == NULL)
    {
        printf("a_rule == NULL\n");
        return(-1);
    }
    printf("a_rule: [%p]\n", a_rule);

    printf("add: [%d]\n", zc_arraylist_add(zlog_env_conf->rules, a_rule));
    return(0);
}
