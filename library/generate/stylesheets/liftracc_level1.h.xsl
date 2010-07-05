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

<xsl:param name="PREFIX">liftracc_</xsl:param>

<!-- document output options -->
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="*">
<xsl:apply-templates/>
</xsl:template>


<xsl:template match="/blas_functions">
<![CDATA[/**
 * \file liftracc_level1.h
 * \brief [generated file]
 */

/* This file is generated automatically, do not edit manually! */

#ifndef __LIFTRACC_LEVEL1_H__
#define __LIFTRACC_LEVEL1_H__

#include "liftracc_common.h"

]]>
<xsl:apply-templates/>
<![CDATA[#endif // __LIFTRACC_LEVEL1_H__

]]>
</xsl:template>

<xsl:template match="/blas_functions/level1_functions/function">
  <xsl:value-of select="dyn:evaluate(concat('$',@type))"/>
  <xsl:text> </xsl:text>
  <xsl:value-of select="concat($PREFIX, @name)"/>
  <xsl:text>(</xsl:text>
  <xsl:value-of select="helper:type-param-str()"/>
  <xsl:text>);</xsl:text>
  <xsl:text>
</xsl:text>
  <xsl:value-of select="dyn:evaluate(concat('$',@type))"/>
  <xsl:text> </xsl:text>
  <xsl:value-of select="concat($PREFIX, @name, '_')"/>
  <xsl:text>(</xsl:text>
  <xsl:value-of select="helper:type-param-str-mkl()"/>
  <xsl:text>);</xsl:text>
<xsl:text>

</xsl:text>
</xsl:template>

</xsl:stylesheet>

