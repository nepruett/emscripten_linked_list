/*
    ./emcc
        src/c/hello_world.c
        -o build/js/hello_world.js
        -s EXPORTED_FUNCTIONS="['_hello']"
*/
extern char *hello() {
    return "Hello World!";
}