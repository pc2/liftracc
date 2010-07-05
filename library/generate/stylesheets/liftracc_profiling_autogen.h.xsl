<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:func="http://exslt.org/functions"
  xmlns:dyn="http://exslt.org/dynamic"
  xmlns:helper="helper"
  extension-element-prefixes="func dyn helper">

<!-- import type definitions -->
<xsl:import href="ctypes.xsl"/>

<!-- import helper functions -->
<xsl:import href="helper_functions.xsl"/>

<xsl:param name="PREFIX">LIFTRACC_FUNCTION_</xsl:param>

<!-- document output options -->
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="*">
<xsl:apply-templates/>
</xsl:template>


<xsl:template match="/blas_functions">
<![CDATA[/**
 * \file liftracc_profiling_autogen.h
 * \brief [generated file]
 */

/* This file is generated automatically, do not edit manually! */

#ifndef __LIFTRACC_PROFILING_AUTOGEN_H__
#define __LIFTRACC_PROFILING_AUTOGEN_H__

#if _LIFTRACC_PROFILING_ > 0

typedef enum {
    LIFTRACC_INIT,
    LIFTRACC_FINI,]]>
<xsl:apply-templates/><![CDATA[    LIFTRACC_FUNCTIONS_COUNT
} liftracc_functions_t;

#endif // _LIFTRACC_PROFILING_

#endif // __LIFTRACC_PROFILING_AUTOGEN_H__
]]>
</xsl:template>

<xsl:template match="/blas_functions//*//function">
  <xsl:text>    </xsl:text>
  <xsl:value-of select="concat($PREFIX, helper:upper-case(@name))"/>
  <xsl:text>,
</xsl:text>
</xsl:template>

</xsl:stylesheet>

