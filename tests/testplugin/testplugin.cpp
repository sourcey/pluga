#include "testplugin.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string.h>

	
//
// Test Plugin
// 


SCY_PLUGIN(TestPlugin, "Test Plugin", "0.1.1")


TestPlugin::TestPlugin()
{
	std::cout << "TestPlugin: Create" << std::endl;
}


TestPlugin::~TestPlugin() 
{
	std::cout << "TestPlugin: Destroy" << std::endl;
}
	

bool TestPlugin::onCommand(const char* node, const char* data, unsigned int size)
{
	std::cout << "TestPlugin: Command: " << node << ": " << data << std::endl;
	
    try {
        // Handle a JSON encoded options hash
        if (strcmp(node, "options:set") == 0) {   
#if 0
            json::Value root;
            json::Reader reader;
            if (!reader.parse(data, size, root))          
                throw std::runtime_error("Invalid JSON format: " + reader.getFormatedErrorMessages());
                
            // Do something with JSON data here...
#endif
        }

        // Handle raw file data
        else if (strcmp(node, "file:write") == 0) {
            std::string path("test.bin");
            std::ofstream ofs(path, std::ios::out|std::ios::binary);
            if (!ofs.is_open())
                throw std::runtime_error("Cannot write to output file: " + path);
            ofs.write(data, size);
            ofs.close();
        }

        // Handle unknown commands
        else throw std::runtime_error("Unknown command");
    }
    
	// Catch exceptions to set the internal error message and return false
    catch (std::exception& exc) {
		_error.assign(exc.what());
        std::cerr << "Command error: " << _error << std::endl;
        return false;
    }

	return true;
}


void TestPlugin::setValue(const char* value)
{
	std::cout << "TestPlugin: Set value: " << value << std::endl;
	_value = value;
}


std::string TestPlugin::sValue() const 
{ 
	return _value;
}


const char* TestPlugin::cValue() const 
{ 
	return _value.c_str();
}


const char* TestPlugin::lastError() const 
{ 
	return _error.empty() ? nullptr : _error.c_str();
}


//
// Static Methods
// 


extern "C" SCY_PLUGIN_EXPORT int gimmeFive();


int gimmeFive()
{
	return 5;
}
