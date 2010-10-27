/**
 * @file liftracc_logging.h
 * @brief Logging definitions of the liftracc lib
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * Implements the logging mechanism used by the library.
 * The log level is controlled via -D compiler parameters.
 * Diffetent log level can be selected via ccmake.
 *
 * <b>\#define _DEBUG_</b><br>
 * Turn on and off debug messages globally.
 *
 * <b>\#define _DEBUG_LEVEL_</b><br>
 * Defines the debug level.<br>
 * 0-NONE<br>
 * 1-ERROR<br>
 * 2-ERROR,MSG<br>
 * 3-ERROR,MSG,WARN<br>
 * 4-ERROR,MSG,WARN,INFO
 */
#ifndef __LIFTRACC_LOGGING_H__
#define __LIFTRACC_LOGGING_H__

#include <stdio.h>

#ifdef _DEBUG_

#if _DEBUG_LEVEL_ < 4
#define INFO(...)
#else
#define INFO(...) fprintf(stderr, "[I] "), fprintf(stderr, __VA_ARGS__), fprintf(stderr, " (%s:%d)\n", __FILE__, __LINE__)
#endif

#if _DEBUG_LEVEL_ < 3
#define WARN(...)
#else
#define WARN(...) fprintf(stderr, "[W] "), fprintf(stderr, __VA_ARGS__), fprintf(stderr, " (%s:%d)\n", __FILE__, __LINE__)
#endif

#if _DEBUG_LEVEL_ < 2
#define MSG(...)
#else
#define MSG(...) fprintf(stderr, "--- "), fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n")
#endif

#if _DEBUG_LEVEL_ < 1
#define ERROR(...)
#else
#define ERROR(...) fprintf(stderr, "[E] "), fprintf(stderr, __VA_ARGS__), fprintf(stderr, " (%s:%d)\n", __FILE__, __LINE__)
#endif

#else

#define MSG(...)
#define INFO(...)
#define WARN(...)
#define ERROR(...)

#endif


#endif // __LIFTRACC_LOGGING_H__

