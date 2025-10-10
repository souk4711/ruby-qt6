RSpec.describe RubyQt6::QtWidgets do
  describe "Bindings" do
    qmod = OpenStruct.new(name: "QtWidgets")

    Dir.glob("ext/**/bando-q*.cpp").each do |cppfile|
      it cppfile do
        RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod
      end
    end

    Dir.glob("ext/**/q*.cpp").each do |cppfile|
      next if cppfile == "ext/qt6/qtwidgets/qtwidgets-rb.cpp"
      next if cppfile == "ext/qt6/qtwidgets/qtwidgetsversion-rb.cpp"

      it cppfile do
        RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod
      end
    end
  end

  describe "Transfer ownership to callee" do
    [
      ["addLayout", "layout"],
      ["addWidget", "widget"],
      ["addPermanentWidget", "widget"],
      ["addTab", "widget"],
      ["addItem", "item"],
      ["addSpacerItem", "item"],
      ["addTopLevelItem", "item"],
      ["addRow", "field"],
      ["insertLayout", "layout"],
      ["insertWidget", "widget"],
      ["insertPermanentWidget", "widget"],
      ["insertTab", "widget"],
      ["insertItem", "item"],
      ["insertSpacerItem", "item"],
      ["insertRow", "field"],
      ["setLayout", "layout"],
      ["setWidget", "widget"],
      ["setCellWidget", "widget"],
      ["setItemWidget", "widget"],
      ["setHeaderItem", "item"],
      ["setHorizontalHeaderItem", "item"],
      ["setVerticalHeaderItem", "item"],
      ["setItem", "item"],
      ["setItemPrototype", "item"]
    ].each do |fname, argname|
      Dir.glob("ext/**/q*.cpp").each do |cppfile|
        next if cppfile == "ext/qt6/qtwidgets/qcombobox-rb.cpp"
        next if cppfile == "ext/qt6/qtwidgets/qtabbar-rb.cpp"
        next if cppfile == "ext/qt6/qtwidgets/qtablewidget-rb.cpp"
        next if cppfile == "ext/qt6/qtwidgets/qlistwidget-rb.cpp"

        File.read(cppfile).each_line do |line|
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

  describe "Take ownership from callee" do
    [
      "takeAt"
    ].each do |fname|
      Dir.glob("ext/**/q*.cpp").each do |cppfile|
        File.read(cppfile).each_line do |line|
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
