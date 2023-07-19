/*************************************************************************
 *                     COPYRIGHT NOTICE
 *            Copyright 2020 Horizon Robotics, Inc.
 *                   All rights reserved.
 *************************************************************************/
#ifndef UTILS_TIME_H
#define UTILS_TIME_H
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/time.h>/*PRQA S ALL*/
#include <logging.h>
#include "log.h"

#define ONE_SEC_TO_MS (1000)
#define ONE_SEC_TO_NS (1000000)
#define HB_TIME_CALCULATE_UNIT_1000      1000
#define HB_TIME_CALCULATE_UNIT_1000000   1000000
#define HB_TIME_CALCULATE_UNIT_FLOAT_1000000   1000000.0f

#define J5_LKOF_DEBUG (1)

#define MAX_LKOF_PRINT_LENGTH 512
#define MAX_LKOF_LARGE_PRINT_LENGTH 1024

typedef enum lkof_log_level {
		NONE = 0,
		LKOF_ERR,
		LKOF_WARN,
		LKOF_INFO,
		LKOF_DEBUG,
		MAX_LKOF_LOG_LEVEL
} lkof_log_level_e;

#if J5_LKOF_DEBUG
#define lkof_err(fmt, ...)		hb_utils_log_warpper(LKOF_ERR, lkof_pr_fmt(fmt), ##__VA_ARGS__)
#define lkof_warn(fmt, ...)		hb_utils_log_warpper(LKOF_WARN, lkof_pr_fmt(fmt), ##__VA_ARGS__)
#define lkof_dbg(fmt, ...)		hb_utils_log_warpper(LKOF_DEBUG, lkof_pr_fmt(fmt), ##__VA_ARGS__)
#define lkof_info(fmt, ...)		hb_utils_log_warpper(LKOF_INFO, lkof_pr_fmt(fmt), ##__VA_ARGS__)
#else
#define lkof_err(fmt, ...)		hb_utils_log_warpper(LKOF_ERR, lkof_pr_fmt(fmt), ##__VA_ARGS__)
#endif

#define android_printLog_dbg(fmt, ...)    android_printLog(3, NULL, fmt, ##__VA_ARGS__)
#define android_printLog_info(fmt, ...)    android_printLog(4, NULL, fmt, ##__VA_ARGS__)
#define android_printLog_warn(fmt, ...)    android_printLog(5, NULL, fmt, ##__VA_ARGS__)
#define android_printLog_err(fmt, ...)    android_printLog(6, NULL, fmt, ##__VA_ARGS__)
int32_t load_file_to_buff(const char *path, char *filebuff, int32_t size);
void time_add_ms(struct timeval *time, uint16_t ms);
int32_t get_cost_time_ms(struct timeval const *start, struct timeval const *end);
int32_t cond_timedwait_msecs(pthread_cond_t *cond,
		pthread_mutex_t * lock, long msecs);/*PRQA S ALL*/
int64_t get_time_ms(void);
void hb_utils_log_warpper(lkof_log_level_e level, const char *format, ...);//no need return value for check
#endif //UTILS_TIME_H
