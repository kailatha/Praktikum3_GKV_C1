#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0, wristSide = 0;
// Jari Jempol angle (base, middle joint, tip joint)
static int thumbBase = 0, thumbMiddle = 0, thumbTip = 0;
// Jari Telunjuk angle (base, middle joint, tip joint)
static int indexBase = 0, indexMiddle = 0, indexTip = 0;
// Jari Tengah angle (base, middle joint, tip joint)
static int middleBase = 0, middleMiddle = 0, middleTip = 0;
// Jari Manis angle (base, middle joint, tip joint)
static int ringBase = 0, ringMiddle = 0, ringTip = 0;
// Jari Kelingking (base, middle joint, tip joint)
static int pinkyBase = 0, pinkyMiddle = 0, pinkyTip = 0;


void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

//Untuk membuat jari 
void drawFinger(float length, float width, int baseAngle, int middleAngle, int tipAngle, int isThumb) {
    if (isThumb) {
        // Jari Jempol gerakannya
        glRotatef((GLfloat)baseAngle, 0.0, 0.0, 1.0);
    } else {
        // Jari lain gerakannya
        glRotatef((GLfloat)baseAngle, 0.0, 1.0, 0.0);
    }
    
    // Pangkal Jari
    glPushMatrix();
    glTranslatef(length/6, 0.0, 0.0);
    glScalef(length/3, width, width);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Sendi Tengah
    glTranslatef(length/3, 0.0, 0.0);
    if (isThumb) {
        // Jari Jempol gerakannya
        glRotatef((GLfloat)middleAngle, 0.0, 0.0, 1.0);
    } else {
        // Jari lain gerakannya
        glRotatef((GLfloat)middleAngle, 0.0, 1.0, 0.0);
    }
    
    // Segmen Jari Tengah 
    glPushMatrix();
    glTranslatef(length/6, 0.0, 0.0);
    glScalef(length/3, width*0.9, width*0.9); 
    glutWireCube(1.0);
    glPopMatrix();
    
    // Sendi Ujung
    glTranslatef(length/3, 0.0, 0.0);
    if (isThumb) {
        // Jari Jempol gerakannya
        glRotatef((GLfloat)tipAngle, 0.0, 0.0, 1.0);
    } else {
        // Jari lain gerakannya
        glRotatef((GLfloat)tipAngle, 0.0, 1.0, 0.0);
    }
    
    // Segmen ujung jari
    glPushMatrix();
    glTranslatef(length/6, 0.0, 0.0);
    glScalef(length/3, width*0.8, width*0.8);  // Even smaller for the tip
    glutWireCube(1.0);
    glPopMatrix();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    // Gerakan Bahu
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    // Lengan Atas
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Gerakan siku
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    
    // Lengan bawah
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Pergelangan Tangan
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);     // Atas Bawah
    glRotatef((GLfloat)wristSide, 0.0, 1.0, 0.0); // Pergerakan ke samping
    glTranslatef(0.2, 0.0, 0.0);
    
    // Pergelangan Tangan
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);  
    glutWireCube(1.0);
    glPopMatrix();
    
    // Telapak Tangan
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.7, 0.7, 0.3);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Jari Jempol
    glPushMatrix();
    glTranslatef(-0.05, -0.3, 0.2);
    glRotatef(-30.0, 1.0, 0.0, 0.0);  
    glRotatef(-60.0, 0.0, 0.0, 1.0);  
    drawFinger(0.5, 0.18, thumbBase, thumbMiddle, thumbTip, 1);
    glPopMatrix();
    
    //Jari Kelingking
    glPushMatrix();
    glTranslatef(0.35, 0.27, 0.0);
    drawFinger(0.45, 0.12, pinkyBase, pinkyMiddle, pinkyTip, 0);
    glPopMatrix();
    
    // Jari Manis
    glPushMatrix();
    glTranslatef(0.35, 0.1, 0.0);
    drawFinger(0.6, 0.14, ringBase, ringMiddle, ringTip, 0);
    glPopMatrix();
    
    
    // Jari Tengah
    glPushMatrix();
    glTranslatef(0.35, -0.1, 0.0);
    drawFinger(0.65, 0.15, middleBase, middleMiddle, middleTip, 0);
    glPopMatrix();
    
    // Jari Telunjuk
    glPushMatrix();
    glTranslatef(0.35, -0.3, 0.0);
    drawFinger(0.6, 0.14, indexBase, indexMiddle, indexTip, 0);
    glPopMatrix();
    
    glPopMatrix(); 
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Kontrol Bahu
        case 's':
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        
        // Kontrol Siku
        case 'e':
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        
        // Kontrol Pergelangan Tangan
        case 'w':
            wrist = (wrist + 5) % 360;
            glutPostRedisplay();
            break;
        case 'W':
            wrist = (wrist - 5) % 360;
            glutPostRedisplay();
            break;
            
        // Wrist controls - side to side
        case 'a':
            wristSide = (wristSide + 5) % 360;
            glutPostRedisplay();
            break;
        case 'A':
            wristSide = (wristSide - 5) % 360;
            glutPostRedisplay();
            break;
        
        // Kontrol Jari Jempol
        case '1':  // Jempol base joint
            thumbBase = (thumbBase + 5) % 90;
            glutPostRedisplay();
            break;
        case '!':
            thumbBase = (thumbBase - 5);
            if (thumbBase < 0) thumbBase += 90;
            glutPostRedisplay();
            break;
        case 'q':  // Jempol middle joint
            thumbMiddle = (thumbMiddle + 5) % 90;
            glutPostRedisplay();
            break;
        case 'Q':
            thumbMiddle = (thumbMiddle - 5);
            if (thumbMiddle < 0) thumbMiddle += 90;
            glutPostRedisplay();
            break;
        case 'z':  // Jempol tip joint
            thumbTip = (thumbTip + 5) % 90;
            glutPostRedisplay();
            break;
        case 'Z':
            thumbTip = (thumbTip - 5);
            if (thumbTip < 0) thumbTip += 90;
            glutPostRedisplay();
            break;
        
        // Jari Telunjuk
        case '2':  // Telunjuk base joint
            indexBase = (indexBase + 5) % 90;
            glutPostRedisplay();
            break;
        case '@':
            indexBase = (indexBase - 5);
            if (indexBase < 0) indexBase += 90;
            glutPostRedisplay();
            break;
        case 'i':  // Telunjuk middle joint
            indexMiddle = (indexMiddle + 5) % 90;
            glutPostRedisplay();
            break;
        case 'I':
            indexMiddle = (indexMiddle - 5);
            if (indexMiddle < 0) indexMiddle += 90;
            glutPostRedisplay();
            break;
        case 'x':  // Telunjuk tip joint
            indexTip = (indexTip + 5) % 90;
            glutPostRedisplay();
            break;
        case 'X':
            indexTip = (indexTip - 5);
            if (indexTip < 0) indexTip += 90;
            glutPostRedisplay();
            break;
        
        // Jari Tengah
        case '3':  // Tengah base joint
            middleBase = (middleBase + 5) % 90;
            glutPostRedisplay();
            break;
        case '#':
            middleBase = (middleBase - 5);
            if (middleBase < 0) middleBase += 90;
            glutPostRedisplay();
            break;
        case 'm':  // Tengah middle joint
            middleMiddle = (middleMiddle + 5) % 90;
            glutPostRedisplay();
            break;
        case 'M':
            middleMiddle = (middleMiddle - 5);
            if (middleMiddle < 0) middleMiddle += 90;
            glutPostRedisplay();
            break;
        case 'c':  // Tengah tip joint
            middleTip = (middleTip + 5) % 90;
            glutPostRedisplay();
            break;
        case 'C':
            middleTip = (middleTip - 5);
            if (middleTip < 0) middleTip += 90;
            glutPostRedisplay();
            break;
        
        // Jari Manis
        case '4':  // Manis base joint
            ringBase = (ringBase + 5) % 90;
            glutPostRedisplay();
            break;
        case '$':
            ringBase = (ringBase - 5);
            if (ringBase < 0) ringBase += 90;
            glutPostRedisplay();
            break;
        case 'r':  // Manis middle joint
            ringMiddle = (ringMiddle + 5) % 90;
            glutPostRedisplay();
            break;
        case 'R':
            ringMiddle = (ringMiddle - 5);
            if (ringMiddle < 0) ringMiddle += 90;
            glutPostRedisplay();
            break;
        case 'v':  // Manis tip joint
            ringTip = (ringTip + 5) % 90;
            glutPostRedisplay();
            break;
        case 'V':
            ringTip = (ringTip - 5);
            if (ringTip < 0) ringTip += 90;
            glutPostRedisplay();
            break;
        
        // Jari Kelingking
        case '5':  // Kelingking base joint
            pinkyBase = (pinkyBase + 5) % 90;
            glutPostRedisplay();
            break;
        case '%':
            pinkyBase = (pinkyBase - 5);
            if (pinkyBase < 0) pinkyBase += 90;
            glutPostRedisplay();
            break;
        case 't':  // Kelingking middle joint
            pinkyMiddle = (pinkyMiddle + 5) % 90;
            glutPostRedisplay();
            break;
        case 'T':
            pinkyMiddle = (pinkyMiddle - 5);
            if (pinkyMiddle < 0) pinkyMiddle += 90;
            glutPostRedisplay();
            break;
        case 'b':  // Kelingking tip joint
            pinkyTip = (pinkyTip + 5) % 90;
            glutPostRedisplay();
            break;
        case 'B':
            pinkyTip = (pinkyTip - 5);
            if (pinkyTip < 0) pinkyTip += 90;
            glutPostRedisplay();
            break;
        
        
        case 27:  // ESC key
            exit(0);
            break;
        
        default:
            break;
    }
}

//Fungsi Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
