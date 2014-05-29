#include "scy/base.h"
#include "scy/logger.h"
#include "scy/sharedlibrary.h"
#include "scy/plugu/plugu.h"

#include "testplugin/testpluginapi.h"

#include <assert.h>


using std::cout;
using std::cerr;
using std::endl;
using namespace scy;


namespace scy {
namespace plugu {


class Tests
{
public:
	Tests()
	{
		runPluginTest();
	}

	void runPluginTest() 
	{
		// Set the plugin shared library location
		std::string path(SCY_INSTALL_PREFIX);
		path += "/bin/testplugin/testplugin";
#if WIN32
# ifdef _DEBUG
		path += "d.dll";
# else
		path += ".dll";
# endif
#else
		path += ".so";
#endif
		
		try {
			// Load the shared library
			cout << "Loading: " << path << endl;
			SharedLibrary lib;
			lib.open(path);
			
			// Get plugin descriptor and exports
			PluginDetails* info;
			lib.sym("exports", reinterpret_cast<void**>(&info));
			cout << "Plugin Info: " 
				<< "\n\tAPI Version: " << info->apiVersion 
				<< "\n\tFile Name: " << info->fileName 
				<< "\n\tClass Name: " << info->className 
				<< "\n\tPlugin Name: " << info->pluginName 
				<< "\n\tPlugin Version: " << info->pluginVersion
				<< endl;
			
			// API version checking 
			if (info->apiVersion != SCY_PLUGIN_API_VERSION)
				throw std::runtime_error(
					util::format("Plugin version mismatch. Expected %s, got %s.", 
						SCY_PLUGIN_API_VERSION, info->apiVersion));
			
			// Instantiate the plugin
			IPlugin* plugin = reinterpret_cast<IPlugin*>(info->initializeFunc());
			
			// Call string accessor methods
			plugin->setValue("abracadabra");
			assert(strcmp(plugin->cValue(), "abracadabra") == 0);
#if PLUGU_ENABLE_STL
			assert(plugin->sValue() == "abracadabra");
#endif

			// Call command methods
			assert(plugin->onCommand("options:set", "rendomdata", 10));
			assert(plugin->lastError() == nullptr);
			assert(plugin->onCommand("unknown:command", "rendomdata", 10) == false);
			assert(strcmp(plugin->lastError(), "Unknown command") == 0);
		
			// Call a C function 
			GimmeFiveFunc gimmeFive;
			lib.sym("gimmeFive", reinterpret_cast<void**>(&gimmeFive));
			assert(gimmeFive() == 5);	
			
			// Close the plugin and free memory
			lib.close();
		}
		catch (std::exception& exc) {
			cerr << "Error: " << exc.what() << endl;
			assert(0);
		}
		
		cout << "Ending" << endl;
	}
};


} } // namespace scy::plugu


int main(int argc, char** argv) 
{	
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Run tests
	{
		plugu::Tests run;	
	}	
	
	// Wait for user intervention before exiting
	scy::pause();
	return 0;
}