#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
        LOG_NORMAL,
        LOG_WARNING,
        LOG_ERROR,
        LOG_DEBUG,
        LOG_ALL
} log_level_t;

void LOG_printf(log_level_t log_level, const char* format, ...);

void LOG_set_level(log_level_t log_level);

void LOG_set_logger_name(const char* name);

#endif
