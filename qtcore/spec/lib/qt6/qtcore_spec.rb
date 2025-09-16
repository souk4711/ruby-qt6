RSpec.describe RubyQt6::QtCore do
  Dir.glob("ext/**/*.cpp").each do |f|
    contents = File.read(f)
    matched = contents.match(/define_constructor\(Constructor<(\w+)/)
    next unless matched

    klass = matched[1]
    next if klass.start_with?("Bando_")
    next if klass == "QMetaObjectBuilder"

    it "redefine #initialize for #{klass}" do
      contents = File.read("lib/qt6/qtcore/#{klass.downcase}.rb")
      expect(contents.match("alias_method :_initialize, :initialize")).not_to be_nil
      expect(contents.match("def initialize")).not_to be_nil
    end
  end
end
