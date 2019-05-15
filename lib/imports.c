//emcc lib/imports.c -s WASM=1 -o public/imports.js
#include <emscripten.h>
#include <stdio.h>

// Declare a reusable JS function
// return type, function name, arguments, code
EM_JS( void, jsFunction, (int n), {
    console.log("Call from EM_JS" + n);
});

int main() {
    // console log with emscripten
    printf("WASM ready \n");

    // Call JS function (eval)
    emscripten_run_script("console.log('Hello from C!')");

    // Call JS function ASYNC (eval)
    // first argument is code to be evaluated
    //   second is how long to wait to run the script in ms
    emscripten_async_run_script("alert('Hello from C! - ASYNC!')", 2000);

    // Call a js function that returns an int
    int jsVal = emscripten_run_script_int("getNum()");
    printf("Val from getNum(): %d\n", jsVal);

    // Call a js function that returns a string
    char * jsValStr = emscripten_run_script_string("getStr()");
    printf("Val from getStr(): %s\n", jsValStr);

    // execute EM_JS fn 
    jsFunction(144);


    // Note! You want to be careful with these c -> js and JS -> c calls
    // especially strings
    // c is good at handling numbers, not so much strings
    // also passing data and making calls back and forth is costly

    return 1;
}
