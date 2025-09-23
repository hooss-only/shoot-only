#include "logger.h"

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char logger_name[10] = "Main";
log_level_t global_log_level = LOG_NORMAL;

void LOG_printf(log_level_t log_level, const char* format, ...) {
        va_list args;

        va_start(args, format);
        
        if (log_level <= global_log_level) {
                printf("[%s] ", logger_name);
                printf(format, args);
        }

        va_end(args);
}

void LOG_set_level(log_level_t log_level) {
        global_log_level = log_level;
}

void LOG_set_logger_name(char name[10]) {
        strcpy(logger_name, name);
}
