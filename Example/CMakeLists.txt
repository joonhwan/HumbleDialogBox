
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Example)

set(${PROJECT_NAME}_CPP
  ExampleApp.cpp
  ExampleDlg.cpp
  )

set(${PROJECT_NAME}_H
  ExampleApp.h
  ExampleDlg.h
  resource.h
  stdafx.h
  targetver.h
  )

set(${PROJECT_NAME}_RC
  Example.rc
  )

ADD_MSVC_PRECOMPILED_HEADER("stdafx.h" "stdafx.cpp" ${PROJECT_NAME}_CPP)

target_link_libraries(${PROJECT_NAME}
  ${MFC_LIBRARIES}
  )
