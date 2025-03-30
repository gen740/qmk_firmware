#!bash

# qmk generate-compilation-database -kb crkbd/rev4_1/standard -km gen740

# flash
if [ "$1" = "flash" ]; then
    echo "Flashing..."
    python3 ./generator/format.py --format ./dvorak.txt
    python3 ./generator/format.py --format ./naginata.txt
    python3 ./generator/code_generator.py dvorak
    python3 ./generator/code_generator.py naginata
    qmk flash -kb crkbd/rev4_1/standard -km gen740
    exit
# compile
elif [ "$1" = "compile" ]; then
    echo "Compiling..."
    python3 ./generator/format.py --format ./dvorak.txt
    python3 ./generator/format.py --format ./naginata.txt
    python3 ./generator/code_generator.py dvorak
    python3 ./generator/code_generator.py naginata
    qmk compile -kb crkbd/rev4_1/standard -km gen740
    exit
# error
else
    echo "Invalid argument"
    exit
fi
