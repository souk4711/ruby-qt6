RSpec.describe RubyQt6 do
  describe "._qmetaobject" do
    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define ._qmetaobject @ #{klass}" do
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
    todo_qlasses = [
      RubyQt6::QtCore::QIODevice,
      RubyQt6::QtCore::QFileDevice,
      RubyQt6::QtCore::QFile,
      RubyQt6::QtGui::QClipboard,
      RubyQt6::QtWidgets::QLayout,
      RubyQt6::QtWidgets::QBoxLayout,
      RubyQt6::QtWidgets::QHBoxLayout,
      RubyQt6::QtWidgets::QVBoxLayout,
      RubyQt6::QtWidgets::QFormLayout,
      RubyQt6::QtWidgets::QGridLayout,
      RubyQt6::QtWidgets::QStackedLayout,
      RubyQt6::QtWidgets::QAbstractButton,
      RubyQt6::QtWidgets::QAbstractItemView,
      RubyQt6::QtWidgets::QAbstractSlider,
      RubyQt6::QtWidgets::QAbstractSpinBox,
      RubyQt6::QtQuickWidgets::QQuickWidget,
      RubyQt6::QtUiTools::QUiLoader
    ]

    ::Object.constants.grep(/^Q/).each do |klass|
      cls = ::Object.const_get(klass)
      next unless cls.is_a?(Class)
      next unless cls.ancestors.include?(RubyQt6::QtCore::QObject)

      it "define Bando::#{klass}" do
        skip if todo_qlasses.include?(cls)
        expect(RubyQt6::Bando.constants).to include(klass)
      end
    end
  end
end
