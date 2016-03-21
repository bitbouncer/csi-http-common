cmake_minimum_required(VERSION 2.8)
INCLUDE(${CMAKE_SOURCE_DIR}/../build-scripts/CMakeDependencies.txt)

set(EXT_LIBS ${CSI_HTTP_CLIENT_LIBS})

#compile a avro library from third party source since everything boost in avro build seems to conflict with our version
include_directories (${AVROCPP_PATH}/api)

file(GLOB CSI_AVRO_SRC
    ${AVROCPP_PATH}/api/*.hh
	${AVROCPP_PATH}/api/buffer/*.hh
    ${AVROCPP_PATH}/impl/*.cc
	${AVROCPP_PATH}/impl/json/*.cc
	${AVROCPP_PATH}/impl/parsing/*.cc
)

ADD_LIBRARY(csi-avro STATIC ${CSI_AVRO_SRC})

SET(SNAPPY_SRCS
        ${SNAPPY_PATH}/snappy.h 
        ${SNAPPY_PATH}/snappy.cc
        ${SNAPPY_PATH}/snappy-c.cc
        ${SNAPPY_PATH}/snappy-c.h
        ${SNAPPY_PATH}/snappy-internal.h
        ${SNAPPY_PATH}/snappy-sinksource.cc        
        ${SNAPPY_PATH}/snappy-sinksource.h
        ${SNAPPY_PATH}/snappy-stubs-internal.cc
        ${SNAPPY_PATH}/snappy-stubs-internal.h)        

if(WIN32)
add_definitions(-Dssize_t=int)
endif()

ADD_LIBRARY(csi-snappy STATIC ${SNAPPY_SRCS})
	
add_subdirectory(csi_http_common)
