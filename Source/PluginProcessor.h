#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <qs/qs.h>

class PluginProcessor : public juce::AudioProcessor {
public:
    PluginProcessor();
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    bool isBusesLayoutSupported(const BusesLayout&) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return JucePlugin_Name; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    bool isMidiEffect() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }
    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void getStateInformation(juce::MemoryBlock&) override {}
    void setStateInformation(const void*, int) override {}
private:
    qs::decode::MultiBandDecoder decoder = {
        std::vector<qs::decode::BandSpec>({
            {20.0f,20.0f,10.0f,10.0f,juce::Decibels::decibelsToGain(-6.0f),
             qs::decode::FilterCoefficients(0.061511768503621556,0.061511768503621556,0.0,1.0,-0.8769764629927568,0.0)},
            {20.0f,20.0f,10.0f,10.0f,juce::Decibels::decibelsToGain(-6.0f),
             qs::decode::FilterCoefficients(0.9384882314963784,-0.9384882314963784,0.0,1.0,-0.8769764629927568,0.0)}
        })
    };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
