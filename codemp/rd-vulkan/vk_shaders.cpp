/*
===========================================================================
Copyright (C) 1999 - 2005, Id Software, Inc.
Copyright (C) 2000 - 2013, Raven Software, Inc.
Copyright (C) 2001 - 2013, Activision, Inc.
Copyright (C) 2013 - 2015, OpenJK contributors

This file is part of the OpenJK source code.

OpenJK is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License version 2 as
published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#include "tr_local.h"
#include "shaders/spirv/shader_data.c"

// Vulkan has to be specified in a bytecode format which is called SPIR-V
// and is designed to be work with both Vulkan and OpenCL.
//
// The graphics pipeline is the sequence of the operations that take the
// vertices and textures of your meshes all way to the pixels in the
// render targets.
static VkShaderModule SHADER_MODULE( const uint8_t *bytes, const int count ) {
    VkShaderModuleCreateInfo desc;
    VkShaderModule module;

    if (count % 4 != 0) {
        ri.Error(ERR_FATAL, "Vulkan: SPIR-V binary buffer size is not a multiple of 4");
    }

    desc.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    desc.pNext = NULL;
    desc.flags = 0;
    desc.codeSize = count;
    desc.pCode = (const uint32_t*)bytes;

    VK_CHECK(qvkCreateShaderModule(vk.device, &desc, NULL, &module));

    return module;
}
#define SHADER_MODULE( name ) SHADER_MODULE( name, sizeof( name ) )

void vk_create_shader_modules( void )
{
    int i, j, k, l;

    vk.shaders.vert.gen[0][0][0][0] = SHADER_MODULE(vert_tx0);
    vk.shaders.vert.gen[0][0][0][1] = SHADER_MODULE(vert_tx0_fog);
    vk.shaders.vert.gen[0][0][1][0] = SHADER_MODULE(vert_tx0_env);
    vk.shaders.vert.gen[0][0][1][1] = SHADER_MODULE(vert_tx0_env_fog);

    vk.shaders.vert.gen[1][0][0][0] = SHADER_MODULE(vert_tx1);
    vk.shaders.vert.gen[1][0][0][1] = SHADER_MODULE(vert_tx1_fog);
    vk.shaders.vert.gen[1][0][1][0] = SHADER_MODULE(vert_tx1_env);
    vk.shaders.vert.gen[1][0][1][1] = SHADER_MODULE(vert_tx1_env_fog);

    vk.shaders.vert.gen[1][1][0][0] = SHADER_MODULE(vert_tx1_cl);
    vk.shaders.vert.gen[1][1][0][1] = SHADER_MODULE(vert_tx1_cl_fog);
    vk.shaders.vert.gen[1][1][1][0] = SHADER_MODULE(vert_tx1_cl_env);
    vk.shaders.vert.gen[1][1][1][1] = SHADER_MODULE(vert_tx1_cl_env_fog);

    vk.shaders.vert.gen[2][0][0][0] = SHADER_MODULE(vert_tx2);
    vk.shaders.vert.gen[2][0][0][1] = SHADER_MODULE(vert_tx2_fog);
    vk.shaders.vert.gen[2][0][1][0] = SHADER_MODULE(vert_tx2_env);
    vk.shaders.vert.gen[2][0][1][1] = SHADER_MODULE(vert_tx2_env_fog);

    vk.shaders.vert.gen[2][1][0][0] = SHADER_MODULE(vert_tx2_cl);
    vk.shaders.vert.gen[2][1][0][1] = SHADER_MODULE(vert_tx2_cl_fog);
    vk.shaders.vert.gen[2][1][1][0] = SHADER_MODULE(vert_tx2_cl_env);
    vk.shaders.vert.gen[2][1][1][1] = SHADER_MODULE(vert_tx2_cl_env_fog);

    for (i = 0; i < 3; i++) {
        const char *tx[] = { "single", "double", "triple" };
        const char *cl[] = { "", "+cl" };
        const char *env[] = { "", "+env" };
        const char *fog[] = { "", "+fog" };
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l < 2; l++) {
                    const char *s = va("%s-texture%s%s%s vertex module", tx[i], cl[j], env[k], fog[l]);
                    VK_SET_OBJECT_NAME(vk.shaders.vert.gen[i][j][k][l], s, VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
                }
            }
        }
    }
    vk.shaders.frag.gen0_df = SHADER_MODULE(frag_tx0_df);
    VK_SET_OBJECT_NAME(vk.shaders.frag.gen0_df, "single-texture df fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.vert.gen0_ident = SHADER_MODULE(vert_tx0_ident);
    vk.shaders.frag.gen0_ident = SHADER_MODULE(frag_tx0_ident);
    VK_SET_OBJECT_NAME(vk.shaders.vert.gen0_ident, "single-texture ident.color vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.frag.gen0_ident, "single-texture ident.color fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.frag.gen[0][0][0] = SHADER_MODULE(frag_tx0);
    vk.shaders.frag.gen[0][0][1] = SHADER_MODULE(frag_tx0_fog);

    vk.shaders.frag.gen[1][0][0] = SHADER_MODULE(frag_tx1);
    vk.shaders.frag.gen[1][0][1] = SHADER_MODULE(frag_tx1_fog);

    vk.shaders.frag.gen[1][1][0] = SHADER_MODULE(frag_tx1_cl);
    vk.shaders.frag.gen[1][1][1] = SHADER_MODULE(frag_tx1_cl_fog);

    vk.shaders.frag.gen[2][0][0] = SHADER_MODULE(frag_tx2);
    vk.shaders.frag.gen[2][0][1] = SHADER_MODULE(frag_tx2_fog);

    vk.shaders.frag.gen[2][1][0] = SHADER_MODULE(frag_tx2_cl);
    vk.shaders.frag.gen[2][1][1] = SHADER_MODULE(frag_tx2_cl_fog);

    for (i = 0; i < 3; i++) {
        const char *tx[] = { "single", "double", "triple" };
        const char *cl[] = { "", "+cl" };
        const char *fog[] = { "", "+fog" };
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                const char *s = va("%s-texture%s%s fragment module", tx[i], cl[j], fog[k]);
                VK_SET_OBJECT_NAME(vk.shaders.frag.gen[i][j][k], s, VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
            }
        }
    }

    vk.shaders.vert.light[0] = SHADER_MODULE(vert_light);
    vk.shaders.vert.light[1] = SHADER_MODULE(vert_light_fog);
    VK_SET_OBJECT_NAME(vk.shaders.vert.light[0], "light vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.vert.light[1], "light fog vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.frag.light[0][0] = SHADER_MODULE(frag_light);
    vk.shaders.frag.light[0][1] = SHADER_MODULE(frag_light_fog);
    vk.shaders.frag.light[1][0] = SHADER_MODULE(frag_light_line);
    vk.shaders.frag.light[1][1] = SHADER_MODULE(frag_light_line_fog);
    VK_SET_OBJECT_NAME(vk.shaders.frag.light[0][0], "light fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.frag.light[0][1], "light fog fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.frag.light[1][0], "linear light fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.frag.light[1][1], "linear light fog fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.color_fs = SHADER_MODULE(color_frag_spv);
    vk.shaders.color_vs = SHADER_MODULE(color_vert_spv);
    VK_SET_OBJECT_NAME(vk.shaders.color_vs, "single-color vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.color_fs, "single-color fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.fog_vs = SHADER_MODULE(fog_vert_spv);
    vk.shaders.fog_fs = SHADER_MODULE(fog_frag_spv);
    VK_SET_OBJECT_NAME(vk.shaders.fog_vs, "fog-only vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.fog_fs, "fog-only fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.dot_vs = SHADER_MODULE(dot_vert_spv);
    vk.shaders.dot_fs = SHADER_MODULE(dot_frag_spv);
    VK_SET_OBJECT_NAME(vk.shaders.dot_vs, "dot vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.dot_fs, "dot fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.bloom_fs = SHADER_MODULE(bloom_frag_spv);
    vk.shaders.blur_fs = SHADER_MODULE(blur_frag_spv);
    vk.shaders.blend_fs = SHADER_MODULE(blend_frag_spv);
    VK_SET_OBJECT_NAME(vk.shaders.bloom_fs, "bloom extraction fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.blur_fs, "gaussian blur fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.blend_fs, "final bloom blend fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);

    vk.shaders.gamma_fs = SHADER_MODULE(gamma_frag_spv);
    vk.shaders.gamma_vs = SHADER_MODULE(gamma_vert_spv);
    VK_SET_OBJECT_NAME(vk.shaders.gamma_fs, "gamma post-processing fragment module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
    VK_SET_OBJECT_NAME(vk.shaders.gamma_vs, "gamma post-processing vertex module", VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT);
}

void vk_destroy_shader_modules( void )
{
    int i, j, k, l;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                for (l = 0; l < 2; l++) {
                    if (vk.shaders.vert.gen[i][j][k][l] != VK_NULL_HANDLE) {
                        qvkDestroyShaderModule(vk.device, vk.shaders.vert.gen[i][j][k][l], NULL);
                        vk.shaders.vert.gen[i][j][k][l] = VK_NULL_HANDLE;
                    }
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                if (vk.shaders.frag.gen[i][j][k] != VK_NULL_HANDLE) {
                    qvkDestroyShaderModule(vk.device, vk.shaders.frag.gen[i][j][k], NULL);
                    vk.shaders.frag.gen[i][j][k] = VK_NULL_HANDLE;
                }
            }
        }
    }
    for (i = 0; i < 2; i++) {
        if (vk.shaders.vert.light[i] != VK_NULL_HANDLE) {
            qvkDestroyShaderModule(vk.device, vk.shaders.vert.light[i], NULL);
            vk.shaders.vert.light[i] = VK_NULL_HANDLE;
        }
        for (j = 0; j < 2; j++) {
            if (vk.shaders.frag.light[i][j] != VK_NULL_HANDLE) {
                qvkDestroyShaderModule(vk.device, vk.shaders.frag.light[i][j], NULL);
                vk.shaders.frag.light[i][j] = VK_NULL_HANDLE;
            }
        }
    }
    qvkDestroyShaderModule(vk.device, vk.shaders.vert.gen0_ident, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.frag.gen0_ident, NULL);

    qvkDestroyShaderModule(vk.device, vk.shaders.frag.gen0_df, NULL);

    qvkDestroyShaderModule(vk.device, vk.shaders.color_fs, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.color_vs, NULL);

    qvkDestroyShaderModule(vk.device, vk.shaders.fog_vs, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.fog_fs, NULL);

    qvkDestroyShaderModule(vk.device, vk.shaders.dot_vs, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.dot_fs, NULL);

    qvkDestroyShaderModule(vk.device, vk.shaders.bloom_fs, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.blur_fs, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.blend_fs, NULL);

    qvkDestroyShaderModule(vk.device, vk.shaders.gamma_vs, NULL);
    qvkDestroyShaderModule(vk.device, vk.shaders.gamma_fs, NULL);
}