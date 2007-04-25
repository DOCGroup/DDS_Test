rm -rf /obj/*
(cd settingsParser/impl
sh build.sh RTI SettingsParserXerces_impl
sh build.sh RTI SettingsParserXercesNode_impl)
(cd scenario/impl
sh build.sh RTI ActorSetting_impl
sh build.sh RTI NamedSetting_impl
sh build.sh RTI ParticipantSetting_impl
sh build.sh RTI ReaderSetting_impl
sh build.sh RTI ReflectorSetting_impl
sh build.sh RTI ScenarioSetting_impl
sh build.sh RTI SinkSetting_impl
sh build.sh RTI SourceSetting_impl
sh build.sh RTI TopicSetting_impl
sh build.sh RTI WriterSetting_impl)
(cd actors/impl
sh build.sh RTI Actor_impl
sh build.sh RTI Reflector_impl
sh build.sh RTI Sink_impl
sh build.sh RTI Source_impl)
(cd readerWriter/RTI/generated
sh build_TypeSupport.sh
sh build.sh deepTypes
sh build.sh deepTypesSupport
sh build.sh deepTypesPlugin)
(cd readerWriter/impl
sh build.sh RTI ReaderWriterFactory_impl
sh build.sh RTI TypedFunctions)
(cd main
sh build.sh RTI deepParticipant)
