#pragma once
#include <juce_gui_basics/juce_gui_basics.h>
class PluginProcessor;
class PluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PluginEditor(PluginProcessor&);
    void paint(juce::Graphics&) override;
private:
    PluginProcessor& processor;
};
