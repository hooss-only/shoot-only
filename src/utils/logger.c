#include "logger.h"

#include <string.h>
#include <stdarg.h>
#include <stdio.h>

char logger_name[10] = "Main";
log_level_t global_log_level = LOG_NORMAL;

void print_log_level(log_level_t log_level);

void LOG_printf(log_level_t log_level, const char* format, ...) {
        va_list args;

        va_start(args, format);
        
        print_log_level(log_level);
        
        if (log_level <= global_log_level) {
                printf("%s] ", logger_name);
                vprintf(format, args);
        }

        va_end(args);
}

void LOG_set_level(log_level_t log_level) {
        global_log_level = log_level;
}

void LOG_set_logger_name(char name[10]) {
        strcpy(logger_name, name);
}

void print_log_level(log_level_t log_level) {
        switch (log_level) {
                case LOG_NORMAL:
                        printf("[NORMAL:");
                        break;
                case LOG_DEBUG:
                        printf("[DEBUG:");
                        break;
                case LOG_WARNING:
                        printf("[WARNING:");
                        break;
                case LOG_ERROR:
                        printf("[ERROR:");
                        break;
                default:
                        break;
        }
}
