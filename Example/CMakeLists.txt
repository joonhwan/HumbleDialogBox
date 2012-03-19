CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(Example)

SET(${PROJECT_NAME}_CPP
  Example.cpp
  ExampleDlg.cpp
  )

SET(${PROJECT_NAME}_H
  Example.h
  ExampleDlg.h
  resource.h
  stdafx.h
  targetver.h
  )

SET(${PROJECT_NAME}_RC
  Example.rc
  )

ADD_MSVC_PRECOMPILED_HEADER("stdafx.h" "stdafx.cpp" ${PROJECT_NAME}_CPP)

ADD_EXECUTABLE(${PROJECT_NAME} WIN32
  ${${PROJECT_NAME}_CPP}
  ${${PROJECT_NAME}_H}
  ${${PROJECT_NAME}_RC}
  )

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
  ${MFC_LIBRARIES}
  UiLib
  )
