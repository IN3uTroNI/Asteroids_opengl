//------- Ignore this ----------
#include<filesystem>

#include "Particles.h"
#include "Spawner.h"


namespace fs = std::filesystem;
//------------------------------

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<stb/stb_image.h>

#include"shaderClass.h"
#include"Cube.h"
#include"Colors.h"
#include"Circle.h"
#include"Timer.h"

int main()
{
	glfwInitHint(GLFW_PLATFORM, GLFW_PLATFORM_X11);
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 1000 by 1000 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(1000, 1000, "ITWorks", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 1000, y = 1000
	glViewport(0, 0, 1000, 1000);

	// Generates Shader object using shaders default.vert and default.frag
	shader shaderProgram("src/default.vert", "src/default.frag");

	// Gets ID of uniform called "scale"
	GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");


	// Create square
	GLfloat cubeLocation[] = {
		0.0f, -0.58f
	};
	GLfloat spawnerLocation[] = {
		0.0f, 0.7f
	};


	int score_ = 0;
	Timer score(score_, 0.65f, 0.75f, 0.5f, colors::white);
	Spawner spawner(spawnerLocation);

	Cube cube(cubeLocation, 0.1f, 0.05f, colors::white, spawner, score_);



	// Bind, Link and Unbind the VAO, VBO, EBO to initialize the squares
	cube.cubeInit();
	spawner.spawnerInit();
	score.timerInit();


	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.102f, 0.102f, 0.180f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
		shaderProgram.Activate();
		// Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
		glUniform1f(uniID, 0.5f);
		// movement
		cube.Input(window);
		spawner.spawnerMovement();
		// Draw the objects
		cube.drawCube();
		spawner.spawnerDraw();


		score.timerUpdate(cube.getScore());

		score.timerDraw();


		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();

		// Break the loop if the score gets to 99
		if (cube.getScore() == 100) {
			break;
		}
		if (!spawner.getAlive()) {
			break;
		}
	}

	// Delete the objects
	cube.cubeDelete();
	spawner.spawnerDelete();
	score.timerDelete();



	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}