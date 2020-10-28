This is the solution to the programming assignment by Laukik Mujumdar
The GUI was constructed using C++ 11, QT 5.9.5 in a Linux Environment (Ubuntu 16.04 LTS)

Please find a detailed map of the modules and functions in docs/annotated.html

To run the GUI, navigate to the GUI directory and run the following in the terminal:
	./trial

If you want to recompile, run the following commands from the GUI directory (make sure QT 5.x is installed)
	qmake
	make


For Q1, my approach was as follows:

Widget Class: This is the main window that pops up after running the GUI.
This class contains functions to capture mouse inputs (motion, as well as press/release). It also has a Grid object that is responsible 
for all the computation, which it relays back to the PaintEvent function of the Widget class. The PaintEvent function does all the display.

The Grid class contains the code to display points. The function 'ColorPoints' is responsible for doing all computation,
once it knows the circle center and radius given to it by its widget.

The 'ColorPoints' function of the Grid class takes the center and radius of the circle as input by moving anticlockwise from the bottom most point of the circle
  The pseudocode is as follows
  1. Calculate the bottom_most point of the circle, given its center and radius.
  2. Calculate the 'next' points depending on the quadrant. (e.g.) if in the 1st quadrant, and moving acw, x has to decrease, and y had to increase)
  3. While(next_points are all not visited){
  4.  best_point=nearest_to_circle(next_points)
  5.  color(best_point)=blue;
  6.  current_point=best_point
  7.}
This always results in a complete solution, because when the acw traversal loops back, it always encounters the bottom point,
where the algorithm started, and recognizes it as being visited, stopping the execution.

For Q2:
I derived a class 'Grid2' publicly from 'Grid'. I added another class Widget2 to record only the double clicks, which were sent to the Grid2 object of the Widget2 class.
Using Widget2, I implemented a toggle functionality on the GUI, with much of the plotting code being the same (inherited the constructor from Grid, thanks to C++11).

Being new to QT, I got stuck in the process of adding a button to the Widget2 class, and I ran out of time.
If I had more time, I would have implemented the method outlined here:https://goodcalculators.com/best-fit-circle-least-squares-calculator/ 
