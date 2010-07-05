<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:func="http://exslt.org/functions"
  xmlns:dyn="http://exslt.org/dynamic"
  xmlns:helper="helper"
  extension-element-prefixes="func dyn helper">

<func:function name="helper:upper-case">
  <xsl:param name="str"/>
  <xsl:variable name="lc" select="'abcdefghijklmnopqrstuvwxyz'"/>
  <xsl:variable name="uc" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>
  <func:result select="translate($str, $lc, $uc)"/>
</func:function>

<func:function name="helper:lower-case">
  <xsl:param name="str"/>
  <xsl:variable name="lc" select="'abcdefghijklmnopqrstuvwxyz'"/>
  <xsl:variable name="uc" select="'ABCDEFGHIJKLMNOPQRSTUVWXYZ'"/>
  <func:result select="translate($str, $uc, $lc)"/>
</func:function>

<func:function name="helper:type-param-str">
  <xsl:variable name="TMP_STR">
    <xsl:for-each select="param">
      <xsl:value-of select="dyn:evaluate(concat('$',@type))"/>
      <xsl:text> </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:if test="position()!=last()">
        <xsl:text>, </xsl:text>
      </xsl:if>
    </xsl:for-each>
    <!--<xsl:for-each select="params">
      <xsl:text>, ...</xsl:text>
    </xsl:for-each>-->
  </xsl:variable>
  <func:result select="$TMP_STR"/>
</func:function>

<func:function name="helper:param-str">
  <xsl:variable name="TMP_STR">
    <xsl:for-each select="param">
      <xsl:value-of select="@name"/>
      <xsl:if test="position()!=last()">
        <xsl:text>, </xsl:text>
      </xsl:if>
    </xsl:for-each>
  </xsl:variable>
  <func:result select="$TMP_STR"/>
</func:function>

<func:function name="helper:type-param-str-mkl">
  <xsl:variable name="TMP_STR">
    <xsl:for-each select="param">
      <xsl:choose>
        <xsl:when test="starts-with(@type, 'PTR_')">
          <xsl:value-of select="dyn:evaluate(concat('$',@type))"/>
        </xsl:when>
        <xsl:otherwise>
          <xsl:value-of select="dyn:evaluate(concat('$PTR_',@type))"/>
        </xsl:otherwise>
      </xsl:choose>
      <xsl:text> </xsl:text>
      <xsl:value-of select="@name"/>
      <xsl:if test="position()!=last()">
        <xsl:text>, </xsl:text>
      </xsl:if>
    </xsl:for-each>
    <!--<xsl:for-each select="params">
      <xsl:text>, ...</xsl:text>
    </xsl:for-each>-->
  </xsl:variable>
  <func:result select="$TMP_STR"/>
</func:function>

<func:function name="helper:param-str-mkl">
  <xsl:variable name="TMP_STR">
    <xsl:for-each select="param">
      <xsl:choose>
        <xsl:when test="starts-with(@type, 'PTR_')">
          <xsl:value-of select="@name"/>
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

</xsl:stylesheet>

