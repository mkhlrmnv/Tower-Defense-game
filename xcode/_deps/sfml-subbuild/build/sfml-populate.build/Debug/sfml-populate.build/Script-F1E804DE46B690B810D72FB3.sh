#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/mkhlrmnv/Desktop/cpp_project/tower-defence/xcode/_deps
  /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -P /Users/mkhlrmnv/Desktop/cpp_project/tower-defence/xcode/_deps/sfml-subbuild/sfml-populate-prefix/tmp/sfml-populate-gitclone.cmake
  /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E touch /Users/mkhlrmnv/Desktop/cpp_project/tower-defence/xcode/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/Debug/sfml-populate-download
fi

