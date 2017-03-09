///
//
// LibSourcey
// Copyright (c) 2005, Sourcey <http://sourcey.com>
//
// SPDX-License-Identifier: LGPL-2.1+
//
/// @addtogroup pluga
/// @{


#ifndef SCY_Pluga_H
#define SCY_Pluga_H


#include "scy/base.h"


// Shared library exports
#if defined(SCY_WIN) && defined(SCY_SHARED_LIBRARY)
    #if defined(Pluga_EXPORTS)
        #define Pluga_API __declspec(dllexport)
    #else
        #define Pluga_API __declspec(dllimport)
    #endif
#else
    #define Pluga_API // nothing
#endif


namespace scy {
namespace pluga {


// Forward declare the plugin class which must be defined externally.
class Pluga_API IPlugin;

// Define the API version.
// This value is incremented whenever there are ABI breaking changes.
#define SCY_PLUGIN_API_VERSION 1

#ifdef SCY_WIN
#define SCY_PLUGIN_EXPORT __declspec(dllexport)
#else
#define SCY_PLUGIN_EXPORT // empty
#endif

// Define a type for the static function pointer.
Pluga_API typedef IPlugin* (*GetPluginFunc)();

// Plugin details structure that's exposed to the application.
struct PluginDetails
{
    int apiVersion;
    const char* fileName;
    const char* className;
    const char* pluginName;
    const char* pluginVersion;
    GetPluginFunc initializeFunc;
};

#define SCY_STANDARD_PLUGIN_STUFF SCY_PLUGIN_API_VERSION, __FILE__

#define SCY_PLUGIN(classType, pluginName, pluginVersion)                       \
    extern "C" {                                                               \
    SCY_PLUGIN_EXPORT scy::pluga::IPlugin* getPlugin()                         \
    {                                                                          \
        static classType singleton;                                            \
        return &singleton;                                                     \
    }                                                                          \
    SCY_PLUGIN_EXPORT scy::pluga::PluginDetails exports = {                    \
        SCY_STANDARD_PLUGIN_STUFF,                                             \
        #classType,                                                            \
        pluginName,                                                            \
        pluginVersion,                                                         \
        getPlugin,                                                             \
    };                                                                         \
    }


} // namespace pluga
} // namespace scy


#endif // SCY_Pluga_H


/// @\}
