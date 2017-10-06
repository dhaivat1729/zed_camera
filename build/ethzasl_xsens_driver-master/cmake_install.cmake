# Install script for directory: /home/dhaivat666/catkin_zed/src/ethzasl_xsens_driver-master

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dhaivat666/catkin_zed/install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dhaivat666/catkin_zed/build/ethzasl_xsens_driver-master/catkin_generated/installspace/xsens_driver.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/xsens_driver/cmake" TYPE FILE FILES
    "/home/dhaivat666/catkin_zed/build/ethzasl_xsens_driver-master/catkin_generated/installspace/xsens_driverConfig.cmake"
    "/home/dhaivat666/catkin_zed/build/ethzasl_xsens_driver-master/catkin_generated/installspace/xsens_driverConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/xsens_driver" TYPE FILE FILES "/home/dhaivat666/catkin_zed/src/ethzasl_xsens_driver-master/package.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/xsens_driver" TYPE PROGRAM FILES
    "/home/dhaivat666/catkin_zed/src/ethzasl_xsens_driver-master/nodes/mtnode.py"
    "/home/dhaivat666/catkin_zed/src/ethzasl_xsens_driver-master/nodes/mtdef.py"
    "/home/dhaivat666/catkin_zed/src/ethzasl_xsens_driver-master/nodes/mtdevice.py"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/xsens_driver" TYPE DIRECTORY FILES "/home/dhaivat666/catkin_zed/src/ethzasl_xsens_driver-master/launch")
endif()

