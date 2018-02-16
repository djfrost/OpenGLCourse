#include <iostream>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const GLint Width = 800, Height = 600;

int main() {
	glfwInit();

	//Set version to 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Set GLFW to use newest opengl profile instead of compatability mode
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Set forward compatability to true
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//Allow window to be resized
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	//Create a window 
	GLFWwindow *window = glfwCreateWindow(Width, Height, "OpenGL Learning", nullptr, nullptr);

	int screenWidth, screenHeight;

	//Get actual width and height relative to the actual screen
	//Size can vary on high density screens etc.
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	//Check if window was created successfully
	if (nullptr == window) {
		//Window was not created successfully terminate and cleanup
		std::cout << "Failed to create GLFW window. " << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}

	//Assign GLFW context to current window
	glfwMakeContextCurrent(window);

	//Use modern approach new model of pointer retrieval etc.
	glewExperimental = GL_TRUE;

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to intialize GLEW." << std::endl;
		return EXIT_FAILURE;
	}

	//Set the viewport to the window relative to screen.
	glViewport(0, 0, screenWidth, screenHeight);

	//While window is open and not closing
	while (!glfwWindowShouldClose(window)) {
		//See if any events have occured such as input
		glfwPollEvents();

		//Clears color buffers and sets them to the specified value (if nothing rendered in that coordinate this is used.
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		//Clear the color buffer
		glClear(GL_COLOR_BUFFER_BIT);

		//Draw opengl stuff

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return EXIT_SUCCESS;
}