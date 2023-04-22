# a simple c-oop library

## Usage: (see [tests/main.c](tests/main.c))

### create a interface
```
PUBLIC INTERFACE_START(String)
    EXTENDS(Class);
    PUBLIC char * content;
    PUBLIC char *(*getString)(String *);
    PUBLIC void (*setString)(String *, const char *);
INTERFACE_END(String);
```

### create a class
```
PRIVATE CLASS(String, string_ctor, string_dtor);
```

### create an abstract class (continue...)

## Author
- Wavin Don