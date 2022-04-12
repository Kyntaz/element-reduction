if (!(Test-Path -Path ./build)) {
    mkdir ./build;
}
echo "Compiling main.exe";
gcc -std=c11 ./src/main.c -o ./build/main.exe;
echo "Done.";
