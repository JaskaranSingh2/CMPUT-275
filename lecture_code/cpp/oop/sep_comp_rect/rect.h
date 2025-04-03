
class Rect {
    int x, y, w, h;
  public:
    // Note, as with any forward declaration of a function
    // parameter names are not /necessary/ however, if this
    // declaration was just
    // Rect(int, int, int, int);
    // The client programmer would not know which order they
    // are supposed to provide the arguments, so giving them
    // names is just a succinct form of documentation
    Rect(int x, int y, int w, int h);
    Rect();
    int area();
};
