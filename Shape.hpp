//
//  Shape.hpp
//  vjshader
//
//  Created by Ecem Karaca on 23/05/2020.
//

#ifndef Shape_hpp
#define Shape_hpp

#include "ofMain.h"
#include "ofxGui.h"

class Shape {
public:
  void setup();
  void update();
  void draw();
  
  ofParameterGroup shapeParams;
    
  ofParameter <bool> drawBox;
  ofParameter<float> decay;
  ofParameter<ofVec3f> rotateScene;
  ofParameter<int> numberOfShapes;
    
  ofVec3f rotate;
  
  int NUM_SHAPES = 100;

  vector<ofVec3f> posShape;
  vector<ofColor> colShape;
    
  ofSoundPlayer sound;
  float *fft;
  float *soundSpectrum;
  int bands;
};


#endif /* Shape_hpp */
