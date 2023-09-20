#pragma once
#include <glm/glm.hpp>
#include "color.h"

// Representa el resultado del shader de fragmentos
struct FragColor {
    Color color;  // Color del fragmento
    double z;     // Valor de profundidad (en lugar del z-buffer)
};

// La estructura Fragment ahora se usa solo para representar la entrada del shader de fragmentos.
struct Fragment {
    uint16_t x;          // Coordenada x del fragmento
    uint16_t y;          // Coordenada y del fragmento
    double z;
    Color color;
    float intensity;     // Intensidad de la luz del fragmento (si se usa)
};
