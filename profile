#!/bin/sh

export PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# build with clang or g++ ?
# export CC=/usr/bin/clang
# export CXX=/usr/bin/clang++
export CXX=/usr/bin/g++

export PROJECT_NAME=$(basename ${PROJECT_ROOT})
export PROJECT_BUILD_DIR="/build/${PROJECT_NAME}"
export PROJECT_BIN_DIR="/build/${PROJECT_NAME}"
export PROJECT_SRC_DIR="${PROJECT_ROOT}/src"

compiler_banner=$(${CXX} --version)

echo "${compiler_banner}"
echo ""
echo -e "Building \e[32m${PROJECT_NAME}..\e[39m"
echo ""


# 3rd party libraries live in /artifacts/
# it's your job to acquire and build them..for now
export ARTIFACT_ROOT="${HOME}/src/3rdp"
export BOOST_ROOT="${ARTIFACT_ROOT}/boost_1_72_0"

export OPENSSL_ROOT_DIR="${ARTIFACT_ROOT}/openssl"
export OPENSSL_USE_STATIC_LIBS="TRUE"
