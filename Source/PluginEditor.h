/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"



class OscilloscopeComponent : public juce::Component, public juce::Timer
{
public:
    OscilloscopeComponent()
    {
        setOpaque(true);
    }

    void paint(juce::Graphics& g) override
    {
        juce::MessageManagerLock mmLock;

        if (!mmLock.lockWasGained())
            return;

        g.fillAll(juce::Colours::black.withAlpha(0.8f));

        if (processor == nullptr)
            return;

        if (auto* playHead = processor->getPlayHead())
        {
            juce::AudioPlayHead::CurrentPositionInfo pos;
            playHead->getCurrentPosition(pos);
        }

        const int numChannels = processor->getTotalNumInputChannels();
        const int numSamples = processor->getAudioBuffer().getNumSamples();

        juce::Path path;

        for (int sample = 0; sample < numSamples; ++sample)
        {
            float sum = 0.0f;

            for (int channel = 0; channel < numChannels; ++channel)
            {
                const float* channelData = processor->getAudioBuffer().getReadPointer(channel);
                sum += channelData[sample];
            }

            float x = static_cast<float>(sample) / numSamples * getWidth();
            float y = getHeight() / 2 + sum / numChannels * getHeight() / 2;

            if (sample == 0)
                path.startNewSubPath(x, y);
            else
                path.lineTo(x, y);
        }

        g.setColour(juce::Colours::white);
        g.strokePath(path, juce::PathStrokeType(2.0f));
    }

    void OscilloscopeComponent::timerCallback()
    {
        if (isVisible())
            repaint();
    }

    void setProcessor(ModuScopeAudioProcessor* processorToUse)
    {
        processor = processorToUse;
        startTimerHz(120);
    }

private:
    ModuScopeAudioProcessor* processor = nullptr;
};

//==============================================================================
/**
*/
class ModuScopeAudioProcessorEditor  : public juce::AudioProcessorEditor, private juce::AsyncUpdater
{
public:
    ModuScopeAudioProcessorEditor (ModuScopeAudioProcessor&);
    ~ModuScopeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ModuScopeAudioProcessor& audioProcessor;
    OscilloscopeComponent oscilloscopeComponent;
    
    void handleAsyncUpdate() override
    {
        repaint();
    }

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModuScopeAudioProcessorEditor)
};
