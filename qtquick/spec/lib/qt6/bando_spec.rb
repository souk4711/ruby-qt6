RSpec.describe RubyQt6::Bando do
  [
    [RubyQt6::Bando::QQuickWindow, RubyQt6::QtQuick::QQuickWindow],
    [RubyQt6::Bando::QQuickView, RubyQt6::QtQuick::QQuickView],
    [RubyQt6::Bando::QQuickItem, RubyQt6::QtQuick::QQuickItem]
  ].each do |bando_qlass, qlass|
    it "#{bando_qlass} should behave like #{qlass}" do
      expect(bando_qlass._rubyqt6_metaobject).to eq(qlass._rubyqt6_metaobject)
      expect(bando_qlass._qmetaobject).to eq(qlass._qmetaobject)
    end
  end
end
