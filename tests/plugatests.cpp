#include "scy/pluga/pluga.h"
#include "scy/base.h"
#include "scy/logger.h"
#include "scy/sharedlibrary.h"
#include "scy/test.h"

#include "plugatestplugin/testpluginapi.h"


using std::cout;
using std::cerr;
using std::endl;


#define PLUGA_ENABLE_STL 1


namespace scy {
namespace pluga {


class Tests
{
public:
    Tests() { runPluginTest(); }

    void runPluginTest()
    {
        // Set the plugin shared library location
        std::string path(SCY_BUILD_DIR);
        path += "/src/pluga/tests/plugatestplugin/";
#if WIN32
#ifdef _DEBUG
        path += "plugatestplugind.dll";
#else
        path += "plugatestplugin.dll";
#endif
#else
#ifdef _DEBUG
        path += "libplugatestplugind.so";
#else
        path += "libplugatestplugin.so";
#endif
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
                throw std::runtime_error(util::format(
                    "Plugin version mismatch. Expected %s, got %s.",
                    SCY_PLUGIN_API_VERSION, info->apiVersion));

            // Instantiate the plugin
            auto plugin = reinterpret_cast<IPlugin*>(info->initializeFunc());

            // Call string accessor methods
            plugin->setValue("abracadabra");
            expect(strcmp(plugin->cValue(), "abracadabra") == 0);
#if PLUGA_ENABLE_STL
            expect(plugin->sValue() == "abracadabra");
#endif

            // Call command methods
            expect(plugin->onCommand("options:set", "rendomdata", 10));
            expect(plugin->lastError() == nullptr);
            expect(plugin->onCommand("unknown:command", "rendomdata", 10) == false);
            expect(strcmp(plugin->lastError(), "Unknown command") == 0);

            // Call a C function
            GimmeFiveFunc gimmeFive;
            lib.sym("gimmeFive", reinterpret_cast<void**>(&gimmeFive));
            expect(gimmeFive() == 5);

            // Close the plugin and free memory
            lib.close();
        } catch (std::exception& exc) {
            cerr << "Error: " << exc.what() << endl;
            expect(false);
        }

        cout << "Ending" << endl;
    }
};


} // namespace pluga
} // namespace scy


int main(int argc, char** argv)
{
#ifdef _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    // Run tests
    {
        scy::pluga::Tests run;
    }

    return 0;
}
