#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor()
 : AudioProcessor(BusesProperties()
   .withInput("Input", juce::AudioChannelSet::stereo(), true)
   .withOutput("Output", juce::AudioChannelSet::quadraphonic(), true)) {}

void PluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    decoder.prepare(sampleRate, samplesPerBlock);
}
void PluginProcessor::releaseResources() {}

bool PluginProcessor::isBusesLayoutSupported(const BusesLayout& l) const {
    return l.getMainInputChannelSet() == juce::AudioChannelSet::stereo()
        && l.getMainOutputChannelSet() == juce::AudioChannelSet::quadraphonic();
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;
    decoder.process(buffer);
}

juce::AudioProcessorEditor* PluginProcessor::createEditor() {
    return new PluginEditor(*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() {
    return new PluginProcessor();
}
