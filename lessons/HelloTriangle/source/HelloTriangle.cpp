#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

const char *vertexShaderSource = "#version 330 core\n"
								 "layout (location=0) in vec3 aPos;\n"
								 "void main()\n"
								 "{\n"
								 "gl_Position = vec4(aPos.x,aPos.y,aPos.z,1);\n"
								 "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
								   "out vec4 FragColor;\n"
								   "coid main()\n"
								   "{\n"
								   "FragColor = vec4(1.0f,0.3f,0.7f,1.0f);\n"
								   "}\0";

int main(int argc, char **argv)
{

	if (!glfwInit())
	{
		std::cerr << "Failed to init glfw\n";
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "Hello Triangle", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cerr << "Failed to initialize window\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to load glad" << std::endl;
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// glDrawArrays(GL_TRIANGLES, 0, 3);
	return 0;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0F, 0.0F, 0.0F, 1.0F);
	}
	else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0F, 1.0F, 0.0F, 1.0F);
	}
	else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0F, 0.0F, 1.0F, 1.0F);
	}
}