//
//  ofxFFTLiveMutilChannel.h
//  fftTest
//
//  Created by coheiaoki on 2013/03/26.
//
//

#ifndef __fftTest__ofxFFTLiveMutilChannel__
#define __fftTest__ofxFFTLiveMutilChannel__

#include "ofMain.h"
#include "ofxFFTBase.h"

class FFTLive : public ofxFFTBase {    
public:
    FFTLive(){};
    ~FFTLive(){};
};

class ofxFFTLiveMutilChannel : public ofBaseApp 
{
public:
    ofxFFTLiveMutilChannel();
    ~ofxFFTLiveMutilChannel();
    void setup(ofSoundStream * soundStream,int input);
    void update();
    void audioIn(float * input, int bufferSize, int nChannels);
    ofSoundStream * soundStream;
    const int buffersize = 512;
    int nInput;
    ofMutex mutex;
    float *specData;
    vector <FFTLive*> fftLives;

};

#endif /* defined(__fftTest__ofxFFTLiveMutilChannel__) */
