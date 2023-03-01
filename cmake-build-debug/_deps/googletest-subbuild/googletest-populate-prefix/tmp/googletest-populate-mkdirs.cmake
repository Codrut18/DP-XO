# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-src"
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-build"
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/FACULTATE/Facultate/An_2_sem_2/DP_DesignPattern/ProjectX0/DP-XO/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
