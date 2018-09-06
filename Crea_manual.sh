#!/bin/bash

pandoc --latex-engine=xelatex   -V papersize:a4paper    --template=./LaTeX_ES.latex    -o "Tema 1 - Introducción a Arduino.pdf"     Cabecera.md        "Tema 1 - Introducción a Arduino.md"
pandoc --latex-engine=xelatex   -V papersize:a4paper    --template=./LaTeX_ES.latex    -o "Tema 2 - Hardware de  Arduino.pdf"     Cabecera.md        "Tema 2 - Hardware de  Arduino.md"

pandoc --latex-engine=xelatex \
      --from=markdown \
      -V papersize:a4paper \
      --template=./LaTeX_ES.latex \
      -o "Tema 3 - Programación de  Arduino.pdf" \
       Cabecera.md     \
      "Tema 3 - Programación de  Arduino.md"


pandoc --latex-engine=xelatex        -V papersize:a4paper       --template=./LaTeX_ES.latex       -o "Tema 4 - Controlando el mundo físico con Arduino.pdf"       Cabecera.md           "Tema 4 - Controlando el mundo físico con Arduino.md"
