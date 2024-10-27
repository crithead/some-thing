# Some Thing

This was going to be an AWS IoT Thing, but the project was cancelled before
it became much more than this.  This project is now an example of how to set
up a Makefile to build the objects in a side directory and how to write unit
tests using Boost::Test.

## Build

For building on CentOS 9, install the following packages.

```sh
sudo yum install boost-devel boost-test
```

BuIld the project and run the tests.

```sh
make
make clean build V=1 D=1
make clean test V=1
```

