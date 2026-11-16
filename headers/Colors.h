//
// Created by neutron on 14.11.2026.
//

#ifndef MYOPENGLPROJECT_COLORS_H
#define MYOPENGLPROJECT_COLORS_H
#include "glad/glad.h"

// Colors to be used in creation
namespace colors {
        // Basics
    inline static GLfloat black[3]   = {0.0f, 0.0f, 0.0f};
    inline static GLfloat white[3]   = {1.0f, 1.0f, 1.0f};
    inline static GLfloat red[3]     = {1.0f, 0.0f, 0.0f};
    inline static GLfloat green[3]   = {0.0f, 1.0f, 0.0f};
    inline static GLfloat blue[3]    = {0.0f, 0.0f, 1.0f};

    // Secondary colors
    inline static GLfloat yellow[3]  = {1.0f, 1.0f, 0.0f};
    inline static GLfloat cyan[3]    = {0.0f, 1.0f, 1.0f};
    inline static GLfloat magenta[3] = {1.0f, 0.0f, 1.0f};

    // Grays
    inline static GLfloat darkGray[3]  = {0.25f, 0.25f, 0.25f};
    inline static GLfloat gray[3]      = {0.5f, 0.5f, 0.5f};
    inline static GLfloat silver[3]    = {0.753f, 0.753f, 0.753f};
    inline static GLfloat lightGray[3] = {0.827f, 0.827f, 0.827f};

    // Reds / pinks
    inline static GLfloat maroon[3]  = {0.5f, 0.0f, 0.0f};
    inline static GLfloat crimson[3] = {0.863f, 0.078f, 0.235f};
    inline static GLfloat salmon[3]  = {0.980f, 0.502f, 0.447f};
    inline static GLfloat coral[3]   = {1.0f, 0.498f, 0.314f};
    inline static GLfloat pink[3]    = {1.0f, 0.753f, 0.796f};
    inline static GLfloat hotPink[3] = {1.0f, 0.412f, 0.706f};

    // Oranges / yellows / browns
    inline static GLfloat orange[3]    = {1.0f, 0.647f, 0.0f};
    inline static GLfloat gold[3]      = {1.0f, 0.843f, 0.0f};
    inline static GLfloat khaki[3]     = {0.941f, 0.902f, 0.549f};
    inline static GLfloat beige[3]     = {0.961f, 0.961f, 0.863f};
    inline static GLfloat brown[3]     = {0.647f, 0.165f, 0.165f};
    inline static GLfloat chocolate[3] = {0.824f, 0.412f, 0.118f};

    // Greens
    inline static GLfloat darkGreen[3]   = {0.0f, 0.392f, 0.0f};
    inline static GLfloat forestGreen[3] = {0.133f, 0.545f, 0.133f};
    inline static GLfloat olive[3]       = {0.5f, 0.5f, 0.0f};
    inline static GLfloat teal[3]        = {0.0f, 0.5f, 0.5f};
    inline static GLfloat turquoise[3]   = {0.251f, 0.878f, 0.816f};

    // Blues / purples
    inline static GLfloat navy[3]     = {0.0f, 0.0f, 0.5f};
    inline static GLfloat skyBlue[3]  = {0.529f, 0.808f, 0.922f};
    inline static GLfloat indigo[3]   = {0.294f, 0.0f, 0.510f};
    inline static GLfloat purple[3]   = {0.5f, 0.0f, 0.5f};
    inline static GLfloat violet[3]   = {0.933f, 0.510f, 0.933f};
    inline static GLfloat lavender[3] = {0.902f, 0.902f, 0.980f};

}

#endif //MYOPENGLPROJECT_COLORS_H
