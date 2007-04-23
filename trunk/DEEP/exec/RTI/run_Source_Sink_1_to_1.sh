export NDDS_DISCOVERY_PEERS=udpv4://blade31.isislab.vanderbilt.edu
./deepParticipant scenario$1.xml SinkParticipant 80 &
./deepParticipant scenario$1.xml SourceParticipant 40
