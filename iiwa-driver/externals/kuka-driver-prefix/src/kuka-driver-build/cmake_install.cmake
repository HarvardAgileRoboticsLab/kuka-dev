# Install script for directory: /home/yezhao/code/kuka-dev/iiwa-driver/kuka-driver

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/yezhao/code/kuka-dev/iiwa-driver/build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake_lcmt_iiwa_command.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake_lcmt_iiwa_status.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lib/libkuka_driver_lcmtypes.a")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/kuka_driver.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lib/pkgconfig/CFLAGS.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/drake" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake/lcmt_iiwa_command.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes/drake" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake/lcmt_iiwa_status.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/lcmtypes" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/kuka_driver.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/java" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmtypes_kuka_driver.jar")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lib/pkgconfig/lcmtypes_kuka-driver-java.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake/__init__.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake/__init__.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake/lcmt_iiwa_command.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake/lcmt_iiwa_command.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake/__init__.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake/__init__.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake/lcmt_iiwa_status.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/yezhao/code/kuka-dev/iiwa-driver/build/lib/python2.7/dist-packages/drake" TYPE FILE FILES "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/lcmgen/lcmtypes/drake/lcmt_iiwa_status.py")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/yezhao/code/kuka-dev/iiwa-driver/externals/kuka-driver-prefix/src/kuka-driver-build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
