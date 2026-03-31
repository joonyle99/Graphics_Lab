#version 410

layout (location = 0) in vec3 pos;
layout (location = 3) in vec2 uv;

out vec2 fragUV;

void main(){
	// GLSL의 내장 변수, 정점의 최종 위치를 지정
    gl_Position = vec4(pos, 1.0); // 4차원 좌표 (동차좌표)
    fragUV = vec2(uv.x, 1.0 - uv.y);
}
