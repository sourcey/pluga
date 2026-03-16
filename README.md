# Pluga

> Simple C++ plugin system

[![CI](https://github.com/sourcey/libsourcey/actions/workflows/ci.yml/badge.svg)](https://github.com/sourcey/libsourcey/actions/workflows/ci.yml)

**Repository**: [https://github.com/sourcey/libsourcey](https://github.com/sourcey/libsourcey)
**Dependencies**: [LibSourcey (base)](https://github.com/sourcey/libsourcey)
**Licence**: LGPL-2.1+

Pluga is a simple C++ plugin system that you can drop into your own projects. It currently supports:

* Loading cross-platform plugins and shared libraries
* Simple and elegant API for defining plugins
* Strict API versioning for ABI safety

## Installing

Pluga is part of the [LibSourcey](https://github.com/sourcey/libsourcey) project. To build:

~~~ bash
git clone --recurse-submodules https://github.com/sourcey/libsourcey.git
cd libsourcey
cmake -B build -DBUILD_MODULE_pluga=ON -DBUILD_TESTS=ON
cmake --build build
~~~

Pluga can also be used as an external module by cloning it into the LibSourcey `src` folder, where it will be auto-discovered by the build system.

## Contributing

Contributions in the form of pull requests are always welcome.

1. [Fork LibSourcey on Github](https://github.com/sourcey/libsourcey)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
