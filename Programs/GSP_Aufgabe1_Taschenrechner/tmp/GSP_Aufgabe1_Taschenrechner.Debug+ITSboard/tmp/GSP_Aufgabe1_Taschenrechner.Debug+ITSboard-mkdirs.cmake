# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard"
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/1"
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard"
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard/tmp"
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard/src/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard-stamp"
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard/src"
  "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard/src/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard/src/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Christoph/Desktop/HAW-Git/Semester 2/ITS-BRD-VSC/Programs/GSP_Aufgabe1_Taschenrechner/tmp/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard/src/GSP_Aufgabe1_Taschenrechner.Debug+ITSboard-stamp${cfgdir}") # cfgdir has leading slash
endif()
