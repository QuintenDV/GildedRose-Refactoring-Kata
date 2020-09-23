# C++ version of Gilded Rose refactoring kata

## Remarks
* Work in progress.
* It doesn't seem right that _Inventory_ is a separate class. Maybe I should merge it into the CatItemFactory.
* Might do some renaming, for example Inventory and CategorizedItem

## How to use
The C++ version of the Gilded Rose refactoring kata uses the following test framework:
  1. Traditional unit test with the [Googletest](https://github.com/google/googletest) test framework in the `test/cpp_googletest_unittest` folder.

## Prerequisites

* CMake version >= 3.13
* C++ compiler that support C++11

## How to build and run tests in a terminal

### Build and run tests

    $ cd ${GIT_FOLDER}
    $ cpp/run_tests.sh