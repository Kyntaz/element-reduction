if (!(Test-Path -Path ./build)) {
    mkdir ./build;
}
echo "Compiling main.exe";
gcc ./src/main.c -o ./build/main.exe;
echo "Done.";
