# Pluga

> Simple C++ plugin system

[![CI](https://github.com/sourcey/icey/actions/workflows/ci.yml/badge.svg)](https://github.com/sourcey/icey/actions/workflows/ci.yml)

**Repository**: [https://github.com/sourcey/icey](https://github.com/sourcey/icey)
**Dependencies**: [icey (base)](https://github.com/sourcey/icey)
**Licence**: LGPL-2.1+

Pluga is a simple C++ plugin system that you can drop into your own projects. It currently supports:

* Loading cross-platform plugins and shared libraries
* Simple and elegant API for defining plugins
* Strict API versioning for ABI safety

## Installing

Pluga is part of the [icey](https://github.com/sourcey/icey) project. To build:

~~~ bash
git clone https://github.com/sourcey/icey.git
cd icey
git submodule update --init src/pluga
cmake -B build -DBUILD_MODULE_pluga=ON -DBUILD_TESTS=ON
cmake --build build
~~~

Pluga can also be used as an external module by cloning it into the icey `src` folder, where it will be auto-discovered by the build system.

## Contributing

Contributions in the form of pull requests are always welcome.

1. [Fork icey on Github](https://github.com/sourcey/icey)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request
