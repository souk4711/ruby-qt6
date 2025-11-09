RSpec.describe RubyQt6::RSpec do
  describe ".verify_bando_cppfile" do
    it "ext/qt6/qtcore/bando-qobject-rb.cpp" do
      cppfile = "ext/qt6/qtcore/bando-qobject-rb.cpp"
      qmod = OpenStruct.new(name: "QtCore")
      rs = RubyQt6::RSpec.verify_bando_cppfile cppfile, qmod

      r = rs["QObject"]
      expect(r.bando.name).to eq("QObject")
    end
  end

  describe ".verify_qlass_cppfile" do
    it "ext/qt6/qtcore/qobject-rb.cpp" do
      cppfile = "ext/qt6/qtcore/qobject-rb.cpp"
      qmod = OpenStruct.new(name: "QtCore")
      rs = RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod

      r = rs["QObject"]
      expect(r.verified_initialize).to eq(1)
      expect(r.verified_methods_count).to eq(41)
      expect(r.verified_enums_count).to eq(nil)

      qlass = r.qlass
      qlass_methods = qlass.methods.group_by(&:type)
      expect(qlass_methods[:rubyqt6_defined_functions].count).to eq(3)
      expect(qlass_methods[:constructor].count).to eq(1)
      expect(qlass_methods[:inherits]).to eq(nil)
      expect(qlass_methods[:public_functions].count).to eq(30)
      expect(qlass_methods[:public_slots].count).to eq(1)
      expect(qlass_methods[:signals].count).to eq(2)
      expect(qlass_methods[:static_public_members].count).to eq(4)

      method = qlass.methods.find { |method| method.rbname == "set_object_name" }
      expect(method.cppname).to eq("setObjectName")
    end

    it "ext/qt6/qtcore/qmetamethod-rb.cpp" do
      cppfile = "ext/qt6/qtcore/qmetamethod-rb.cpp"
      qmod = OpenStruct.new(name: "QtCore")
      rs = RubyQt6::RSpec.verify_qlass_cppfile cppfile, qmod

      r = rs["QMetaMethod"]
      expect(r.verified_initialize).to eq(nil)
      expect(r.verified_methods_count).to eq(29)
      expect(r.verified_enums_count).to eq(3)

      qlass = r.qlass
      qlass_enums = qlass.enums
      expect(qlass_enums.map(&:name)).to eq(["Access", "Attributes", "MethodType"])
    end
  end
end
