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

<xsl:param name="PREFIX">CBLAS_FUNCTION_</xsl:param>

<!-- document output options -->
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="*">
<xsl:apply-templates/>
</xsl:template>


<xsl:template match="/blas_functions">
<![CDATA[/**
 * \file cblas_autogen.h
 * \brief [generated file]
 */

/* This file is generated automatically, do not edit manually! */

#ifndef __CBLAS_AUTOGEN_H__
#define __CBLAS_AUTOGEN_H__

typedef enum {]]>
<xsl:apply-templates/><![CDATA[    CBLAS_FUNCTIONS_COUNT
} liftracc_cblas_functions_t;

extern const char *liftracc_cblas_function_names[];

#endif /* __CBLAS_AUTOGEN_H__ */
]]>
</xsl:template>

<xsl:template match="/blas_functions//*//function">
  <xsl:text>    </xsl:text>
  <xsl:value-of select="concat($PREFIX, helper:upper-case(@name))"/>
  <xsl:text>,
</xsl:text>
</xsl:template>

</xsl:stylesheet>

