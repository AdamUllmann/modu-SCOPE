# Modu-SCOPE

This project is a JUCE-based audio plugin that provides both an oscilloscope and a spectrogram for visualizing audio waveforms and frequencies in real-time. Part of the ModuSuite plugin collection.

![Visualizer Interface](https://github.com/AdamUllmann/images-for-repos/blob/f23ac0a683ca1676e91188208fab18e0e798e441/modu_scope.png)

## Features

- **Oscilloscope**: Visualize the audio waveform in the time domain.

- **Spectrogram**: Visualize the audio frequencies over time using a spectrogram.

### Building from Source

1. Clone this repository to your local machine.

2. Open the project in your preferred C++ IDE with JUCE support (e.g., Projucer, Visual Studio with JUCE plugin).

3. Build the project for your target platform (e.g., VST, AU, AAX).

4. Locate the built plugin file (e.g., .vst3, .au, .aax) and copy it to your audio plugin directory.

## Usage

Once installed, you can use the plugin in any audio software that supports VST, AU, or AAX plugins.

1. Open your audio software and create a new project.

2. Add modu-SCOPE to a track or channel in your project.

3. Play audio in your project, and you should see the waveform in the plugin UI.

## License

This project is licensed under the [Apache License](LICENSE).
