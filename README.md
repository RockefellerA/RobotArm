A functional and mostly finished robot-arm coded with OpenGL/Glut.

The screen has been separated into four different camera angles.

Keyboard input moves individual fingers and joints.

Fingers: (Holding shift moves it back to its start position)

Thumb - F/f

Pointer - P/p

Middle - M/m

Ring - R/r

Pinky - T/t

Shoulder - S/s

Elbow - E/e

Hand - H/h

Creepy hand-grab motion - C/c


To compile:

In Mac OS, if you have an nVidia GPU, compile with the following:

g++ RobotArm.cpp -o robotarm -framework GLUT -I/System/Library/Frameworks/OpenGL.framework/Headers -framework OpenGLe

In Linux, compile with the provided makefile or the following:

g++ RobotArm.cpp -o robotarm -lGL -lglut -lGLU

NOTE: If you have never coded in OpenGL before, you will need to run:

sudo apt-get install freeglut3 freeglut3-dev

sudo apt-get install binutils-gold

Thanks and enjoy!
