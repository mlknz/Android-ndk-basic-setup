precision highp float;
varying vec2 vUv;

void main()
{
    if (dot(vUv-0.5, vUv-0.5) > 0.25) discard;
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}
