#!/bin/sh

echo "Emptying Build Folder"
find build -delete
mkdir build
cd build

echo "Stale build files removed, generating new project files."
cmake ../src