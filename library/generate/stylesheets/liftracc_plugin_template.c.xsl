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

<xsl:param name="PREFIX">liftracc_plugin_</xsl:param>
<xsl:param name="UUID">????????-????-????-????-????????????</xsl:param>
<xsl:param name="PRIO">?</xsl:param>
<xsl:param name="NAME">?</xsl:param>
<xsl:param name="DESC">?</xsl:param>

<!-- document output options -->
<xsl:output method="text"/>
<xsl:strip-space elements="*"/>

<xsl:template match="*">
<xsl:apply-templates/>
</xsl:template>


<xsl:template match="/blas_functions">
<![CDATA[/**
 * Template file to create new plugins easily.
 * Delete unneeded functions and fill in code to fulfill your functionality.
 */

#include "liftracc.h"
#include "plugin.h"
#include "logging.h"
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

plugin_info_t liftracc_plugin_info = {
    "]]><xsl:value-of select="$UUID"/><![CDATA[", // uuid
    "]]><xsl:value-of select="$NAME"/><![CDATA[", // name
    "]]><xsl:value-of select="$DESC"/><![CDATA[", // description
    ]]><xsl:value-of select="$PRIO"/><![CDATA[, // priority 0-255 0:low
};

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
    INFO("%s loaded.", liftracc_plugin_info.name);
}

void __attribute__ ((destructor)) liftracc_plugin_unload(void)
{
    INFO("%s unloaded.", liftracc_plugin_info.name);    
}

]]>
<xsl:apply-templates/>
</xsl:template>

<xsl:template match="/blas_functions//*//function">
  <xsl:value-of select="dyn:evaluate(concat('$',@type))"/>
  <xsl:text> </xsl:text>
  <xsl:value-of select="concat($PREFIX, @name)"/>
  <xsl:text>(</xsl:text>
  <xsl:value-of select="helper:type-param-str()"/><![CDATA[)
{
    ]]><xsl:text>INFO("%s</xsl:text><xsl:value-of select="concat('_', @name)"/><![CDATA[", liftracc_plugin_info.name);

}

]]>
</xsl:template>

</xsl:stylesheet>

