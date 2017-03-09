set(SOURCES_LIB
    test1.cxx
)

set(SOURCES_EXE main.cxx)

# Headers from sources
string(REPLACE ".cxx" ".h" HEADERS_LIB "${SOURCES_LIB}")
string(REPLACE ".cxx" ".h" HEADERS_EXE "${SOURCES_EXE}")

set(PROJECT_UTIL_LIB "${PROJECT_NAME}Support")
add_library(${PROJECT_UTIL_LIB} SHARED ${SOURCES_LIB})
# target_include_directories(${PROJECT_UTIL_LIB} PUBLIC ${ROOT_INCLUDE_DIR} ${FASTJET_DIR}/include ${PYTHIA8_DIR}/include $ENV{FASTSIM}/EmcalTriggerFast/src $ENV{FASTSIM}/src/rutil)
# target_link_libraries(${PROJECT_UTIL_LIB} ${PYTHIA8_LDFLAGS} ${FASTJET_LIBS} ${ROOT_LIBRARIES} fjwrapper wrapper revent rutil pyutil EMCpidPar -L$ENV{FASTSIM}/lib -lEMCALTriggerFast)

target_include_directories(${PROJECT_UTIL_LIB} PUBLIC ${ROOT_INCLUDE_DIR})
target_link_libraries(${PROJECT_UTIL_LIB} ${PYTHIA8_LDFLAGS} ${FASTJET_LIBS} ${ROOT_LIBRARIES} MyUtils)

add_executable(${PROJECT_NAME} ${SOURCES_EXE})
target_include_directories(${PROJECT_NAME} PUBLIC ${ROOT_INCLUDE_DIR})
target_link_libraries( ${PROJECT_NAME} ${PROJECT_UTIL_LIB})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

install(TARGETS ${PROJECT_UTIL_LIB} LIBRARY DESTINATION lib)

install(FILES ${HEADERS_LIB} DESTINATION include)
