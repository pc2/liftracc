<xsl:stylesheet version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<!-- begin definitions -->
<xsl:param name="VOID_TYPE">void</xsl:param>
<xsl:param name="PTR_VOID_TYPE">void *</xsl:param>
<xsl:param name="CONST_VOID_TYPE">const void</xsl:param>
<xsl:param name="PTR_CONST_VOID_TYPE">const void *</xsl:param>

<xsl:param name="SIZE_T_TYPE">liftracc_index_t</xsl:param>
<xsl:param name="PTR_SIZE_T_TYPE">liftracc_index_t *</xsl:param>
<xsl:param name="PTR_CONST_CHAR_TYPE">const char *</xsl:param>

<xsl:param name="INT_TYPE">int</xsl:param>
<xsl:param name="PTR_INT_TYPE">int *</xsl:param>
<xsl:param name="CONST_INT_TYPE">const int</xsl:param>
<xsl:param name="PTR_CONST_INT_TYPE">const int *</xsl:param>

<xsl:param name="FLOAT_TYPE">float</xsl:param>
<xsl:param name="PTR_FLOAT_TYPE">float *</xsl:param>
<xsl:param name="CONST_FLOAT_TYPE">const float</xsl:param>
<xsl:param name="PTR_CONST_FLOAT_TYPE">const float *</xsl:param>

<xsl:param name="DOUBLE_TYPE">double</xsl:param>
<xsl:param name="PTR_DOUBLE_TYPE">double *</xsl:param>
<xsl:param name="CONST_DOUBLE_TYPE">const double</xsl:param>
<xsl:param name="PTR_CONST_DOUBLE_TYPE">const double *</xsl:param>

<xsl:param name="CONST_ORDER_TYPE">const liftracc_order_t</xsl:param>
<xsl:param name="PTR_CONST_ORDER_TYPE">const liftracc_order_t *</xsl:param>

<xsl:param name="CONST_TRANSPOSE_TYPE">const liftracc_transpose_t</xsl:param>
<xsl:param name="PTR_CONST_TRANSPOSE_TYPE">const liftracc_transpose_t *</xsl:param>

<xsl:param name="CONST_UPLO_TYPE">const liftracc_uplo_t</xsl:param>
<xsl:param name="PTR_CONST_UPLO_TYPE">const liftracc_uplo_t *</xsl:param>

<xsl:param name="CONST_DIAG_TYPE">const liftracc_diag_t</xsl:param>
<xsl:param name="PTR_CONST_DIAG_TYPE">const liftracc_diag_t *</xsl:param>

<xsl:param name="CONST_SIDE_TYPE">const liftracc_side_t</xsl:param>
<xsl:param name="PTR_CONST_SIDE_TYPE">const liftracc_side_t *</xsl:param>
<!-- end definitions -->
</xsl:stylesheet>

