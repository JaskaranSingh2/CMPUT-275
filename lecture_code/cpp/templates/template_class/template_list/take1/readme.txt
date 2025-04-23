This code doesn't link, because the template code to generate
the methods of list is in list.cc

However, within list.cc we never instantiate a template of List with any types.
The compiler only generates code for the types it sees instantiated.

As such, the compiler doesn't generate any versions of these functions
since in list.cc we never actually instantiate a list.

In main.cc where we do instantiate a list with ints, the compiler doesn't
have access to the code because the header only includes the declarations.

So, the compiler at that point /can't/ generate the code for a List<int> and
when we end up linking we can't find the methods for List<int> becuase
they were never generated.

So how to fix this? The ADT implementation file has the implementation details
needed to implement the type. However, the client code is the one who knows
for which types it will ask the compiler to generate those types...

In order for our template type to work for any types the client wants
(that meet our requirements) the client /must/ have access to the implementation
so that the compiler can generate the necessary versions when compiling
the client code.

As such, when it comes to templates, we must put our implementation in the
header file :(
