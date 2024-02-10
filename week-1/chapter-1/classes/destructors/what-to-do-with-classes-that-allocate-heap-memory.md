# If a class allocates memory, it must:

1. Eventually free that memory by implementing a **destructor**.
2. Overload the default, compiler-generated destructor to avoid shallow copies.
3. Overload the default, compiler-generated assignment operator to avoid
   shallow copies.
