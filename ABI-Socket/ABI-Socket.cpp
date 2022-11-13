#include <iostream>
#include "ServerSocket.hpp"
// #include <Ws2tcpip.h> 

using namespace std;

#define SERVERPORT 5586
#define SERVERIP "127.0.0.1"

int server();
int client();

int main()
{
	int typ;

	cout << endl << " Server\t-->[1]"
		<< endl << " Client\t-->[2]"
		<< endl << endl << "Bitte auswaehlen --> ";

	cin >> typ;

	if (typ == 1) server();
	if (typ == 2) client();

	return 0;
}

int server()
{
	system("cls");
	system("color 9F");
	system("mode 50,30");

	ServerSocket srv_sock(SERVERPORT); // 1) ServerSocket() - erzeugt einen Server-Socket UND bind() UND listen()

	// Vorbereiten des zu übertragenden Textes
	string textString = "Hallo";
	char   textChar[] = "Hallo";
	int	   zahl = 65;

	//Schleife für Anfragen
	int i = 3;
	while (i > 0)
	{
		//Verbindung annehmen
		cout << "Warten auf die " << 4 - i << ". Verbindungsanfrage... " << endl;
		Socket* work_sock = srv_sock.accept(); // 2) accept() - Rückgabe ist ein Zeiger! Siehe Methode.
		cout << "Verbindung akzeptiert... " << endl;

		//Senden des Begrüßungstextes
		//work_sock->write(textString); // string
	    work_sock->write(textChar, 6); // char Feld
		//work_sock->write(zahl); // int Feld
		cout << "---------------------------------------" << endl;

		//Schließen des Arbeitssockets
		work_sock->close(); // 4) close() - Arbeitssocket schließen 
		i--;
	}

	//Schließen des Serversockets;
	srv_sock.close(); //5) cloe() - Serversocket schließen
	return 0;
}

int client()
{
	system("cls");
	system("color 4B");

	Socket client_sock(SERVERIP, SERVERPORT); // 1) Socket() - erzeugt einen Arbeitssocket

	cout << "Warte auf Serververbindung" << endl;
	while (client_sock.connect() == 0)	// 2) connect() - stellt eine Verbi9ndung zum Server her
	{
		cout << ".";    // Lebenszeichen ausgeben
		Sleep(500);   // 500ms warten
	}

	// Server gefunden
	cout << "\nVerbunden mit dem Server" << endl;

	// Nachricht abholen und ausgeben

	// String
	//string textString = client_sock.readLine(); 
	//cout << "String erhalten -> " << textString << endl;

	// Char Feld
	char textChar[6] = { 0 };
	cout << "Anzahl gelesener Zeichen: " << client_sock.read(textChar, 6); // char Feld
	cout << "Char-Feld erhalten -> " << textChar << endl;
	
	// int
	//int zahl = client_sock.read(); 
	//cout << "int erhalten -> " << zahl << endl;
	//cout << "als char interpretiert -> " << static_cast<char>(zahl) << endl;

	client_sock.close(); // 4) close() - Arbeitssocket

	system("Pause");
	return 0;
}