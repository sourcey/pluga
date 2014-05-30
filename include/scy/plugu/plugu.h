//
// LibSourcey
// Copyright (C) 2005, Sourcey <http://sourcey.com>
//
// LibSourcey is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// LibSourcey is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//

#ifndef SCY_Pluga_H
#define SCY_Pluga_H


#include "scy/base.h"


namespace scy {
namespace pluga {


// Forward declare the plugin class which must be defined externally.
class IPlugin;

// Define the API version.
// This value is incremented whenever there are ABI breaking changes.
#define SCY_PLUGIN_API_VERSION 1
    
#ifdef WIN32
# define SCY_PLUGIN_EXPORT __declspec(dllexport)
#else
# define SCY_PLUGIN_EXPORT // empty
#endif

// Define a type for the static function pointer.
SCY_EXTERN typedef IPlugin* (*GetPluginFunc)();

// Plugin details structure that's exposed to the application.
struct PluginDetails {
    int apiVersion;
    const char* fileName;
    const char* className;
    const char* pluginName;
    const char* pluginVersion;
    GetPluginFunc initializeFunc;
};

#define SCY_STANDARD_PLUGIN_STUFF \
    SCY_PLUGIN_API_VERSION,       \
    __FILE__

#define SCY_PLUGIN(classType, pluginName, pluginVersion)     \
  extern "C" {                                               \
      SCY_PLUGIN_EXPORT scy::pluga::IPlugin* getPlugin()     \
      {                                                      \
          static classType singleton;                        \
          return &singleton;                                 \
      }                                                      \
      SCY_PLUGIN_EXPORT scy::pluga::PluginDetails exports =  \
      {                                                      \
          SCY_STANDARD_PLUGIN_STUFF,                         \
          #classType,                                        \
          pluginName,                                        \
          pluginVersion,                                     \
          getPlugin,                                         \
      };                                                     \
  }


} } // namespace scy::pluga


#endif // SCY_Pluga_H