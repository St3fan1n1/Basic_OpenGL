# Basic OpenGL 
This repository is to document my personal study on OpenGL.

## Build and Running (command line)

### Building
```shell
cmake -B build
cmake --build build
```

### Running
```shell
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

Finally, we set the current context to the specified window. A context is essentially an environment where OpenGL commands can be executed and OpenGL rendering can take place.

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
Following all the setup, the main loop for the rendering is set in place.
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
The first thing we need to process inside the main loop is the input. In this case, we dont have any input yet.

Next we do the actual rendering. In this code we only have the basic, which is **glClearColor** and **glClear**. **glClearColor** sets the color value that OpenGL uses to reset the colorbuffer. As soon as **glClear** or **glClearBuffer** are called, it uses the value already set to reset the color value. **glClear** clears the entire buffer of the current framebuffer. When specifying the **GL_COLOR_BUFFER_BIT** the buffer is cleared to the color as specified before. Others bits to set are **GL_DEPTH_BUFFER_BIT** and **GL_STENCIL_BUFFER_BIT** clear the depth buffer and the stencil buffer respectively

Then, we need to swap the buffer with **glfwSwapBuffers** and get all the events with **glfwPollEvents**. 

The **glfwPollEvents** function checks if any events are triggered (like keyboard input or mouse movement events), updates the window state and calls the corresponding functions (which can be registered via callback methods).

The **glfwSwapBuffers** function will swap the color buffer (a large 2D buffer that contains color values for each pixel in GLFW's window) that is used to render to during this render iteration and show it as output to the screen. 

> Double buffer
When an application draws in a single buffer the resulting image may display flickering issues. This is because the resulting output image is not drawn in an instant, but drawn pixel by pixel and usually from left to right and top to bottom. Because this image is not displayed at an instant to the user while still being rendered to, the result may contain artifacts. To circumvent these issues, windowing applications apply a double buffer for rendering. The front buffer contains the final output image that is shown at the screen, while all the rendering commands draw to the back buffer. As soon as all the rendering commands are finished we swap the back buffer to the front buffer so the image can be displayed without still being rendered to, removing all the aforementioned artifacts. 

### Cleanup
This section is to delete all allocated resources before closing the application.
```c++
glfwTerminate();
```
The **glfwTerminate** function destroys all remaining windows and frees all remaining resources allocated.