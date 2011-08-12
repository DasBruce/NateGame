#include "stdafx.h"
#include "world.h"

using namespace std;

void Init(void);
void Shut_Down(int return_code);
void Main_Loop(void);
void Draw(void);
//void MouseHandler(int Button, int Press);

float rotate_y = 0,
      rotate_z = 0;
const float rotations_per_tick = .2;

World world;

void MouseHandler(int Button, int Press){
    TwEventMouseButtonGLFW(Button, Press);
    MouseHandler(Button, Press);
}

int main(void)
{
    Init();
    Main_Loop();
    Shut_Down(0);
}

void Init(void)
{
    const int window_width = 1024,
            window_height = 768;

    if (glfwInit() != GL_TRUE)
    Shut_Down(1);
    // 800 x 600, 16 bit color, no depth, alpha or stencil buffers, windowed
    if (glfwOpenWindow(window_width, window_height, 5, 6, 5,
                     0, 0, 0, GLFW_WINDOW) != GL_TRUE)
    Shut_Down(1);
    glfwSetWindowTitle("The GLFW Window");

    // set the projection matrix to a normal frustum with a max depth of 50
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspect_ratio = ((float)window_height) / window_width;
    glFrustum(.5, -.5, -.5 * aspect_ratio, .5 * aspect_ratio, 1, 50);
    glMatrixMode(GL_MODELVIEW);

    TwWindowSize(window_width, window_height);

//	glfwSetMouseButtonCallback(MouseHandler);
}

void Shut_Down(int return_code)
{
    glfwTerminate();
    exit(return_code);
}

void Main_Loop(void)
{
    double speed = 0.3;
    bool wire = false;
    double old_time = glfwGetTime();
        // Initialize AntTweakBar


    while(true)
    {
        // calculate time elapsed, and the amount by which stuff rotates
        double current_time = glfwGetTime();
        double delta_rotate = (current_time - old_time) * rotations_per_tick * 360;
        old_time = current_time;
        // escape to quit, arrow keys to rotate view
        if (glfwGetKey(GLFW_KEY_ESC) == GLFW_PRESS)
            break;
        if (glfwGetKey(GLFW_KEY_LEFT) == GLFW_PRESS)
            rotate_y += delta_rotate;
        if (glfwGetKey(GLFW_KEY_RIGHT) == GLFW_PRESS)
            rotate_y -= delta_rotate;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//        Draw();
        world.Draw();

        glfwSwapBuffers();
    }
}
