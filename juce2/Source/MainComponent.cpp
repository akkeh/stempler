/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include "AudioCallback.h"
#include "loadfile.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);

 	load_but = new TextButton(("play"));
    (*load_but).setBounds(10, 10, 50, 20);
    addAndMakeVisible(load_but);
    (*load_but).addListener(this);
    
    note_but = new TextButton(("noot"));
    (*note_but).setBounds(100, 10, 50, 20);
    addAndMakeVisible(note_but);
    (*note_but).addListener(this);


}

MainContentComponent::~MainContentComponent()
{
    deleteAllChildren();
}

void MainContentComponent::buttonClicked(Button* button) {
    if(button == load_but) {
		load_button();
	} else if (button == note_but) {

	}
}

void MainContentComponent::load_button() {
	FileChooser myChooser ("I pitty the file who doesn't choose a fool!", File::getSpecialLocation(File::userHomeDirectory), "*.wav");
        if(myChooser.browseForFileToOpen()) {
            File wavFile (myChooser.getResult());
			long length_of_file; int channels;
            float* data = load_file(wavFile.getFullPathName(), &length_of_file, &channels);
			file_buf = data;
			file_len = length_of_file;
			file_chn = channels;
        }

}


void MainContentComponent::audioCallback(float** buffer, int channels, int frames) {

}


void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

note::note(float* n_buf, long n_len) {
	this->buffer = n_buf;
	this->len = n_len;
	this->read_p = 0;
}
