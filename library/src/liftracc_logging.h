/**
 * \file liftracc_logging.h
 * \brief Logging definitions of the liftracc lib
 *
 * \author Manuel Niekamp <niekma@upb.de>
 * \version 0.1
 * \date 10/2009-03/2010
 *
 * Implements the logging mechanism used by the library.
 * The log level is controlled via -D compiler parameters.
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

