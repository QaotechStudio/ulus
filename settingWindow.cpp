//  vjshader
//
//  settingWindow.cpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#include "settingWindow.hpp"

//--------------------------------------------------------------
void settingWindow::setup(){
  ofSetWindowTitle("controls");
  shapes.setup();
    
  gui.setup();
  gui.add(uiAction.set("action", false));
  gui.add(uiActionSpeed.set("action speed", 0, 0, 1));
  gui.add(uiColor.set("color", ofVec3f(0), ofVec3f(0), ofVec3f(1)));
  shapes.shapeParams.setName("Shape Parameters");
    
  shapes.shapeParams.add(shapes.drawBox.set("Box", false));
  shapes.shapeParams.add(shapes.decay.set("Decay", 0.0, 0.0, 1.0));
  shapes.shapeParams.add(shapes.rotateScene.set("Rotate", ofVec3f(0.0), ofVec3f(-1.0), ofVec3f(1.0)));
    
  shapes.shapeParams.add(shapes.numberOfShapes.set("# Shapes", 50, 0, 100));
  gui.add(shapes.shapeParams);

  
  fbo.allocate(640, 360);
  fbo.begin();
  ofClear(255);
  shader.allocate(fbo.getWidth(), fbo.getHeight());
  shader.load("color.frag");
  fbo.end();
}

//--------------------------------------------------------------
void settingWindow::update(){
  fbo.begin();
  //update shapes
  shapes.update();
  shader.setUniform3f("u_color", uiColor->x, uiColor->y, uiColor->z);
  fbo.end();
  
  fbo.begin();
  shader.render();
//  shader.draw(0, 0);
    shader.draw(0, 0, ofGetWidth(), ofGetHeight());
  fbo.end();
}

//--------------------------------------------------------------
void settingWindow::draw(){
    fbo.draw(0, 0);
    //draw shapes
    camera.begin();
    shapes.draw();
    camera.end();
    
    if (bHide){
      gui.draw();
    }
    
}

//--------------------------------------------------------------
void settingWindow::keyPressed(int key){
  if (key == 'h'){
    bHide = !bHide;
  }
}

//--------------------------------------------------------------
void settingWindow::windowResized(int w, int h){
  shader.allocate(w, h);
  fbo.allocate(w, h);
}
