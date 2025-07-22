imobiliaria: main.o id.o corretor.o cliente.o imovel.o agendamento.o haversine.o
	g++ -o imobiliaria main.o id.o corretor.o cliente.o imovel.o agendamento.o haversine.o
	rm *.o
	
main.o: main.cpp
	g++ -c main.cpp 

id.o: id.cpp id.h
	g++ -c id.cpp 
	
corretor.o: corretor.cpp corretor.h
	g++ -c corretor.cpp
	
cliente.o: cliente.cpp cliente.h
	g++ -c cliente.cpp
	
imovel.o: imovel.cpp imovel.h
	g++ -c imovel.cpp

agendamento.o: agendamento.cpp agendamento.h
	g++ -c agendamento.cpp 
	
haversine.o: haversine.cpp haversine.h
	g++ -c haversine.cpp

clean:
	rm *.o imobiliaria