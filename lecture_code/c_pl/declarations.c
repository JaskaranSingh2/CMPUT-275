int main() {
  int x; // This is a declaration (and definition) of variable x
  // A declaration is asserting to the compiler that an identifier exists.
  // A definition is asking the compiler to allocate space and create that entity.
  // Declaraing a variable like this is both!

  // When declaring a variable, or defining it (since every definition is also
  // a declaration), you must specify the type of it (because it's statically typed language).
  // When using that variable after the fact you do not have to say so.
  x = 5;
  // NOW x is initialized and can be read from! Best habit to get into though
  // is to initialize your variables at definition so that you never accidentally read
  // an uninitialized variable.
}
