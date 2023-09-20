#pragma once
#include <glm/glm.hpp>

struct Uniforms {
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 projection;
    glm::mat4 viewport;
};

// Shader de vértices
Vertex vertexShader(const Vertex& vertex, const Uniforms& uniforms) {
    // Transforma el vértice por las matrices model, view y projection
    glm::vec4 viewSpaceVertex = uniforms.view * uniforms.model * glm::vec4(vertex.position, 1.0f);
    glm::vec4 clipSpaceVertex = uniforms.projection * viewSpaceVertex;

    // Realiza la perspectiva divide
    glm::vec3 ndcVertex = glm::vec3(clipSpaceVertex) / clipSpaceVertex.w;

    // Aplica el transform de viewport
    glm::vec4 screenVertex = uniforms.viewport * glm::vec4(ndcVertex, 1.0f);

    // Calcula la normal transformada (en este ejemplo, no se realiza normalización)
    glm::vec3 transformedNormal = glm::mat3(uniforms.model) * vertex.normal;

    // Devuelve el vértice transformado
    return Vertex{
        glm::vec3(screenVertex),
        transformedNormal
    };
}

// Shader de fragmentos
Fragment fragmentShader(const Fragment& fragment) {
    // Realiza cualquier procesamiento necesario aquí
    // En este ejemplo, simplemente aplicamos la intensidad al color
    Fragment modifiedFragment = fragment;
    modifiedFragment.color = modifiedFragment.color * modifiedFragment.intensity;
    
    return modifiedFragment;
}
