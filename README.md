# ABI-Klasse-Socket (Übersetzt die Java "ServerSocket" und "Socket" Funktionalitäten in C++)
Sockets
Bei der Erstellung der Anwendung zur Kommunikation im Netz kann auf eine existierende Klassen Socket und ServerSocket zurückgegriffen werden, welche die grundlegenden Methoden zur Kommunikation via TCP/IP bereitstellen. (vgl. Klassen-Diagramm).

Kurzbeschreibung der Klasse ServerSocket:<br>
![grafik](https://user-images.githubusercontent.com/78038701/230719931-bbb7cc18-c8b5-4c01-b643-58e04e577679.png)

ServerSocket(localPort: int)<br>	
erzeugt einen Server-Socket, bindet ihn an den angegebenen Port.<br>

accept(): Socket<br>
wartet darauf, dass ein Client eine Verbindung aufbauen will. Die Methode accept() ist "blockierende"; das heißt, accept() blockiert den aufrufenden (Server-)Prozess so lange, bis eine Verbindung vorhanden ist. Eine Schleife ist damit nicht notwendig.
Wurde eine Verbindung aufgebaut, liefert die Methode das entsprechende Socket-Objekt.<br>

close()	<br>	
schließt den Server-Socket.<br>

Kurzbeschreibung der Klasse Socket:<br>
![grafik](https://user-images.githubusercontent.com/78038701/230719992-210346ea-535d-47f3-812c-378ea502acc2.png)

Socket(remoteHostIP: string, remotePort int) 	<br>
erzeugt einen Socket-Objekt.<br>

connect():bool	<br>
stellt eine Verbindet zum RemoteHost  her; liefert true, wenn die eine Verbindung hergestellt werden konnte.<br>
dataAvailable():int	<br>
liefert die Anzahl der Byte, die vom Socket gelesen werden können, ohne beim nächsten Aufruf von read() zu blockieren.<br>
read(): int	<br>
liest ein Byte  (0..255) vom Socket, bzw. liefert –1, wenn der Socket nicht geöffnet ist. Die Methode blockiert, bis ein Byte verfügbar ist.<br>
read(b: char[], len: int)	<br>
liest bis zu len Bytes vom Socket in ein Char-Array ; die Anzahl der tatsächlich gelesenen Bytes wird zurückgeliefert, bzw. –1, wenn der Socket nicht geöffnet ist. Die Methode blockiert, bis mindestens ein Byte verfügbar ist.<br>
readLine(): string	<br>
liest eine Zeile vom Socket, bzw. liefert null, wenn der Socket nicht geöffnet ist. Eine Zeile wird durch ein Zeilenendezeichen abgeschlossen; das Zeilenendezeichen wird jedoch nicht in den zurückgegebenen String übernommen. Die Methode blockiert, bis eine komplette Zeile eingelesen ist.<br>
write(value: int)<br> 	
schreibt ein Byte (0..255) auf den Socket ; ist keine Verbindung hergestellt, geschieht nichts.<br>

