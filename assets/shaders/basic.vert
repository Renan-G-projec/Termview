// Ad Maiorem Dei Gloriam!
#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNorm;
layout (location = 2) in vec2 aUV;

uniform mat4 u_MVP;

out vec3 position;

void main() {
    gl_Position = u_MVP * vec4(aPos, 1.0);
    position = vec3(gl_Position.x, gl_Position.y, gl_Position.z);
}
