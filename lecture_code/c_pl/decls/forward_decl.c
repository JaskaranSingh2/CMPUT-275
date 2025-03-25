#include <stdio.h>

// Note, these functions don't even work because they're infinitely recursive,
// That's not the point right now though!

/*
This code cannot compile because grade needs to know about attendance,
AND attendance needs to know about grade. So putting one before the other
means the first one doesn't know about the function it needs to call.

So, how can we let grade (the first function here) know that attendance exists?

We must /declare/ it.
*/

// This is a forward declaration of the function attendance.
// It asserts, at this point, to the compiler that there will
// exist a function named attendance with no parameters that
// returns a float. The compiler takes that promise, and assumes at
// some point it will find the definition for that code (or, someone
// else will - the linker, more on that later).
float attendance();

float grade() {
  // Given attendance [0,1] which represents the
  // percentage of students that attend determine
  // the average grade.
  float attend = attendance();
  float gr = attend + 0.15;
  if (gr > 1.0) gr = 1.0;
  return gr;
}

float attendance() {
  const int CAPACITY = 200;
  float showUp = CAPACITY/2.0;
  float score = grade();
  score = score-0.7;
  // If score is negative, that means its below 0.7, and students
  // will show up more often
  if (score < 0) {
    score = score*-1;
    showUp = CAPACITY*score;
  }
  return showUp;
}


int main() {


}
