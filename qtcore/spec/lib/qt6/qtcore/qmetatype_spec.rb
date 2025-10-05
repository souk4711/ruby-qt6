RSpec.describe RubyQt6::QtCore::QMetaType do
  it ".from_klass" do
    o = described_class.from_klass(true)
    expect(o.id).to eq(1)
    expect(o.name).to eq("bool")

    o = described_class.from_klass(false)
    expect(o.id).to eq(1)
    expect(o.name).to eq("bool")

    o = described_class.from_klass(1234)
    expect(o.id).to eq(2)
    expect(o.name).to eq("int")

    o = described_class.from_klass(78.9)
    expect(o.id).to eq(6)
    expect(o.name).to eq("double")

    o = described_class.from_klass("str")
    expect(o.id).to eq(10)
    expect(o.name).to eq("QString")

    o = described_class.from_klass("qstr")
    expect(o.id).to eq(10)
    expect(o.name).to eq("QString")
  end
end
