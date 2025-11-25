RSpec.describe Kernel do
  describe "#rubyqt6_declare_enum_under" do
    it "#to_s" do
      expect(RubyQt6::QtCore::QLocale::Language::C.to_s).to eq("C")
    end

    it "#to_i" do
      expect(RubyQt6::QtCore::QLocale::Language::C.to_i).to eq(1)
    end

    it "#to_int" do
      expect(RubyQt6::QtCore::QLocale::Language::C.to_int).to eq(1)
    end

    it "#<=>" do
      expect(RubyQt6::QtCore::QLocale::Language::C > RubyQt6::QtCore::QLocale::Language::AnyLanguage).to eq(true)
      expect(RubyQt6::QtCore::QLocale::Language::C < RubyQt6::QtCore::QLocale::Language::Korean).to eq(true)
    end

    it "#~" do
      expect(~RubyQt6::QtCore::Qt::AlignHCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
      expect(~RubyQt6::QtCore::Qt::AlignHCenter).to eq(~0x0004)
    end

    it "#&" do
      expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignVCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
      expect(RubyQt6::QtCore::Qt::AlignHCenter & RubyQt6::QtCore::Qt::AlignVCenter).to eq(0x0004 & 0x0080)
    end

    it "#^" do
      expect(RubyQt6::QtCore::Qt::AlignHCenter ^ RubyQt6::QtCore::Qt::AlignVCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
      expect(RubyQt6::QtCore::Qt::AlignHCenter ^ RubyQt6::QtCore::Qt::AlignVCenter).to eq(0x0004 ^ 0x0080)
    end

    it "#|" do
      expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignVCenter).to be_a(RubyQt6::QtCore::Qt::Alignment)
      expect(RubyQt6::QtCore::Qt::AlignHCenter | RubyQt6::QtCore::Qt::AlignVCenter).to eq(0x0004 | 0x0080)
    end

    it "option - :alias" do
      expect(RubyQt6::QtCore::QLocale::Language.const_defined?(:C)).to eq(true)
      expect(RubyQt6::QtCore::QLocale.const_defined?(:C)).to eq(true)

      expect(RubyQt6::QtCore::QLocale::TagSeparator.const_defined?(:Dash)).to eq(true)
      expect(RubyQt6::QtCore::QLocale.const_defined?(:Dash)).to eq(false)
    end
  end
end
