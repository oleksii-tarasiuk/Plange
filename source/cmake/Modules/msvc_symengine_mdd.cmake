file(GLOB_RECURSE VCXPROJ_FILES "${PLC_SYMENGINE_BINARY_DIR}/*.vcxproj")
foreach(VCXPROJ_FILE ${VCXPROJ_FILES})
	file(READ "${VCXPROJ_FILE}" VCXPROJ_CONTENTS)
	string(REPLACE "<RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary>" "<RuntimeLibrary>MultiThreadedDebugDLL</RuntimeLibrary>" VCXPROJ_CONTENTS "${VCXPROJ_CONTENTS}")
	file(WRITE "${VCXPROJ_FILE}" "${VCXPROJ_CONTENTS}")
endforeach(VCXPROJ_FILE)