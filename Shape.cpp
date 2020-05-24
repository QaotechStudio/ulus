//
//  Shape.cpp
//  vjshader
//
//  Created by Ecem Karaca on 23/05/2020.
//

#include "Shape.hpp"

void Shape::setup(){
    sound.load("muziek.wav");
    sound.play();
    sound.setLoop(true);
    
    // Setup shape positions
    for (int i = 0; i < NUM_SHAPES; i++)
    {
        posShape.push_back(ofVec3f(ofRandom(-300, 300), ofRandom(-300, 300), ofRandom(-500, 500)));
        colShape.push_back(ofColor::fromHsb(255 * i / (float)NUM_SHAPES, 255, 255, 255));
    }    
    bands = 128;
    
    fft = new float[bands];
    for (int i = 0; i < bands; i++) {
        fft[i] = 0;
    }
    ofSetLineWidth(10.0);
}

void Shape::update(){
    ofSoundUpdate();
     
    sound.setVolume(0.2);

     
    soundSpectrum = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
      fft[i] *= decay;
      if (fft[i] < soundSpectrum[i]) {
        fft[i] = soundSpectrum[i];
      }
    }
    
    rotate.x += rotateScene->x;
    rotate.y += rotateScene->y;
    rotate.z += rotateScene->z;
             
}

void Shape::draw(){
        for (int i = 0; i < numberOfShapes; i++) {
              
              ofSetColor(colShape[i]);
              ofPushMatrix();
              ofTranslate(posShape[i]);
              for(int j = 0; j < bands; j++){
                  ofRotateXDeg(rotate.x);
                  ofRotateYDeg(rotate.y);
                  ofRotateZDeg(rotate.z);
                  if(drawBox){
                      ofFill();
                      ofDrawBox(fft[j] * 50);
                  }else{
                    ofNoFill();
                   ofDrawCircle(0, 0, fft[j] * 50);
                  }
              }
              ofPopMatrix();
            }

}


