#ifndef LU_TEXTURE_HPP
#define LU_TEXTURE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "glew.h"
#include "glfw3.h"

#include "shader.hpp"
#include "../src/common/controls.hpp"
#include "glm.hpp" 
#include "gtc/matrix_transform.hpp" 


// Load a .BMP file using our the loader 
GLuint loadBMP_custom(const char * imagepath);

// Load a .DDS file using GLFW's own loader
GLuint loadDDS(const char * imagepath);


#endif