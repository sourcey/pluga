# Pluga

> Simple C++ plugin system

[![Circle CI](https://circleci.com/gh/sourcey/libsourcey.svg?style=shield&circle-token=ab142562b19bb857de796d729aab28fa9df7682d)](https://circleci.com/gh/sourcey/libsourcey)
[![Doxygen](http://sourcey.com/images/doxygen.svg)](http://sourcey.com/libsourcey/api-pacm/)

**Homepage**: [http://sourcey.com/pluga](http://sourcey.com/pluga/)  
**Documentation**: [http://sourcey.com/libsourcey/api-pluga/](http://sourcey.com/libsourcey/api-pluga/)  
**Dependencies**: [LibSourcey (base, uv)](http://sourcey.com/libsourcey/)  
**Licence**: LGPL

Pluga is a simple C++ plugin system that you can drop into your own projects. It currently supports:

* Loading cross-platform plugins and shared libraries
* Simple and elegant API for defining plugins
* Strict API versioning for ABI safety

For more information take a look at [this blog post](http://sourcey.com/building-a-simple-cpp-cross-platform-plugin-system) which talks about the concepts and mothodology behind Pluga.

## Installing

* Install [LibSourcey](http://sourcey.com/libsourcey/#installation)
* Clone the Pluga repository in the LibSourcey `src` folder:
~~~ bash
cd libsourcey/src
git clone https://github.com/sourcey/pluga.git
~~~
* Ensure the `BUILD_MODULE_pluga` build variables are enabled in CMake and regenerate the LibSourcey project files
* To build Pluga tests also enable the `BUILD_TESTS` and `BUILD_TEST_pluga` variables in CMake

## Contributing

Contributions in the form of pull requests are always welcome.

1. [Fork Pluga on Github](https://github.com/sourcey/pluga)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## Issues

If you find any bugs or issues please use the [Github issue tracker](https://github.com/sourcey/pluga/issues).
