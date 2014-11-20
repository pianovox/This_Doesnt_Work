#include "ofApp.h"





//--------------------------------------------------------------
void ofApp::setup(){

    myImage.loadImage("url.jpg");
    myImage.setImageType(OF_IMAGE_GRAYSCALE);
    myImageThreshold.allocate(myImage.getWidth(), myImage.getHeight(),
                              OF_IMAGE_GRAYSCALE);
    pixorig = myImage.getPixels();
    pixthresh = myImageThreshold.getPixels();
    
    
    
    whiteCount  = 0;
    blackCount  = 0;
    avePosWhiteX = 0;
    avePosWhiteY = 0;
    xPosForWhitePix = 0;
    yPosForWhitePix = 0;
    avePosBlackX = 0;
    avePosBlackY = 0;
    xPosForBlackPix = 0;
    yPosForBlackPix = 0;

    
    
    }




//--------------------------------------------------------------
void ofApp::update(){
    
    
    for (int i = 0; i < myImage.getWidth() * myImage.getHeight(); i++){
        
        if (pixorig[i] > mouseY){
            pixthresh[i] = 255;
        } else {
            pixthresh[i] = 0;
        }
        
    }
    
    myImageThreshold.update();
    
    //-------------------------------------------------
    // counting white
    
    
    for (int i = 0; i < myImageThreshold.getWidth() * myImageThreshold.getHeight(); i++){
        
        if (pixthresh[i] == 255){
            whiteCount = whiteCount + 1;
        }
    }
    
    //-------------------------------------------------
    // counting black
    
    
    for (int i = 0; i < myImageThreshold.getWidth() * myImageThreshold.getHeight(); i++){
        
        if (pixthresh[i] == 0){
            blackCount = blackCount + 1;
        }
    }
    
    //-------------------------------------------------
    // find average x/y for WHITE
    

    
    for (int i = 0; i < myImageThreshold.getWidth(); i++){
        for (int j = 0; j < myImageThreshold.getHeight(); j++){
            
            // y * w + x
            // i = x....
            // j = y...
            
            if (pixthresh[ (int)(j * myImageThreshold.getWidth() + i) ] == 255){
                xPosForWhitePix = xPosForWhitePix + i;
                yPosForWhitePix = yPosForWhitePix + j;
            }
        }
    }
    avePosWhiteX = xPosForWhitePix/whiteCount;
    avePosWhiteY = yPosForWhitePix/whiteCount;
    
    
    //-------------------------------------------------
    // find average x/y for BLACK
    
    
    for (int i = 0; i < myImageThreshold.getWidth(); i++){
        for (int j = 0; j < myImageThreshold.getHeight(); j++){
            
            // y * w + x
            // i = x....
            // j = y...
            
            if (pixthresh[ (int)(j * myImageThreshold.getWidth() + i) ] == 255){
                xPosForBlackPix = xPosForBlackPix + i;
                yPosForBlackPix = yPosForBlackPix + j;
            }
        }
    }
    avePosBlackX = xPosForBlackPix/blackCount;
    avePosBlackY = yPosForBlackPix/blackCount;
    
    
    
    //-------------------------------------------------
    // Bounding Box
    
    
    for (int i = 0; i < myImageThreshold.getWidth(); i++){
        for (int j = 0; j < myImageThreshold.getHeight(); j++){
            

            
            if (pixthresh[ (int)(j * myImageThreshold.getWidth() + i) ] == 255){
                xPosForBlackPix = xPosForBlackPix + i;
                yPosForBlackPix = yPosForBlackPix + j;
            }
        }
        
 //       if x width is small set it
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    myImage.draw(0,0);
    myImageThreshold.draw(myImage.getWidth(), 0);
 
    ofSetColor(0, 0, 100, 100);
    ofCircle(avePosWhiteX, avePosWhiteY, 10);
    ofSetColor(100, 0, 0, 100);
    ofCircle(avePosBlackX, avePosBlackY, 10);

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
