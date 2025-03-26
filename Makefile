OPCIONS = -std=c++11 -DGLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -fno-extended-identifiers

program.exe:  program.o Cjt_estaciones.o Cjt_bicis.o Estacion.o Bici.o
	g++ -o program.exe program.o Cjt_estaciones.o Cjt_bicis.o Estacion.o Bici.o

program.o:  program.cc Cjt_estaciones.hh Cjt_bicis.hh Estacion.hh Bici.hh
	g++ -c program.cc $(OPCIONS)

Cjt_estaciones.o:  Cjt_estaciones.cc Cjt_estaciones.hh Bici.hh Estacion.hh Cjt_bicis.hh
	g++ -c Cjt_estaciones.cc $(OPCIONS)

Bici.o:  Bici.cc Cjt_bicis.hh Bici.hh Estacion.hh Cjt_estaciones.hh
	g++ -c Bici.cc $(OPCIONS)

Estacion.o:  Estacion.cc Cjt_bicis.hh Bici.hh Estacion.hh Cjt_estaciones.hh
	g++ -c Estacion.cc $(OPCIONS)

Cjt_bicis.o:  Cjt_bicis.cc Cjt_bicis.hh Bici.hh Estacion.hh Cjt_estaciones.hh
	g++ -c Cjt_bicis.cc $(OPCIONS)

practica.tar: program.cc Bici.cc Estacion.cc Cjt_estaciones.cc Cjt_bicis.cc Bici.hh Estacion.hh Cjt_estaciones.hh BinTree.hh PRO2Excepcio.hh Cjt_bicis.hh Makefile html.zip justificacion_funciones.pdf
	tar -cvf practica.tar program.cc Bici.cc Estacion.cc Cjt_estaciones.cc Cjt_bicis.cc Bici.hh Estacion.hh Cjt_estaciones.hh BinTree.hh PRO2Excepcio.hh Cjt_bicis.hh Makefile html.zip justificacion_funciones.pdf

clean:
	rm -f *.o
	rm -f *.exe
