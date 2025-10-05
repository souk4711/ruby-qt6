RSpec.describe RubyQt6::QtCore::QVariant do
  it "bool" do
    o = described_class.from_bool(true)
    expect(o.type_name).to eq("bool")
    expect(described_class.to_bool(o)).to eq(true)
  end

  it "int" do
    o = described_class.from_int(1234)
    expect(o.type_name).to eq("int")
    expect(described_class.to_int(o)).to eq(1234)
  end

  it "double" do
    o = described_class.from_double(12.34)
    expect(o.type_name).to eq("double")
    expect(described_class.to_double(o)).to eq(12.34)
  end

  it "QString" do
    o = described_class.from_qstring("abc")
    expect(o.type_name).to eq("QString")
    expect(described_class.to_qstring(o)).to eq("abc")

    o = described_class.from_qstring(RubyQt6::QtCore::QString.new("abc"))
    expect(o.type_name).to eq("QString")
    expect(described_class.to_qstring(o)).to eq("abc")
  end
end
