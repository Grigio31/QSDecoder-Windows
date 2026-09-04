#include "PluginEditor.h"
#include "PluginProcessor.h"
PluginEditor::PluginEditor(PluginProcessor& p) : AudioProcessorEditor(&p), processor(p) { setSize(360,220); }
void PluginEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colours::black);
    g.setColour(juce::Colours::white);
    g.setFont(14.0f);
    g.drawFittedText("QSDecoder - Windows VST3\n\nStereo QS input: 1 Total Left / 2 Total Right\n\nQuad output:\n1 Front Left\n2 Front Right\n3 Rear Left\n4 Rear Right", getLocalBounds().reduced(18), juce::Justification::topLeft, 10);
}
