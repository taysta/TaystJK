@echo off

set "VSCMD_START_DIR=%CD%"
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"

set tools_dir=tools
set bh=%tools_dir%\bin2hex.exe
set bh_cpp=%tools_dir%\bin2hex.c
if not exist %bh% (
    cl.exe /EHsc /nologo /Fe%tools_dir%\ /Fo%tools_dir%\ %bh_cpp%
)

set PATH=%tools_dir%;%PATH%

set glsl=glsl\
set cl=%VULKAN_SDK%\glslangValidator.exe
set tmpf=spirv\data.spv
set outf=+spirv\shader_data.c

echo %bh%

mkdir spirv

del /Q spirv\shader_data.c
del /Q "%tmpf%"

@rem compile individual shaders

for %%f in (%glsl%*.vert) do (
    "%cl%" -S vert -V -o "%tmpf%" "%%f"
    "%bh%" "%tmpf%" %outf% %%~nf_vert_spv
    del /Q "%tmpf%"
)

for %%f in (%glsl%*.frag) do (
    "%cl%" -S frag -V -o "%tmpf%" "%%f"
    "%bh%" "%tmpf%" %outf% %%~nf_frag_spv
    del /Q "%tmpf%"
)

@rem compile lighting shader variations from templates

"%cl%" -S vert -V -o "%tmpf%" %glsl%light_vert.tmpl
"%bh%" "%tmpf%" %outf% vert_light

"%cl%" -S vert -V -o "%tmpf%" %glsl%light_vert.tmpl -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_light_fog

"%cl%" -S frag -V -o "%tmpf%" %glsl%light_frag.tmpl
"%bh%" "%tmpf%" %outf% frag_light

"%cl%" -S frag -V -o "%tmpf%" %glsl%light_frag.tmpl -DUSE_FOG 
"%bh%" "%tmpf%" %outf% frag_light_fog

"%cl%" -S frag -V -o "%tmpf%" %glsl%light_frag.tmpl -DUSE_LINE
"%bh%" "%tmpf%" %outf% frag_light_line

"%cl%" -S frag -V -o "%tmpf%" %glsl%light_frag.tmpl -DUSE_LINE -DUSE_FOG
"%bh%" "%tmpf%" %outf% frag_light_line_fog

@rem compile generic shader variations from templates

@rem single-texture vertex

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl
"%bh%" "%tmpf%" %outf% vert_tx0

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx0_fog

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx0_env

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_FOG -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx0_env_fog

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL0_IDENT
"%bh%" "%tmpf%" %outf% vert_tx0_ident

@rem double-texture vertex

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX1
"%bh%" "%tmpf%" %outf% vert_tx1

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX1 -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx1_fog

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX1 -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx1_env

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX1 -DUSE_FOG -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx1_env_fog

@rem double-texture vertex, non-identical colors

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL1 -DUSE_TX1
"%bh%" "%tmpf%" %outf% vert_tx1_cl

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL1 -DUSE_TX1 -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx1_cl_fog

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL1 -DUSE_TX1 -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx1_cl_env

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL1 -DUSE_TX1 -DUSE_ENV -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx1_cl_env_fog

@rem triple-texture vertex

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX2
"%bh%" "%tmpf%" %outf% vert_tx2

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX2 -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx2_fog

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX2 -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx2_env

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_TX2 -DUSE_ENV -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx2_env_fog

@rem triple-texture vertex, non-identical colors

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL2 -DUSE_TX2
"%bh%" "%tmpf%" %outf% vert_tx2_cl

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL2 -DUSE_TX2 -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx2_cl_fog

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL2 -DUSE_TX2 -DUSE_ENV
"%bh%" "%tmpf%" %outf% vert_tx2_cl_env

"%cl%" -S vert -V -o "%tmpf%" %glsl%gen_vert.tmpl -DUSE_CL2 -DUSE_TX2 -DUSE_ENV -DUSE_FOG
"%bh%" "%tmpf%" %outf% vert_tx2_cl_env_fog

@rem single-texture fragment

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_CL0_IDENT
"%bh%" "%tmpf%" %outf% frag_tx0_ident

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_ATEST -DUSE_DF
"%bh%" "%tmpf%" %outf% frag_tx0_df

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_ATEST
"%bh%" "%tmpf%" %outf% frag_tx0

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_ATEST -DUSE_FOG
"%bh%" "%tmpf%" %outf% frag_tx0_fog

@rem double-texture fragment

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_TX1
"%bh%" "%tmpf%" %outf% frag_tx1

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_TX1 -DUSE_FOG
"%bh%" "%tmpf%" %outf% frag_tx1_fog

@rem double-texture fragment, non-identical colors

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_CL1 -DUSE_TX1
"%bh%" "%tmpf%" %outf% frag_tx1_cl

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_CL1 -DUSE_TX1 -DUSE_FOG
"%bh%" "%tmpf%" %outf% frag_tx1_cl_fog

@rem triple-texture fragment

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_TX2
"%bh%" "%tmpf%" %outf% frag_tx2

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_TX2 -DUSE_FOG
"%bh%" "%tmpf%" %outf% frag_tx2_fog

@rem triple-texture fragment, non-identical colors

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_CL2 -DUSE_TX2
"%bh%" "%tmpf%" %outf% frag_tx2_cl

"%cl%" -S frag -V -o "%tmpf%" %glsl%gen_frag.tmpl -DUSE_CL2 -DUSE_TX2 -DUSE_FOG
"%bh%" "%tmpf%" %outf% frag_tx2_cl_fog

del /Q "%tmpf%"

pause