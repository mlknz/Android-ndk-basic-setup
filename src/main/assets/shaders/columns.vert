attribute vec2 position;

uniform float wPosX;
uniform float aspectRatio;

void main() {
    gl_Position = vec4((position - vec2(wPosX, 0.0)), 0., 1.);
}
