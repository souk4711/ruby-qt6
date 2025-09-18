RSpec.describe RubyQt6::Bando do
  [
    [RubyQt6::Bando::QApplication, RubyQt6::QtWidgets::QApplication],
    [RubyQt6::Bando::QWidget, RubyQt6::QtWidgets::QWidget]
  ].each do |bando_qlass, qlass|
    it "#{bando_qlass} should behave like #{qlass}" do
      expect(bando_qlass._rubyqt6_metaobject).to eq(qlass._rubyqt6_metaobject)
      expect(bando_qlass._qmetaobject).to eq(qlass._qmetaobject)
    end
  end
end
