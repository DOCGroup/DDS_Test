ospl start file://ospl.xml
./deepParticipant scenario.xml SinkParticipant 80 &
./deepParticipant scenario.xml SourceParticipant 40
sleep 4
ospl stop
