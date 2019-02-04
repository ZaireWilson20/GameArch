# Homework2 - Math Library
Second homework for Game Architecture.

Due: Monday 2/4/19, 11:59pm

In this homework you will implement parts of vector and matrix math library. 
See src/engine/math/ga_vec3f.h and src/engine/math/ga_mat4f.cpp.

To determine if your implementation is functionally correct, the engine runs
some simple unit tests. See src/engine/math/ga_vec3f.tests.cpp and
src/engine/math/ga_mat4f.tests.cpp.

For this homework you must correctly implement the stubbed out methods
in ga_vec3f and ga_mat4f (search for "TODO: Homework 2") and all unit tests
must pass.

This repo is meant to be built stand-alone, with just the math code. If you wish
to incorporate the rest of the engine, you'll need to update CMakeLists.txt

Run build\setup_win64.bat, then in the newly-created folder, open gamearch2.sln
in Visual Studio. Build the project, and set "ga" to be your startup project,
as before. 

For 10% Extra Credit, implement in 2D one sprite with translational and rotational movement, 
and a player-controlled sprite with translational and rotational movement, such as up arrow=forward, left/right arrow=+/- rotation,
both using your vector and math library.
You do not need to draw the sprites rotated, but use your vec3f and mat4f classes to represent their positions, orientations, and movements.
(Recall that movement in 2 dimensions is a special case of movement in 3 dimensions)

To submit this assignment:

1. clone your working repository from Submitty:

git clone https://submitty.cs.rpi.edu/git/s19/cogs4550/hw2/{username}

2. this will clone a bare empty directory from the submitty server to your local machine. 
3. add the sample code from this repository into your working repo
4. commit and push to upload your work back to the submitty git server.  You only need to add the source files you have changed (.cpp and .h), you do not need to add build files.
