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
    
        
    //shape paramaters
    shapeParams.setName("Shape Parameters");
    
    shapeParams.add(drawBox.set("Box", false));
    shapeParams.add(decay.set("Decay", 0.0, 0.0, 1.0));
    shapeParams.add(rotateScene.set("Rotate", ofVec3f(0.0), ofVec3f(-1.0), ofVec3f(1.0)));
    shapeParams.add(numberOfShapes.set("# Shapes", 100, 0, 200));
    
    // Setup shape positions
    for (int i = 0; i < NUM_SHAPES; i++)
    {
        posShape.push_back(ofVec3f(ofRandom(-300, 300), ofRandom(-300, 300), ofRandom(-300, 300)));
        colShape.push_back(ofColor::fromHsb(255 * i / (float)NUM_SHAPES, 255, 255, 255));
    }
    
    bands = 128;
    
    fft = new float[bands];
    for (int i = 0; i < bands; i++) {
        fft[i] = 0;
    }
    


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
    //camera.begin();
    if(drawBox){
//          for (int i = 0; i < posShape.size(); i++)
        for (int i = 0; i < numberOfShapes; i++) {
              ofSetColor(colShape[i]);
              ofPushMatrix();
              ofTranslate(posShape[i]);
              for(int j = 0; j < bands; j++){
                  ofRotateXDeg(rotate.x);
                  ofRotateYDeg(rotate.y);
                  ofRotateZDeg(rotate.z);
                  ofDrawBox(fft[j] * 20);
              }
              ofPopMatrix();
            }
    }
    //camera.end();
    
}


