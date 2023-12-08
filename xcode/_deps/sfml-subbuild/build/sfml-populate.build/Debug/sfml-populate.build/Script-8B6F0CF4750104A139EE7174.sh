#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/mkhlrmnv/Desktop/cpp_project/tower-defence/xcode/_deps/sfml-src
  /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -Dcan_fetch=YES -P /Users/mkhlrmnv/Desktop/cpp_project/tower-defence/xcode/_deps/sfml-subbuild/sfml-populate-prefix/tmp/sfml-populate-gitupdate.cmake
fi

