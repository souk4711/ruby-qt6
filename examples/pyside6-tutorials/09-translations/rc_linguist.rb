require "qt6/all"

# $ lrelease example_de.ts
# $ rcc linguist.qrc -binary -o linguist.qrc.rcc
QResource.register_resource(File.join(__dir__, "linguist.qrc.rcc"))
