#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main(int argc, char const *argv[])
{
  glfwSetErrorCallback([](int error, const char *description)
                       { std::cerr << "GLFW Error (" << error << "): " << description << std::endl; });

  if (!glfwInit())
  {
    std::cerr << "Failed to init glfw\n";
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "First window", NULL, NULL);

  if (!window)
  {
    std::cerr << "Failed to create window\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "Failed to load GLAD\n";
    return -1;
  }

  glViewport(0, 0, 800, 600);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  float vertices[] = {
      0.5f,
      -0.5f,
      0.0f,
      -0.5f,
      0.5f,
      0.0f,
      0.0f,
      0.5f,
      0.0f,
  };
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  while (!glfwWindowShouldClose(window))
  {
    processInput(window);
    // glClearColor(0.9f, 0.3f, 0.4f, 1.0f);
    // glClear(GL_COLOR_BUFFER_BIT);
    // glClearColor(1.0f, 0.5f, 0.5f, 0.5f);
    // glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
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
