RSpec.describe RubyQt6 do
  describe "._qmetaobject" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define ._qmetaobject @ #{klass}" do
        next if [RubyQt6::QtDBus::QDBusInterface].include?(cls)
        expect(cls._qmetaobject.class_name).to eq(klass.to_s)
      end
    end
  end

  describe "._rubyqt6_metaobject" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define ._rubyqt6_metaobject @ #{klass}" do
        expect(cls._rubyqt6_metaobject.class_name.split("::").last).to eq(klass.to_s)
      end
    end
  end

  describe "Bando::<...>" do
    bando_klasses = RubyQt6::Bando.constants

    todo = [
      :QAbstractButton,
      :QAbstractItemView,
      :QAbstractSlider,
      :QAbstractSpinBox,
      :QQuickWidget
    ]

    ::Object.constants.grep(/^Q/).each do |klass|
      required = (::Object.const_get(klass).ancestors & [
        RubyQt6::QtGui::QWindow,
        RubyQt6::QtWidgets::QWidget,
        RubyQt6::QtQuick::QQuickItem
      ]).count.nonzero?

      if required
        it "define Bando::#{klass}" do
          skip if todo.include?(klass)
          expect(bando_klasses.delete(klass)).to eq(klass)
        end
      end
    end

    it "define Bando::..." do
      expect(bando_klasses.delete(:QObject)).to eq(:QObject)
      expect(bando_klasses.delete(:QItemDelegate)).to eq(:QItemDelegate)
      expect(bando_klasses.delete(:QStyledItemDelegate)).to eq(:QStyledItemDelegate)
      expect(bando_klasses.delete(:QLayout)).to eq(:QLayout)
      expect(bando_klasses.delete(:QDBusInterface)).to eq(:QDBusInterface)
      expect(bando_klasses).to eq([])
    end
  end
end
