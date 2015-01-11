##############################################
#          Library Creation                  #
##############################################
SET (LIBRARY_NAME planning_common)
SET (LIB_MAJOR 0)
SET (LIB_MINOR 0)
SET (LIB_RELEASE 1)

ADD_LIBRARY( ${LIBRARY_NAME} SHARED
  GraphDisplay.cpp
  PlanNode.h
  ActionNode.h
  LiteralNode.h
)

target_link_libraries(${LIBRARY_NAME} 
  ${LEMON_LIBRARIES}
  )

SET (_soversion ${LIB_MAJOR}.${LIB_MINOR}.${LIB_RELEASE})

set_target_properties(${LIBRARY_NAME} PROPERTIES SOVERSION ${LIB_MAJOR} VERSION ${_soversion})

INSTALL(TARGETS ${LIBRARY_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
)
