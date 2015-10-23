#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    /*
	img.loadImage("test.jpg");
	finder.setup("haarcascade_frontalface_default.xml");
	finder.findHaarObjects(img);
    */
    
    //  load image
    //image.loadImage("usagi.png");
    usagi.loadImage("usagi.png");
    
    ofSetWindowShape(640, 480);
    camera.setDeviceID(0);
    camera.initGrabber(640, 480);
    finder.setup("haarcascade_frontalface_default.xml");
    msec = ofGetElapsedTimeMillis();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    //  camera -> image
    image.setFromPixels(camera.getPixels(), 640, 480, OF_IMAGE_COLOR);
    //  face detection
    finder.findHaarObjects(image, 40, 40);
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //  draw image
    ofSetColor(255, 255, 255);
    image.draw(0, 0);
    
    
    int msecNow = ofGetElapsedTimeMillis();
    float fps = 1000.0 / (msecNow - msec);
    msec = msecNow;
    
    //  draw markers
    ofSetColor(255, 255, 255);
    char buf[100];
    sprintf(buf, "%5.2f fps", fps);
    ofDrawBitmapString(buf, 20, 20);
    ofSetLineWidth(3);
    ofNoFill();
    
    for(int i = 0; i < finder.blobs.size(); i++) {
        ofRectangle cur = finder.blobs[i].boundingRect;
        ofRect(cur.x, cur.y, cur.width, cur.height);
        usagi.draw(cur.x-120, cur.y-230,cur.width+230, cur.height+230);
        
        ofDrawBitmapString(ofToString(cur.x), 10, 40);
        ofDrawBitmapString(ofToString(cur.y), 10, 50);

        
    }
    

    
    /*
	img.draw(0, 0);
	ofNoFill();
	for(unsigned int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
		ofRect(cur.x, cur.y, cur.width, cur.height);
	}
     */
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
