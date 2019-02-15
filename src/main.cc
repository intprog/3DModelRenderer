#include <GL/glut.h>
#include <math.h>
#include "gtest/gtest.h"
 
void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    // glBegin(GL_POLYGON);
    //     glVertex3f(0.5, 0.0, 0.5);
    //     glVertex3f(0.5, 0.0, 0.0);
    //     glVertex3f(0.0, 0.5, 0.0);
    //     glVertex3f(0.0, 0.0, 0.5);
    // glEnd();
    glBegin(GL_LINES);
        glVertex3f(-0.5, 0.0, 0.0);
        glVertex3f(0.5, 0.5, 0.0 );
    glEnd();
    glColor3b(20, 50, 0);
    glBegin(GL_LINES);
        glVertex3f(-0.5, 0.0, 0.0);
        glVertex3f(0.5, -0.5, 0.0 );
    glEnd();

    glFlush();
}
 
 
double squareRoot(const double a) {
    double b = sqrt(a);
    if(b != b) { // nan check
        return -1.0;
    }else{
        return sqrt(a);
    }
}

TEST(SquareRootTest, PositiveNos) { 
    ASSERT_EQ(6, squareRoot(36.0));
    ASSERT_EQ(18.0, squareRoot(324.0));
    ASSERT_EQ(25.4, squareRoot(645.16));
    ASSERT_EQ(0, squareRoot(0.0));
    EXPECT_EQ (5, squareRoot(26.0));
}
 
TEST(DISABLE_SquareRootTest, NegativeNos) {
    ASSERT_EQ(-1.0, squareRoot(-15.0));
    ASSERT_EQ(-1.0, squareRoot(-0.2));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// int main(int argc, char** argv)
// {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE);
//     glutInitWindowSize(400, 300);
//     glutInitWindowPosition(100, 100);
//     glutCreateWindow("Hello world!");
//     glutDisplayFunc(displayMe);
//     glutMainLoop();
//     return 0;
// }
