///
//
// Icey
// Copyright (c) 2005, Icey <http://0state.com>
//
// SPDX-License-Identifier: LGPL-2.1+
//
/// @defgroup pluga Pluga module
///
/// Plugin system for shared library loading.
/// @{


#pragma once


#include "icy/base.h"


// Shared library exports
#if defined(ICY_WIN) && defined(ICY_SHARED_LIBRARY)
#if defined(Pluga_EXPORTS)
#define Pluga_API __declspec(dllexport)
#else
#define Pluga_API __declspec(dllimport)
#endif
#else
#define Pluga_API // nothing
#endif


namespace icy {
/// @ingroup pluga
/// Shared-library plugin discovery helpers and export metadata.
namespace pluga {


/// Abstract plugin interface exported by shared libraries.
/// The concrete implementation is provided by the plugin itself.
class Pluga_API IPlugin;

/// ABI version expected by the host when loading plugins.
/// Increment this whenever plugin-facing binary compatibility changes.
#define ICY_PLUGIN_API_VERSION 1

#ifdef ICY_WIN
#define ICY_PLUGIN_EXPORT __declspec(dllexport)
#else
#define ICY_PLUGIN_EXPORT // empty
#endif

/// Function pointer type for the exported plugin entry point.
using GetPluginFunc = IPlugin* (*)();

/// Metadata descriptor exported alongside a dynamically loaded plugin.
struct PluginDetails
{
    /// ABI version reported by the plugin.
    int apiVersion;

    /// Source file used when the plugin export block was compiled.
    const char* fileName;

    /// Concrete plugin class name.
    const char* className;

    /// Human-readable plugin display name.
    const char* pluginName;

    /// Plugin version string.
    const char* pluginVersion;

    /// Entry point that returns the plugin singleton.
    GetPluginFunc initializeFunc;
};

/// Default metadata prefix used by the `ICY_PLUGIN` export helper.
#define ICY_STANDARD_PLUGIN_STUFF ICY_PLUGIN_API_VERSION, __FILE__

/// Declares the standard exported entry points and metadata for a plugin class.
/// @param classType Concrete plugin implementation type.
/// @param pluginName Human-readable plugin name string.
/// @param pluginVersion Plugin version string.
#define ICY_PLUGIN(classType, pluginName, pluginVersion)    \
    extern "C" {                                            \
    ICY_PLUGIN_EXPORT icy::pluga::IPlugin* getPlugin()      \
    {                                                       \
        static classType singleton;                         \
        return &singleton;                                  \
    }                                                       \
    ICY_PLUGIN_EXPORT icy::pluga::PluginDetails exports = { \
        ICY_STANDARD_PLUGIN_STUFF,                          \
        #classType,                                         \
        pluginName,                                         \
        pluginVersion,                                      \
        getPlugin,                                          \
    };                                                      \
    }


} // namespace pluga
} // namespace icy


/// @}
