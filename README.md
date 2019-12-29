# project notes

## state machine

## requirements
 - cmake
 - ninja
 - g++
 - boost (built against 1_72_0)

## profile
The profile file declares environment variables for the project build.  For example, profile exports variables like:

    export ARTIFACT_ROOT="/artifacts"

It's worth starting here to understand that 3rd party libraries are built (by you) and made available in this directory, then first referenced in profile.

## building
see build.sh
