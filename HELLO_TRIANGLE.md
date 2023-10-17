# Hello Triangle
## OpenGL Pipeline
The main job for OpenGL is to transform all the 3D coordinates to 2D pixels that fit on the screen. This process is made in the OpenGL graphics pipeline. The 3D coordinates passed to the pipeline are transformed into 2D colored pixels. The graphics pipeline can be divided into multiple steps. The processing cores run programs on the GPU for each step of the pipeline. Theses small programs are called ***shaders***.

Below is the abstract representation of the pipeline. The blue sections represent sections where we can inject out own shader programs.

![alt-text](img/pipeline.png "OpenGL Pipeline")

As input to the graphic pipeline we pass a list of three 3D coordinates that should form a triangle. We called this array Vertex Data.

> In order for OpenGL to know what to make of the collection of coordinates and color values, OpenGL requires you to hint the render type. Those hints are called primitive and some of them are **GL_POINT**, **GL_TRIANGLE** and **GL_LINE_STRIP**.

The first part of the pipeline is the **vertex shader**. This shader takes as input a single vertex. This stage handles the processing of individual vertices.

The output of the vertex shader is optionally passed to the **geometry shader**. The geometry shader takes as input a collection of vertices that form a primitive and has the ability to generate other shapes by emitting new vertices to form new primitives.

The **primitive assembly** stage takes all the vertices from the vertex or geometry shader as input and forms a primitive shape.

The output of the primitive assembly stage is passed to the **rasterization stage** where it maps the corresponding .