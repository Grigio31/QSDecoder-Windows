cmake_minimum_required(VERSION 3.26)
project(QSDecoderWindows2024Core VERSION 1.0.0 LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
  JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
  GIT_TAG 8.0.12
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(JUCE)

# Test build pinned to the original public QS library commit from 2024-06-04.
FetchContent_Declare(
  QS
  GIT_REPOSITORY https://github.com/quarkquad/qs.git
  GIT_TAG 3820485b208e3de2a8d6b274ad52c82e0143c7f9
)
FetchContent_MakeAvailable(QS)

juce_add_plugin(QSDecoder2024Core
  VERSION "1.0.0"
  COMPANY_NAME "QSDecoder Windows"
  BUNDLE_ID "com.qsdecoder.windows.2024core"
  PLUGIN_MANUFACTURER_CODE Qsdw
  PLUGIN_CODE Q24c
  FORMATS VST3
  VST3_CATEGORIES "Fx"
  PRODUCT_NAME "QSDecoder-2024Core"
  DESCRIPTION "QS Regular Matrix active decoder - original public QS core from 2024-06-04"
  COPY_PLUGIN_AFTER_BUILD FALSE
)

target_sources(QSDecoder2024Core PRIVATE
  Source/PluginProcessor.cpp
  Source/PluginProcessor.h
  Source/PluginEditor.cpp
  Source/PluginEditor.h
)

target_compile_features(QSDecoder2024Core PRIVATE cxx_std_17)

target_link_libraries(QSDecoder2024Core PRIVATE
  quark::qs
  juce::juce_dsp
  juce::juce_audio_utils
  juce::juce_recommended_config_flags
  juce::juce_recommended_lto_flags
  juce::juce_recommended_warning_flags
)

target_compile_definitions(QSDecoder2024Core PUBLIC
  JUCE_WEB_BROWSER=0
  JUCE_USE_CURL=0
  JUCE_VST3_CAN_REPLACE_VST2=0
)
