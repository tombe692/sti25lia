                         kör MOSQUITTO Lokalt
                         
# MQTT SETUP GUIDE - Komplett Guide

## 1. INSTALLATION MOSQUITTO
- Gå till: https://mosquitto.org/download/
- Ladda ner: mosquitto-2.x.x-install-windows-xxx.exe
- Kör installationsfilen som Administrator
- Följ installationsguiden
- Välj "Install as Windows Service" om det finns

## 2. BRANDVÄGGSKONFIGURATION (Görs en gång)
- Öppna Command Prompt som Administrator
- Skriv: wf.msc
- Högerklicka på "Inkommande regler" i vänstermenyn
- Välj "Ny regel..."
- Välj "Port" → Klicka "Nästa"
- Välj "TCP" och "Specifika lokala portar"
- Skriv: 1883
- Klicka "Nästa"
- Välj "Tillåt anslutningen" → Klicka "Nästa"
- Lämna alla tre profiler ikryssade (Domän, Privat, Offentligt)
- Klicka "Nästa"
- Namn: "Mosquitto MQTT"
- Klicka "Slutför"

## 3. HITTA DIN IP-ADRESS
- Öppna Command Prompt
- Skriv: ipconfig
- Leta efter: "IPv4-adress ->: 192.000.0.XXX"
- Skriv ner denna IP-adress

## 4. KONFIGURERA OCH STARTA MOSQUITTO

### Alternativ A: Utan lösenord (enkelt test)
```cmd
echo listener 1883 0.0.0.0 > config.txt
echo allow_anonymous true >> config.txt
mosquitto -c config.txt -v

Alternativ B: Med lösenord (säkrare)
```cmd
echo listener 1883 0.0.0.0 > config.txt
echo allow_anonymous false >> config.txt
mosquitto_passwd -c pwfile fileNamn
echo password_file pwfile >> config.txt
mosquitto -c config.txt -v
Lägg till denna rad i setup() funktionen, EFTER WiFi-anslutning men FÖRE MQTT-anslutning:
cpp
mqttClient.setUsernamePassword("fileNamn", "ditt_lösenord");


i din arduino code:
#define SECRET_BROKER "192.000.0.XXX"  // Ersätt med din IP
#define SECRET_BROKER_PORT 1883
---------------------------------------------------------------
Om du vill testa i terminal oberoende av din kode!
6. TESTA ANSLUTNINGEN
Testa utan lösenord:
cmd
# Terminal 1 - Lyssnare
mosquitto_sub -h 192.XXX.X.XXX -t "test" -v
# Terminal 2 - Sändare
mosquitto_pub -h 192.XXX.X.XXX -t "test" -m "hello"

Testa med lösenord:
cmd
# Terminal 1 - Lyssnare
mosquitto_sub -h 192.XXX.X.XXX -t "test" -u "användarnamn" -P "lösenord" -v

# Terminal 2 - Sändare
mosquitto_pub -h 192.XXX.X.XXX -t "test" -m "hello" -u "användarnamn" -P "lösenord"


VIKTIGA KOMMANDON:
Starta Mosquitto: mosquitto -c config.txt -v
Kolla IP: ipconfig
Stoppa Mosquitto: Ctrl+C

FELSÖKNING:
Fel -2: Mosquitto körs inte → Starta Mosquitto
Fel -1: Fel IP-adress → Kolla med ipconfig
Ingen anslutning: Brandväggen blockerar → Kontrollera brandväggsregeln
"Connection refused": Config filen saknas eller är felaktig

SÄKERHETSINFO:
allow_anonymous true: Låg risk i hemmanätverk, bra för test
allow_anonymous false + lösenord: Rekommenderas för långtidsbruk
Mosquitto körs bara lokalt i ditt nätverk
Ingen direkt åtkomst från internet
