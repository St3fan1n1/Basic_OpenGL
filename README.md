# Basic OpenGL 
This repository is to document my personal study on OpenGL.

## Build and Running (command line)

### Building
```
cmake -B build
cmake --build build
```

### Running
```
./build/test
```

## Creating a window
### Initialize GLFW
```c++
glfwInit();
```
This function initializes glfw. It returns **GL_TRUE** if successful, otherwise it returns **GL_FALSE**. 

### Configure GLFW and create Window
```c++
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

GLFWwindow* window;
window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
glfwMakeContextCurrent(window);
```
After initializing the library, we configure GLFW with **glfwWindowHint**. This function sets the hints for the next creation of a window. Some affect the window itself, others affect the framebuffer or the context.

Next we need to create the window object. For this we call the **glfwCreateWindow** function.
The parameters of glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) are as follow:
- **width**: desired width, in screen coordinates, of the window
- **height**: desired height, in screen coordinates, of the window
- **title**: Initial window title
- **monitor**: The monitor to use fullscreen, or NULL for windowed mode
- **share**: The window whose context to share resources with, or NULL to not share resources

Finally, we set the current context to the specified window. A context is essentialy an enviroment where OpenGL commands can be executed and OpenGL rendering can take place.

### Initializing GLEW
```c++
GLenum err = glewInit();
```
GLEW is a library that enables you to access and use of OpenGL extension and functions that might not be part of the core OpenGL specification.

### Size of rendering window
We have to tell OpenGL the size of the rendering window so that it knows how we want to display the data and coordinates with respect to the window.
```c++
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
```
The function **glViwport** specifies the actual window rectangle for your rendering. The function requires 4 parameters for the left, bottom, right and top coordinates of the rectangle viewport.

The parameters for glViewport(GLint x, GLint y, GLsizei width, GLsizei height) are as follow:
- **x**: The left coordinates for the rectangle
- **y**: The bottom coordinates for the rectangle
- **width**: The width or right coordinates of the rectangle
- **height**: The height or top coordinates of the rectangle

> Note that the y coordinates start at the bottom of the viewport. If y = 0, its at the bottom of the viewport.

### Main loop
```c++
while (!glfwWindowShouldClose(window))
    {
        // Input

        // Rendering code
        glClearColor(0.21f, 0.19f, 0.38f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Call events and swap buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
```