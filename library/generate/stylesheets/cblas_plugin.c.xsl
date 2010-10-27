<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:func="http://exslt.org/functions"
  xmlns:dyn="http://exslt.org/dynamic"
  xmlns:helper="helper"
  extension-element-prefixes="func dyn helper">

<!-- import type definitions -->
<xsl:import href="ctypes.xsl"/>

<!-- import my user defined functions -->
<xsl:import href="helper_functions.xsl"/>

<xsl:param name="PREFIX">liftracc_plugin_</xsl:param>
<xsl:param name="UUID">f4a17438-80ed-4f9f-90f1-1728df8ea630</xsl:param>
<xsl:param name="PRIO">1</xsl:param>
<xsl:param name="NAME">liftracc_cblas_plugin</xsl:param>
<xsl:param name="DESC">wrapper to standard blas library</xsl:param>

<!-- document output options -->
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="*">
<xsl:apply-templates/>
</xsl:template>


<xsl:template match="/blas_functions">
<![CDATA[/**
 * @file cblas_plugin.c
 * @brief [generated file]
 *
 * This file is generated automatically, do not edit manually!
 */

#include "liftracc.h"
#include "liftracc_plugin.h"
#include "liftracc_logging.h"
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <stdlib.h>

#include "cblas_autogen.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
#include "liftracc_selector.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = { };
#endif  /* _LIFTRACC_PROFILING_ */

decision_data_t decision_data[FUNCTION_COUNT*ARRAY_SIZE] = { };

void *liftracc_plugin_fptr[CBLAS_FUNCTIONS_COUNT] = { };

plugin_info_t liftracc_plugin_info = {
    .uuid = "]]><xsl:value-of select="$UUID"/><![CDATA[",
    .name = "]]><xsl:value-of select="$NAME"/><![CDATA[",
    .desc = "]]><xsl:value-of select="$DESC"/><![CDATA[",
    .prio = ]]><xsl:value-of select="$PRIO"/><![CDATA[
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    char *libname = getenv("USE_CBLAS_LIB");
    
    if (libname)
        handle = dlopen(libname, RTLD_LAZY);

    if (!handle)
        handle = dlopen("libcblas_inner.so", RTLD_LAZY);

    if (!handle)
        ERROR("%s", dlerror());
    else
        INFO("%s loaded.", liftracc_plugin_info.name);

    char plugin_data_filename[PATH_MAX];
    Dl_info info;
    dladdr(liftracc_plugin_load, &info);
    strncpy(plugin_data_filename, info.dli_fname, PATH_MAX);
#ifdef _LIFTRACC_AUTOMODE_
    strncat(plugin_data_filename, ".data", PATH_MAX-strlen(plugin_data_filename)-1);
    MSG("plugin_data_filename: %s", plugin_data_filename);
#else /* _LIFTRACC_AUTOMODE_ */
    strncat(plugin_data_filename, ".txt", PATH_MAX-strlen(plugin_data_filename)-1);
    MSG("plugin_data_filename: %s", plugin_data_filename);
#endif /* _LIFTRACC_AUTOMODE_ */
    liftracc_selector_loadinfo(plugin_data_filename, &decision_data[0]);

    int i;
    for (i=0; i<CBLAS_FUNCTIONS_COUNT; i++) {
        liftracc_plugin_fptr[i] = dlsym(handle, liftracc_cblas_function_names[i]);
    }

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */ 
}

void __attribute__ ((destructor)) liftracc_plugin_unload(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FINI]));
#endif /* _LIFTRACC_PROFILING_ */
    if (handle) dlclose(handle);
        handle = 0;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    char plugin_data_filename[PATH_MAX];

    Dl_info info;
    dladdr(liftracc_plugin_load, &info);
    strncpy(plugin_data_filename, info.dli_fname, PATH_MAX);
    strncat(plugin_data_filename, ".data", PATH_MAX-strlen(plugin_data_filename)-1);

    MSG("plugin_data_filename: %s", plugin_data_filename);

    liftracc_selector_saveinfo(plugin_data_filename, &decision_data[0]);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

    INFO("%s unloaded.", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FINI]));
    print_profiling_data(liftracc_plugin_info.name, &(function_profiling_data[0]), liftracc_function_names, LIFTRACC_FUNCTIONS_COUNT);
#endif /* _LIFTRACC_PROFILING_ */
}

decision_data_t liftracc_plugin_getdecision(liftracc_selector_funcid_t id, int index)
{
#ifdef _LIFTRACC_AUTOMODE_
    return decision_data[id*ARRAY_SIZE+index];
#else
    if (decision_data[id*ARRAY_SIZE+index] > 0)
        return decision_data[id*ARRAY_SIZE+index];
    return liftracc_plugin_info.prio;
#endif /* _LIFTRACC_AUTOMODE_ */
}

#if _LIFTRACC_PROFILING_ == 1
int liftracc_plugin_calltest_dynamic(int a, int b, int c)
{
    liftracc_function_timing_stop(&(liftracc_profiling_data[CALL_DYNAMIC]));
    /* INFO("liftracc_plugin_calltest_dynamic"); */
    return rand()-a*b+c;
}
#endif /* _LIFTRACC_PROFILING_  */

]]>
<xsl:apply-templates/>
</xsl:template>

<xsl:template match="/blas_functions//*//function">
  <xsl:value-of select="dyn:evaluate(concat('$',@type))"/><xsl:text> </xsl:text><xsl:value-of select="concat($PREFIX, @name, '(')"/><xsl:value-of select="helper:type-param-str()"/><![CDATA[)
{
    INFO("%s]]><xsl:value-of select="concat('_', @name)"/><![CDATA[", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[]));
#endif /* _LIFTRACC_PROFILING_ */
    
    int success = 1;
    ]]><xsl:value-of select="dyn:evaluate(concat('$',@type))"/><![CDATA[ (*func)();
    ]]><xsl:if test="@type!='VOID_TYPE'"><xsl:value-of select="dyn:evaluate(concat('$',@type))"/><![CDATA[ ret = 0.0;
    ]]></xsl:if><![CDATA[
    *(void **) (&func) = liftracc_plugin_fptr[]]><xsl:value-of select="concat('CBLAS_FUNCTION_', helper:upper-case(@name))"/><![CDATA[];
    
    if (func != 0) {
        ]]><xsl:if test="@type!='VOID_TYPE'"><![CDATA[ret = ]]></xsl:if><![CDATA[(*func)(]]><xsl:value-of select="helper:param-str()"/><![CDATA[);]]><![CDATA[
    } else {
        success = 0;
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
]]><xsl:choose>
<xsl:when test="@name='srotg'"><![CDATA[    int n = 0;]]></xsl:when>
<xsl:when test="@name='srotmg'"><![CDATA[    int n = 0;]]></xsl:when>
<xsl:when test="@name='drotg'"><![CDATA[    int n = 0;]]></xsl:when>
<xsl:when test="@name='drotmg'"><![CDATA[    int n = 0;]]></xsl:when>
<xsl:when test="@name='xerbla'"><![CDATA[    int n = 0;]]></xsl:when>
<xsl:otherwise><![CDATA[]]></xsl:otherwise>
</xsl:choose><![CDATA[
    set_decision_data(success, &decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[, SELECT_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

]]><xsl:if test="@type!='VOID_TYPE'"><![CDATA[

    return ret;

]]></xsl:if><![CDATA[}]]>
<xsl:text>

</xsl:text>
</xsl:template>

</xsl:stylesheet>

