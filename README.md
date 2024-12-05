# 2024-09_RAPL_Accuracy
MSc_GreenComputing_Project

Im zweiten Semester belegte ich das Modul "Green Computing". Als Prüfungsleistung bearbeitete ich das Projekt, dessen Ergebnisse in diesem Repository zu finden sind. Die Forschungsfrage lautet
### Wie kurz kann eine Belastung auf die CPU dauern (t <= 1ms), dass RAPL es erkennt und aufzeichnet?
Das Thema ist RAPL (= Running Average Power Limit Energy Reporting), eine programmgesteuerte Messung des Energieverbrauchs von Intel Prozessoren, und dessen Genauigkeit. Mithilfe von EMA (= Energy Measurement for Applications), welches mir zur Verfügung gestellt wurde, führte ich auf einem externen Rechner (naaice1) eine Messung durch. Es wurde untersucht wie kurz eine CPU-Belastung sein kann, dass RAPL sie erkennt und aufzeichnet. Ab einer Belastungsdauer von t = 0.6ms scheint RAPL recht verlässlich einen Energieverbrauch zu messen. Mit dieser Angabe sollte man dennoch vorsichtig umgehen, denn gerade bei Einzelmessungen sind die RAPL- Werte nicht belastbar. Trotz möglicher Störvariablen sind die Messergebnisse dieses Projekts belastbar.  
Genauere Erklärungen und die Ergebnisse sind im [Bericht](Dokumentation/Bericht.pdf) und in der [Präsentation](Dokumentation/Präsentation.pdf) zu lesen.  
Folgende Dateien sind außerdem im Repository enthalten:  
| Dateiname                                   | Was                                                  |  
|---------------------------------------------|------------------------------------------------------|  
| [Zeitplan](Dokumentation/Zeitplan.pdf)      | Zuvor erstellter Zeitplan des Projekts               |  
| [rapl_measure.c](code/rapl_measure.c)       | Quellcode für Messung                               |  
| [terminal_commands](code/terminal_commands) | Terminal Befehle für Kompillierung und Durchführung  |  
| [main](code/main)                           | main-Datei als Ausgabe der Kompilierung              |  
| [output/Naaice1](output/Naaice1)            | Ordner mit Ausgabe-Dateien von Messung mit naaice1   |  
| [output/ThinkPad](output/ThinkPad)          | Ordner mit Ausgabe-Dateien von Messung mit ThinkPad  | 
