#ifndef CONTROLS_HPP
#define CONTROLS_HPP
// Include GLFW
#include "glfw3.h"
extern GLFWwindow* window; // The "extern" keyword here is to access the variable "window" declared in tutorialXXX.cpp. This is a hack to keep the tutorials simple. Please avoid this.

// Include GLM
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
//using namespace glm;

//#include "controls.hpp"

void computeMatricesFromInputs();
glm::mat4 getViewMatrix();
glm::mat4 getProjectionMatrix();

#endif