# Math

A [library](https://github.com/cfnptr/math) providing portable programming language compiler and virtual machine.

See the [documentation](https://cfnptr.github.io/plan).

## Features

TODO: 

## Supported operating systems

* Windows (10/11)
* Ubuntu (22.04/24.04)
* macOS (14/15)

This list includes only those systems on which functionality testing is conducted.
However, you can also compile it under any other Linux distribution or operating system.

## Build requirements

* C++17 compiler
* [Git 2.30+](https://git-scm.com/)
* [CMake 3.16+](https://cmake.org/)

Use building [instructions](BUILDING.md) to install all required tools and libraries.

### CMake options

| Name              | Description               | Default value |
|-------------------|---------------------------|---------------|
| PLAN_BUILD_SHARED | Build Plan shared library | `ON`          |
| PLAN_BUILD_TESTS  | Build Plan library tests  | `ON`          |

### CMake targets

| Name        | Description          | Windows | macOS    | Linux |
|-------------|----------------------|---------|----------|-------|
| plan-static | Static Plan library  | `.lib`  | `.a`     | `.a`  |
| plan-shared | Dynamic Plan library | `.dll`  | `.dylib` | `.so` |

## Cloning

```
git clone https://github.com/cfnptr/plan
```

## Building ![CI](https://github.com/cfnptr/plan/actions/workflows/cmake.yml/badge.svg)

* Windows: ```./scripts/build-release.bat```
* macOS / Ubuntu: ```./scripts/build-release.sh```

### Inspired by

* [WebAssembly](https://en.wikipedia.org/wiki/WebAssembly)