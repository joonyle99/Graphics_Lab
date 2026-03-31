#version 410

uniform sampler2D alien;

in vec2 fragUV;
out vec4 outCol;

void main(){
    outCol = texture(alien, fragUV);
    if (outCol.a < 1.0) discard; // 
}
