rm -rf /obj/*
(cd settingsParser/impl
sh build.sh OpenSplice SettingsParserXerces_impl
sh build.sh OpenSplice SettingsParserXercesNode_impl)
(cd scenario/impl
sh build.sh OpenSplice ActorSetting_impl
sh build.sh OpenSplice NamedSetting_impl
sh build.sh OpenSplice ParticipantSetting_impl
sh build.sh OpenSplice ReaderSetting_impl
sh build.sh OpenSplice ReflectorSetting_impl
sh build.sh OpenSplice ScenarioSetting_impl
sh build.sh OpenSplice SinkSetting_impl
sh build.sh OpenSplice SourceSetting_impl
sh build.sh OpenSplice TopicSetting_impl
sh build.sh OpenSplice WriterSetting_impl)
(cd actors/impl
sh build.sh OpenSplice Actor_impl
sh build.sh OpenSplice Reflector_impl
sh build.sh OpenSplice Sink_impl
sh build.sh OpenSplice Source_impl)
(cd readerWriter/generated/OpenSplice
sh build_TypeSupport.sh
sh build.sh deepTypes
sh build.sh deepTypesDcps
sh build.sh deepTypesDcps_impl
sh build.sh deepTypesSplDcps)
(cd readerWriter/impl
sh build.sh OpenSplice ReaderWriterFactory_impl
sh build.sh OpenSplice TypedFunctions)
(cd main
sh build.sh OpenSplice deepParticipant)


