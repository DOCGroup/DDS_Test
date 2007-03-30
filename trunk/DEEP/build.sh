rm obj/*
(cd settingsParser/impl
sh build.sh SettingsParserXerces_impl
sh build.sh SettingsParserXercesNode_impl)
(cd scenario/impl
sh build.sh ActorSetting_impl
sh build.sh NamedSetting_impl
sh build.sh ParticipantSetting_impl
sh build.sh ReaderSetting_impl
sh build.sh ReflectorSetting_impl
sh build.sh ScenarioSetting_impl
sh build.sh SinkSetting_impl
sh build.sh SourceSetting_impl
sh build.sh TopicSetting_impl
sh build.sh WriterSetting_impl)
(cd actors/impl
sh build.sh Actor_impl
sh build.sh Reflector_impl
sh build.sh Sink_impl
sh build.sh Source_impl)
(cd readerWriter/impl
sh build.sh ReaderWriterFactory_impl
sh build.sh TypedFunctions)
(cd readerWriter/generated
sh build.sh deepTypes
sh build.sh deepTypesDcps
sh build.sh deepTypesDcps_impl
sh build.sh deepTypesSplDcps)
(cd main
sh build.sh deepParticipant)


