PROJECT(UiLib)

SET(sources
  ChainComposer.cpp
  MockChainComposerView.cpp
  )

SET(header
  ChainComposer.h
  ChainComposerView.h
  )

ADD_LIBRARY(${PROJECT_NAME}
  ${sources}
  ${header}
  )
