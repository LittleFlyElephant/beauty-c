cmake_minimum_required(VERSION 3.5)
project(beauty_c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl")

set(SOURCE_FILES
    curlHelper/curly.cpp
    curlHelper/curly.h
#    cxlogic/Do.cpp
#    cxlogic/Method.cpp
#    cxlogic/Point.cpp
    entity/APIHelper.cpp
    entity/APIHelper.h
    entity/Author.cpp
    entity/Author.h
    entity/Entity.cpp
    entity/Entity.h
    rapidjson/error/en.h
    rapidjson/error/error.h
    rapidjson/internal/biginteger.h
    rapidjson/internal/diyfp.h
    rapidjson/internal/dtoa.h
    rapidjson/internal/ieee754.h
    rapidjson/internal/itoa.h
    rapidjson/internal/meta.h
    rapidjson/internal/pow10.h
    rapidjson/internal/regex.h
    rapidjson/internal/stack.h
    rapidjson/internal/strfunc.h
    rapidjson/internal/strtod.h
    rapidjson/internal/swap.h
    rapidjson/msinttypes/inttypes.h
    rapidjson/msinttypes/stdint.h
    rapidjson/allocators.h
    rapidjson/document.h
    rapidjson/encodedstream.h
    rapidjson/encodings.h
    rapidjson/filereadstream.h
    rapidjson/filewritestream.h
    rapidjson/fwd.h
    rapidjson/istreamwrapper.h
    rapidjson/memorybuffer.h
    rapidjson/memorystream.h
    rapidjson/ostreamwrapper.h
    rapidjson/pointer.h
    rapidjson/prettywriter.h
    rapidjson/rapidjson.h
    rapidjson/reader.h
    rapidjson/schema.h
    rapidjson/stream.h
    rapidjson/stringbuffer.h
    rapidjson/writer.h
    web/mongoose.c
    web/mongoose.h
    entity/main.cpp)

add_executable(beauty_c ${SOURCE_FILES})

