
#include <stdio.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

const char *description;

#define PRINT_GLFW_ERROR\
    glfwGetError(&description);\
    perror(description);

int main()
{ 
    int     width       = 800;
    int     height      = 600;
    float   offset_x    = 0.0f;
    float   offset_y    = 0.0f;

    if (glfwInit() != GLFW_TRUE)
    {
        PRINT_GLFW_ERROR;
        return 1;
    }
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "gl test", NULL, NULL);
    if (!window)
    {
        PRINT_GLFW_ERROR;
        return 2;
    }

    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);

    if (glewInit() != GLEW_OK)
        return 3;
    
    while(true)
    {
        if (glfwWindowShouldClose(window))
            break;

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);
            glVertex2f((0.0f + offset_x) * ((float)height / width), (0.0f + offset_y));
            glVertex2f((0.25f + offset_x) * ((float)height / width), (0.45f + offset_y));
            glVertex2f((0.5f + offset_x) * ((float)height / width), (0.0f + offset_y));
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_RIGHT))
            offset_x += 0.01f;
        
        if (glfwGetKey(window, GLFW_KEY_LEFT))
            offset_x -= 0.01f;
        
        if (glfwGetKey(window, GLFW_KEY_UP))
            offset_y += 0.01f;
        
        if (glfwGetKey(window, GLFW_KEY_DOWN))
            offset_y -= 0.01f;
    }

    glfwTerminate();

    return 0;
}
