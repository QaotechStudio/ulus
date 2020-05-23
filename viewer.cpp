//  vjshader
//
//  viewer.cpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#include "viewer.hpp"

//--------------------------------------------------------------
void viewer::setup(){
  fbo.allocate(ofGetWidth(), ofGetHeight());
  fbo.begin();
  ofClear(255);
  shader.allocate(fbo.getWidth(), fbo.getHeight());
  shader.load("color.frag");
  fbo.end();
  shapes.setup();

  // Setup light
  light.setPosition(1000, 1000, 2000);
}

//--------------------------------------------------------------
void viewer::update(){
  fbo.begin();
  shapes.update();
  shader.setUniform3f("u_color", color.x, color.y, color.z);
  fbo.end();
  
  fbo.begin();
  shader.render();
  shader.draw(0, 0, ofGetWidth(), ofGetHeight());
  fbo.end();
}

//--------------------------------------------------------------
void viewer::draw(){
//    ofEnableDepthTest();
    light.enable();
    fbo.draw(0, 0);
    camera.begin();
    shapes.draw();
    camera.end();
}

//--------------------------------------------------------------
void viewer::keyPressed(int key){
  if (key == 'f'){
    ofToggleFullscreen();
  }
}

//--------------------------------------------------------------
void viewer::windowResized(int w, int h){
  shader.allocate(w, h);
  fbo.allocate(w, h);
}
