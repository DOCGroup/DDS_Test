DEF_NOF_REFLECTORS=1
if [ -n "$1" ]
then
  NOF_REFLECTORS=$1
else
  NOF_REFLECTORS=$DEF_NOF_REFLECTORS
fi

ospl start

./deepParticipant ../scenario4.xml SinkParticipant 80 &
./deepParticipant ../scenario4.xml SinkParticipant 82 &
for ((refl=1; refl <= NOF_REFLECTORS ; refl++))
do
    ./deepParticipant ../scenario4.xml ReflectorParticipant 60 &
done
./deepParticipant ../scenario4.xml SourceParticipant 40

ospl -a
