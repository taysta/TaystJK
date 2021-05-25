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

#define CASE_STR(x) case (x): return #x

const char *vk_format_string(VkFormat format)
{
    static char buf[16];

    switch (format) {
        // color formats
        CASE_STR(VK_FORMAT_B8G8R8A8_SRGB);
        CASE_STR(VK_FORMAT_R8G8B8A8_SRGB);
        CASE_STR(VK_FORMAT_B8G8R8A8_SNORM);
        CASE_STR(VK_FORMAT_R8G8B8A8_SNORM);
        CASE_STR(VK_FORMAT_B8G8R8A8_UNORM);
        CASE_STR(VK_FORMAT_R8G8B8A8_UNORM);
        CASE_STR(VK_FORMAT_B4G4R4A4_UNORM_PACK16);
        CASE_STR(VK_FORMAT_R16G16B16A16_UNORM);
        CASE_STR(VK_FORMAT_A2B10G10R10_UNORM_PACK32);
        CASE_STR(VK_FORMAT_A2R10G10B10_SNORM_PACK32);
        // depth formats
        CASE_STR(VK_FORMAT_D16_UNORM);
        CASE_STR(VK_FORMAT_D16_UNORM_S8_UINT);
        CASE_STR(VK_FORMAT_X8_D24_UNORM_PACK32);
        CASE_STR(VK_FORMAT_D24_UNORM_S8_UINT);
        CASE_STR(VK_FORMAT_D32_SFLOAT);
        CASE_STR(VK_FORMAT_D32_SFLOAT_S8_UINT);
    default:
        Com_sprintf(buf, sizeof(buf), "#%i", format);
        return buf;
    }
}

const char *vk_result_string(VkResult code) {
    static char buffer[32];

    switch (code) {
        CASE_STR(VK_SUCCESS);
        CASE_STR(VK_NOT_READY);
        CASE_STR(VK_TIMEOUT);
        CASE_STR(VK_EVENT_SET);
        CASE_STR(VK_EVENT_RESET);
        CASE_STR(VK_INCOMPLETE);
        CASE_STR(VK_ERROR_OUT_OF_HOST_MEMORY);
        CASE_STR(VK_ERROR_OUT_OF_DEVICE_MEMORY);
        CASE_STR(VK_ERROR_INITIALIZATION_FAILED);
        CASE_STR(VK_ERROR_DEVICE_LOST);
        CASE_STR(VK_ERROR_MEMORY_MAP_FAILED);
        CASE_STR(VK_ERROR_LAYER_NOT_PRESENT);
        CASE_STR(VK_ERROR_EXTENSION_NOT_PRESENT);
        CASE_STR(VK_ERROR_FEATURE_NOT_PRESENT);
        CASE_STR(VK_ERROR_INCOMPATIBLE_DRIVER);
        CASE_STR(VK_ERROR_TOO_MANY_OBJECTS);
        CASE_STR(VK_ERROR_FORMAT_NOT_SUPPORTED);
        CASE_STR(VK_ERROR_FRAGMENTED_POOL);
        CASE_STR(VK_ERROR_OUT_OF_POOL_MEMORY);
        CASE_STR(VK_ERROR_INVALID_EXTERNAL_HANDLE);
        CASE_STR(VK_ERROR_SURFACE_LOST_KHR);
        CASE_STR(VK_ERROR_NATIVE_WINDOW_IN_USE_KHR);
        CASE_STR(VK_SUBOPTIMAL_KHR);
        CASE_STR(VK_ERROR_OUT_OF_DATE_KHR);
        CASE_STR(VK_ERROR_INCOMPATIBLE_DISPLAY_KHR);
        CASE_STR(VK_ERROR_VALIDATION_FAILED_EXT);
        CASE_STR(VK_ERROR_INVALID_SHADER_NV);
        CASE_STR(VK_ERROR_NOT_PERMITTED_EXT);
    default:
        sprintf(buffer, "code %i", code);
        return buffer;
    }
}

const char *vk_shadertype_string(Vk_Shader_Type code) {
    static char buffer[32];

    switch (code) {
            CASE_STR(TYPE_COLOR_WHITE);
            CASE_STR(TYPE_COLOR_GREEN);
            CASE_STR(TYPE_COLOR_RED);
            CASE_STR(TYPE_FOG_ONLY);
            CASE_STR(TYPE_DOT);


            CASE_STR(TYPE_SINGLE_TEXTURE_LIGHTING);
            CASE_STR(TYPE_SINGLE_TEXTURE_LIGHTING_LINEAR);

            CASE_STR(TYPE_SINGLE_TEXTURE_DF);

            CASE_STR(TYPE_SINGLE_TEXTURE);
            CASE_STR(TYPE_SINGLE_TEXTURE_ENV);

            CASE_STR(TYPE_MULTI_TEXTURE_MUL2);
            CASE_STR(TYPE_MULTI_TEXTURE_MUL2_ENV);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD2_IDENTITY);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD2_IDENTITY_ENV);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD2);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD2_ENV);

            CASE_STR(TYPE_MULTI_TEXTURE_MUL3);
            CASE_STR(TYPE_MULTI_TEXTURE_MUL3_ENV);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD3_IDENTITY);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD3_IDENTITY_ENV);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD3);
            CASE_STR(TYPE_MULTI_TEXTURE_ADD3_ENV);

            CASE_STR(TYPE_BLEND2_ADD);
            CASE_STR(TYPE_BLEND2_ADD_ENV);
            CASE_STR(TYPE_BLEND2_MUL);
            CASE_STR(TYPE_BLEND2_MUL_ENV);
            CASE_STR(TYPE_BLEND2_ALPHA);
            CASE_STR(TYPE_BLEND2_ALPHA_ENV);
            CASE_STR(TYPE_BLEND2_ONE_MINUS_ALPHA);
            CASE_STR(TYPE_BLEND2_ONE_MINUS_ALPHA_ENV);
            CASE_STR(TYPE_BLEND2_MIX_ALPHA);
            CASE_STR(TYPE_BLEND2_MIX_ALPHA_ENV);
            CASE_STR(TYPE_BLEND2_MIX_ONE_MINUS_ALPHA);
            CASE_STR(TYPE_BLEND2_MIX_ONE_MINUS_ALPHA_ENV);

            CASE_STR(TYPE_BLEND2_DST_COLOR_SRC_ALPHA);
            CASE_STR(TYPE_BLEND2_DST_COLOR_SRC_ALPHA_ENV);

            CASE_STR(TYPE_BLEND3_ADD);
            CASE_STR(TYPE_BLEND3_ADD_ENV);
            CASE_STR(TYPE_BLEND3_MUL);
            CASE_STR(TYPE_BLEND3_MUL_ENV);
            CASE_STR(TYPE_BLEND3_ALPHA);
            CASE_STR(TYPE_BLEND3_ALPHA_ENV);
            CASE_STR(TYPE_BLEND3_ONE_MINUS_ALPHA);
            CASE_STR(TYPE_BLEND3_ONE_MINUS_ALPHA_ENV);
            CASE_STR(TYPE_BLEND3_MIX_ALPHA);
            CASE_STR(TYPE_BLEND3_MIX_ALPHA_ENV);
            CASE_STR(TYPE_BLEND3_MIX_ONE_MINUS_ALPHA);
            CASE_STR(TYPE_BLEND3_MIX_ONE_MINUS_ALPHA_ENV);

            CASE_STR(TYPE_BLEND3_DST_COLOR_SRC_ALPHA);
            CASE_STR(TYPE_BLEND3_DST_COLOR_SRC_ALPHA_ENV);
    default:
        sprintf(buffer, "code %i", code);
        return buffer;
    }
}
#undef CASE_STR

static const char *TruncateVKExtensionsString(const char *extensionsString, int maxExtensions)
{
    const char* p = extensionsString;
    const char* q;
    int numExtensions = 0;
    size_t extensionsLen = strlen(extensionsString);

    char* truncatedExtensions;

    while ((q = strchr(p, ' ')) != NULL && numExtensions <= maxExtensions)
    {
        p = q + 1;
        numExtensions++;
    }

    if (q != NULL)
    {
        // We still have more extensions. We'll call this the end

        extensionsLen = p - extensionsString - 1;
    }

    truncatedExtensions = (char*)Hunk_Alloc(extensionsLen + 1, h_low);
    Q_strncpyz(truncatedExtensions, extensionsString, extensionsLen + 1);

    return truncatedExtensions;
}

static void vk_print_instance_extensions(int setting)
{
    uint32_t i = 0;
    uint32_t nInsExt = 0;
    VkExtensionProperties* pInsExt;

    // To retrieve a list of supported extensions before creating an instance
    VK_CHECK(qvkEnumerateInstanceExtensionProperties(NULL, &nInsExt, NULL));
    assert(nInsExt > 0);

    pInsExt = (VkExtensionProperties*)malloc(sizeof(VkExtensionProperties) * nInsExt);
    VK_CHECK(qvkEnumerateInstanceExtensionProperties(NULL, &nInsExt, pInsExt));

    vk_debug("----- Total %d Instance Extension Supported -----\n", nInsExt);
    for (i = 0; i < nInsExt; ++i)
    {
        vk_debug("%s\n", pInsExt[i].extensionName);
    }
    vk_debug("----- ------------------------------------- -----\n\n");

    if (setting)
    {
        uint32_t indicator = 0;

        char ext_str[BIG_INFO_STRING] = { 0 };

        for (i = 0; i < nInsExt; ++i)
        {
            uint32_t len = strlen(pInsExt[i].extensionName);
            memcpy(ext_str + indicator, pInsExt[i].extensionName, len);

            indicator += len;
            ext_str[indicator++] = ' ';
        }

        glConfig.extensions_string = TruncateVKExtensionsString(ext_str, 128);
        free(pInsExt);
    }
}

static void vk_print_device_extensions(void)
{
    uint32_t i, nDevExts = 0;
    VkExtensionProperties* pDevExt;

    // To query the extensions available to a given physical device
    VK_CHECK(qvkEnumerateDeviceExtensionProperties(vk.physical_device, NULL, &nDevExts, NULL));

    assert(nDevExts > 0);

    pDevExt = (VkExtensionProperties*)malloc(sizeof(VkExtensionProperties) * nDevExts);

    qvkEnumerateDeviceExtensionProperties(vk.physical_device, NULL, &nDevExts, pDevExt);

    vk_debug("--------- Total %d Device Extension Supported ---------\n", nDevExts);
    for (i = 0; i < nDevExts; ++i)
    {
        vk_debug(" %s \n", pDevExt[i].extensionName);
    }
    vk_debug("--------- ----------------------------------- ---------\n");

    free(pDevExt);
}

void vk_get_vulkan_properties(VkPhysicalDeviceProperties *props)
{
    const char *device_type, *vendor_name;
    uint32_t major, minor, patch;

    vk_debug("\nActive 3D API: Vulkan\n");

    // To query general properties of physical devices once enumerated
    qvkGetPhysicalDeviceProperties(vk.physical_device, props);

    major = VK_VERSION_MAJOR(props->apiVersion);
    minor = VK_VERSION_MINOR(props->apiVersion);
    patch = VK_VERSION_PATCH(props->apiVersion);

    switch (props->deviceType) {
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: device_type = "INTEGRATED_GPU"; break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: device_type = "DISCRETE_GPU";  break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: device_type = "VIRTUAL_GPU"; break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU: device_type = "CPU"; break;
        default: device_type = "OTHER"; break;
    }

    vk.offscreenRender = qtrue;

    switch (props->vendorID) {
        case 0x1002: vendor_name = "Advanced Micro Devices, Inc."; break;
        case 0x106B: vendor_name = "Apple Inc."; break;
        case 0x10DE: 
            vendor_name = "NVIDIA"; 
#ifdef _WIN32
            // https://github.com/SaschaWillems/Vulkan/issues/493
            // we can't render to offscreen presentation surfaces on nvidia
            vk.offscreenRender = qfalse;
#endif
            break;
        case 0x14E4: vendor_name = "Broadcom Inc."; break;
        case 0x1AE0: vendor_name = "Google Inc."; break;
        case 0x8086: vendor_name = "Intel Corporation"; break;
        default: vendor_name = "OTHER"; break;
    }

    ri.Printf(PRINT_ALL, "----- Vulkan -----\n");
    ri.Printf(PRINT_ALL, "Api version: %d.%d.%d\n", major, minor, patch);
    ri.Printf(PRINT_ALL, "Driver version: %d\n", props->driverVersion);
    ri.Printf(PRINT_ALL, "Vendor id: 0x%X (%s)\n", props->vendorID, vendor_name);
    ri.Printf(PRINT_ALL, "Device id: 0x%X\n", props->deviceID);
    ri.Printf(PRINT_ALL, "Device type: %s\n", device_type);
    ri.Printf(PRINT_ALL, "Device name: %s\n", props->deviceName);
    ri.Printf(PRINT_ALL, "\n");

    char tmpBuf[128] = { 0 };
    char rd_string[128] = { 0 };

    snprintf(tmpBuf, 128, " Vk api version: %d.%d.%d ", major, minor, patch);
    glConfig.vendor_string = (const char*)vendor_name;
    glConfig.version_string = (const char*)tmpBuf;
    glConfig.renderer_string = (const char*)props->deviceName;

    VK_SET_OBJECT_NAME((intptr_t)vk.device, glConfig.renderer_string, VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT);

    //
    // Info that for UI display
    //
    vk_print_instance_extensions(1);

    vk_print_device_extensions();
}