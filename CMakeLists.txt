CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(HumbleDialog)

# 
# MFC configuration
# 
ADD_DEFINITIONS(-D_AFXDLL)
ADD_DEFINITIONS(-DUNICODE)
ADD_DEFINITIONS(-D_UNICODE)
ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
SET(CMAKE_MFC_FLAG 2)
# not really needed but explicitly...
SET(MFC_LIBRARIES 
  "debug;mfc90ud.lib;debug;msvcrtd.lib;debug;msvcprtd.lib"
  )

# PCH support
SET(MSVC_PCH_PREFIX "")
MACRO(ADD_MSVC_PRECOMPILED_HEADER PrecompiledHeader PrecompiledSource SourcesVar)
  GET_FILENAME_COMPONENT(PrecompiledBasename ${PrecompiledHeader} NAME_WE)
  # set(PrecompiledBinary "$(IntDir)/$(TargetName).pch")
  SET(PrecompiledBinary "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/${PROJECT_NAME}.pch")
  SET(Sources ${${SourcesVar}})
  
  SET_SOURCE_FILES_PROPERTIES(${PrecompiledSource}
    PROPERTIES COMPILE_FLAGS "/Yc\"${PrecompiledHeader}\" /Fp\"${PrecompiledBinary}\""
    OBJECT_OUTPUTS "${PrecompiledBinary}")
  SET_SOURCE_FILES_PROPERTIES(${Sources}
    PROPERTIES COMPILE_FLAGS "/Yu\"${PrecompiledHeader}\" /FI\"${PrecompiledBinary}\" /Fp\"${PrecompiledBinary}\""
    OBJECT_DEPENDS "${PrecompiledBinary}")
  # Add precompiled header to SourcesVar
  LIST(APPEND ${SourcesVar} ${PrecompiledSource})
  SET(MSVC_PCH_PREFIX "")
ENDMACRO(ADD_MSVC_PRECOMPILED_HEADER)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/CppUnitLite)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/UiLib)

ENABLE_TESTING()

ADD_SUBDIRECTORY(CppUnitLite)
ADD_SUBDIRECTORY(UiLib)
ADD_SUBDIRECTORY(UiLibTest)
ADD_SUBDIRECTORY(Example)

