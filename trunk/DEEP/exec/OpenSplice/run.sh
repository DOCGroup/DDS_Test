DEF_NOF_REFLECTORS=1
if [ -n "$1" ]
then
  NOF_REFLECTORS=$1
else
  NOF_REFLECTORS=$DEF_NOF_REFLECTORS
fi

ospl start

./deepParticipant ../scenario16384.xml SinkParticipant 80 &
for ((refl=1; refl <= NOF_REFLECTORS ; refl++))
do
    ./deepParticipant ../scenario16384.xml ReflectorParticipant 60 &
done
./deepParticipant ../scenario16384.xml SourceParticipant 40

sleep 50

ospl -a
