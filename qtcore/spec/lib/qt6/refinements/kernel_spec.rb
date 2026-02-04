RSpec.describe Kernel do
  describe "#rubyqt6_declare_enum_under" do
    it "#to_s" do
      expect(QLocale::Language::C.to_s).to eq("C")
    end

    it "#to_i" do
      expect(QLocale::Language::C.to_i).to eq(1)
    end

    it "#to_int" do
      expect(QLocale::Language::C.to_int).to eq(1)
    end

    it "#<=>" do
      expect(QLocale::Language::C > QLocale::Language::AnyLanguage).to eq(true)
      expect(QLocale::Language::C < QLocale::Language::Korean).to eq(true)
    end

    it "#~" do
      expect(~Qt::AlignHCenter).to be_a(Qt::Alignment)
      expect(~Qt::AlignHCenter).to eq(~0x0004)
    end

    it "#&" do
      expect(Qt::AlignHCenter & Qt::AlignVCenter).to be_a(Qt::Alignment)
      expect(Qt::AlignHCenter & Qt::AlignVCenter).to eq(0x0004 & 0x0080)
    end

    it "#^" do
      expect(Qt::AlignHCenter ^ Qt::AlignVCenter).to be_a(Qt::Alignment)
      expect(Qt::AlignHCenter ^ Qt::AlignVCenter).to eq(0x0004 ^ 0x0080)
    end

    it "#|" do
      expect(Qt::AlignHCenter | Qt::AlignVCenter).to be_a(Qt::Alignment)
      expect(Qt::AlignHCenter | Qt::AlignVCenter).to eq(0x0004 | 0x0080)
    end

    it "QVariant#initialize" do
      qvariant = QVariant.new(Qt::AlignHCenter)
      expect(qvariant.type_id).to eq(Qt::AlignmentFlag.default_qmetatype.id)
      expect(qvariant.type_name).to eq("Qt::AlignmentFlag")
    end

    it "QVariant#value" do
      qvariant = QVariant.new(Qt::AlignHCenter)
      expect(qvariant.value).to eq(Qt::AlignHCenter)
      expect(qvariant.value).to be_a(Qt::AlignmentFlag)
    end

    it "option - :alias" do
      expect(QLocale::Language.const_defined?(:C)).to eq(true)
      expect(QLocale.const_defined?(:C)).to eq(true)

      expect(QLocale::TagSeparator.const_defined?(:Dash)).to eq(true)
      expect(QLocale.const_defined?(:Dash)).to eq(false)
    end
  end
end
