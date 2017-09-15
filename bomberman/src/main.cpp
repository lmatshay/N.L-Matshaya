// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <vector>

// Include GLEW
#include "glew.h"

// Include GLFW
#include "glfw3.h"

#include "Wall.hpp"
#include "shader.hpp"
#include "Graphics.hpp"
#include "Window.hpp"
#include "MainMenu.hpp"
#include "Player.hpp"
#include "Floor.hpp" 
#include "Portal.hpp"
#include "StaticWall.hpp"
#include "Destructible.hpp"
#include "loader.hpp"
#include "lu_texture.hpp"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "common/controls.hpp"

GLFWwindow* window;
MainMenu *mainMenu;
Graphics *graphics;
Player *player;
Portal *portal;

//================================================================================================

// camera
glm::vec3 cameraPos   = glm::vec3(-1.0f, 2.0f,  3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  1.0f);

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void timeLogic()
{
    // per-frame time logic
    // --------------------
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

void cameraFunction(GLuint shadersID)
{
    glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    glUniformMatrix4fv(glGetUniformLocation(shadersID, "view"), 1, GL_FALSE, &view[0][0]);
    //return view;
}

void perspectiveView(GLuint shadersID)
{
    
    //create transformations
    glm::mat4 model;
    model = glm::translate(model, glm::vec3(-1.3f,  2.0f, -1.5f));
    float angle = 20.0f * 0;
    model = glm::rotate(model, glm::radians(-30.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    
    //glm::mat4 view;
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(30.0f), (float)WIDTH / (float) HEIGHT, 0.1f, 100.0f);
    glUniformMatrix4fv(glGetUniformLocation(shadersID, "projection"), 1, GL_FALSE, &projection[0][0]);
    
    unsigned int modelLoc = glGetUniformLocation(shadersID, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    float cameraSpeed = 2.5 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_RIGHT)== GLFW_PRESS)
        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}


//=================================================================================================


//move player callback        :Trinity
static void player_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveDown();
	if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveUp();
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveLeft();
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		player->moveRight();
	if (key == GLFW_KEY_SPACE)
	{
		std::cout << "Call the Bomb Class \n";
	}
}

//Key Checking input        :Cradebe
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_UP || key == GLFW_KEY_ENTER) && action == GLFW_PRESS)
	{
		mainMenu->toggleCommands(key);
		if (mainMenu->getInput() == 0 && key == GLFW_KEY_ENTER)
			glfwSetKeyCallback(window, player_callback);
	}
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

//Load player into the map
static void load_object(GLuint texture_programID, GLuint MatrixID, GLuint TextureID, GLuint Texture, GLuint uvbuffer, GLuint vertexbuffer, std::vector<glm::vec3> vertices)
{
	// Use our shader
	glUseProgram(texture_programID);

	// Compute the MVP matrix from keyboard and mouse input
	//computeMatricesFromInputs();
	glm::mat4 ProjectionMatrix = getProjectionMatrix();
	glm::mat4 ViewMatrix = getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);
	glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	// Send our transformation to the currently bound shader, 
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(TextureID, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, vertices.size() );

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

int main(void)
{
	Sound *sound;
	Window myWindow;
	WindowKeyEvents *keyEvents;

	myWindow.runGame();
	sound = myWindow.getSound();
	window = myWindow.getWindow();
	keyEvents = myWindow.getEvents();

	glfwSetKeyCallback(window, key_callback);

	// Initialize GLEW
    //reuben to revisit to create a function
	glewExperimental = true; // Needed for core profile

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Create and compile our GLSL program from the shaders
	//GLuint programID = LoadShaders("SimpleVertexShader.vertexshader", "TextureFragmentShader.hlsl");
    
    //=========================================================================================
    //build and compile our shader program
    GLuint shadersID = LoadShaders("shaderVertexCoordinate.vs", "shaderFragCoordinate.fs");
    glUseProgram(shadersID);
    perspectiveView(shadersID);
    //====================================================================================

	graphics = new Graphics();
	player = new Player();
	portal = new Portal();
	Wall wall;
	StaticWall staticWall;
	Destructible destructible;
    Floor floor;

	graphics->initGlArrays();
	//graphics->initPlayerVertices(&pVBO, &pVAO, &pEBO);
	mainMenu = new MainMenu(window, graphics);
	mainMenu->initMenuImage();
	wall.init();
	staticWall.init();
	destructible.init();
    floor.init();
	portal->init();
	player->init();
	Mix_VolumeMusic(10);
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	GLuint texture_programID = LoadShaders( "BombermanModels/lu_TransformVertexShader.vertexshader", "BombermanModels/lu_TextureFragmentShader.fragmentshader" );
	
		// Get a handle for our "MVP" uniform
		GLuint MatrixID = glGetUniformLocation(texture_programID, "MVP");
	
		// Load the texture
		GLuint Texture = loadDDS("BombermanModels/uvmap.DDS");
		
		// Get a handle for our "myTextureSampler" uniform
		GLuint TextureID  = glGetUniformLocation(texture_programID, "myTextureSampler");
	
		// Read our .obj file
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals; // Won't be used at the moment.
		std::vector<unsigned short> indices;
		bool res = loadOBJ("BombermanModels/loaded_on_the_side.obj", vertices, uvs, normals); 

		GLuint vertexbuffer;
		glGenBuffers(1, &vertexbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
	
		GLuint uvbuffer;
		glGenBuffers(1, &uvbuffer);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
	
///////////////// ////////////////////////////////////////////////////////////////////////////////////////////////////////
	player->init();

	do {
		// Clear the screen
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		keyEvents->keyEventsWrapper(window, sound, graphics);
		switch (graphics->getDrawMode())
		{
			case MAINMENU:
				sound->playMusicForvever(MUSIC_MENU1);
				mainMenu->LoadMainMenuImage();
				break;
			case GAMEPLAY:
				sound->playMusicForvever(MUSIC_BACK);
				// Use our shader
				//glUseProgram(programID);
                //------------------------------
               // processInput(window);
                glUseProgram(shadersID);
                timeLogic();
                cameraFunction(shadersID);
                floor.draw();
                //---------------------------------
				wall.draw();
				staticWall.draw();
				destructible.draw();
				load_object(texture_programID, MatrixID, TextureID, Texture, uvbuffer, vertexbuffer, vertices);
				player->init();
				//graphics->drawElements();
				
				//player transformations
				//player->transform();
				//draw player
				//player->draw();

				//Portal trans and draw
			//	portal->transform();
			//	portal->draw();
			default:
				break;
		}

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Cleanup VBO
	delete graphics;
	delete player;
	delete portal;
	
	mainMenu->menuCleanup();
	//glDeleteProgram(programID);
    glDeleteProgram(shadersID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
