PROJECT(CppUnitLite)

SET(sources
  Failure.cpp
  SimpleString.cpp
  Test.cpp
  TestRegistry.cpp
  TestResult.cpp
  )

SET(header
  Failure.h
  SimpleString.h
  Test.h
  TestHarness.h
  TestRegistry.h
  TestResult.h
  )

ADD_LIBRARY(${PROJECT_NAME}
  ${sources}
  ${header}
  )
