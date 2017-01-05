#ifndef SCY_TestPlugin_H
#define SCY_TestPlugin_H


#include "testpluginapi.h"


/// Test plugin implementation
class TestPlugin : public scy::pluga::IPlugin
{
public:
    TestPlugin();
    virtual ~TestPlugin();

    ///// Commands
    /// Handle a command from the application.
    virtual bool onCommand(const char* node, const char* data,
                           unsigned int size);

    // Return the last error message as a char pointer.
    /// If no error is set a nullptr will be returned.
    virtual const char* lastError() const;


    ///// String accessors
    /// Sets the internal string from the given value.
    /// The given value must be null terminated.
    virtual void setValue(const char* value);

    // Return the internal string value as a char pointer.
    /// Since we are returning a POD type plugins will be ABI agnostic.
    virtual const char* cValue() const;


#if PLUGU_ENABLE_STL
    /// Return the internal string value as an STL string.
    /// This method breaks ABI agnosticity.
    /// See the PLUGU_ENABLE_STL definition above.
    virtual std::string sValue() const;

#endif

protected:
    std::string _error;
    std::string _value;
};


#endif