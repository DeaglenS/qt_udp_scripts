TEMPLATE = subdirs

SUBDIRS += \
    core \
    network \
    ScriptEditor \
    ScriptRunner

ScriptEditor.depends = core network
ScriptRunner.depends = core network

