
SET(LIB_SRCS
	csi_http.h
	csi_http.cpp
	spinlock.cpp
	spinlock.h
	encoding/avro_json_encoding.h
	encoding/avro_json_spirit_encoding.h
	encoding/avro_raw_binary_encoding.h
    )

add_library (csi-http-common STATIC ${LIB_SRCS})
target_include_directories(csi-http-common PRIVATE ${CSI_INCLUDE_PATH})
