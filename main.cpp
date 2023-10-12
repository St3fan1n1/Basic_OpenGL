#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>

int main()
{
    // Initiate GLFW
    if (!glfwInit())
    {
        return -1;
    }

    // Setup and create window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window;
    window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initiate GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
        glfwTerminate();
        return -1;
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    // Cleanup
    glfwTerminate();

    return 0;
}
