RSpec.describe RubyQt6::Bando do
  [
    [RubyQt6::Bando::QObject, RubyQt6::QtCore::QObject],
    [RubyQt6::Bando::QCoreApplication, RubyQt6::QtCore::QCoreApplication]
  ].each do |bando_qlass, qlass|
    it "#{bando_qlass} should behave like #{qlass}" do
      expect(bando_qlass._rubyqt6_metaobject).to eq(qlass._rubyqt6_metaobject)
      expect(bando_qlass._qmetaobject).to eq(qlass._qmetaobject)
    end
  end
end
