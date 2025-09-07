all:derle bagla calistir
derle:
		g++ -c -I "./include" ./src/Main.cpp -o ./lib/Main.o
		g++ -c -I "./include" ./src/LinkedList.cpp -o ./lib/LinkedList.o
		g++ -c -I "./include" ./src/ListNode.cpp -o ./lib/ListNode.o
		g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
		g++ -c -I "./include" ./src/Agac.cpp -o ./lib/Agac.o
bagla:
		g++ ./lib/Main.o ./lib/LinkedList.o ./lib/ListNode.o ./lib/Dugum.o ./lib/Agac.o -o ./bin/program
calistir:
		./bin/program