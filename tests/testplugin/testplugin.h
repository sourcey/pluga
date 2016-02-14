#ifndef SCY_TestPlugin_H
#define SCY_TestPlugin_H


#include "testpluginapi.h"


class TestPlugin: public scy::pluga::IPlugin 
    // Test plugin implementation
{
public:
    TestPlugin();
    virtual ~TestPlugin();

    //
    /// Commands

    virtual bool onCommand(const char* node, const char* data, unsigned int size);
        // Handle a command from the application.
    
    virtual const char* lastError() const;
        // Return the last error message as a char pointer.
        // If no error is set a nullptr will be returned.
    
    //
    /// String accessors

    virtual void setValue(const char* value);
        // Sets the internal string from the given value.
        // The given value must be null terminated.
    
    virtual const char* cValue() const;
        // Return the internal string value as a char pointer.
        // Since we are returning a POD type plugins will be ABI agnostic.

#if PLUGU_ENABLE_STL
    virtual std::string sValue() const;
        // Return the internal string value as an STL string.
        // This method breaks ABI agnosticity.
        // See the PLUGU_ENABLE_STL definition above.
#endif

protected:
     std::string _error;
     std::string _value;
};


#endif