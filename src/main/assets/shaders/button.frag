precision highp float;

uniform sampler2D map;

varying vec2 vUv;

// uniform vec3 textColor;

void main()
{    
    // vec4 sampled = vec4(1.0, 1.0, 1.0, texture2D(text, TexCoords).r);
    gl_FragColor = texture2D(map, vUv);
}  
