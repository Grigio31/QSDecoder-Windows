cmake_minimum_required(VERSION 3.25)
project(SQdecode64 VERSION 0.1.0 DESCRIPTION "SQdecode v1.2 compatible SQ decoder VST3")

add_subdirectory(external)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(SQdecode64
    dsp/HilbertCoefficients.h
    dsp/SQDecoder.h
    dsp/SQDecoder.cpp
    vst3/SQdecodeIDs.h
    vst3/SQdecodeProcessor.h
    vst3/SQdecodeProcessor.cpp
    vst3/SQdecodeController.h
    vst3/SQdecodeEntry.cpp
)

target_include_directories(SQdecode64 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_features(SQdecode64 PRIVATE cxx_std_17)
target_link_libraries(SQdecode64 PRIVATE sdk)

if(MSVC)
    target_compile_options(SQdecode64 PRIVATE /W4 /permissive-)
endif()
