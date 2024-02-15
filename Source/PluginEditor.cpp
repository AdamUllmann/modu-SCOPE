/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ModuScopeAudioProcessorEditor::ModuScopeAudioProcessorEditor (ModuScopeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible(oscilloscopeComponent);
    oscilloscopeComponent.setProcessor(&audioProcessor);

    setSize(800, 600);
}

ModuScopeAudioProcessorEditor::~ModuScopeAudioProcessorEditor()
{
}

//==============================================================================
void ModuScopeAudioProcessorEditor::paint (juce::Graphics& g)
{
    juce::Image background(juce::Image::ARGB, getWidth(), getHeight(), true);
    juce::Graphics bgGraphics(background);
    bgGraphics.fillAll(juce::Colours::black.withAlpha(0.8f));

    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

    g.drawImageAt(background, 0, 0);
}

void ModuScopeAudioProcessorEditor::resized()
{
    oscilloscopeComponent.setBounds(getLocalBounds());
}
