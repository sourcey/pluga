# Plugu

**Homepage**: [http://sourcey.com/plugu](http://sourcey.com/plugu)  
**Licence**: LGPL  
**Dependencies**: [LibSourcey (base, uv)](http://sourcey.com/libsourcey)  

Plugu is a simple C++ plugin system that's dead simple to use in your own projects. It currently supports:

* Loading cross-platform plugins and shared libraries
* Simple and elegant API for defining plugins
* Strict API versioning for ABI safety

For more information take a look at [this blog post](http://sourcey.com/building-a-cross-platform-plugin-system-in-cpp) which talks about the concepts and mothodology behind Plugu.

## Installing

* Install [LibSourcey](http://sourcey.com/libsourcey/#install-libsourcey)
* Clone the Plugu repository in the LibSourcey `src` folder:
~~~ bash
cd libsourcey/src
git clone https://github.com/sourcey/plugu.git
~~~
* Ensure the `BUILD_MODULE_plugu` build variables are enabled in CMake and regenerate the LibSourcey project files
* To build Plugu tests also enable the `BUILD_MODULE_TESTS` and `BUILD_TEST_plugu` variables in CMake

## Contributing

Contributions in the form of pull requests are always welcome.

1. [Fork Plugu on Github](https://github.com/sourcey/plugu)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## Issues

If you find any bugs or issues please use the new [Github issue tracker](https://github.com/sourcey/plugu/issues).