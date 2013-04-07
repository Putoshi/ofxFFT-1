//
//  ofxFFTLiveMutilChannel.cpp
//  fftTest
//
//  Created by coheiaoki on 2013/03/26.
//
//

#include "ofxFFTLiveMutilChannel.h"

ofxFFTLiveMutilChannel::ofxFFTLiveMutilChannel(){
    soundStream = NULL;
}

ofxFFTLiveMutilChannel::~ofxFFTLiveMutilChannel() {
    if(soundStream) {
        delete soundStream;
        soundStream = NULL;
    }
    fftLives.clear();
}

void ofxFFTLiveMutilChannel::setup(ofSoundStream * soundStream,int input) {
    this->soundStream = soundStream;
    nInput = input;
    soundStream->setup(
                       this,                   // callback obj.
                       0,                      // out channels.
                       nInput,                      // in channels.
                       44100,                  // sample rate.
                       buffersize,         // buffer size.
                       4                       // number of buffers.
                       );
    for (int i=0; i<nInput; i++) {
        FFTLive *fftLive = new FFTLive();
        fftLives.push_back(fftLive);
    }
    
}

void ofxFFTLiveMutilChannel::update(){
    for (int i=0; i<nInput; i++) {
        fftLives[i]->update();
    }
}

void ofxFFTLiveMutilChannel::audioIn(float * input, int bufferSize, int nChannels) {
     for (int i=0; i<nInput; i++) {
        int cnt = 0;
        for (int j=0; j < bufferSize; j=(j+1)*(nChannels-1)) {
            fftLives[i]->specData[cnt] = input[j];
            cnt++;
            
        }
    }
 }