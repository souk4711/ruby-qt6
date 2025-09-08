RSpec.describe RubyQt6::QtGui do
  Dir.glob("ext/**/*.cpp").each do |f|
    contents = File.read(f)
    matched = contents.match(/define_constructor\(Constructor<(\w+)/)
    next unless matched

    klass = matched[1]
    it "redefine #initialize for #{klass}" do
      contents = File.read("lib/qt6/qtgui/#{klass.downcase}.rb")
      expect(contents.match("alias_method :_initialize, :initialize")).not_to be_nil
      expect(contents.match("def initialize")).not_to be_nil
    end
  end
end
