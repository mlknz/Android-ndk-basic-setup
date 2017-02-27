attribute vec2 position; // [0, 1]
attribute vec2 uv;

uniform vec2 pos;
uniform float radius;
uniform float aspectRatio;

varying vec2 vUv;

void main() {
    vec2 scrPos = (position - 0.5) * vec2(radius, radius * aspectRatio) + pos;
    gl_Position = vec4(scrPos, 0., 1.);
    vUv = uv;
}
