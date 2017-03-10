#ifndef SCY_TestPluginAPI_H
#define SCY_TestPluginAPI_H


#include "scy/pluga/pluga.h"
#include <string>


namespace scy {
namespace pluga {


// NOTE: When using STL containers and other complex types you
// will need to ensure plugins are always built using the same
// compiler, since system libraries aren't ABI compatible.
#define PLUGA_ENABLE_STL 1


/// Virtual base class for plugins
class IPlugin
{
public:
    IPlugin(){};
    virtual ~IPlugin(){};

    //
    /// Commands

    /// Handle a command from the application.
    virtual bool onCommand(const char* node, const char* data,
                           unsigned int size) = 0;

    /// Return the last error message as a char pointer.
    /// If no error is set a nullptr will be returned.
    virtual const char* lastError() const = 0;


    //
    /// String accessors

    // Sets the internal string from the given value.
    /// The given value must be null terminated.
    virtual void setValue(const char* value) = 0;

    // Return the internal string value as a char pointer.
    /// Since we are returning a POD type plugins will be ABI agnostic.
    virtual const char* cValue() const = 0;


#if PLUGA_ENABLE_STL
    /// Return the internal string value as an STL string.
    /// This method breaks ABI agnosticity.
    /// See the PLUGU_ENABLE_STL definition above.
    virtual std::string sValue() const = 0;
#endif
};


typedef int (*GimmeFiveFunc)(); /// Static function which returns, you guessed
                                /// it, the number 5!


} // namespace pluga
} // namespace scy


#endif
