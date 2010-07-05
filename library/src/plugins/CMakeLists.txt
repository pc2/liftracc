
if(CBLAS_FOUND)
  add_liftracc_plugin(cblas_plugin
    cblas_plugin.c
    cblas_autogen.c
    LINK dl
  )
endif(CBLAS_FOUND)

if(GOTO2_FOUND)
  add_liftracc_plugin(goto2_plugin
    goto2_plugin.c
    LINK dl
  )
endif(GOTO2_FOUND)

if(ATLAS_FOUND)
  add_liftracc_plugin(atlas_plugin
    atlas_plugin.c
    LINK dl
  )
endif(ATLAS_FOUND)

if(CUDA_FOUND)  
  add_liftracc_plugin(cublas_plugin
    cublas_plugin.c
    LINK cublas dl
  )
endif(CUDA_FOUND)

if(CLEARSPEED_FOUND)
  add_liftracc_plugin(clearspeed_plugin
    clearspeed_plugin.c
    LINK dl
  )
endif(CLEARSPEED_FOUND)

