#include <windows.h>
#include <GL/glut.h>

// Ângulos de rotação
float bodyAngle = 0.0f;
float headAngle = 0.0f;
float legAngle = 0.0f;

// Função para desenhar o dinossauro
void drawDinosaur()
{
    // Corpo
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    glRotatef(bodyAngle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.5f, 0.0f); // Cor verde
    glutSolidCube(1.0);
    
    // Cabeça
    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.0f);
    glRotatef(headAngle, 0.0f, 0.0f, 1.0f);
    glColor3f(0.5f, 0.0f, 0.0f); // Cor vermelha
    glutSolidCube(0.5);
    glPopMatrix();
    
    // Perna esquerda
    glPushMatrix();
    glTranslatef(-0.3f, -0.5f, 0.0f);
    glRotatef(legAngle, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.5f); // Cor azul
    glutSolidCube(0.3);
    glPopMatrix();
    
    // Perna direita
    glPushMatrix();
    glTranslatef(0.3f, -0.5f, 0.0f);
    glRotatef(-legAngle, 1.0f, 0.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.5f); // Cor azul
    glutSolidCube(0.3);
    glPopMatrix();
    
    glPopMatrix();
}

// Função de desenho
void renderScene()
{
    // Limpa o buffer de cor
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a matriz de projeção ortográfica
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -1, 1);

    // Define a matriz de modelo-visão
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Desenha o dinossauro
    drawDinosaur();

    // Troca os buffers
    glutSwapBuffers();
}

// Função de callback para eventos de teclado
void keyCallback(unsigned char key, int x, int y)
{
    switch (key) {
        case 'a':
            bodyAngle += 5.0f;
            break;
        case 'd':
            bodyAngle -= 5.0f;
            break;
        case 'w':
            headAngle += 5.0f;
            break;
        case 's':
            headAngle -= 5.0f;
            break;
        case 'q':
            legAngle += 5.0f;
            break;
        case 'e':
            legAngle -= 5.0f;
            break;
        case 27: // Tecla Esc
            exit(0);
            break;
    }

    glutPostRedisplay();
}

// Função principal
int main(int argc, char** argv)
{
    // Inicialização do GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Dinossauro OpenGL");

    // Definição das funções de callback
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyCallback);

    // Loop principal do GLUT
    glutMainLoop();

    return 0;
}
