#include "ofApp.h"

// 일반 함수
void buildMesh(ofMesh& mesh, float w, float h, glm::vec3 pos) {
	float verts[] = {
		-w + pos.x, -h + pos.y, pos.z, // left bottom
		-w + pos.x, +h + pos.y, pos.z, // left top
		+w + pos.x, +h + pos.y, pos.z, // right top
		+w + pos.x, -h + pos.y, pos.z // right bottom
	};
	float uvs[] = {
		0, 0, // left bottom
		0, 1, // left top
		1, 1, // right top
		1, 0 // right bottom
	};

	for (int i = 0; i < 4; i++) {
		int verIdx = i * 3;
		int uvIdx = i * 2;
		mesh.addVertex(glm::vec3(verts[verIdx], verts[verIdx + 1], verts[verIdx + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIdx], uvs[uvIdx + 1]));
	}

	ofIndexType indices[6] = { 0, 1, 2, 2, 3, 0 };
	mesh.addIndices(indices, 6);
}

// 멤버 함수
//--------------------------------------------------------------
void ofApp::setup() {
	ofDisableArbTex(); // legacy - pixel 좌표 사용 기능 off / uv 좌표 사용 기능 on

	buildMesh(charMesh, 0.25, 0.5, glm::vec3(0, 0.15, 0)); // ndc는 -1.0 ~ +1.0

	backgournd.load("forest.png");
	alienImg.load("alien.png");

	charShader.load("alien.vert", "alien.frag");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	charShader.begin();

	charShader.setUniformTexture("alien", alienImg, 0);
	charMesh.draw();

	charShader.end();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
