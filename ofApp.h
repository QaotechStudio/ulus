//  vjshader
//
//  ofApp.h
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxShader.h"
#include "ofxShaderFilter.h"
#include "viewer.hpp"
#include "settingWindow.hpp"
#include "Shape.hpp"

class ofApp : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void windowResized(int w, int h);
  void gotMessage(ofMessage msg);
  
//  CONTROLS
  ofxPanel gui;
  
  ofxShaderFilter curShader;
  ofxShaderFilter futShader;
  
  viewer viewer;
  
  shared_ptr<settingWindow> future;
};
