///
//
// Icey
// Copyright (c) 2005, Icey <http://icey.com>
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
namespace pluga {


// Forward declare the plugin class which must be defined externally.
class Pluga_API IPlugin;

// Define the API version.
// This value is incremented whenever there are ABI breaking changes.
#define ICY_PLUGIN_API_VERSION 1

#ifdef ICY_WIN
#define ICY_PLUGIN_EXPORT __declspec(dllexport)
#else
#define ICY_PLUGIN_EXPORT // empty
#endif

// Define a type for the static function pointer.
using GetPluginFunc = IPlugin* (*)();

/// Metadata descriptor for a dynamically loaded plugin
struct PluginDetails
{
    int apiVersion;
    const char* fileName;
    const char* className;
    const char* pluginName;
    const char* pluginVersion;
    GetPluginFunc initializeFunc;
};

#define ICY_STANDARD_PLUGIN_STUFF ICY_PLUGIN_API_VERSION, __FILE__

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


/// @\}
