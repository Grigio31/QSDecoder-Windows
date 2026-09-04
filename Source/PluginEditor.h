#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
class PluginProcessor;
class PluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PluginEditor(PluginProcessor&);
    void paint(juce::Graphics&) override;
private:
    PluginProcessor& processor;
};
