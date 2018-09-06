
all: 1 2 3 4

S1="Tema 1 - Introducción a Arduino.pdf"
F1="Tema 1 - Introducción a Arduino.md"
S2="Tema 2 - Hardware de  Arduino.md"
F2="Tema 2 - Hardware de  Arduino.pdf"
S3="Tema 3 - Programación de  Arduino.md"
F3="Tema 3 - Programación de  Arduino.pdf"
S4="Tema 4 - Controlando el mundo físico con Arduino.md"
F4="Tema 4 - Controlando el mundo físico con Arduino.pdf"

1:
	pandoc --latex-engine=xelatex   \
					-V papersize:a4paper    \
					--template=./LaTeX_ES.latex    \
					-o  $(S1)  \
					Cabecera.md        \
					$(F1)
2:
	pandoc --latex-engine=xelatex   \
					-V papersize:a4paper    \
					--template=./LaTeX_ES.latex    \
					-o $(F2)     \
					Cabecera.md        \
					$(S2)

3:
	pandoc --latex-engine=xelatex \
					--from=markdown \
					-V papersize:a4paper \
					--template=./LaTeX_ES.latex \
		      -o $(F3) \
		       Cabecera.md     \
		      $(S3)
4:
	pandoc --latex-engine=xelatex       \
					-V papersize:a4paper        \
					--template=./LaTeX_ES.latex \
					-o $(F4) \
					Cabecera.md           \
					$(S4)
clean:
	rm $(F1) $(F2) $(F3) $(F4)

cp:
	cp $(F1) $(F2) $(F3) $(F4) ../../domobot17

push:
	git commit -m "update" $(F1);
	git commit -m "update" $(F2);
	git commit -m "update" $(F3);
	git commit -m "update" $(F4);
	git push;
