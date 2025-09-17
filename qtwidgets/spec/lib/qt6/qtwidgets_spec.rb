RSpec.describe RubyQt6::QtWidgets do
  describe "#initialize" do
    Dir.glob("ext/**/q*.cpp").each do |f|
      File.read(f).each_line do |line|
        matched = line.match(/define_constructor\(Constructor<(\w+)/)
        next unless matched

        klass = matched[1]
        it "redefine #initialize @ #{klass}" do
          contents = File.read("lib/qt6/qtwidgets/#{klass.downcase}.rb")
          expect(contents.match("alias_method :_initialize, :initialize")).not_to be_nil
          expect(contents.match("def initialize")).not_to be_nil
        end
      end
    end
  end

  describe "transfer ownership to callee" do
    [
      ["addItem", "item"],
      ["addLayout", "layout"],
      ["addWidget", "widget"],
      ["addSpacerItem", "item"],
      ["addRow", "field"],
      ["insertItem", "item"],
      ["insertLayout", "layout"],
      ["insertWidget", "widget"],
      ["insertSpacerItem", "item"],
      ["insertRow", "field"],
      ["setLayout", "layout"],
      ["setWidget", "widget"]
    ].each do |fname, argname|
      Dir.glob("ext/**/q*.cpp").each do |f|
        File.read(f).each_line do |line|
          matched = line.match(/&(\w+)::#{fname},(.+)/)
          next unless matched

          klass = matched[1]
          klassfname = "#{klass}##{fname}"
          it "transfer #{argname.rjust(6)}'s ownership to #{klass.ljust(14)} @ #{klassfname}" do
            expect(matched[2]).to include("Arg(\"#{argname}\").takeOwnership()")
          end
        end
      end
    end
  end

  describe "take ownership from callee" do
    [
      "takeAt"
    ].each do |fname|
      Dir.glob("ext/**/q*.cpp").each do |f|
        File.read(f).each_line do |line|
          matched = line.match(/&(\w+)::#{fname},(.+)/)
          next unless matched

          klass = matched[1]
          klassfname = "#{klass}##{fname}"
          it "take item's ownership from #{klass.ljust(14)} @ #{klassfname}" do
            expect(matched[2]).to include("Return().takeOwnership()")
          end
        end
      end
    end
  end
end
