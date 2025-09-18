RSpec.describe RubyQt6::Bando do
  [
    [RubyQt6::Bando::QGuiApplication, RubyQt6::QtGui::QGuiApplication],
    [RubyQt6::Bando::QWindow, RubyQt6::QtGui::QWindow]
  ].each do |bando_qlass, qlass|
    it "#{bando_qlass} should behave like #{qlass}" do
      expect(bando_qlass._rubyqt6_metaobject).to eq(qlass._rubyqt6_metaobject)
      expect(bando_qlass._qmetaobject).to eq(qlass._qmetaobject)
    end
  end
end
