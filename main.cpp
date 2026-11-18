//------- Ignore this ----------
#include<filesystem>



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

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
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

	// All circles have been executed
	// GLfloat circleLocation1[] = { -0.4f, 0.0f };
	// GLfloat circleLocation2[] = { -0.2f, 0.0f };
	// GLfloat circleLocation3[] = { 0.0f, 0.0f };
	// GLfloat circleLocation4[] = { 0.2f, 0.0f };
	// GLfloat circleLocation5[] = { 0.4f, 0.0f };

	Cube cube(cubeLocation, 0.15f, 0.075f, colors::white);

	// Circle circle1(circleLocation1, 0.075f, colors::lightGray, res::LOW_RES, cube);
	// Circle circle2(circleLocation2, 0.075f, colors::lightGray, res::MEDIUM_LOW_RES, cube);
	// Circle circle3(circleLocation3, 0.075f, colors::lightGray, res::MEDIUM_RES, cube);
	// Circle circle4(circleLocation4, 0.075f, colors::lightGray, res::MEDIUM_HIGH_RES, cube);
	// Circle circle5(circleLocation5, 0.075f, colors::lightGray, res::HIGH_RES, cube);

	int score_ = 65;
	Timer score(score_, 0.65f, 0.75f, 0.5f, colors::white);

	// Bind, Link and Unbind the VAO, VBO, EBO to initialize the squares
	cube.cubeInit();

	// circle1.circleInit();
	// circle2.circleInit();
	// circle3.circleInit();
	// circle4.circleInit();
	// circle5.circleInit();

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



		// Draw the square
		cube.drawCube();

		// circle1.circleDraw();
		// circle2.circleDraw();
		// circle3.circleDraw();
		// circle4.circleDraw();
		// circle5.circleDraw();

		score.timerDraw();

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete the square
	cube.cubeDelete();

	// circle1.circleDelete();
	// circle2.circleDelete();
	// circle3.circleDelete();
	// circle4.circleDelete();
	// circle5.circleDelete();

	score.timerDelete();

	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}