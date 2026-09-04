cmake_minimum_required(VERSION 3.26)
project(QSDecoderWindows VERSION 1.0.0 LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
  JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 8.0.12
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(JUCE)

FetchContent_Declare(
  QS
  GIT_REPOSITORY https://github.com/quarkquad/qs.git
  GIT_TAG main
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(QS)

juce_add_plugin(QSDecoder
  VERSION "1.0.0"
  COMPANY_NAME "QSDecoder Windows"
  BUNDLE_ID "com.qsdecoder.windows"
  PLUGIN_MANUFACTURER_CODE Qsdw
  PLUGIN_CODE Qsdc
  FORMATS VST3
  VST3_CATEGORIES "Fx"
  PRODUCT_NAME "QSDecoder"
  DESCRIPTION "QS Regular Matrix active decoder - stereo input to quad output"
  COPY_PLUGIN_AFTER_BUILD FALSE
)

target_sources(QSDecoder PRIVATE
  Source/PluginProcessor.cpp
  Source/PluginProcessor.h
  Source/PluginEditor.cpp
  Source/PluginEditor.h
)

target_compile_features(QSDecoder PRIVATE cxx_std_17)

target_link_libraries(QSDecoder PRIVATE
  quark::qs
  juce::juce_dsp
  juce::juce_audio_utils
  juce::juce_recommended_config_flags
  juce::juce_recommended_lto_flags
  juce::juce_recommended_warning_flags
)

target_compile_definitions(QSDecoder PUBLIC
  JUCE_WEB_BROWSER=0
  JUCE_USE_CURL=0
  JUCE_VST3_CAN_REPLACE_VST2=0
)
