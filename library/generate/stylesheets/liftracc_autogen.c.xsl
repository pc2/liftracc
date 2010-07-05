<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:func="http://exslt.org/functions"
  xmlns:dyn="http://exslt.org/dynamic"
  xmlns:helper="helper"
  xmlns:local="local"
  extension-element-prefixes="func dyn helper local">

<!-- import type definitions -->
<xsl:import href="ctypes.xsl"/>

<!-- import helper functions -->
<xsl:import href="helper_functions.xsl"/>

<xsl:param name="PREFIX">liftracc_</xsl:param>

<!-- document output options -->
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="*">
<xsl:apply-templates/>
</xsl:template>

<func:function name="local:param-str">
  <xsl:variable name="TMP_STR">
    <xsl:for-each select="param">
      <xsl:choose>
        <xsl:when test="@name!='form'">
          <xsl:value-of select="@name"/>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="'str'"/>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:if test="position()!=last()">
        <xsl:text>, </xsl:text>
      </xsl:if>
    </xsl:for-each>
  </xsl:variable>
  <func:result select="$TMP_STR"/>
</func:function>

<func:function name="local:param-str-mkl">
  <xsl:variable name="TMP_STR">
    <xsl:for-each select="param">
      <xsl:choose>
        <xsl:when test="starts-with(@type, 'PTR_')">
          <xsl:choose>
            <xsl:when test="@name!='form'">
              <xsl:value-of select="@name"/>
            </xsl:when>
            <xsl:otherwise>
              <xsl:value-of select="'str'"/>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="concat('*',@name)"/>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:if test="position()!=last()">
        <xsl:text>, </xsl:text>
      </xsl:if>
    </xsl:for-each>
  </xsl:variable>
  <func:result select="$TMP_STR"/>
</func:function>


<xsl:template match="/blas_functions">
<![CDATA[/***
 * This file is generated automatically, do not edit manually!
 */

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

#include "liftracc.h"
#include "liftracc_logging.h"
#include "liftracc_selector.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
extern profiling_data_t liftracc_function_profiling_data[];
#endif

liftracc_selector_problem_info_t pinfo = { };

]]>
<xsl:apply-templates/>
</xsl:template>

<xsl:template match="/blas_functions//*//function"><![CDATA[
/***
 * ]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[
 */

]]><xsl:value-of select="dyn:evaluate(concat('$',@type))"/><xsl:text> </xsl:text><xsl:value-of select="concat($PREFIX, @name)"/><![CDATA[(]]><xsl:value-of select="helper:type-param-str()"/><xsl:if test="@name='xerbla'">, ...</xsl:if><![CDATA[)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[]));
#endif /* _LIFTRACC_PROFILING_ */
    ]]><xsl:if test="@name='xerbla'"><![CDATA[va_list argptr;
    char *str = 0;

    va_start(argptr, form);
    vasprintf(&str, form, argptr);
    va_end(argptr);
    
    ]]></xsl:if><xsl:value-of select="dyn:evaluate(concat('$',@type))"/><![CDATA[ (*liftracc_plugin_func)();
    ]]><xsl:if test="@type!='VOID_TYPE'"><xsl:value-of select="dyn:evaluate(concat('$',@type))"/><![CDATA[ ret = 0.0;]]></xsl:if><![CDATA[
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

]]><xsl:choose>
<xsl:when test="@name='srotg'"><![CDATA[    pinfo.info1 = 0;]]></xsl:when>
<xsl:when test="@name='srotmg'"><![CDATA[    pinfo.info1 = 0;]]></xsl:when>
<xsl:when test="@name='drotg'"><![CDATA[    pinfo.info1 = 0;]]></xsl:when>
<xsl:when test="@name='drotmg'"><![CDATA[    pinfo.info1 = 0;]]></xsl:when>
<xsl:when test="@name='xerbla'"><![CDATA[    pinfo.info1 = 0;]]></xsl:when>
<xsl:otherwise><![CDATA[    pinfo.info1 = n;]]></xsl:otherwise>
</xsl:choose><![CDATA[

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_]]><xsl:value-of select="helper:lower-case(@name)"/><![CDATA[");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ]]><xsl:if test="@name='xerbla'"><![CDATA[// call func without '...'
        ]]></xsl:if><xsl:if test="@type!='VOID_TYPE'"><![CDATA[ret = ]]></xsl:if><![CDATA[(*liftracc_plugin_func)(]]><xsl:value-of select="local:param-str()"/><![CDATA[);]]><![CDATA[
    } else
        ERROR("liftracc_]]><xsl:value-of select="helper:lower-case(@name)"/><![CDATA[ not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[]));
#endif /* _LIFTRACC_PROFILING_ */

    ]]><xsl:if test="@name='xerbla'"><![CDATA[free(str);]]></xsl:if><![CDATA[
    ]]><xsl:if test="@type!='VOID_TYPE'"><![CDATA[return ret;]]></xsl:if><![CDATA[
}

]]><xsl:value-of select="dyn:evaluate(concat('$',@type))"/><xsl:text> </xsl:text><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA[(]]><xsl:value-of select="helper:type-param-str-mkl()"/><xsl:if test="@name='xerbla'">, ...</xsl:if><![CDATA[)
{
    ]]><xsl:if test="@name='xerbla'"><![CDATA[va_list argptr;
    char *str = 0;

    va_start(argptr, form);
    vasprintf(&str, form, argptr);
    va_end(argptr);

    // call func without '...'
    ]]></xsl:if><xsl:if test="@type!='VOID_TYPE'"><![CDATA[return ]]></xsl:if><xsl:value-of select="concat($PREFIX, @name)"/><![CDATA[(]]><xsl:value-of select="local:param-str-mkl()"/><![CDATA[);]]><xsl:if test="@name='xerbla'"><![CDATA[
    free(str);]]></xsl:if><![CDATA[
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (]]><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA[) ]]><xsl:value-of select="@name"/><![CDATA[ __attribute__ ((alias("]]><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA["))); */
/* __typeof__ (]]><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA[) ]]><xsl:value-of select="concat(@name, '_')"/><![CDATA[ __attribute__ ((alias("]]><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA["))); */
__typeof__ (]]><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA[) ]]><xsl:value-of select="helper:upper-case(@name)"/><![CDATA[ __attribute__ ((alias("]]><xsl:value-of select="concat($PREFIX, @name, '_')"/><![CDATA[")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (]]><xsl:value-of select="concat($PREFIX, @name)"/><![CDATA[) ]]><xsl:value-of select="concat('cblas_', @name)"/><![CDATA[ __attribute__ ((alias("]]><xsl:value-of select="concat($PREFIX, @name)"/><![CDATA[")));
#endif // _LIFTRACC_CBLAS_INTERFACE_
]]>
</xsl:template>

</xsl:stylesheet>

