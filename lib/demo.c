// emscripten command:
//   emcc lib/demo.c -s WASM=1 -o public/demo.js
// creates full page that includes the wasm:
//   emcc lib/demo.c -s WASM=1 -o public/demo.html
// just create wasm file:
//   emcc lib/demo.c -s WASM=1 -s SIDE_MODULE=1 -o public/demo.wasm
// set optimization level:
//   emcc lib/demo.c -s WASM=1 -O2 -o public/demo.js
// prepend javascript
//   emcc lib/demo.c -s WASM=1 --post-js public/ready.js -O2 -o public/demo.js

#include <stdio.h>
#include <string.h>

int main() {
    // console log with emscripten
    printf("WASM ready \n");
    return 1;
}

// export functions while compiling:
//   emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNum']" --post-js public/ready.js -O2 -o public/demo.js 
// you can then access it with "_getNum()"
// you can also do ccall('getNum'), this can be good when a string is returned (see #greet)
int getNum() {
    return 22;
}

// emcc lib/demo.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_getNum', '_greet']" --post-js public/ready.js -O2 -o public/demo.js 
// calling _greet() will return the int of the memory location
// but we can use ccall to simplify:
// ccall('greet', 'string')
// ccall is provided by preamble (through emscripten) and provides helpers for passing data
//   back and forth and calling functions
char * greet() {
    return "hello";
}

// ccall can also help us with passing complex arguments (strings etc):
// ccall(function name, return value, argument type, argument value)
// ccall('greetWithArg', 'string', ['string'], ['john'])
// ccall can also be wrapped by a js function to make it more convenient to call (see index.html)
char * greetWithArg( char * name ) {
    char * greeting = "Hello ";
    strcat(greeting, name);
    return greeting;
}