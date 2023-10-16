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
```
After initializing the library, we configure GLFW with **glfwWindowHint**. This function sets the hints for the next creation of a window. Some affect the window itself, others affect the framebuffer or the context.

Next we need to create the window object. For this we call the **glfwCreateWindow** function.
The parameters of glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share) are as follow:
- **width**: desired width, in screen coordinates, of the window
- **height**: desired height, in screen coordinates, of the window
- **title**: Initial window title
- **monitor**: The monitor to use fullscreen, or NULL for windowed mode
- **share**: The window whose context to share resources with, or NULL to not share resources